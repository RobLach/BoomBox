/****************************************
* common.cpp
* part of example source code
*
* This file is part of the "Zoidcom Automated Networking System" application library.
* Copyright (C)2002-2006 by Joerg Rueppel. See documentation for copyright and licensing details.
*****************************************/

#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#include <zoidcom.h>

#include "common.h"

BITMAP *buffer = NULL;

char target[256] = "127.0.0.1";
char target_port[7] = "9988";

// keyboard state
char keylast[KEY_MAX];

char loccliport[6] = "0";
char locsrvport[6] = "9988";
bool client = true, server = true;
char *str1 = "Target address:";
char *str2 = "Start server";
char *str3 = "Start client";
char *str4 = "Ok";
char *str5 = "On port:";
char *str6 = "Port:";
char *str7 = "Broadcast LAN";
char *str8 = "Zoidcom Example Program";
char *str9 = "LAN Server List";

// handle current broadcast
int broadcast_handle_proc(int msg, DIALOG *d, int c);
// start new broadcast
int start_broadcast_proc(int msg, DIALOG *d, int c);
// getter for broadcast list
char *listbox_getter(int index, int *list_size);
// draw system log
int draw_console(int msg, DIALOG *d, int c);
// handle list
int select_list_proc(int msg, DIALOG *d, int c);


DIALOG the_dialog[] =
{
   /* (proc)                (x)  (y)  (w)  (h)  (fg) (bg) (key) (flags)     (d1) (d2) (dp)            (dp2) (dp3) */
   { draw_console,          0,   0,   0,   0,   0,   0,   0,    0,          0,   0,   NULL,           NULL, NULL },
   { d_box_proc,            204, 72,  400, 392, 255, 199, 0,    0,          0,   0,   0,              NULL, NULL },
   { d_text_proc,           240, 112, 88,  12,  255, 0,   0,    0,          0,   0,   str1,           NULL, NULL },
   { d_edit_proc,           240, 128, 140, 8,   255, 0,   0,    D_GOTFOCUS, 255, 0,   target,         NULL, NULL },
   { d_edit_proc,           388, 128, 50,  8,   255, 0,   0,    0,          5,   0,   target_port,    NULL, NULL },
   { d_check_proc,          248, 340, 104, 20,  255, 0,   0,    D_SELECTED, 1,   0,   str2,           NULL, NULL },
   { d_check_proc,          460, 340, 120, 20,  255, 0,   0,    D_SELECTED, 1,   0,   str3,           NULL, NULL },
   { start_broadcast_proc,  456, 124, 120, 16,  255, 0,   0,    D_EXIT,     0,   0,   str7,           NULL, NULL },
   { d_text_proc,           248, 368, 52,  12,  255, 0,   0,    0,          1,   0,   str5,           NULL, NULL },
   { d_edit_proc,           316, 368, 44,  8,   255, 0,   0,    0,          5,   0,   locsrvport,     NULL, NULL },
   { d_text_proc,           460, 368, 52,  12,  255, 0,   0,    0,          1,   0,   str5,           NULL, NULL },
   { d_edit_proc,           528, 368, 44,  8,   255, 0,   0,    0,          5,   0,   loccliport,     NULL, NULL },
   { d_button_proc,         356, 400, 100, 49,  255, 0,   0,    D_EXIT,     0,   0,   str4,           NULL, NULL },
   { select_list_proc,      260, 168, 296, 156, 0,   0,   0,    0,          0,   0,   (void*)listbox_getter, NULL, NULL },
   { d_text_proc,           388, 112, 40,  12,  255, 0,   0,    0,          0,   0,   str6,           NULL, NULL },
   { d_ctext_proc,          396, 80,  128, 12,  255, 0,   0,    0,          0,   0,   str8,           NULL, NULL },
   { d_ctext_proc,          400, 156, 124, 8,   0,   0,   0,    0,          0,   0,   str9,           NULL, NULL },
   { broadcast_handle_proc, 0,   0,   0,   0,   0,   0,   0,    0,          0,   0,   NULL,           NULL, NULL },
   { NULL,                  0,   0,   0,   0,   0,   0,   0,    0,          0,   0,   NULL,           NULL, NULL },
};

volatile long timer = 0;

void sys_timer()
{
  timer++;
}
END_OF_FUNCTION(sys_timer);

void sys_init()
{
  srand((unsigned)time(NULL));
  allegro_init();
  install_keyboard();
  install_mouse();
  install_timer();

  set_color_depth(desktop_color_depth());
  if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0) != 0)
    if (set_gfx_mode(GFX_SAFE, 800, 600, 0, 0) != 0)
    {
      allegro_message("unable to set graphics mode");
      exit(255);
    }

  // install timer at 50 ticks/second
  LOCK_FUNCTION(sys_timer);
  LOCK_VARIABLE(timer);
  install_int_ex(sys_timer, BPS_TO_TIMER(UPDATE_RATE));

  set_window_title("Zoidcom Sample Program");
  set_display_switch_mode(SWITCH_BACKGROUND);

  memset(keylast, 0, sizeof(char)*KEY_MAX);

  if (gfx_capabilities & GFX_HW_VRAM_BLIT)
    buffer = create_video_bitmap(800, 600);
  else
    buffer = create_bitmap(800, 600);

  if (!buffer)
  {
    allegro_message("unable to create backbuffer");
    exit(255);
  }

  for (int ret = 0; the_dialog[ret].proc; ret++)
  {
    the_dialog[ret].fg = makecol(0, 0, 0);
    the_dialog[ret].bg = makecol(200, 200, 200);
    // edit fields have different color
    if (the_dialog[ret].proc == d_edit_proc)
    {
      the_dialog[ret].fg = makecol(255, 255, 255);
      the_dialog[ret].bg = makecol(20, 20, 20);
    }
  }
}

void sys_config()
{
  do_dialog(the_dialog, -1);

  if (!(the_dialog[5].flags & D_SELECTED))
    server = false;
  if (!(the_dialog[6].flags & D_SELECTED))
    client = false;
}

void sys_exit()
{
  destroy_bitmap(buffer);
  buffer = NULL;
  allegro_exit();
}

void sys_draw_help()
{
  rectfill(buffer, 100, 50, 700, 550, makecol(0, 0, 0));
  rect(buffer, 100, 50, 700, 550, makecol(200, 200, 200));

  int x = 105;
  int y = 55;

  textout_ex(buffer, font, "Keys:", x, y, makecol(255, 255, 255),  -1); y += text_height(font)*2;
  textout_ex(buffer, font, "F1 - toggle help", x, y, makecol(150, 150, 150),  -1); y += text_height(font);
  textout_ex(buffer, font, "F2 - toggle authority node (outlined rect)", x, y, makecol(150, 150, 150),  -1); y += text_height(font);
  textout_ex(buffer, font, "F3 - toggle owner node (filled rect)", x, y, makecol(150, 150, 150),  -1); y += text_height(font);
  textout_ex(buffer, font, "F4 - toggle proxy node (filled circle)", x, y, makecol(150, 150, 150),  -1); y += text_height(font);
  textout_ex(buffer, font, "F5 - toggle proxy spline", x, y, makecol(150, 150, 150),  -1); y += text_height(font);
  textout_ex(buffer, font, "F6 - toggle logoutput", x, y, makecol(150, 150, 150),  -1); y += text_height(font)*2;
  textout_ex(buffer, font, "F7/F8 - decrease/increase outgoing client and server lag", x, y, makecol(150, 150, 150),  -1); y += text_height(font);
  textout_ex(buffer, font, "        if both client and server are present, the lag is x2", x, y, makecol(150, 150, 150),  -1); y += text_height(font);
  textout_ex(buffer, font, "F9/F10 - dec/inc packetloss", x, y, makecol(150, 150, 150),  -1); y += text_height(font)*3;

  textout_ex(buffer, font, "SPACE (on server) - set random position for all objects (force correction)", x, y, makecol(150, 150, 150),  -1); y += text_height(font);
  textout_ex(buffer, font, "ENTER (on client) - try to cheat - set random position for own object", x, y, makecol(150, 150, 150),  -1); y += text_height(font)*3;

  textout_ex(buffer, font, "ARROW KEYS - move owner node", x, y, makecol(150, 150, 150),  -1); y += text_height(font)*2;
  textout_ex(buffer, font, "BACKSPACE - stop demo recording and switch to playback mode", x, y, makecol(150, 150, 150),  -1); y += text_height(font);
  textout_ex(buffer, font, "INSERT - advance demo position by -1", x, y, makecol(150, 150, 150),  -1); y += text_height(font);
  textout_ex(buffer, font, "DELETE - advance demo position by +1", x, y, makecol(150, 150, 150),  -1); y += text_height(font);
  textout_ex(buffer, font, "PGUP - advance demo position by -15", x, y, makecol(150, 150, 150),  -1); y += text_height(font);
  textout_ex(buffer, font, "PGDN - advance demo position by +15", x, y, makecol(150, 150, 150),  -1); y += text_height(font)*2;
  textout_ex(buffer, font, "P - pause", x, y, makecol(150, 150, 150),  -1); y += text_height(font);
  textout_ex(buffer, font, "Q - disconnect", x, y, makecol(150, 150, 150),  -1); y += text_height(font);
  textout_ex(buffer, font, "ESC - quit", x, y, makecol(150, 150, 150),  -1); y += text_height(font);
  y += text_height(font)*3;

  textout_ex(buffer, font, "Visuals:", x, y, makecol(255, 255, 255),  -1); y += text_height(font)*2;
  textout_ex(buffer, font, "Nodes flash GREEN when data was received", x, y, makecol(150, 150, 150),  -1); y += text_height(font);
  textout_ex(buffer, font, "Nodes flash RED when data was sent", x, y, makecol(150, 150, 150),  -1); y += text_height(font);
  y += text_height(font)*3;
  textout_ex(buffer, font, "Proxy nodes are only visible with a second client", x, y, makecol(150, 150, 150),  -1); y += text_height(font);
}

#define TXT_LEN 255
#define TXT_CNT 100
static char texthist[TXT_CNT][TXT_LEN+1];
static int last_line = 0;
void (*printhook) ( const char*, void* ) = NULL;
void *printhookdata = NULL;

void sys_print(const char *msg, ...)
{
  va_list args;
  char buf[1024];

  if (msg)
  {
    va_start( args, msg );
    vsprintf( buf, msg, args );
    va_end( args );
  }
  else
    return;

  if (last_line == TXT_CNT)
  {
    for (int i = 1; i < TXT_CNT; i++)
      strcpy(texthist[i-1], texthist[i]);
    last_line--;
  }

  strncpy(texthist[last_line], buf, TXT_LEN);
  texthist[last_line][TXT_LEN]=0;
  last_line++;

  if (printhook)
    printhook(buf, printhookdata);

//  printf("%s\n", buf);
}

void sys_setprinthook(void ( *_logfunc ) ( const char*, void* ), void *_data)
{
  printhook = _logfunc;
  printhookdata = _data;
}

void sys_draw_console()
{
  int y = 0;
  int start = MAX(last_line - (550/text_height(font)), 0);

  for (int i = start; i < last_line; i++)
  {
    char tmp = texthist[i][5];
    texthist[i][5] = 0;
    int color;
    if (strcmp(texthist[i], "[ZCOM") == 0)
      color = makecol(120, 120, 120);
    else
      color = makecol(150, 150, 150);

    texthist[i][5] = tmp;

    if (texthist)
      textout(buffer, font, texthist[i], 5, y, color);
    y += text_height(font);
  }
}

void sys_clear_console()
{
  last_line = 0;
}

void sys_draw()
{
  textprintf_right(buffer, font, 800, 580, makecol(255, 255, 255), "<F1> for help");
  blit(buffer, screen, 0, 0, 0, 0, 800, 600);
  clear(buffer);
}

void sys_rest(int x)
{
#ifdef ZCOM_PLATFORM_WIN32
  rest(x);
#elif defined ZCOM_PLATFORM_LINUX
  timeval t;
  t.tv_usec = x * 1000;
  t.tv_sec = 0;

  select(0, 0, 0, 0, &t);
#endif
}

// array holding running controls
#define MAX_FIND 32
char found_ctrls[MAX_FIND][256];
int found_fill = 0;

// zcom_control solely used for the broadcasting feature in the configurator
class Broadcaster : public ZCom_Control
{
public:
  void ZCom_cbDiscovered(const ZCom_Address &_addr, ZCom_BitStream &_reply)
  {
    if (found_fill < 32)
      sprintf(found_ctrls[found_fill++], "%d.%d.%d.%d:%d", _addr.getIP(0), _addr.getIP(1), _addr.getIP(2), _addr.getIP(3), _addr.getPort());
    const char *r = _reply.getStringStatic();
    sys_print("broadcast reply: %s", r);
  }

  virtual void ZCom_cbConnectResult( ZCom_ConnID _id, eZCom_ConnectResult _result, ZCom_BitStream &_reply ) {}
  virtual bool ZCom_cbConnectionRequest( ZCom_ConnID  _id, ZCom_BitStream &_request, ZCom_BitStream &_reply ){return false;}
  virtual void ZCom_cbConnectionSpawned( ZCom_ConnID _id ) {}
  virtual void ZCom_cbConnectionClosed( ZCom_ConnID _id, eZCom_CloseReason _reason, ZCom_BitStream &_reasondata ) {}
  virtual bool ZCom_cbZoidRequest( ZCom_ConnID _id, zU8 _requested_level, ZCom_BitStream &_reason ) {return false;}
  virtual void ZCom_cbZoidResult( ZCom_ConnID _id, eZCom_ZoidResult _result, zU8 _new_level, ZCom_BitStream &_reason ) {}
  virtual void ZCom_cbNodeRequest_Dynamic( ZCom_ConnID _id, ZCom_ClassID _requested_class, ZCom_BitStream *_announcedata, eZCom_NodeRole _role, ZCom_NodeID _net_id ) {}
  virtual void ZCom_cbNodeRequest_Tag( ZCom_ConnID _id, ZCom_ClassID _requested_class, ZCom_BitStream *_announcedata, eZCom_NodeRole _role, zU32 _tag ) {}
  virtual void ZCom_cbDataReceived( ZCom_ConnID _id, ZCom_BitStream &_data ) {}
  virtual bool ZCom_cbDiscoverRequest( const ZCom_Address &_addr, ZCom_BitStream &_request, ZCom_BitStream &_reply ) {return false;}
};

Broadcaster *broadcaster = NULL;

// broadcast proc
int start_broadcast_proc(int msg, DIALOG *d, int c)
{
  int ret;

  /* call the parent object */
  ret = d_button_proc(msg, d, c);


  /* trap the close return value and restart broadcast */
  if (ret == D_CLOSE) {
    found_fill = 0;
    if (broadcaster) delete broadcaster;
    broadcaster = new Broadcaster;
    if (broadcaster) 
    {
      if (broadcaster->ZCom_initSockets(true, 0, 0, CONTROL_ID_SIZE))
      {
        ZCom_Address addr;
        addr.setPort(BROADCAST_PORT);
        addr.setControlID(CONTROL_ID);
        ZCom_BitStream *bs = new ZCom_BitStream();
        bs->addString("anyone there?");
        broadcaster->ZCom_Discover(addr, bs);
        sprintf(found_ctrls[0], "Broadcasting to port %d...", BROADCAST_PORT);
        found_fill++;
      }
    }
    // error occured
    if (found_fill == 0)
    {
      sprintf(found_ctrls[0], "Error broadcasting to port %d...", BROADCAST_PORT);
      found_fill++;
    }
    return D_REDRAW; 
  }

  // on end dialog remove broadcaster again
  if (msg == MSG_END)
    if (broadcaster)
    {
      delete broadcaster;
      broadcaster = NULL;
    }

  /* otherwise just return */
  return ret;
}

// handle broadcast replies
int broadcast_handle_proc(int msg, DIALOG *d, int c)
{
  if (broadcaster)
    broadcaster->ZCom_processInput(eZCom_NoBlock);

 
  return D_O_K;
}

// give info to list gui element
char *listbox_getter(int index, int *list_size)
{
  if (index < 0) {
    *list_size = found_fill;
    return NULL;
  }
  else
    return found_ctrls[index]; 
}

// draw console while in GUI
int draw_console(int msg, DIALOG *d, int c)
{
  if (msg == MSG_DRAW)
  {
    // GUI wants to draw to screen only
    BITMAP *tmp = buffer;
    buffer = screen;
    sys_draw_console();
    buffer = tmp;
    // sys_draw();
  }
  return D_O_K;
}

// broadcast proc
int select_list_proc(int msg, DIALOG *d, int c)
{
  int ret;

  bool click = (msg == MSG_CLICK);

  /* call the parent object */
  ret = d_list_proc(msg, d, c);

  if (click) {
    if (d->d1 > 0)
    {
      strncpy(target, found_ctrls[d->d1], 255);
      char *p = strrchr(target, ':');
      if (p) {
        *p = '\0'; p++;
        strncpy(target_port, p, 6);
      }
    }
    return D_REDRAW; 
  }

  static int found_fill_old = -1;
  if (found_fill_old != found_fill) {
    found_fill_old = found_fill;
    return D_REDRAW;
  }

  /* otherwise just return */
  return ret;
}


/************************************************************************/
/* key press detection                                                  */
/************************************************************************/


void sys_keyprocess()
{
}

bool sys_keypressed(int _key)
{
  char c;
  if (key[_key])
    c = key[_key];
  else
  {
    keylast[_key] = 0;
    return false;
  }

  bool res = (c && !keylast[_key]);
  keylast[_key] = c;

  return res;
}

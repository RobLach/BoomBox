/****************************************
* main.cpp
* part of example source code
*
* This file is part of the "Zoidcom Automated Networking System" application library.
* Copyright (C)2002-2006 by Joerg Rueppel. See documentation for copyright and licensing details.
*****************************************/

#include <stdlib.h>
#include <stdio.h>

// input/output code
#include "common.h"

#include <zoidcom.h>

#include "nodeobj.h"
#include "client.h"
#include "server.h"
#include "demorec.h"

bool show_help = false;
bool show_log = true;
bool show_authority = false;
bool show_proxies = true;
bool show_spline = false;
bool show_owner = true;

void logfunc(const char *_log)
{
  sys_print(_log);
}

long local_time;

int main(int argc, char *argv[])
{
  sys_init();

  // initialize zoidcom
  ZoidCom *zcom = new ZoidCom(logfunc);
  if (!zcom)
    return -1;
  if (!zcom->Init())
  {
    sys_draw();
    sys_rest(2000);
    exit(255);
  }
  
  sys_config();

  // server operates on internal port 1 and UDP port 8899
  Server * srv = NULL;
  Client *cli = NULL;
  
  if (server)
    srv = new Server( 1, atoi(locsrvport) );

  // client on internal 2 and UDP 9988
  if (client)
    cli = new Client( 2, atoi(loccliport) );

  DemoRec demorec;
  demorec.Init(srv, cli, 20000);

  demorec.startRecording();

  // prepare target connection address for client
  // since Server and Client are both in this process, we can connect through an internal socket

  // put this whole thing into an extra {} block, so that the ZCom_Address objects get
  // out of scope before the ZoidCom object is deleted
  {
    ZCom_Address dst_loc;
    dst_loc.setType( eZCom_AddressLocal );
    dst_loc.setPort( 1 ); // server is on port 1
    dst_loc.setControlID(CONTROL_ID);

    // but we use UDP by default
    ZCom_Address dst_udp;
    char dst_address[512];
    sprintf(dst_address, "%s:%s", target, target_port);
    dst_udp.setAddress( eZCom_AddressUDP, CONTROL_ID, dst_address );

    // prepare the request
    ZCom_BitStream *req = new ZCom_BitStream();
    req->addString( "letmein2" );

    // initiate request
    if (strlen(target) > 0 && cli)
      if (!cli->ZCom_Connect( dst_udp, req ))
        sys_print("Client: unable to connect!");
  }

  local_time = timer;

  // we have to enter the mainloop now in order to get the connection processed
  while (!(key[KEY_ESC]))
  {
    while (key[KEY_P])
      yield_timeslice();

    // if exit reason do
    if (key[KEY_Q])
    {
      ZCom_BitStream *reason = new ZCom_BitStream();
      reason->addString( "shutting down..." );
      // supplying a reason is optional
      if (cli) cli->ZCom_disconnectAll( reason );
      else
        if (srv) srv->ZCom_disconnectAll( reason );
    }

    if (sys_keypressed(KEY_F1))
      show_help = !show_help;
    if (sys_keypressed(KEY_F2))
      show_authority = !show_authority;
    if (sys_keypressed(KEY_F3))
      show_owner = !show_owner;
    if (sys_keypressed(KEY_F4))
      show_proxies = !show_proxies;
    if (sys_keypressed(KEY_F5))
      show_spline = !show_spline;
    if (sys_keypressed(KEY_F6))
      show_log = !show_log;

    if (sys_keypressed(KEY_F7))
    {
      int lag = -20;
      if (srv && cli) lag /= 2;
      if (cli) cli->changeLagAndLoss(0, lag);
      if (srv) srv->changeLagAndLoss(0, lag);
    }
    if (sys_keypressed(KEY_F8))
    {
      int lag = 20;
      if (srv && cli) lag /= 2;
      if (cli) cli->changeLagAndLoss(0, lag);
      if (srv) srv->changeLagAndLoss(0, lag);
    }
    if (sys_keypressed(KEY_F9)) {
      if (cli) cli->changeLagAndLoss(-0.1f, 0);
      if (srv) srv->changeLagAndLoss(-0.1f, 0);
    }
    if (sys_keypressed(KEY_F10)) {
      if (srv) srv->changeLagAndLoss(0.1f, 0);
      if (cli) cli->changeLagAndLoss(0.1f, 0);
    }

    /************************************************************************/
    /* demo recording                                                       */
    /************************************************************************/

    if (!demorec.isPlaying())
    {
      while(local_time < timer)
      {
        {
          if (cli) cli->update();
          if (srv) srv->update();
        }
        local_time++;

        demorec.Update();
      }
    } else
      demorec.Update();

    /************************************************************************/
    /* demo player control                                                 */
    /************************************************************************/

    if (sys_keypressed(KEY_BACKSPACE)) { 
      demorec.stopRecording(); 
      demorec.startPlayback(); 
      sys_clear_console();
      sys_print("playback mode");
    }

    if (demorec.isPlaying())
    {
      if (sys_keypressed(KEY_PGDN))           demorec.nextPlayPos(15);
      if (sys_keypressed(KEY_PGUP))           demorec.prevPlayPos(15);
      if (sys_keypressed(KEY_INSERT))         demorec.prevPlayPos(1);
      if (sys_keypressed(KEY_DEL))            demorec.nextPlayPos(1);
      if (sys_keypressed(KEY_HOME))           demorec.startPlayback();
    }
    
    /************************************************************************/
    /* draw                                                                 */
    /************************************************************************/

    if (show_log)
      sys_draw_console();
    if (cli) 
      cli->draw(show_proxies, show_owner, show_spline);
    if (show_authority && srv)
      srv->draw();
    textprintf_right(buffer, font, 800, 590, makecol(255, 255, 255), "demopos: %d", demorec.getCurrentPos());
    if (show_help)
      sys_draw_help();
    sys_draw();

    sys_keyprocess();
    
    sys_rest(0);
  }


  delete cli;
  delete srv;

  delete zcom;

  sys_exit();

  return 0;
}
// allegro specific
END_OF_MAIN()

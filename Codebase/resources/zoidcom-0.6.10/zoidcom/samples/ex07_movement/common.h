/****************************************
* common.h
* part of example source code
*
* This file is part of the "Zoidcom Automated Networking System" application library.
* Copyright (C)2002-2006 by Joerg Rueppel. See documentation for copyright and licensing details.
*****************************************/

#ifndef _common_h_
#define _common_h_

#include <allegro.h>

#pragma warning(disable:4996)

extern char target[256], target_port[7];
extern char loccliport[6];
extern char locsrvport[6];
extern bool server, client;
extern volatile long timer;

extern BITMAP *buffer;

#define BROADCAST_PORT 9987

#define CONTROL_ID_SIZE 1
#define CONTROL_ID      0

#define UPDATE_RATE 50                              // hz
#define SIMULATION_TIME_PER_UPDATE (1000/UPDATE_RATE) // msecs per update

void sys_init();
void sys_config();
void sys_exit();
void sys_draw();
void sys_draw_console();
void sys_clear_console();
void sys_draw_help();
void sys_print(const char *msg, ...);
void sys_setprinthook(void ( *_logfunc ) ( const char*, void* ), void *_data);
void sys_rest(int x);

void sys_keyprocess();
bool sys_keypressed(int key);


#endif


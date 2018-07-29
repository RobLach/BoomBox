/****************************************
* demorec.h
* demo recorder
*
* This file is part of the "Zoidcom Automated Networking System" application library.
* Copyright (C)2002-2006 by Joerg Rueppel. See documentation for copyright and licensing details.
*****************************************/

#ifndef demorec_h
#define demorec_h

#include <zoidcom.h>
#include "nodeobj.h"
#include "common.h"

const zU32 cLogMaxLen = 300;
const zU32 cLogPerFrame = 10;

void demorec_loghook(const char *_log, void *_data);

class DemoRecClient
{
public:
  virtual zU32 getStateSize() = 0;
  virtual char* getState() = 0;
  virtual void setState(char *_data) = 0;
};

class DemoRec
{
  DemoRecClient *srv;
  char *srvdata;
  zU32  srvsize;

  DemoRecClient *cli;
  char *clidata;
  zU32  clisize;
  char *logdata;

  zU32 recpos, recmax;
  zU32 playpos, playmax;
  zU32 logframe;

  bool recording, playing;
public:
  DemoRec() : srv(NULL), cli(NULL), srvdata(NULL), clidata(NULL), logdata(NULL), recpos(0), playpos(0), playmax(0), recmax(0), logframe(0),
  recording(false), playing(false) {  }

  void Init(DemoRecClient *_srv, DemoRecClient *_cli, zU32 _amount) {
    srv = _srv;
    cli = _cli;
    if (srv) {
      srvsize = srv->getStateSize();
      srvdata = new char[srvsize*_amount];
    }
    else
      srvsize = 0;

    if (cli) {
      clisize = cli->getStateSize();
      clidata = new char[clisize*_amount];
    }
    else
      clisize = 0;

    logdata = new char[cLogMaxLen * _amount * cLogPerFrame];
    recmax = _amount-1;
    if ((srv && !srvdata) || (cli && !clidata) || !logdata)
    {
      if (srvdata) delete[]srvdata;
      if (clidata) delete[]clidata;
      if (logdata) delete[]logdata;
      return;
    }
    if (srvdata)
      memset(srvdata, 0, srvsize*_amount);
    if (clidata)
      memset(clidata, 0, clisize*_amount);

    memset(logdata, 0, cLogMaxLen*_amount);

    sys_setprinthook(demorec_loghook, this);
  }

  void startRecording()  {
    recpos = 0;
    playpos = 0;
    playmax = 0;
    recording = true;
  }

  void stopRecording() {
    recording = false;
  }

  zU32 getCurrentPos() {
    if (playing)
      return playpos;
    else
      return recpos;
  }

  void startPlayback() {
    playpos = 0;
    playing = true;
  }

  void stopPlayback() {
    playing = false;
  }

  void Update()
  {
    if (playing)
      playState();

    if (recording) {
      storeState();
      storeNext();
    }
  }

  bool isPlaying() { return playing; }

  zU32 getLogIndex(zU32 pos, zU32 frame) {
    return pos*cLogPerFrame*cLogMaxLen+frame*cLogMaxLen;
  }

  void storeState() {
    if (srv)
      memcpy(&srvdata[recpos*srvsize], srv->getState(), srvsize);
    if (cli)
    memcpy(&clidata[recpos*clisize], cli->getState(), clisize);
  }
  void storeLog(char *_data) {
    strncpy(&logdata[getLogIndex(recpos, logframe)], _data, cLogMaxLen-1);
    if (logframe < cLogPerFrame-1)
      logframe++;
  }
  void storeNext() {
    if (recpos < recmax)
    {
      recpos++;
      logframe = 0;
      playmax++;
    }
  }
  void playState() {
    if (srv)
      srv->setState(&srvdata[playpos*srvsize]);
    if (cli)
      cli->setState(&clidata[playpos*clisize]);
  }
  char* getLog(zU32 _logframe) {
    return &logdata[getLogIndex(playpos, logframe)];
  }
  void setPlayPos(zU32 _pos) {
    if (_pos < playmax)
      playpos = _pos;
  }
  void nextPlayPos(zU32 _amount) {
    if (playpos + _amount < playmax)
    {
      playpos += _amount;
      logframe = 0;
    }

    for (int i = 0; i < cLogPerFrame; i++)
      if (getLog(i)[0])
        sys_print("%s", getLog(i));
  }
  void prevPlayPos(zU32 _amount) {
    if (playpos - _amount > 0 && playpos > 0)
      playpos -= _amount;

    sys_clear_console();

    // rebuild log on screen
    zU32 temp = playpos;
    playpos = 0;
    while (temp > playpos)
      nextPlayPos(1);
  }
};


#endif

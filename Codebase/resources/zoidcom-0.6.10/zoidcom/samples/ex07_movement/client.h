/****************************************
* client.h
* part of example source code
*
* This file is part of the "Zoidcom Automated Networking System" application library.
* Copyright (C)2002-2006 by Joerg Rueppel. See documentation for copyright and licensing details.
*****************************************/

#ifndef client_h
#define client_h

#include <zoidcom.h>
#include "nodeobj.h"
#include "demorec.h"

class Client : public ZCom_Control, public DemoRecClient
{
protected:
  NObject *objs[OBJ_MAX];
  ZCom_ConnID m_id;
  int         m_localnode;
  float       m_packetloss;
  zS32        m_lag;
public:
  bool m_exitnow;

  Client( int _internalport, int _udpport );
  ~Client();

  // draw known objects to screen
  void draw(bool show_proxies, bool show_owners, bool show_spline);

  // handle keyboard input
  void update();

  void changeLagAndLoss(float _lossdelta, zS32 _lagdelta);

  // demorec interface
  zU32 getStateSize();
  char* getState();
  void setState(char *_data);
protected:
  // called when initiated connection process yields a result
  void ZCom_cbConnectResult( ZCom_ConnID _id, eZCom_ConnectResult _result, ZCom_BitStream &_reply );

  // connection has closed
  void ZCom_cbConnectionClosed( ZCom_ConnID _id, eZCom_CloseReason _reason, ZCom_BitStream &_reasondata );

  // zoidlevel transition finished
  void ZCom_cbZoidResult(ZCom_ConnID _id, eZCom_ZoidResult _result, zU8 _new_level, ZCom_BitStream &_reason);

  // server wants to tell us about new node
  void ZCom_cbNodeRequest_Dynamic(ZCom_ConnID _id, ZCom_ClassID _requested_class, ZCom_BitStream *_announcedata, eZCom_NodeRole _role, ZCom_NodeID _net_id);

  virtual bool ZCom_cbConnectionRequest( ZCom_ConnID  _id, ZCom_BitStream &_request, ZCom_BitStream &_reply ){return false;}
  virtual void ZCom_cbConnectionSpawned( ZCom_ConnID _id ) {}
  virtual bool ZCom_cbZoidRequest( ZCom_ConnID _id, zU8 _requested_level, ZCom_BitStream &_reason ) {return false;}
  virtual void ZCom_cbNodeRequest_Tag( ZCom_ConnID _id, ZCom_ClassID _requested_class, ZCom_BitStream *_announcedata, eZCom_NodeRole _role, zU32 _tag ) {}
  virtual void ZCom_cbDataReceived( ZCom_ConnID _id, ZCom_BitStream &_data ) {}
  virtual bool ZCom_cbDiscoverRequest( const ZCom_Address &_addr, ZCom_BitStream &_request, ZCom_BitStream &_reply ) {return false;}
  virtual void ZCom_cbDiscovered( const ZCom_Address & _addr, ZCom_BitStream &_reply )  {}
};

#endif

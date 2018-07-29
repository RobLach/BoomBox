/****************************************
* server.h
* part of example source code
*
* This file is part of the "Zoidcom Automated Networking System" application library.
* Copyright (C)2002-2005 by Joerg Rueppel. See documentation for copyright and licensing details.
*****************************************/

#ifndef server_h
#define server_h

#include <zoidcom.h>
#include <string.h>

#include "nodeobj.h"
#include "demorec.h"

class Server : public ZCom_Control, public DemoRecClient
{
protected:
  NObject *objs[OBJ_MAX];
  int      conncount;
  float    m_packetloss;
  zS32     m_lag;
public:
  bool is_ok;

  Server( int _internalport, int _udpport );
  ~Server();

  int getConnCount() { return conncount; }

  void changeLagAndLoss(float _lossdelta, zS32 _lagdelta);

  void update();
  void draw();

  // demorec interface
  zU32 getStateSize();
  char* getState();
  void setState(char *_data);
protected:
  // called on incoming connections
  bool ZCom_cbConnectionRequest( ZCom_ConnID _id, ZCom_BitStream &_request, ZCom_BitStream &_reply );
  // called when incoming connection has been established
  void ZCom_cbConnectionSpawned( ZCom_ConnID _id );
  // called when a connection closed
  void ZCom_cbConnectionClosed( ZCom_ConnID _id, eZCom_CloseReason _reason, ZCom_BitStream &_reasondata );
  // called when a connection wants to enter a zoidlevel
  bool ZCom_cbZoidRequest( ZCom_ConnID _id, zU8 _requested_level, ZCom_BitStream &_reason);
  // called when a connection entered a zoidlevel
  void ZCom_cbZoidResult(ZCom_ConnID _id, eZCom_ZoidResult _result, zU8 _new_level, ZCom_BitStream &_reason);
  // called when broadcast has been received
  bool ZCom_cbDiscoverRequest(const ZCom_Address &_addr, ZCom_BitStream &_request, ZCom_BitStream &_reply);

  virtual void ZCom_cbConnectResult( ZCom_ConnID _id, eZCom_ConnectResult _result, ZCom_BitStream &_reply ) {}
  virtual void ZCom_cbNodeRequest_Dynamic( ZCom_ConnID _id, ZCom_ClassID _requested_class, ZCom_BitStream *_announcedata, eZCom_NodeRole _role, ZCom_NodeID _net_id ) {}
  virtual void ZCom_cbNodeRequest_Tag( ZCom_ConnID _id, ZCom_ClassID _requested_class, ZCom_BitStream *_announcedata, eZCom_NodeRole _role, zU32 _tag ) {}
  virtual void ZCom_cbDataReceived( ZCom_ConnID _id, ZCom_BitStream &_data ) {}
  virtual void ZCom_cbDiscovered( const ZCom_Address & _addr, ZCom_BitStream &_reply )  {}
};


#endif

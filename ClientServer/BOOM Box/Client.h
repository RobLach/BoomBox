#ifndef __client_h_
#define __client_h_

#include <stdlib.h>
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <vector>

#include "zoidcom.h"

#include "Object.h"

using namespace std;


class Client : public ZCom_Control
{
private:
  ZCom_ConnID m_id;
  vector<Object*> objs;
  
public:
  // constructor - gets called when the client is created with new Client(...)
  Client();

  void ProcessUpdates();
  void registerClasses();

  bool exit_now;

protected:

  // called when the connecting ends
  void ZCom_cbConnectResult( ZCom_ConnID _id, eZCom_ConnectResult _result, ZCom_BitStream &_reply );
	
	// called when client finished entering zoidlevel
  void ZCom_cbZoidResult(ZCom_ConnID _id, eZCom_ZoidResult _result, zU8 _new_level, ZCom_BitStream &_reason);

  // called when a connection closed
  void ZCom_cbConnectionClosed( ZCom_ConnID _id, eZCom_CloseReason _reason, ZCom_BitStream &_reasondata );

  // called when data has been received
  void ZCom_cbDataReceived( ZCom_ConnID _id, ZCom_BitStream &_data );

  void Client::ZCom_cbNodeRequest_Dynamic(ZCom_ConnID _id, ZCom_ClassID _requested_class, ZCom_BitStream *_announcedata, eZCom_NodeRole _role, ZCom_NodeID _net_id);

  // unused callbacks are empty
  void ZCom_cbConnectionSpawned( ZCom_ConnID _id ) {}
  bool ZCom_cbConnectionRequest( ZCom_ConnID  _id, ZCom_BitStream &_request, ZCom_BitStream &_reply ){return false;}
  bool ZCom_cbZoidRequest( ZCom_ConnID _id, zU8 _requested_level, ZCom_BitStream &_reason) {return false;}
  bool ZCom_cbDiscoverRequest(const ZCom_Address &_addr, ZCom_BitStream &_request, ZCom_BitStream &_reply) {return false;}
  void ZCom_cbNodeRequest_Tag( ZCom_ConnID _id, ZCom_ClassID _requested_class, ZCom_BitStream *_announcedata, eZCom_NodeRole _role, zU32 _tag ) {}
  void ZCom_cbDiscovered( const ZCom_Address & _addr, ZCom_BitStream &_reply )  {}

  void ZCom_CleanUp();
};

#endif _CLIENT_H_
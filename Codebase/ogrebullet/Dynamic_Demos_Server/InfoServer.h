#ifndef __infoserver_h_
#define __infoserver_h_

#include "zoidcom.h"
#include "Object.h"

#include <vector>

#define BROADCAST_PORT 9987

// should check the system clock for time elapsed between game loop updates, but these will work for now
#define UPDATE_RATE 50                              // hz
#define SIMULATION_TIME_PER_UPDATE (1000/UPDATE_RATE) // msecs per update

using namespace std;

class Server : public ZCom_Control
{
protected:
  // number of users currently connected
  int      m_conncount;
  vector<Object*> objs;
public:
  // constructor - gets called when the server is created with new Server(...)u
  Server( int _internalport, int _udpport );

  void update();	// process any changes, service zoidcom, main game loop stuff

protected:
  // called on incoming connections
  bool ZCom_cbConnectionRequest( ZCom_ConnID _id, ZCom_BitStream &_request, ZCom_BitStream &_reply );

  // called when incoming connection has been established
  void ZCom_cbConnectionSpawned( ZCom_ConnID _id );

  // called when a connection closed
  void ZCom_cbConnectionClosed( ZCom_ConnID _id, eZCom_CloseReason _reason, ZCom_BitStream &_reasondata );

  bool ZCom_cbZoidRequest( ZCom_ConnID _id, zU8 _requested_level, ZCom_BitStream &_reason);

  void ZCom_cbZoidResult(ZCom_ConnID _id, eZCom_ZoidResult _result, zU8 _new_level, ZCom_BitStream &_reason);

  bool ZCom_cbDiscoverRequest(const ZCom_Address &_addr, ZCom_BitStream &_request, ZCom_BitStream &_reply);

  void ZCom_cbDataReceived( ZCom_ConnID _id, ZCom_BitStream &_data );
  
  // unused callbacks are empty
  void ZCom_cbConnectResult( ZCom_ConnID _id, eZCom_ConnectResult _result, ZCom_BitStream &_reply ) {}
  void ZCom_cbNodeRequest_Dynamic( ZCom_ConnID _id, ZCom_ClassID _requested_class, ZCom_BitStream *_announcedata, eZCom_NodeRole _role, ZCom_NodeID _net_id ) {}
  void ZCom_cbNodeRequest_Tag( ZCom_ConnID _id, ZCom_ClassID _requested_class, ZCom_BitStream *_announcedata, eZCom_NodeRole _role, zU32 _tag ) {}
  void ZCom_cbDiscovered( const ZCom_Address & _addr, ZCom_BitStream &_reply )  {}
};

#endif __infoserver_h_
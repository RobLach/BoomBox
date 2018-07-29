/****************************************
* server.cpp
* part of example source code
*
* This file is part of the "Zoidcom Automated Networking System" application library.
* Copyright (C)2002-2006 by Joerg Rueppel. See documentation for copyright and licensing details.
*****************************************/

#include "common.h"
#include "server.h"

Server::Server( int _internalport, int _udpport )
{
  // this will allocate the sockets and create local bindings
  if ( !ZCom_initSockets( true, _udpport, _internalport, CONTROL_ID_SIZE ) )
  {
    sys_print( "Server: unable to initialize the sockets" );
    is_ok = false;
  }
  else
    is_ok = true;

  ZCom_setControlID(CONTROL_ID);

  // string shown in zcoms debug output
  ZCom_setDebugName("ZCOM_SRV");

  // server wants to reply to broadcasts
  ZCom_setDiscoverListener(eZCom_DiscoverEnable, BROADCAST_PORT);

  // initialize object array
  int i;
  for (i = 0; i < OBJ_MAX; i++)
    objs[i] = NULL;

  // register the only object class we are going to use
  ZCom_registerClass("NObject", 0);

  // maximum 8k/sec upstream and 2k/sec/connection
  ZCom_setUpstreamLimit(8000, 2000);

  conncount = 0;

  m_packetloss = 0.0f;
  m_lag = 0;
}

Server::~Server()
{
  for (int i = 0; i < OBJ_MAX; i++)
    if (objs[i])
    {
      delete objs[i];
      objs[i] = NULL;
    }
}

void Server::changeLagAndLoss(float _lossdelta, zS32 _lagdelta)
{
  // change packet loss
  if (_lossdelta != 0.0f)
  {
    m_packetloss += _lossdelta;
    if (m_packetloss < 0) m_packetloss = 0.0f; else
      if (m_packetloss > 1) m_packetloss = 1.0f;
    ZCom_simulateLoss(0, m_packetloss);
  }

  // change lag
  if (_lagdelta != 0)
  {
    m_lag += _lagdelta;
    if (m_lag < 0) m_lag = 0; else
      if (m_lag > 400) m_lag = 400;
    ZCom_simulateLag(0, m_lag);
  }
}

// update the four random moving objects
void Server::update()
{
  // update replicators and tell zoidcom how much ingame time has passed since the last
  // time this was called
  ZCom_processReplicators(SIMULATION_TIME_PER_UPDATE);

  // all callbacks are generated from within the processInput calls
  ZCom_processInput( eZCom_NoBlock );

  // update the objects and their physics
	for (int i=0; i<OBJ_MAX; i++)
		if(objs[i])
			objs[i]->update();

  if (sys_keypressed(KEY_SPACE))
  {
    sys_print("server changing position of all objects");

    // set objects to random position
    for (int i=0; i<OBJ_MAX; i++)
      if(objs[i])
      {
        objs[i]->data.position[0] = 100+rand()%400;
        objs[i]->data.position[1] = 100+rand()%300;
      }
  }

  // outstanding data will be packed up and sent from here
  ZCom_processOutput();
}

void Server::draw()
{
  // draw objects
  for (int i = 0; i < OBJ_MAX; i++)
    if (objs[i])
      objs[i]->draw(false);
}

// called on incoming connections
bool Server::ZCom_cbConnectionRequest( ZCom_ConnID _id, ZCom_BitStream &_request, ZCom_BitStream &_reply )
{
  // retrieve request, we work with strings now, could as well be anything else the ZCom_BitStream class can handle
  const char * req = _request.getStringStatic();

  // address information
  const ZCom_Address* addr = ZCom_getPeer( _id );
  if ( addr )
  {
    if ( addr->getType() == eZCom_AddressLocal )
      sys_print( "Server: Incoming connection from localport: %d", addr->getPort() );
    else if ( addr->getType() == eZCom_AddressUDP )
      sys_print( "Server: Incoming connection from UDP: %d.%d.%d.%d:%d", addr->getIP( 0 ), addr->getIP( 1 ), addr->getIP( 2 ), addr->getIP( 3 ), addr->getPort() );
  }

  // check what the client is requesting
  if ( req && strlen( req ) > 0 && strcmp( req, "letmein2" ) == 0 )
  {
    sys_print( "Server: Incoming connection with ID: %d requesting: '%s'... accepted", _id, req );
    // accept the connection request
    _reply.addString("come_in");
    return true;
  }
  else
  {
    sys_print( "Server: Incoming connection with ID: %d requesting: '%s'... denied", _id, req );
    // deny connection request and send reason back to requester
    _reply.addString( "invalid request" );
    return false;
  }
}

// called when incoming connection has been established
void Server::ZCom_cbConnectionSpawned( ZCom_ConnID _id )
{
  sys_print( "Server: Incoming connection with ID: %d has been established.", _id );

  // request 20 packets/second and 200 bytes per packet from client (maximum values of course)
  ZCom_requestDownstreamLimit(_id, 20, 200);

  // initialize userdata to -1, otherwise we delete object 0 when connection closes again
  // and the connection has not entered zoidmode before
  ZCom_setUserData(_id, (void*) -1);

  conncount++;
}

// called when a connection closed
void Server::ZCom_cbConnectionClosed( ZCom_ConnID _id, eZCom_CloseReason _reason, ZCom_BitStream &_reasondata )
{
  sys_print( "Server: Connection with ID: %d has been closed", _id);

  // retrieve object belonging to client
  int slot = (int) ZCom_getUserData(_id);
  if (slot >= 0 && slot < OBJ_MAX)
  {
    // and delete the object
    if (objs[slot]) delete objs[slot];
    objs[slot] = NULL;
  }

  conncount--;
}

// a client wants to enter a zoidlevel
bool Server::ZCom_cbZoidRequest( ZCom_ConnID _id, zU8 _requested_level, ZCom_BitStream &_reason)
{
  // check level and accept
  if (_requested_level == 2)
  {
    sys_print("Server: accepted Zoidrequest for level [%d] from %d", _requested_level, _id);
    return true;
  }
  // or deny
  else
    return false;
}

// client entered a zoidlevel or failed
void Server::ZCom_cbZoidResult(ZCom_ConnID _id, eZCom_ZoidResult _result, zU8 _new_level, ZCom_BitStream &_reason)
{
  // failed
  if (_result != eZCom_ZoidEnabled)
  {
    sys_print("Server: %d failed to enter zoidmode", _id);
    return;
  }

  sys_print("Server: Zoidlevel transition successful for level [%d] from connection %d", _new_level, _id);
  sys_print("Server: Creating node for client to play with now...", _new_level, _id);

  // spawn new playerobject
  NObject *no = new NObject;

  // this will create the ZCom_Node and register it with us (we are a ZCom_Control)
  no->init(this);
  // make connection owner of object so connection may change x and y of object (see NObject::init())
  no->node->setOwner(_id, true);

  // search free slot
  for (int i = 0; i < OBJ_MAX; i++)
  {
    if (objs[i] == NULL)
    {
      no->data.slot = i;
      objs[i] = no;
      // remember slot in connection userdata
      ZCom_setUserData(_id, (void*) no->data.slot);
      sys_print("Server: inserted node in slot: %d", i);
      break;
    }
  }
}

// called when broadcast has been received
bool Server::ZCom_cbDiscoverRequest(const ZCom_Address &_addr, ZCom_BitStream &_request, ZCom_BitStream &_reply)
{
  const char *req = _request.getStringStatic();
  sys_print("broadcast request: %s", req);
  _reply.addString("alive and kicking");
  return true;
}


/************************************************************************/
/* demo recording                                                       */
/************************************************************************/

struct state_s
{
  bool isavail[OBJ_MAX];
  NObject::data_s data[OBJ_MAX];
};

static state_s statebuf;

zU32 Server::getStateSize()
{
  return sizeof(state_s);
}

char *Server::getState()
{
  for (int i = 0; i< OBJ_MAX; i++) {
    if (objs[i]) {
      memcpy(&statebuf.data[i], &objs[i]->data, sizeof(NObject::data_s));
      statebuf.isavail[i] = true;
    } else
      statebuf.isavail[i] = false;
  }
  return (char*) &statebuf;
}

void Server::setState(char *_data)
{
  state_s *state = (state_s*) _data;
  for (int i = 0; i< OBJ_MAX; i++)
    if (state->isavail[i] && objs[i])
      memcpy(&objs[i]->data, &state->data[i], sizeof(NObject::data_s));
}

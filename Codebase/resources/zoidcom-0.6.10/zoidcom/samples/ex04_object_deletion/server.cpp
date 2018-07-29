/****************************************
* server.cpp
* simple server in one source file
*
* This file is part of the "Zoidcom Automated Networking System" application library.
* Copyright (C)2002-2004 by Joerg Rueppel. See documentation for copyright and licensing details.
*****************************************/

#include <stdlib.h>
#include <stdio.h>

#include <zoidcom.h>

#include "gameobject.h"
#include "objecthandler.h"

//
// the server class
//

class Server : public ZCom_Control
{
protected:
  // number of users currently connected
  int            m_conncount;
  // the objecthandler
  ObjectHandler  m_objhandler;
public:
  // constructor - gets called when the server is created with new Server(...)
  Server( int _internalport, int _udpport )
  {
    m_conncount = 0;

    // this will allocate the sockets and create local bindings
    if ( !ZCom_initSockets( true, _udpport, _internalport, 0 ) )
    {
      printf("Failed to initialize sockets!\n");
      // exit program immediately
      exit(255);
    }

    // string shown in log output
    ZCom_setDebugName("ZCOM_SRV");

    // maximum 8k/sec upstream and 2k/sec/connection
    ZCom_setUpstreamLimit(8000, 2000);

    printf("Server running and listening on udp port: %d.\n", _udpport);    
  }

  ObjectHandler& getObjectHandler() { return m_objhandler; }

protected:

  //////////// OLD //////////////

  // called when client wants to enter a zoidlevel
  bool ZCom_cbZoidRequest( ZCom_ConnID _id, zU8 _requested_level, ZCom_BitStream &_reason)
  {
    printf("Client requesting to enter Zoidlevel: %d\n", _requested_level);

    // return true to accept the request
    return true;
  }

  // called when client finished entering zoidlevel
  void ZCom_cbZoidResult(ZCom_ConnID _id, eZCom_ZoidResult _result, zU8 _new_level, ZCom_BitStream &_reason)
  {
    if (_result == eZCom_ZoidEnabled)
      printf("Client entered Zoidlevel: %d\n", _new_level);
    else
      printf("Client failed entering Zoidlevel: %d\n", _new_level);
  }

  // called on incoming connections
  bool ZCom_cbConnectionRequest( ZCom_ConnID _id, ZCom_BitStream &_request, ZCom_BitStream &_reply ) 
  {
    printf("Someone wants to connect!\n");

    // return true to allow connection
    return true;
  }

  // called when incoming connection has been established
  void ZCom_cbConnectionSpawned( ZCom_ConnID _id )
  {
    printf("Someone has connected!\n");
    // one more connected
    m_conncount++;
    printf("Number of connections now: %d\n", m_conncount);
  }

  // called when a connection closed
  void ZCom_cbConnectionClosed( ZCom_ConnID _id, eZCom_CloseReason _reason, ZCom_BitStream &_reasondata )
  {
    printf("A connection has closed!\n");
    // one less connected
    m_conncount--;
    printf("Number of connections now: %d\n", m_conncount);
  }

  // called when data has been received
  void ZCom_cbDataReceived( ZCom_ConnID _id, ZCom_BitStream &_data )
  {
    // we assume that clients will only send strings
    // so no special handling, just output of incoming data
    printf("Received: %s\n", _data.getStringStatic());

    // create a new bitstream which will hold the reply
    ZCom_BitStream *answer = new ZCom_BitStream();

    // add data to the bitstream
    answer->addString("your data has been received");

    // send the bitstream to the connection from which the data was received
    ZCom_sendData(_id, answer, eZCom_ReliableOrdered);
  }


  // unused callbacks are empty
  bool ZCom_cbDiscoverRequest(const ZCom_Address &_addr, ZCom_BitStream &_request, ZCom_BitStream &_reply) {return false;}
  void ZCom_cbConnectResult( ZCom_ConnID _id, eZCom_ConnectResult _result, ZCom_BitStream &_reply ) {}
  void ZCom_cbNodeRequest_Dynamic( ZCom_ConnID _id, ZCom_ClassID _requested_class, ZCom_BitStream *_announcedata, eZCom_NodeRole _role, ZCom_NodeID _net_id ) {}
  void ZCom_cbNodeRequest_Tag( ZCom_ConnID _id, ZCom_ClassID _requested_class, ZCom_BitStream *_announcedata, eZCom_NodeRole _role, zU32 _tag ) {}
  void ZCom_cbDiscovered( const ZCom_Address & _addr, ZCom_BitStream &_reply )  {}
};

//
// log output function - writes log from zoidcom to console
//

void logfunc(const char *_log)
{
  // comment out this line if you don't want to see zoidcom's internal logging
  printf("%s\n", _log);
}


//
// main function - program starts here
//

int main(int argc, char *argv[])
{
  // initialize zoidcom with console logging function
  ZoidCom *zcom = new ZoidCom(logfunc);
  if (!zcom)
    return -1;

  if (!zcom->Init())
  {
    printf("Problem initializing Zoidcom.\n");
    return -1;
  }

  // server operates on internal port 1 and UDP port 8899
  Server *srv = new Server( 1, 8899 );

  // register the classes
  Rock::registerClass(srv);
  Tree::registerClass(srv);

  // create two objects, register them to srv, and add them to the object handler
  srv->getObjectHandler().addObject(new Rock(srv));
  srv->getObjectHandler().addObject(new Tree(srv));

  // as soon as a client connects and enters zoidlevel 1, srv will replicate these two objects

  printf("Press CTRL+C to abort.\n");

  // zoidcom needs to get called regularly to get anything done so we enter the mainloop now
  while (1)
  {
    // processes incoming packets
    // all callbacks are generated from within the processInput calls
    srv->ZCom_processInput( eZCom_NoBlock );

    // outstanding data will be packed up and sent from here
    srv->ZCom_processOutput();

    // pause the program for a few milliseconds
    ZoidCom::Sleep(10);

    // with a small probability, a new object is created here
    if (rand() % 100 > 98)
      srv->getObjectHandler().createRandomObject(srv);

    // with a small probability, an object is deleted here
    if (rand() % 100 > 98)
      srv->getObjectHandler().deleteRandomObject();
  }

  // delete the server object
  delete srv;

  // delete zoidcom
  delete zcom;

  return 0;
}

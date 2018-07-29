/****************************************
* client.cpp
* simple client in one source file
*
* This file is part of the "Zoidcom Automated Networking System" application library.
* Copyright (C)2002-2004 by Jörg Rüppel. See documentation for copyright and licensing details.
*****************************************/

#include <stdlib.h>
#include <stdio.h>

#include <zoidcom.h>

#include "gameobject.h"
#include "objecthandler.h"

//
// the client class
//

class Client : public ZCom_Control
{
protected:
  ObjectHandler m_objhandler;
public:
  // constructor - gets called when the client is created with new Client(...)
  Client()
  {
    // this will allocate the sockets and create local bindings
    if ( !ZCom_initSockets( true, 0, 0, 0 ) )
    {
      printf("Failed to initialize sockets!\n");
      // exit program immediately
      exit(255);
    }

    // string shown in log output
    ZCom_setDebugName("ZCOM_CLI");
  }

  ObjectHandler& getObjectHandler() { return m_objhandler; }

protected:

  //////////// NEW //////////////

  // gets called when server replicates a new object to client
  void ZCom_cbNodeRequest_Dynamic( ZCom_ConnID _id, ZCom_ClassID _requested_class, ZCom_BitStream *_announcedata, eZCom_NodeRole _role, ZCom_NodeID _net_id )
  {
    GameObject *newobj = NULL;

    printf("Server requested creation of new class!\n");

    // check if requested object is rock
    if (_requested_class == Rock::getClassID())
      newobj = new Rock(this);
    // or tree
    else if (_requested_class == Tree::getClassID())
      newobj = new Tree(this);

    m_objhandler.addObject(newobj);
  }

  //////////// OLD //////////////

  // called when client finished entering zoidlevel
  void ZCom_cbZoidResult(ZCom_ConnID _id, eZCom_ZoidResult _result, zU8 _new_level, ZCom_BitStream &_reason)
  {
    if (_result == eZCom_ZoidEnabled)
      printf("Client entered Zoidlevel: %d\n", _new_level);
    else
      printf("Client failed entering Zoidlevel: %d\n", _new_level);
  }

  // called when the connecting ends
  void ZCom_cbConnectResult( ZCom_ConnID _id, eZCom_ConnectResult _result, ZCom_BitStream &_reply )
  {
    // connection successful?
    if (_result == eZCom_ConnAccepted)
    {
      printf("Connected! Let's request Zoidlevel 1...\n");

      ZCom_requestZoidMode(_id, 1);
    }
    else
    {
      printf("Connection failed!\n");
      ZoidCom::Sleep(2000);
      // when connection failed, exit program
      exit(255);
    }
  }

  // called when a connection closed
  void ZCom_cbConnectionClosed( ZCom_ConnID _id, eZCom_CloseReason _reason, ZCom_BitStream &_reasondata )
  {
    printf("Connection closed!\n");
    ZoidCom::Sleep(2000);
    exit(0);
  }

  // called when data has been received
  void ZCom_cbDataReceived( ZCom_ConnID _id, ZCom_BitStream &_data )
  {
    // we assume that clients will only send strings
    // so no special handling, just output of incoming data
    printf("Received from server: %s\n", _data.getStringStatic());
  }


  // unused callbacks are empty
  void ZCom_cbConnectionSpawned( ZCom_ConnID _id ) {}
  bool ZCom_cbConnectionRequest( ZCom_ConnID  _id, ZCom_BitStream &_request, ZCom_BitStream &_reply ){return false;}
  bool ZCom_cbZoidRequest( ZCom_ConnID _id, zU8 _requested_level, ZCom_BitStream &_reason) {return false;}
  bool ZCom_cbDiscoverRequest(const ZCom_Address &_addr, ZCom_BitStream &_request, ZCom_BitStream &_reply) {return false;}
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

  // create client
  Client *cli = new Client( );

  // register the classes
  Rock::registerClass(cli);
  Tree::registerClass(cli);

  // create target address 
  ZCom_Address dst_udp;
  char dst_address[512] = "127.0.0.1:8899";
  dst_udp.setAddress( eZCom_AddressUDP, 0, dst_address );

  // connect to server
  printf("Connecting to %s...\n", dst_address);
  if (!cli->ZCom_Connect( dst_udp, NULL ))
  {
    printf("Client: unable to start connecting!\n");  
    exit(255);
  }

  printf("Press CTRL+C to abort.\n");

  // zoidcom needs to get called regularly to get anything done so we enter the mainloop now
  // otherwise it wouldn't even start to connect
  while (1)
  {
    // processes incoming packets
    // all callbacks are generated from within the processInput calls
    cli->ZCom_processInput( eZCom_NoBlock );

    // outstanding data will be packed up and sent from here
    cli->ZCom_processOutput();

    // clean up garbage objects
    cli->getObjectHandler().processEvents();

    // pause the program for a few milliseconds
    ZoidCom::Sleep(10);
  }

  // delete the client object
  delete cli;

  // delete zoidcom
  delete zcom;

  return 0;
}

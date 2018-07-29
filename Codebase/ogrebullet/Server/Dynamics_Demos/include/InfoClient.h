#ifndef __client_h_
#define __client_h_
/****************************************
* client.cpp
* simple client in one source file
*
* This file is part of the "Zoidcom Automated Networking System" application library.
* Copyright (C)2002-2004 by Jörg Rüppel. See documentation for copyright and licensing details.
*****************************************/

#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <list>
#include <iostream>

#include <zoidcom.h>
#include "Ogre.h"

#include "OgreBulletListener.h"
#include "Object.h"
#include "Player.h"
//#include "Team1.h"


using namespace std;
//
// the client class
//
//Team1 team1;

class Client : public ZCom_Control
{
private:
  vector<Object*> objs;
  Player* myAvatar;
  ZCom_ConnID m_id;
  Ogre::SceneManager* mScnMgr;	// keep pointer for new object creation

public:
	 fstream file;

  // constructor - gets called when the client is created with new Client(...)
	Client(Ogre::SceneManager* scnMgr)
	{
		// this will allocate the sockets and create local bindings
		if ( !ZCom_initSockets( true, 0, 0, 0 ) )
		{
			printf("Failed to initialize sockets!\n");
			// exit program immediately
			//     exit(255);
		}

		// string shown in log output
		ZCom_setDebugName("ZCOM_CLI");

		// initialize object array
		objs.clear();

		mScnMgr = scnMgr;

		myAvatar = 0x00;
		
		file.open("ClientOutput.txt", fstream::trunc | fstream::in | fstream::out);
	}

	/*
	void SetAvatarPosition(Ogre::Vector3 pos)
	{
		if (myAvatar)
			myAvatar->setPosition(pos);
	}
	void SetAvatarOrientation(Ogre::Quaternion ori)
	{
		if (myAvatar)
			myAvatar->setOrientation(ori);
	}*/

  void ProcessUpdates(float timeSinceLast)
  {    
	// update replicators and tell zoidcom how much ingame time has passed since the last
	// time this was called
	ZCom_processReplicators(100); //timeSinceLast * 1000); //SIMULATION_TIME_PER_UPDATE);

	// all callbacks are generated from within the processInput calls
	ZCom_processInput( eZCom_NoBlock );
/*
	// update objects and their physics
	for (vector<Object*>::iterator it = objs.begin(); it != objs.end(); it++)
	{
	  // update objects (actually, update only 'our' object by applying arrow key movement)
	  // and check for node events
	  ((Object*)*it)->update();

	  // object wants to be deleted
		if (((GameObject*)*it)->killme)
		{
			delete *it;
			objs.erase(it);
		}
	}
*/
	// outstanding data will be packed up and sent from here
	ZCom_processOutput();
  }

protected:
  // called when the connecting ends
	void ZCom_cbConnectResult( ZCom_ConnID _id, eZCom_ConnectResult _result, ZCom_BitStream &_reply )
	{
		// connection successful?
		if (_result == eZCom_ConnAccepted)
		{
			// create a bitstream for sending stuff to the server, just a test.
			//ZCom_BitStream *data = new ZCom_BitStream();
			//data->addString("Hello World from Client!");
			//// send the data to the server
			//if (ZCom_sendData(_id, data, eZCom_ReliableOrdered) == true)
			//	printf("Data sent!\n");
			//else
			//	printf("Error sending data!\n");

			file << "Connected! Let's request Zoidlevel 1..." << endl;
			ZCom_requestDownstreamLimit(_id, 30, 200);
			// request Zoid level 1
			ZCom_requestZoidMode(_id, 1);

			m_id = _id;
			ZCom_BitStream* connectTest = new ZCom_BitStream();
			connectTest->addString("This is a test message");
			ZCom_sendData(m_id, connectTest);
			connectTest = NULL;
		}
		else
		{
		  printf("Connection failed!\n");
		  ZoidCom::Sleep(2000);
		  // when connection failed, exit program
		  exit(255);
		}
	}
	// called when client finished entering zoidlevel
	void ZCom_cbZoidResult(ZCom_ConnID _id, eZCom_ZoidResult _result, zU8 _new_level, ZCom_BitStream &_reason)
	{
		  // disconnect on failure
		if (_result != eZCom_ZoidEnabled)
		{
			file << "Client: Zoidmode failed, disconnecting" << endl;
			ZCom_Disconnect(_id, NULL);
			return;
		}

		//if (_result == eZCom_ZoidEnabled)
		//  printf("Client entered Zoidlevel: %d\n", _new_level);
		//else
		//  printf("Client failed entering Zoidlevel: %d\n", _new_level);
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

void Client::ZCom_cbNodeRequest_Dynamic(ZCom_ConnID _id, ZCom_ClassID _requested_class, ZCom_BitStream *_announcedata, eZCom_NodeRole _role, ZCom_NodeID _net_id)
{
	// check the requested class
	if (_requested_class == Player::getClassID())
	{
		file << "Client: Server requested creation of a new 'Player' node. Network ID is: [" << _net_id << "]." << endl;
		file << "Client: Role for requested node will be " << (_role == eZCom_RoleProxy ? "'eZCom_RoleProxy'" : "'eZCom_RoleOwner' <- This is the node we can control now!") << endl;

		// create the object
		Player *av = new Player(this);


	
	//team1.addPlayer(*av);
	

		// this will create the object's node and register it with us
		//av->init(this);

//		av->data.slot = -1;

		objs.push_back(av);

		//if (_role == eZCom_RoleOwner)
		//	myAvatar = av;

		//av->setOwnerID(_id);

		// search for a free slot
		//for (int i = 0; i < OBJ_MAX; i++)
		//{
		//  if (objs[i] == NULL)
		//  {
		//	av->data.slot = i;
		//	objs[i] = av;
		//	ZCom_setUserData(_id, (void*) av->data.slot);

		//	// check if object is 'our' object
		//	if (_role == eZCom_RoleOwner)
		//	{
		//	  av->data.local = true;
		//	  m_localnode = i;
		//	}

		//	break;
		//  }
		//}

		// if no free slot was found disconnect
		//if (av->data.slot == -1)
		//{
		//  delete av;
		//  sys_print("Client: unable to handle more objects - diconnecting");
		//  ZCom_Disconnect(m_id, NULL);
		//}
	}
	else
		file << "Client: invalid class requested" << endl;
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

//void logfunc(const char *_log)
//{
//  // comment out this line if you don't want to see zoidcom's internal logging
//  printf("%s\n", _log);
//}

extern Client* myClient;

extern ZoidCom *zcom;

static short ZCom_Init(Ogre::SceneManager* scnMgr)
{
	  // initialize zoidcom with console logging function
	zcom = new ZoidCom("BoomBoxClientLog.txt"); //logfunc);
	if (!zcom)
		return -1;

	if (!zcom->Init())
	{
		cout << "Problem initializing Zoidcom.\n";
		return -1;
	}

	// create client
	myClient = new Client(scnMgr);

	// register the classes
	Player::registerClass(myClient);

	// create a tree, this example uses unique replication
	// for the tree, so we have to register the tree before
	// client connects
	//  Avatar *avatar = new Avatar(myClient, false);

	// create target address 
	ZCom_Address dst_udp;
	char dst_address[512] = "127.0.0.1:8899";
	dst_udp.setAddress( eZCom_AddressUDP, 0, dst_address );

    // prepare the request, i.e. log in password
    ZCom_BitStream *loginInfo = new ZCom_BitStream();
    loginInfo->addString( "guest/letmein" ); // hardcoded username and password

	// connect to server
	cout << "Connecting to " << dst_address << ".." << endl;
	ZCom_ConnID connectionID = myClient->ZCom_Connect( dst_udp, loginInfo );
	loginInfo = NULL;
	if (connectionID == ZCom_Invalid_ID)
	{
		cout << "Client: unable to start connection!\n";
		exit(255);
	}

  cout << "Press CTRL+C to abort.\n";

  return 0;
}

static void ZCom_CleanUp()
{
	myClient->file.close();
	// delete the client object
  delete myClient;

  // delete zoidcom
  delete zcom;


//  return 0;
}

#endif __client_h_
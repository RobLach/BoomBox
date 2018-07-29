#include "Client.h"


Client::Client()
{
	exit_now = false;
	// this will allocate the sockets and create local bindings
	if ( !ZCom_initSockets( true, 0, 0, 0 ) )
	{
		printf("Failed to initialize sockets!\n");
		// exit program immediately
		//     exit(255);
	}
		// string shown in log output
	ZCom_setDebugName("ZCOM_CLI");

	objs.clear();
}


void Client::ProcessUpdates()
{    
	// update replicators and tell zoidcom how much ingame time has passed since the last
	// time this was called
	ZCom_processReplicators(100); //timeSinceLast * 1000); //SIMULATION_TIME_PER_UPDATE);

	// all callbacks are generated from within the processInput calls
	ZCom_processInput( eZCom_NoBlock );

	/*
	Here we're updating each object individually, and also checking that the 
	server hasn't declared it dead.

	for (vector<Object*>::iterator it = objs.begin(); it != objs.end(); it++)
	{
	  // update objects (actually, update only 'our' object by applying arrow key movement)
	  // and check for node events
	  ((Van*)*it)->update();
	  ((Building*)*it)->update();

	  // object wants to be deleted
		if (((Object*)*it)->killme)
		{
			delete *it;
			objs.erase(it);
		}
	}*/

	// outstanding data will be packed up and sent from here
	ZCom_processOutput();
}

 // called when the connecting ends
void Client::ZCom_cbConnectResult( ZCom_ConnID _id, eZCom_ConnectResult _result, ZCom_BitStream &_reply )
{
	// connection successful?
	if (_result == eZCom_ConnAccepted)
	{
		cout << "Connected! Let's request Zoidlevel 1..." << endl;
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
void Client::ZCom_cbZoidResult(ZCom_ConnID _id, eZCom_ZoidResult _result, zU8 _new_level, ZCom_BitStream &_reason)
	{
		  // disconnect on failure
		if (_result != eZCom_ZoidEnabled)
		{
			cout << "Client: Zoidmode failed, disconnecting" << endl;
			ZCom_Disconnect(_id, NULL);
			return;
		}
	}

  // called when a connection closed
void Client::ZCom_cbConnectionClosed( ZCom_ConnID _id, eZCom_CloseReason _reason, ZCom_BitStream &_reasondata )
  {
    printf("Connection closed!\n");
    ZoidCom::Sleep(2000);
    this->exit_now = true;
  }

  // called when data has been received
  void Client::ZCom_cbDataReceived( ZCom_ConnID _id, ZCom_BitStream &_data )
  {
    // we assume that clients will only send strings
    // so no special handling, just output of incoming data
    printf("Received from server: %s\n", _data.getStringStatic());
  }

void Client::ZCom_cbNodeRequest_Dynamic(ZCom_ConnID _id, ZCom_ClassID _requested_class, ZCom_BitStream *_announcedata, eZCom_NodeRole _role, ZCom_NodeID _net_id)
{
	// check the requested class
	if (_requested_class == Van::getClassID())
	{
		cout << "Client: Server requested creation of a new 'Van' node. Network ID is: [" << _net_id << "]." << endl;
		cout << "Client: Role for requested node will be " << (_role == eZCom_RoleProxy ? "'eZCom_RoleProxy'" : "'eZCom_RoleOwner' <- This is the node we can control now!") << endl;
		Van* van = new Van(this);
		objs.push_back(van);
	}
	else if (_requested_class == Building::getClassID())
	{
		cout << "Client: Server requested creation of a new 'Building' node. Network ID is: [" << _net_id << "]." << endl;
		cout << "Client: Role for requested node will be " << (_role == eZCom_RoleProxy ? "'eZCom_RoleProxy'" : "'eZCom_RoleOwner' <- This is the node we can control now!") << endl;
		Building* building = new Building(this);
		objs.push_back(building);
	}
	else
	{
		cout << "Client: invalid class requested" << endl;
	}
}

// registers object classes on server
void Client::registerClasses()
{
	// classes must be registered in same order
	// on client and server
	Van::registerClass(this);
	Building::registerClass(this);
}


int _tmain(int argc, _TCHAR* argv[])
{
	  // initialize zoidcom with console logging function
	ZoidCom* zcom = new ZoidCom("BoomBoxClientLog.txt"); //logfunc);
	if (!zcom)
		return -1;

	if (!zcom->Init())
	{
		cout << "Problem initializing Zoidcom.\n";
		return -1;
	}

	// create client
	Client* myClient = new Client();
	myClient->registerClasses();

	// create target address 
	ZCom_Address dst_udp;
	char dst_address[512] = "127.0.0.1:8899";
	dst_udp.setAddress( eZCom_AddressUDP, 0, dst_address );

	char username[20];
	char password[20];
	cout << "Please enter your username and password." << endl;
	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;

	strcat(username, "/");
	strcat(username, password);

    // prepare the request, i.e. log in password
    ZCom_BitStream *loginInfo = new ZCom_BitStream();
    loginInfo->addString( username ); // hardcoded username and password

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
  while (!myClient->exit_now) {
	  myClient->ProcessUpdates();
  }
  delete myClient;
  delete zcom;

  return 0;
}
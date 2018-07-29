#include "Server.h"

Server::Server( int _internalport, int _udpport )
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

	// server wants to reply to broadcasts
	ZCom_setDiscoverListener(eZCom_DiscoverEnable, BROADCAST_PORT);

	// maximum 8k/sec upstream and 2k/sec/connection
	ZCom_setUpstreamLimit(8000, 2000);

	printf("Server running and listening on udp port: %d.\n", _udpport);  
}

  // called on incoming connections
bool Server::ZCom_cbConnectionRequest( ZCom_ConnID _id, ZCom_BitStream &_request, ZCom_BitStream &_reply ) 
{
  // retrieve request, we work with strings now, could as well be anything else the ZCom_BitStream class can handle
  const char* loginInfo = _request.getStringStatic();

  // address information
  const ZCom_Address* addr = ZCom_getPeer( _id );
  if ( addr )
  {
    if ( addr->getType() == eZCom_AddressLocal )
      cout << "Server: Incoming connection from localport: " << (int)addr->getPort() << endl;
    else if ( addr->getType() == eZCom_AddressUDP )
      cout << "Server: Incoming connection from UDP: " << (int)addr->getIP( 0 ) << "." << (int)addr->getIP( 1 ) << "." << (int)addr->getIP( 2 ) << 
		"." << (int)addr->getIP( 3 ) << ":" << (int)addr->getPort() << endl;
  }
  
  if ( loginInfo && strlen( loginInfo ) > 0 )
  {
    char tempLogin[30];
	strcpy_s(tempLogin, loginInfo);
	char* username = strtok(tempLogin, "/");
	char* password = strtok(NULL, "/");
	cout << "Server: username: " << username << ", password: " << password << endl;

	// check what the client is requesting
	if ( (strcmp( username, "guest" ) && strcmp( password, "letmein" )) == 0 )
	{
		cout << "Server: Incoming connection with ID: " << (int)_id << " with username: '" << username << "'... accepted" << endl;
		// accept the connection request
		_reply.addString("Login Accepted.");
		return true;
	}
	else 
	{
		cout << "Server: Incoming connection with ID: " << (int)_id << " with username: '" << username << "'... invalid login" << endl;
	}
  }
  else
  {
    cout << "Server: Incoming connection with ID: " << (int)_id << " requesting: '" << loginInfo << "'... denied" << endl;
    // deny connection request and send reason back to requester
    _reply.addString( "Invalid Username/Password." );
    return false;
  }
}

// called when incoming connection has been established
void Server::ZCom_cbConnectionSpawned( ZCom_ConnID _id )
{  
	cout << "Server: Incoming connection with ID: " << (int)_id << "has been established." << endl;

  // request 20 packets/second and 200 bytes per packet from client (maximum values of course)
  ZCom_requestDownstreamLimit(_id, 20, 200);

  // initialize userdata to -1, otherwise we delete object 0 when connection closes again
  // and the connection has not entered zoidmode before
  ZCom_setUserData(_id, (void*) _id);

  m_conncount++;
}

// called when a connection closed
void Server::ZCom_cbConnectionClosed( ZCom_ConnID _id, eZCom_CloseReason _reason, ZCom_BitStream &_reasondata )
{
  cout << "Server: Connection with ID: " << (int)_id << " has been closed" << endl;

  m_conncount--;
}

// called when data has been received
void Server::ZCom_cbDataReceived( ZCom_ConnID _id, ZCom_BitStream &_data )
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

// a client wants to enter a zoidlevel
bool Server::ZCom_cbZoidRequest( ZCom_ConnID _id, zU8 _requested_level, ZCom_BitStream &_reason)
{
  // check level and accept
  if (_requested_level == 1)
  {
    cout << "Server: accepted Zoidrequest for level [" << (int)_requested_level << "] from " << (int)_id << endl;
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
		cout << "Server: " << (int)_id << " failed to enter zoidmode" << endl;
		return;
	}

	cout << "Server: Zoidlevel transition successful for level [" << (int)_new_level << "] from connection " << (int)_id << endl;
}


// called when broadcast has been received
bool Server::ZCom_cbDiscoverRequest(const ZCom_Address &_addr, ZCom_BitStream &_request, ZCom_BitStream &_reply)
{
  const char *req = _request.getStringStatic();
  cout << "broadcast request: " << req << endl;
  _reply.addString("alive and kicking");
  return true;
}

void Server::update()
{
	// update replicators and tell zoidcom how much ingame time has passed since the last
	// time this was called
	ZCom_processReplicators(SIMULATION_TIME_PER_UPDATE);

	// all callbacks are generated from within the processInput calls
	ZCom_processInput( eZCom_NoBlock );

	ZCom_processOutput();
}

// registers object classes on server
void Server::registerClasses()
{
	// classes must be registered in same order
	// on client and server
	Van::registerClass(this);
	Building::registerClass(this);
}


int _tmain(int argc, _TCHAR* argv[])
{
	ZoidCom *zcom = new ZoidCom("BoomBoxServerLog.txt"); //logfunc);
	if (!zcom)
		return -1;

	if (!zcom->Init())
	{
		cout << "Problem initializing Zoidcom.\n";
		return -1;
	}

	// server operates on internal port 1 and UDP port 8899
	Server *srv = new Server( 1, 8899 );
	srv->registerClasses();
	Van* van = new Van(srv); // register van nodes

	Building *building = new Building(srv);  // register building node

	printf("Press CTRL+C to abort.\n");

	// zoidcom needs to get called regularly to get anything done so we enter the mainloop now
	// int i=0; DELETE NODES TEST
	while (1)
	{
		srv->update();

		// pause the program for a few milliseconds
		ZoidCom::Sleep(10);
		/*i++;
		if (i == 1000) {
			delete van;
			delete building;
			cout << "Van and Building deleted from server and all clients." << endl;
		}*/
	}

	// delete the server object
	delete srv;

	// delete zoidcom
	delete zcom;

	return 0;
}
#include "OSCReceive.h"

#define PORT 7124

namespace MusiVerse
{
	pthread_mutex_t* oscmutex;
	std::list<OSCData> rxCommands;
}

using namespace MusiVerse;

void *startListenThread(void *arg)
{
    ExamplePacketListener listener;
	//listener.SetMutex(oscmutex);
    UdpListeningReceiveSocket s(IpEndpointName( IpEndpointName::ANY_ADDRESS, PORT ),
            &listener );

    s.RunUntilSigInt();

	return NULL;
}

void ExamplePacketListener::ProcessMessage( const osc::ReceivedMessage& m, const IpEndpointName& remoteEndpoint )
{
    try{
        // example of parsing single messages. osc::OsckPacketListener
        // handles the bundle traversal.
        
		OSCData d;
		d.header = oscNothing;

		osc::ReceivedMessage::const_iterator arg = m.ArgumentsBegin();
        if( strcmp( m.AddressPattern(), "/a" ) == 0 )
		{
			d.header = oscMove;
			d.fData1 = (arg++)->AsFloat();
			d.fData2 = (arg++)->AsFloat();
			d.fData3 = (arg++)->AsFloat();
        } else if( strcmp( m.AddressPattern(), "/b" ) == 0 )
		{
			d.header = oscRotate;
			d.fData1 = (arg++)->AsFloat();
			d.fData2 = (arg++)->AsFloat();
		} else if( strcmp( m.AddressPattern(), "/c" ) == 0 )
		{
			d.header = oscBreak;
			d.iData1 = (arg++)->AsInt32();
		} else if( strcmp( m.AddressPattern(), "/d" ) == 0 )
		{
			d.header = oscSelection;
			d.iData1 = (arg++)->AsInt32();
		} else if( strcmp( m.AddressPattern(), "/e" ) == 0 )
		{
			d.header = oscCreatething;
			d.fData1 = (arg++)->AsFloat();
			d.iData1 = (arg++)->AsInt32();
		} else if( strcmp( m.AddressPattern(), "/f" ) == 0 )
		{
			d.header = oscColor;
			d.fData1 = (arg++)->AsFloat();
			d.fData2 = (arg++)->AsFloat();
			d.fData3 = (arg++)->AsFloat();
        } else if( strcmp( m.AddressPattern(), "/g" ) == 0 )
		{
			d.header = oscSize;
			d.fData1 = (arg++)->AsFloat();	//this is the inner dim as a %
			d.fData2 = (arg++)->AsFloat();	//this is outer dim
        } else if( strcmp( m.AddressPattern(), "/h" ) == 0 )
		{
			d.header = oscAction;
			d.iData1 = (arg++)->AsInt32();
		} else if( strcmp( m.AddressPattern(), "/i" ) == 0 )
		{
			d.header = oscDestination;
			d.fData1 = (arg++)->AsFloat();
			d.fData2 = (arg++)->AsFloat();
			d.fData3 = (arg++)->AsFloat();
		} else if( strcmp( m.AddressPattern(), "/j" ) == 0 )
		{
			d.header = oscLookAt;
			d.fData1 = (arg++)->AsFloat();
			d.fData2 = (arg++)->AsFloat();
			d.fData3 = (arg++)->AsFloat();
		} else if( strcmp( m.AddressPattern(), "/k" ) == 0 )
		{
			d.header = oscElectron;
			d.fData1 = (arg++)->AsFloat();	//this is distance
			d.fData2 = (arg++)->AsFloat();	// this is time to live
			d.fData3 = (arg++)->AsFloat();	//this is speed
		} else if( strcmp( m.AddressPattern(), "/l" ) == 0 )
		{
			d.header = oscMapping;
			d.iData1 = (arg++)->AsInt32();
		}
		if (d.header != oscNothing)
		{
			pthread_mutex_lock(MusiVerse::oscmutex);	//wait for the lock
			MusiVerse::rxCommands.push_back(d);
			pthread_mutex_unlock(MusiVerse::oscmutex);
		}
    }catch( osc::Exception& e )
	{
        // any parsing errors such as unexpected argument types, or 
        // missing arguments get thrown as exceptions.
        std::cout << "error while parsing message: "
            << m.AddressPattern() << ": " << e.what() << "\n";
    }
}
//void ExamplePacketListener::SetMutex(pthread_mutex_t* mut)
//{
//	mymutex = mut;
//}

OSCReceive::OSCReceive()
{
	pthread_mutexattr_t attr;
	pthread_mutexattr_init(&attr);
	MusiVerse::oscmutex = new pthread_mutex_t;
	pthread_mutex_init(MusiVerse::oscmutex, &attr);
	//is it locked to start?
	pthread_mutex_unlock(MusiVerse::oscmutex);
}
OSCReceive::~OSCReceive()
{
	delete MusiVerse::oscmutex;
	delete listenThread;
}

void OSCReceive::StartReception()
{
	int i = 0;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	listenThread = new pthread_t();
	pthread_create(listenThread, &attr, &startListenThread, (void *)i);
}
void OSCReceive::StopReception()
{
	pthread_cancel(*listenThread);
}
OSCData OSCReceive::ReadAPacket()
{
	OSCData o;
	o.header = oscNothing;
	if (pthread_mutex_trylock(MusiVerse::oscmutex) == 0)
	{
		if (MusiVerse::rxCommands.size() > 0)
		{
			o = MusiVerse::rxCommands.front();
			MusiVerse::rxCommands.pop_front();
		}
		pthread_mutex_unlock(MusiVerse::oscmutex);
	}
	return o;
}
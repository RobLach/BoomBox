#ifndef __SimpleSend_h_
#define __SimpleSend_h_

#include "osc/OscOutboundPacketStream.h"
#include "ip/UdpSocket.h"

#define OUTPUT_BUFFER_SIZE 1024

class myOSCHandle
{
protected:
	IpEndpointName ip;
	UdpTransmitSocket* transmitSocket;
	//osc::OutboundPacketStream p;
public:
	myOSCHandle(const char * addr, int prt)
	{
		ip = IpEndpointName(addr,prt); // ADDRESS, PORT );
		transmitSocket = new UdpTransmitSocket( ip );
	}

	/*int oscSend(char* message, int argc, std::string argv[])
	//int oscSend(char* message, int argc, double argv[])
	{	    
		char buffer[OUTPUT_BUFFER_SIZE];
		osc::OutboundPacketStream p( buffer, OUTPUT_BUFFER_SIZE );
	    
		int i;
		p << osc::BeginBundleImmediate
			<< osc::BeginMessage( message );
		for (i=0; i< argc; i++)
		{
			p << argv[i].c_str();
		}

		p << osc::EndMessage << osc::EndBundle;
	    
		transmitSocket->Send( p.Data(), p.Size() );

		return i;
	}*/

	int oscSend(const char* message, int argc, float argv[])
	//int oscSend(char* message, int argc, double argv[])
	{	    
		int i;
		char buffer[OUTPUT_BUFFER_SIZE];
		osc::OutboundPacketStream p( buffer, OUTPUT_BUFFER_SIZE );
	    
		p << osc::BeginBundleImmediate
			<< osc::BeginMessage( message );
		for (i=0; i< argc; i++)
		{
			p << argv[i];
		}

		p << osc::EndMessage << osc::EndBundle;
	    
		transmitSocket->Send( p.Data(), p.Size() );

		return i;
	}

	void oscSend(const char* message)
	{	    
		char buffer[OUTPUT_BUFFER_SIZE];
		osc::OutboundPacketStream p( buffer, OUTPUT_BUFFER_SIZE );
	    
		p << osc::BeginBundleImmediate
			<< osc::BeginMessage( message )
			<< osc::EndMessage 
			<< osc::EndBundle;
	    
		transmitSocket->Send( p.Data(), p.Size() );
	}
};

extern myOSCHandle* myOSC;		//global OSC handle
#endif __SimpleSend_h_
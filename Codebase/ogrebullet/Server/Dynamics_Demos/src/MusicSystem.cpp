/***************************************************************************

This source file is part of BoomBOX

This file defines all classes and functions related to the music system.

-----------------------------------------------------------------------------*/

#include "MusicSystem.h"
#include "SimpleSend.h"
#include <cstdlib>
#include <string>
#include <sstream>
#include <cmath>

MaxMSPHandle::MaxMSPHandle(int portNumber) {
	int mCount = 0;

	const char * addr = "localhost";
	mOSCHandle = new myOSCHandle("localhost", portNumber);
	
	// Fake "other players"
	for (int i = 0; i < NUMPLAYERS; i++) {
		mPlayers[i] = new Player();
		mPlayers[i]->mID = i;
		mPlayers[i]->mClass = 'A' + (rand() % 3);
		mPlayers[i]->mInstrument = rand() % 5;
		mPlayers[i]->mPattern = i;
		mPlayers[i]->mPosX = rand() % 100;
		mPlayers[i]->mPosY = rand() % 100;
	}
}

void MaxMSPHandle::update(int myPosX, int myPosY) {
	// hack hack hack
	mCount++;
	if (mCount % 100 != 0) {
		return;
	}

	std::stringstream stream;
	
	mPlayers[0]->mPosX = myPosX;
	mPlayers[0]->mPosY = myPosY;

	// First, prepare update string about self
	stream << "//myavatar:class=" << mPlayers[0]->mClass
		<< "&patternNumber=" << mPlayers[0]->mPattern;

	// Iterate through other players and append their info to string
	for( int i = 1; i < NUMPLAYERS; i++) {
		stream << "//otheravatar:id=" << mPlayers[i]->mID
			<<"&class=" << mPlayers[i]->mClass 
			<< "&patternNumber=" << mPlayers[i]->mPattern
			<< "&position=" << mPlayers[i]->mPosX << "|" << mPlayers[i]->mPosY
			<< "&distance=" << mCalcDistance(i);
	}
	
	// Now send the message via OSC
//	char * message = stream.str().c_str();

	mOSCHandle->oscSend(stream.str().c_str());
}

float MaxMSPHandle::mCalcDistance(int PlayerID) {
	float myXTerm = (float) (mPlayers[0]->mPosX - mPlayers[PlayerID]->mPosX);
	float myYTerm = (float) (mPlayers[0]->mPosY - mPlayers[PlayerID]->mPosY);
	return sqrt( pow( myXTerm, 2) + pow(myYTerm, 2));
}

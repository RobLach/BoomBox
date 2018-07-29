/***************************************************************************

This source file is part of BoomBOX

This file declares all classes and functions related to the music system.

-----------------------------------------------------------------------------*/

#ifndef _OGREBULLET_MusicSystem__H
#define _OGREBULLET_MusicSystem__H

#include "SimpleSend.h"
#include "Player.h"

// Temporary player num constant
#define NUMPLAYERS 3
/*
// Using temporary "player" class until this info is rolled into main player class
class Player {
public:
	int mID;
	int mPosX;
	int mPosY;
	char mClass;
	int mPattern;
	int mInstrument;
};
*/

class MaxMSPHandle
{
public:
	MaxMSPHandle(int portNumber);

	void update(int myPosX, int myPosY);
	// Future version of this update function will have the following prototype
	// (or something close to this):
	// void update(BBPlayerNode* firstPlayer);
	// For now we are using randomly generated positions for "other players"

private:
	float mCalcDistance(int PlayerID);

	myOSCHandle * mOSCHandle;

	// temporary member array to hold "players"
	Player* mPlayers[NUMPLAYERS];

	// hack hack hack
	int mCount;
};


#endif //_OGREBULLET_MusicSystem__H
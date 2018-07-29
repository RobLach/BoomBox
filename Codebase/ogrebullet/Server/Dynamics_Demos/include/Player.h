#pragma once

#ifndef _OGREBULLET_Player__H
#define _OGREBULLET_Player__H

#include "Object.h"
#include "Shapes/OgreBulletCollisionsBoxShape.h"
#include "OgreBulletCollisionsObject.h"
#include "Shapes/OgreBulletCollisionsCompoundShape.h"
#include "ExampleApplication.h"
#include "OgreBulletDynamics.h"
#include "OgreBulletListener.h"
#include "OgreBulletDynamicsRigidBody.h"
#include "OgreBulletDynamicsWorld.h"
#include "OgreBulletDynamicsRigidBody.h"
#include "Debug/OgreBulletCollisionsDebugDrawer.h"
#include "OgreBulletGuiListener.h"

#include "Constraints/OgreBulletDynamicsRaycastVehicle.h"
#include <string>

class Player : public Object
{
public:
	
	~Player(void);
	static ZCom_ClassID m_classid;

	// delete me later
	Player();

	Player(ZCom_Control *_control);

	static void registerClass(ZCom_Control *_control) {
		m_classid = _control->ZCom_registerClass("Player");
	}
	
	static ZCom_ClassID getClassID() { return m_classid; }

	void setName(string Name);
	int getLife();

	void makeCar(Ogre::SceneManager      *mSceneMgr, OgreBulletDynamics::DynamicsWorld *mWorld, Vector3 Position, int t);

	bool frameStarted(Real elapsedTime, Ogre::Camera * mCamera);
	void keyReleased( int n);
	void keyPressed( int n);

	// Yes, this is a hack
	int mID;
	int mPosX;
	int mPosY;
	char mClass;
	int mPattern;
	int mInstrument;

	  Ogre::Entity    *mChassis;

	  	OgreBulletDynamics::WheeledRigidBody        *mCarChassis;
    OgreBulletDynamics::VehicleTuning	        *mTuning;
    OgreBulletDynamics::VehicleRayCaster	    *mVehicleRayCaster;
    OgreBulletDynamics::RaycastVehicle	        *mVehicle;

	    Ogre::Entity    *mWheels[4];
    Ogre::SceneNode *mWheelNodes[4];

private:


    int mWheelsEngine[4];
    int mWheelsEngineCount;
    int mWheelsSteerable[4];
    int mWheelsSteerableCount;

    float mEngineForce;
    float mSteering;

    int mWheelEngineStyle;
    int mWheelSteeringStyle;


    bool mSteeringLeft;
    bool mSteeringRight;
	bool mAccelerate;
	bool mDecelerate;
	bool mBurnout;

	int playerHealth;
	string userName;
};

#endif
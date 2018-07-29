/***************************************************************************

This source file is part of OGREBULLET
(Object-oriented Graphics Rendering Engine Bullet Wrapper)
For the latest info, see http://www.ogre3d.org/phpBB2addons/viewforum.php?f=10

Copyright (c) 2007 tuan.kuranes@gmail.com (Use it Freely, even Statically, but have to contribute any changes)



This source file is not LGPL, it's public source code that you can reuse.
-----------------------------------------------------------------------------*/
#ifndef _OGREBULLET_Vehicles_Demo__H
#define _OGREBULLET_Vehicles_Demo__H

#include "OgreBulletDynamics.h"
#include "OgreBulletListener.h"

#include "MusicSystem.h"

// -------------------------------------------------------------------------
class Vehicles_Demo : public OgreBulletListener 
{
public:

Vehicles_Demo() : OgreBulletListener()
      {
        mName = "BoomBOX";
      };
    virtual ~Vehicles_Demo(){};


    void init(Ogre::Root *root, Ogre::RenderWindow *win, OgreBulletApplication *application);

    void keyPressed(BULLET_KEY_CODE key);
    void keyReleased(BULLET_KEY_CODE key);

    bool frameStarted(Ogre::Real elapsedTime);

private:
    OgreBulletDynamics::WheeledRigidBody        *mCarChassis;
    OgreBulletDynamics::VehicleTuning	        *mTuning;
    OgreBulletDynamics::VehicleRayCaster	    *mVehicleRayCaster;
    OgreBulletDynamics::RaycastVehicle	        *mVehicle;

    Ogre::Entity    *mChassis;
    Ogre::Entity    *mWheels[4];
    Ogre::SceneNode *mWheelNodes[4];


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

	// Music Stuff
	MaxMSPHandle * mMaxMSPHandle;
};


#endif //_OGREBULLET_Vehicles_Demo__H

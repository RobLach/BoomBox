/***************************************************************************

This source file is part of OGREBULLET
(Object-oriented Graphics Rendering Engine Bullet Wrapper)
For the latest info, see http://www.ogre3d.org/phpBB2addons/viewforum.php?f=10

Copyright (c) 2007 tuan.kuranes@gmail.com (Use it Freely, even Statically, but have to contribute any changes)



This source file is not LGPL, it's public source code that you can reuse.
-----------------------------------------------------------------------------*/
#include "Vehicle_Demo.h" 
//#include "Player.h"

#include "Shapes/OgreBulletCollisionsBoxShape.h"
#include "Shapes/OgreBulletCollisionsCompoundShape.h"

#include "OgreBulletDynamicsWorld.h"
#include "OgreBulletDynamicsRigidBody.h"
#include "Debug/OgreBulletCollisionsDebugDrawer.h"

#include "Constraints/OgreBulletDynamicsRaycastVehicle.h"


#if !(OGRE_VERSION <  ((1 << 16) | (3 << 8) | 0))
using namespace OIS;
#endif 

using namespace Ogre;
using namespace OgreBulletCollisions;
using namespace OgreBulletDynamics;

Team1 team1;


///btRaycastVehicle is the interface for the constraint that implements the raycast vehicle
///notice that for higher-quality slow-moving vehicles, another approach might be better
///implementing explicit hinged-wheel constraints with cylinder collision, rather then raycasts

static float	gMaxEngineForce = 4000.f;
static float	gAccelerationIncrement = 20.0f;

static float	gSteeringIncrement = 0.04f;
static float	gSteeringClamp = 0.4f;

static float	gWheelRadius = 0.5f;
static float	gWheelWidth = 0.4f;

static float	currentFOV = 45.0f;

static float	gWheelFriction = 1.8f;//1000;//1e30f;
static float	gSuspensionStiffness = 30.f;
static float	gSuspensionDamping = 2.3f;
static float	gSuspensionCompression = 4.4f;

static float	gRollInfluence = 0.1f;//1.0f;
static float   gSuspensionRestLength = 0.6;
static float   gMaxSuspensionTravelCm = 500.0;
static float   gFrictionSlip = 10.5;


static const Vector3    CameraStart            = Vector3(0, 25, 0);
// -------------------------------------------------------------------------

 Vector3   CarPosition             = Vector3(30, 3,0);

static btVector3* cameraPos = new btVector3( 100.0f, 100.0f, 100.0f); // for camera linear interpolation
static btVector3* cameraTarget = new btVector3( 10.0f, 10.0f, 10.0f);

static Real timeToUpdate = 0;

static const int gOSCPort = 7400;

#define CUBE_HALF_EXTENTS 1

// -------------------------------------------------------------------------
void Vehicles_Demo::init(Ogre::Root *root, Ogre::RenderWindow *win, OgreBulletApplication *application)
{
	
	team1.addPlayerNames("Shajee");
	playerNames = team1.playerNames;
	
    mHelpKeys.clear();
    mHelpKeys.push_back ("Welcome to Boom Box");
    mHelpKeys.push_back ("Choose What Team You want to play as");

	
    
    mHelpKeys.push_back ("Use Arrow Key to move Car.");
	if(mTeam1 == true && mTeam2 == false)
			mHelpKeys.push_back ("You Are On Team1");
	else if(mTeam1 == false && mTeam2 == true)
			mHelpKeys.push_back ("You Are On Team2");
	else 
		mHelpKeys.push_back ("Your not on a team");
	//wait(10);
	

// reset
    for (int i = 0; i < 4; i++)
    {
        mWheelsEngine[i] = 0;
        mWheelsSteerable[i] = 0;
    }
	 mWheelsSteerableCount = 2;
     mWheelsSteerable[0] = 0;
     mWheelsSteerable[1] = 1;

	mWheelsEngineCount = 2;
    mWheelsEngine[0] = 2;
    mWheelsEngine[1] = 3;

    mSteeringLeft = false;
    mSteeringRight = false;

    mEngineForce = 0;
    mSteering = 0;


	mAccelerate = false;
	mBurnout = false;
	mDecelerate = false;

    // ------------------------
    // Start OgreScene
    mSceneMgr = root->createSceneManager(ST_GENERIC);

    mCamera = mSceneMgr->createCamera("Cam");
    //mCamera->setFOVy(Degree(90));
    mCamera->setNearClipDistance(0.1);
    mCamera->setFarClipDistance(500);
    Viewport *vp = win->addViewport(mCamera);
    vp->setBackgroundColour(ColourValue(0,0,0));
    // Alter the camera aspect ratio to match the viewport
    mCamera->setAspectRatio(
        Real(vp->getActualWidth()) / Real(vp->getActualHeight()));
    mCamera->setPosition(CameraStart);
    mCamera->lookAt(CarPosition);
	

    OgreBulletListener::init(root, win, application);

    // ------------------------
    // add lights
    setBasicLight();

    // ------------------------
    // Add the Gui
    setPhysicGUI();
	
    // ------------------------
    // Start Bullet
    initWorld();

    // ------------------------
    // Add the ground
    
    // 0.1, 0.8
    addStaticPlane(0.3, 0.8);

	
	//Add Bases


#ifdef _DEBUG
	RigidBody* body;
	for(int i = -4; i <4; i++)
	{
		for(int j = -4; j<4; j++)
		{
	body = addStaticTrimesh("TextureMaterial/TEXFACE/CityBlockBase.tga",
			"CityBlockBase.mesh",
			Vector3(i*60,0.01,j*60), 
			Quaternion(Radian(Degree(-90)),Vector3::UNIT_X),
			0.1f, 
			0.8f,true);
	body = addStaticTrimesh("TextureMaterial/TEXFACE/CityBlockWhole.tga",
			"CityBlockWhole.mesh",
			Vector3(i*60,0.01,j*60), 
			Quaternion(Radian(Degree(-90)),Vector3::UNIT_X),
			0.1f, 
			0.8f,true);	
		}
	}
#else
	RigidBody* body;
	for(int i = -25; i <25; i++)
	{
		for(int j = -25; j<25; j++)
		{
	body = addStaticTrimesh("TextureMaterial/TEXFACE/CityBlockBase.tga",
			"CityBlockBase.mesh",
			Vector3(i*60,0.01,j*60), 
			Quaternion(Radian(Degree(-90)),Vector3::UNIT_X),
			0.1f, 
			0.8f,true);
	body = addStaticTrimesh("TextureMaterial/TEXFACE/CityBlockWhole.tga",
			"CityBlockWhole.mesh",
			Vector3(i*60,0.01,j*60), 
			Quaternion(Radian(Degree(-90)),Vector3::UNIT_X),
			0.1f, 
			0.8f,true);	
		}
	}
#endif

    /// create vehicle
	{


		const Vector3 chassisShift(0, 1.0, 0);
		float connectionHeight = 0.7f;

        mChassis = mSceneMgr->createEntity(
                "chassis" + StringConverter::toString(mNumEntitiesInstanced++),
                "chassis.mesh");

        SceneNode *node = mSceneMgr->getRootSceneNode ()->createChildSceneNode ();

        SceneNode *chassisnode = node->createChildSceneNode ();
        chassisnode->attachObject (mChassis);
		
        chassisnode->setPosition (chassisShift);


        mChassis->setQueryFlags (GEOMETRY_QUERY_MASK);
#if (OGRE_VERSION < ((1 << 16) | (5 << 8) | 0)) // only applicable before shoggoth (1.5.0)
        mChassis->setNormaliseNormals(true);
#endif
		mChassis->setCastShadows(true);



        BoxCollisionShape* chassisShape = new BoxCollisionShape(Vector3(1.f,0.75f,2.1f));
        CompoundCollisionShape* compound = new CompoundCollisionShape();
        compound->addChildShape(chassisShape, chassisShift); 

        mCarChassis = new WheeledRigidBody("carChassis", mWorld);

		if (mTeam1 == true)
			CarPosition = Vector3(60, 3, 0);
		else if (mTeam2 == true)
		    CarPosition = Vector3(30, 3, 0);

        mCarChassis->setShape (node, compound, 0.6, 0.6, 800, CarPosition, Quaternion::IDENTITY);
        mCarChassis->setDamping(0.2, 0.2);

        mCarChassis->disableDeactivation ();
        mTuning = new VehicleTuning(
            gSuspensionStiffness,
            gSuspensionCompression,
            gSuspensionDamping,
            gMaxSuspensionTravelCm,
            gFrictionSlip);

        mVehicleRayCaster = new VehicleRayCaster(mWorld);
        mVehicle = new RaycastVehicle(mCarChassis, mTuning, mVehicleRayCaster);

        {
            int rightIndex = 0;
            int upIndex = 1;
            int forwardIndex = 2;

            mVehicle->setCoordinateSystem(rightIndex, upIndex, forwardIndex);

            Vector3 wheelDirectionCS0(0,-1,0);
            Vector3 wheelAxleCS(-1,0,0);

            for (size_t i = 0; i < 4; i++)
            {
                mWheels[i] = mSceneMgr->createEntity(
                    "wheel" + StringConverter::toString(mNumEntitiesInstanced++),
                    "wheel.mesh");

                mWheels[i]->setQueryFlags (GEOMETRY_QUERY_MASK);
#if (OGRE_VERSION < ((1 << 16) | (5 << 8) | 0)) // only applicable before shoggoth (1.5.0)
                mWheels[i]->setNormaliseNormals(true);
#endif
				mWheels[i]->setCastShadows(true);

                mWheelNodes[i] = mSceneMgr->getRootSceneNode ()->createChildSceneNode ();
                mWheelNodes[i]->attachObject (mWheels[i]);

            }

            {
                bool isFrontWheel = true;

                Vector3 connectionPointCS0 (
                    CUBE_HALF_EXTENTS-(0.5*gWheelWidth),
                    connectionHeight,
                    2*CUBE_HALF_EXTENTS-gWheelRadius);


                mVehicle->addWheel(
                    mWheelNodes[0],
                    connectionPointCS0,
                    wheelDirectionCS0,
                    wheelAxleCS,
                    gSuspensionRestLength,
                    gWheelRadius,
                    isFrontWheel, gWheelFriction*0.9, gRollInfluence*2);

                connectionPointCS0 = Vector3(
                    -CUBE_HALF_EXTENTS+(0.5*gWheelWidth),
                    connectionHeight,
                    2*CUBE_HALF_EXTENTS-gWheelRadius);


                mVehicle->addWheel(
                    mWheelNodes[1],
                    connectionPointCS0,
                    wheelDirectionCS0,
                    wheelAxleCS,
                    gSuspensionRestLength,
                    gWheelRadius,
                    isFrontWheel, gWheelFriction*0.9, gRollInfluence*2);


                connectionPointCS0 = Vector3(
                    -CUBE_HALF_EXTENTS+(0.5*gWheelWidth),
                    connectionHeight,
                    -2*CUBE_HALF_EXTENTS+gWheelRadius);

                isFrontWheel = false;
                mVehicle->addWheel(
                    mWheelNodes[2],
                    connectionPointCS0,
                    wheelDirectionCS0,
                    wheelAxleCS,
                    gSuspensionRestLength,
                    gWheelRadius,
                    isFrontWheel, gWheelFriction, gRollInfluence);

                connectionPointCS0 = Vector3(
                    CUBE_HALF_EXTENTS-(0.5*gWheelWidth),
                    connectionHeight,
                    -2*CUBE_HALF_EXTENTS+gWheelRadius);

                mVehicle->addWheel(
                    mWheelNodes[3],
                    connectionPointCS0,
                    wheelDirectionCS0,
                    wheelAxleCS,
                    gSuspensionRestLength,
                    gWheelRadius,
                    isFrontWheel, gWheelFriction, gRollInfluence);
			}
               // mVehicle->setWheelsAttached();
		}
          
}

	// Start music
	{
		mMaxMSPHandle = new MaxMSPHandle(gOSCPort);
	}


}
// -------------------------------------------------------------------------
void Vehicles_Demo::keyPressed(BULLET_KEY_CODE key)
{
    OgreBulletListener::throwDynamicObject (key);
    OgreBulletListener::dropDynamicObject (key);

    switch(key)
    {
    case KC_LEFT: 
        mSteeringLeft = true;
        break;
    case KC_RIGHT: 
        mSteeringRight = true;
        break;
    case KC_DOWN:
		mDecelerate = true;
        break;
	case KC_UP:
		mAccelerate = true;
        break;
    case KC_LCONTROL:
        mBurnout = true;
        break;
	case KC_SPACE:
		mVehicle->getBulletVehicle()->m_wheelInfo[2].m_frictionSlip=0.01f;
		mVehicle->getBulletVehicle()->m_wheelInfo[3].m_frictionSlip=0.01f;
    default:
        break;

    }

  

    return OgreBulletListener::keyPressed (key);
}
// -------------------------------------------------------------------------
void Vehicles_Demo::keyReleased(BULLET_KEY_CODE key)
{
    switch(key)
    {

    case KC_LEFT: 
        mSteeringLeft = false;
        break;
    case KC_RIGHT: 
        mSteeringRight = false;
        break;
    case KC_DOWN:
		mDecelerate = false;
        break;
	case KC_UP:
		mAccelerate = false;
        break;
	case KC_LCONTROL:
        mBurnout = false;
        break;
	case KC_SPACE:
		mVehicle->getBulletVehicle()->m_wheelInfo[2].m_frictionSlip=gWheelFriction;
		mVehicle->getBulletVehicle()->m_wheelInfo[3].m_frictionSlip=gWheelFriction;
    default:
        break;

    }
    return OgreBulletListener::keyReleased (key);
}
// -------------------------------------------------------------------------
bool Vehicles_Demo::frameStarted(Real elapsedTime)
{

	 timeToUpdate += elapsedTime;



	if(mAccelerate)
	{
		if(mEngineForce < gMaxEngineForce/2){
			mEngineForce += gAccelerationIncrement;
		}
	}
	else if(mBurnout)
	{
		mEngineForce = gMaxEngineForce;
	}
	else if(mDecelerate)
	{
		if(mEngineForce > 0)
		{
			mEngineForce = 0;

		}
		if(mEngineForce > -(gMaxEngineForce/10))
		{
			mEngineForce -= gAccelerationIncrement * 100;
		}
	}
	else
	{

		 mEngineForce = 0;

	}


	if(mEngineForce >= 0)
	{
     mVehicle->applyEngineForce (mEngineForce/3.0f, 0);
	 mVehicle->applyEngineForce (mEngineForce/3.0f, 1);
	 mVehicle->applyEngineForce (mEngineForce, 2);
	 mVehicle->applyEngineForce (mEngineForce, 3);
	}
	else
	{
	 mVehicle->applyEngineForce (mEngineForce*2, 0);
	 mVehicle->applyEngineForce (mEngineForce*2, 1);
	 mVehicle->applyEngineForce (mEngineForce/2, 2);
	 mVehicle->applyEngineForce (mEngineForce/2, 3);

	}

	


    if (mSteeringLeft)
    {
        mSteering += gSteeringIncrement;
        if (mSteering > gSteeringClamp)
            mSteering = gSteeringClamp;
    }
    else if (mSteeringRight)
    {
        mSteering -= gSteeringIncrement;
        if (mSteering < -gSteeringClamp)
            mSteering = -gSteeringClamp;
    }
	else
	{
			//Psuedo Opposite Lock
	if (mSteering > 0.01)
	{
		mSteering -= gSteeringIncrement/2;
	}
	else if (mSteering < -0.01)
	{
		mSteering += gSteeringIncrement/2;
	}

	}




    // apply Steering on relevant wheels
    for (int i = mWheelsSteerable[0]; i < mWheelsSteerableCount; i++)
    {
        if (i < 2)
            mVehicle->setSteeringValue (mSteering, mWheelsSteerable[i]);
        else
            mVehicle->setSteeringValue (-mSteering, mWheelsSteerable[i]);
    }
	
	if(timeToUpdate > 1/60) //60fps
	{
	btVector3 temp = mVehicle->getBulletVehicle()->getChassisWorldTransform().getOrigin();
	btVector3 forwardVec = mVehicle->getBulletVehicle()->getForwardVector();


	cameraTarget->setX(cameraTarget->getX() - (cameraTarget->getX() - temp.getX())/10.0f); //linear smoothing
	cameraTarget->setY(cameraTarget->getY() - (cameraTarget->getY() - 1.0f - temp.getY())/10.0f); //linear smoothing
	cameraTarget->setZ(cameraTarget->getZ() - (cameraTarget->getZ() - temp.getZ())/10.0f); //linear smoothing

	if(mBurnout)
	 {
		 currentFOV = currentFOV - ((currentFOV - 25) / 200.0f);
		 cameraTarget->setY(cameraTarget->getY() - (cameraTarget->getY() - 2.0f - temp.getY())/10.0f);
	 }
	 else
	 {
		 currentFOV = currentFOV - ((currentFOV - 70) / 50.0f);

	 }
	

	btVector3* camPos;

	if(mVehicle->getBulletVehicle()->getCurrentSpeedKmHour() < -2.0f)
	{
		camPos = new btVector3(temp.x() - (forwardVec.x()*-4.0f) , 0.5f, temp.z() - (forwardVec.z()*-4.0f));
		currentFOV = currentFOV - ((currentFOV - 120) / 50.0f);
		mVehicle->getBulletVehicle()->m_wheelInfo[0].m_frictionSlip=0.5f;
		mVehicle->getBulletVehicle()->m_wheelInfo[1].m_frictionSlip=0.5f;

	}
	else
	{
		camPos = new btVector3(temp.x() - (forwardVec.x()*4.0f) , 2.5f, temp.z() - (forwardVec.z()*4.0f));
		mVehicle->getBulletVehicle()->m_wheelInfo[0].m_frictionSlip=gWheelFriction;
		mVehicle->getBulletVehicle()->m_wheelInfo[1].m_frictionSlip=gWheelFriction;

	}
	cameraPos->setX(cameraPos->getX() - (cameraPos->getX() - camPos->getX())/30.0f); //linear smoothing
	cameraPos->setY(cameraPos->getY() - (cameraPos->getY() - camPos->getY())/80.0f); //linear smoothing
	cameraPos->setZ(cameraPos->getZ() - (cameraPos->getZ() - camPos->getZ())/30.0f); //linear smoothing

	mCamera->setPosition(cameraPos->x(), cameraPos->y(), cameraPos->z());
	mCamera->lookAt(cameraTarget->x(), cameraTarget->y(), cameraTarget->z());
	mCamera->setFOVy(Degree(currentFOV)); //LOL

	// Send music update to max/msp
	mMaxMSPHandle->update(temp.getX(), temp.getY());

	timeToUpdate = 0;
	}

	


    return OgreBulletListener::frameStarted(elapsedTime);
}
// -------------------------------------------------------------------------

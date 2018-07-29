/***************************************************************************

This source file is part of OGREBULLET
(Object-oriented Graphics Rendering Engine Bullet Wrapper)
For the latest info, see http://www.ogre3d.org/phpBB2addons/viewforum.php?f=10

Copyright (c) 2007 tuan.kuranes@gmail.com (Use it Freely, even Statically, but have to contribute any changes)



This source file is not LGPL, it's public source code that you can reuse.
-----------------------------------------------------------------------------*/
#include "Constraints_Demo.h"

#include "OgreBulletDynamicsWorld.h"
#include "OgreBulletDynamicsRigidBody.h"
#include "Debug/OgreBulletCollisionsDebugDrawer.h"

#if !(OGRE_VERSION <  ((1 << 16) | (3 << 8) | 0))
using namespace OIS;
#endif 

using namespace Ogre;
using namespace OgreBulletCollisions;
using namespace OgreBulletDynamics;

// -------------------------------------------------------------------------
const Vector3 CameraStart					= Vector3(15, 15, 0);
const Vector3 TargetPosition				= Vector3(0, 6, 0);
// -------------------------------------------------------------------------


// -------------------------------------------------------------------------
void Constraints_Demo::init(Ogre::Root *root, Ogre::RenderWindow *win, OgreBulletApplication *application)
{
    mHelpKeys.clear();
    mHelpKeys.push_back (BASIC_HELP_INFO0);
    mHelpKeys.push_back (BASIC_HELP_INFO1);
    mHelpKeys.push_back (BASIC_HELP_INFO2);
    mHelpKeys.push_back (BASIC_HELP_INFO3);
    mHelpKeys.push_back (BASIC_HELP_INFO4);
    mHelpKeys.push_back (BASIC_HELP_INFO5);
    mHelpKeys.push_back (BASIC_HELP_INFO6);


    // ------------------------
    // Start OgreScene
    mSceneMgr = root->createSceneManager(ST_GENERIC);

    mCamera = mSceneMgr->createCamera("Cam");
    //mCamera->setFOVy(Degree(90));
    mCamera->setNearClipDistance(0.1);
    mCamera->setFarClipDistance(100);
    Viewport *vp = win->addViewport(mCamera);
    vp->setBackgroundColour(ColourValue(0,0,0));
    // Alter the camera aspect ratio to match the viewport
    mCamera->setAspectRatio(
        Real(vp->getActualWidth()) / Real(vp->getActualHeight()));
    mCamera->setPosition(CameraStart);
    mCamera->lookAt(TargetPosition);

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
	mWorld->getBulletDynamicsWorld()->setGravity(btVector3(0, -10.0f, 0));

    // ------------------------
    // Add the ground
    // 0.1, 0.8
    addStaticPlane(0.3, 0.8);

	//OgreBulletDynamics::RigidBody* b0 = addCube("obstacle", Ogre::Vector3(0, 6, 0),  Quaternion::IDENTITY, Vector3(1, 1, 1), 0.3, 0.8, 0);
	OgreBulletDynamics::RigidBody* b1 = addDynCube("cube", Vector3(0, 6, 0), Quaternion(Radian(Degree(22.5)), Vector3::UNIT_X), Vector3(1,1,1), 2.6f, 1.6f, 0.2f);
	OgreBulletDynamics::RigidBody* b2 = addDynSphere("sphere", Vector3(3, 6, 0), Quaternion(Radian(Degree(22.5)), Vector3::UNIT_X), 1.0f, 0.1f, 0.1f, 2.0f);

	//OgreBulletDynamics::PointToPointConstraint* constraint = 
	//	new OgreBulletDynamics::PointToPointConstraint(b2, b2->getCenterOfMassPivot(Ogre::Vector3(0, 6, 0)));

	btPoint2PointConstraint* c = new btPoint2PointConstraint(*(b1->getBulletRigidBody()), *(b2->getBulletRigidBody()), btVector3(0, 0, 0), btVector3(0, 3, 3));
	mWorld->getBulletDynamicsWorld()->addConstraint(c, true);

	//OgreBulletDynamics::PointToPointConstraint(
}

OgreBulletDynamics::RigidBody* Constraints_Demo::addDynCube(Ogre::String in_name, Ogre::Vector3 in_pos, Ogre::Quaternion in_q, Ogre::Vector3 in_bounds, Ogre::Real in_restitution, 
				Ogre::Real in_friction, Ogre::Real in_mass)
{
	//const Vector3 vec (mCamera->getDerivedPosition());
            OgreBulletDynamics::RigidBody *body = addCube(in_name, in_pos, in_q, 
                in_bounds, in_restitution, in_friction, in_mass);

            /*body->setLinearVelocity(
                mCamera->getDerivedDirection().normalisedCopy() * mShootSpeed
                );*/

			return body;
}

OgreBulletDynamics::RigidBody* Constraints_Demo::addDynSphere(Ogre::String in_name, Ogre::Vector3 in_pos, Ogre::Quaternion in_q, Ogre::Real in_size, Ogre::Real in_restitution, 
				Ogre::Real in_friction, Ogre::Real in_mass)
{
	//const Vector3 vec (mCamera->getDerivedPosition());
            OgreBulletDynamics::RigidBody *body = addSphere(in_name, in_pos, in_q, 
                in_size, in_restitution, in_friction, in_mass);

            /*body->setLinearVelocity(
                mCamera->getDerivedDirection().normalisedCopy() * mShootSpeed
                );*/

			return body;
}

// -------------------------------------------------------------------------
void Constraints_Demo::keyPressed(BULLET_KEY_CODE key)
{
    OgreBulletListener::throwDynamicObject (key);
    OgreBulletListener::dropDynamicObject (key);

    return OgreBulletListener::keyPressed (key);
}
// -------------------------------------------------------------------------
bool Constraints_Demo::frameStarted(Real elapsedTime)
{

    return OgreBulletListener::frameStarted(elapsedTime);
}

void Constraints_Demo::shutdown()
{
	OgreBulletListener::shutdown();

	//mWorld->getBulletDynamicsWorld()->get
	//mWorld->getBulletDynamicsWorld()->removeConstraint
}

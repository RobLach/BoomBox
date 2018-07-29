/***************************************************************************

This source file is part of OGREBULLET
(Object-oriented Graphics Rendering Engine Bullet Wrapper)
For the latest info, see http://www.ogre3d.org/phpBB2addons/viewforum.php?f=10

Copyright (c) 2007 tuan.kuranes@gmail.com (Use it Freely, even Statically, but have to contribute any changes)



This source file is not LGPL, it's public source code that you can reuse.
-----------------------------------------------------------------------------*/
#include "GameMenuApp.h" 
//#include "Player.h"

#include "Shapes/OgreBulletCollisionsBoxShape.h"
#include "Shapes/OgreBulletCollisionsCompoundShape.h"

#include "OgreBulletDynamicsWorld.h"
#include "OgreBulletDynamicsRigidBody.h"
#include "Debug/OgreBulletCollisionsDebugDrawer.h"

#include "Constraints/OgreBulletDynamicsRaycastVehicle.h"

#include <time.h>


#if !(OGRE_VERSION <  ((1 << 16) | (3 << 8) | 0))
using namespace OIS;
#endif 

using namespace Ogre;
using namespace OgreBulletCollisions;
using namespace OgreBulletDynamics;

//Team1 team1;


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
static bool    carNotMoved = false;


static const Vector3    CameraStart            = Vector3(0, 25, 0);
// -------------------------------------------------------------------------

// Vector3   CarPosition             = Vector3(30, 3,0);

static btVector3* cameraPos = new btVector3( 100.0f, 100.0f, 100.0f); // for camera linear interpolation
static btVector3* cameraTarget = new btVector3( 10.0f, 10.0f, 10.0f);

static Real timeToUpdate = 0;

static const int gOSCPort = 7400;

#define CUBE_HALF_EXTENTS 1

// -------------------------------------------------------------------------
void GameMenuApp::init(Ogre::Root *root, Ogre::RenderWindow *win, OgreBulletApplication *application)
{


	


	
    // ------------------------
    // Start OgreScene
    mSceneMgr = root->createSceneManager(ST_GENERIC);
   // gameGUI= new GameGUI(win, mSceneMgr);
//	gameMenu = new GameMenu1(win, mSceneMgr2);



    mCamera = mSceneMgr->createCamera("Cam");
    //mCamera->setFOVy(Degree(90));
    mCamera->setNearClipDistance(0.1);
    mCamera->setFarClipDistance(500);
    Viewport *vp = win->addViewport(mCamera);
    vp->setBackgroundColour(ColourValue(0,0,0));
    // Alter the camera aspect ratio to match the viewport
    mCamera->setAspectRatio(
        Real(vp->getActualWidth()) / Real(vp->getActualHeight()));
    //mCamera->setPosition(CameraStart);
    //mCamera->lookAt(CarPosition);



	

    OgreBulletListener::init(root, win, application);
//	gameMenu = new GameMenu1(mWindow, mSceneMgr);

	//gameGUI = new GameGUI(mWindow, mSceneMgr);

	 


 //    ------------------------
//     add lights
  //  setBasicLight();

    // ------------------------
    // Add the Gui
//   setPhysicGUI();
	
    // ------------------------
    // Start Bullet
    initWorld();

    // ------------------------
    // Add the ground
    
    // 0.1, 0.8
    //addStaticPlane(0.3, 0.8);

	
	//Add Bases


	

/*

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

*/


  
}
// -------------------------------------------------------------------------
void GameMenuApp::keyPressed(BULLET_KEY_CODE key)
{
	carNotMoved = true;
    OgreBulletListener::throwDynamicObject (key);
    OgreBulletListener::dropDynamicObject (key);

    switch(key)
    {
    case KC_LEFT: 
//        mSteeringLeft = true;
        break;
    case KC_RIGHT: 
  //      mSteeringRight = true;
        break;
    case KC_DOWN:
	//	mDecelerate = true;
        break;
	case KC_UP:
	//	mAccelerate = true;
        break;
    case KC_LCONTROL:
      //  mBurnout = true;
        break;
	case KC_SPACE:
		//mVehicle->getBulletVehicle()->m_wheelInfo[2].m_frictionSlip=0.01f;
	//	mVehicle->getBulletVehicle()->m_wheelInfo[3].m_frictionSlip=0.01f;
    default:
        break;

    }

  

    return OgreBulletListener::keyPressed (key);
}
// -------------------------------------------------------------------------
void GameMenuApp::keyReleased(BULLET_KEY_CODE key)
{
    switch(key)
    {

    case KC_LEFT: 
      //  mSteeringLeft = false;
        break;
    case KC_RIGHT: 
        //mSteeringRight = false;
        break;
    case KC_DOWN:
		//mDecelerate = false;
        break;
	case KC_UP:
		//mAccelerate = false;
        break;
	case KC_LCONTROL:
        //mBurnout = false;
        break;
	case KC_SPACE:
	//	mVehicle->getBulletVehicle()->m_wheelInfo[2].m_frictionSlip=gWheelFriction;
	//	mVehicle->getBulletVehicle()->m_wheelInfo[3].m_frictionSlip=gWheelFriction;
    default:
        break;

    }
    return OgreBulletListener::keyReleased (key);
}
// -------------------------------------------------------------------------
bool GameMenuApp::frameStarted(Real elapsedTime)
{

	 timeToUpdate += elapsedTime;



 /*CEGUI::System *sys = CEGUI::System::getSingletonPtr();

 CEGUI::WindowManager *wmgr = CEGUI::WindowManager::getSingletonPtr();
        CEGUI::Window *quit = wmgr->getWindow((CEGUI::utf8*)"CEGUIDemo/QuitButton");

		quit->subscribeEvent(CEGUI::PushButton::EventClicked,
			CEGUI::Event::Subscriber(&GameMenuApp::quit, this));


CEGUI::Editbox * editBox = static_cast<CEGUI::Editbox*>(CEGUI::WindowManager::getSingletonPtr()->getWindow("Editbox1"));

editBox->subscribeEvent(CEGUI::Editbox::EventTextAccepted, CEGUI::Event::Subscriber(&GameMenuApp::onTextAccepted, this));

CEGUI::Listbox * listBox = static_cast<CEGUI::Listbox*>(CEGUI::WindowManager::getSingletonPtr()->getWindow("Listbox1"));

listBox->subscribeEvent(CEGUI::Listbox::EventSelectionChanged, CEGUI::Event::Subscriber(&GameMenuApp::onSelectionChanged, this));

CEGUI::Checkbox * checkBox = static_cast<CEGUI::Checkbox*>(CEGUI::WindowManager::getSingletonPtr()->getWindow("Checkbox1"));

checkBox->subscribeEvent(CEGUI::Checkbox::EventCheckStateChanged, CEGUI::Event::Subscriber(&GameMenuApp::onCheckStateChanged, this));
checkBox->subscribeEvent(CEGUI::Checkbox::EventMouseEnters, CEGUI::Event::Subscriber(&GameMenuApp::onMouseEnters, this));
checkBox->subscribeEvent(CEGUI::Checkbox::EventMouseLeaves, CEGUI::Event::Subscriber(&GameMenuApp::onMouseLeaves, this));*/




		//multiLineEditbox->subscribeEvent(MultiLineEditbox::EventTextChanged, Event::Subscriber(&GameGUI::onTextChanged, this));



	//if(mMouse)
	//	mMousePanel->capture();

	

	


    return OgreBulletListener::frameStarted(elapsedTime);
}

bool GameMenuApp::quit(const CEGUI::EventArgs &e)
    {
//        mContinue = false;
        return false;
    }

bool GameMenuApp::onTextAccepted(const CEGUI::EventArgs &e)
{
	// Our text has been accepted by either deactivating it or pressing tab or enter.
	CEGUI::Editbox * editBox = static_cast<CEGUI::Editbox*>(CEGUI::WindowManager::getSingletonPtr()->getWindow("Editbox1"));
	// So we got the text here, do something with it. Lets just..put the text back in reverse order.
	CEGUI::String currentText = editBox->getText();

	std::string finalString;

	CEGUI::String::reverse_iterator ppkNode = currentText.rbegin();
	CEGUI::String::reverse_iterator ppkEnd = currentText.rend();

	for (; ppkNode != ppkEnd; ++ppkNode)
	{
		finalString.push_back((*ppkNode));
	}
	editBox->setText(finalString);
	return true;
}

bool GameMenuApp::onSelectionChanged(const CEGUI::EventArgs &e)
{
        // The selection has changed.
	CEGUI::Listbox * listBox = static_cast<CEGUI::Listbox*>(CEGUI::WindowManager::getSingletonPtr()->getWindow("Listbox1"));
	// Get the item we selected
	CEGUI::ListboxItem * selectedItem = listBox->getFirstSelectedItem();
	selectedItem->setText("Time for Speed Bonus");
	gMaxEngineForce *= 2;
		
	return true;
}

bool GameMenuApp::onCheckStateChanged(const CEGUI::EventArgs &e)
{
	// Our item has been checked or unchecked, update our item accordingly.
	updateCheckbox();
	//CarPosition             = Vector3(60, 3,0);
	//if(carNotMoved == false)
    //  mCarChassis->setShape (node, compound, 0.6, 0.6, 800, CarPosition , Quaternion::IDENTITY);
	return true;
}

bool GameMenuApp::onMouseEnters(const CEGUI::EventArgs &e)
{
	// The mouse has entered, update the checkbox accordingly.
	updateCheckbox();		
	return true;
}

bool GameMenuApp::onMouseLeaves(const CEGUI::EventArgs &e)
{
	CEGUI::Checkbox * checkBox = static_cast<CEGUI::Checkbox*>(CEGUI::WindowManager::getSingletonPtr()->getWindow("Checkbox1"));
	// Reset
	checkBox->setText("DO you Wanna Join Team 1");
	return true;
}
	
void  GameMenuApp::updateCheckbox()
{
	CEGUI::Checkbox * checkBox = static_cast<CEGUI::Checkbox*>(CEGUI::WindowManager::getSingletonPtr()->getWindow("Checkbox1"));

	if (checkBox->isSelected())
	{
		// Our checkbox is selected, so someone has previously said 'yes'.
		checkBox->setText("Click to choose no!");
	}
	else
	{
		// Our item is not selected, so someone hasn't done anything yet, or it has been previously
		//  unchecked.
		checkBox->setText("Click to choose yes!");
	}
}








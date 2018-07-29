// SERVER SERVER SERVER SERVER SERVER SERVER SERVER 

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

#include <time.h>

#if !(OGRE_VERSION <  ((1 << 16) | (3 << 8) | 0))
using namespace OIS;
#endif 

using namespace Ogre;
using namespace OgreBulletCollisions;
using namespace OgreBulletDynamics;

Team1 team1;

Player player1;
Player player2;

#include <stdlib.h>
#include <stdio.h>

#include <zoidcom.h>

bool hasConnection = false;

bool throwshit = false;
bool throwshit2 = false;


struct playerKeys {
	playerKeys(bool acc = false, bool dec = false, bool lef = false, 
		       bool rig = false, bool bur = false , bool bra = false) :
	   isAcc(acc), 
	   isDec(dec), 
	   isLeft(lef), 
	   isRight(rig), 
	   isBurnOut(bur), 
	   isHBrake(bra) {}

	bool isAcc;
	bool isDec;
	bool isLeft;
	bool isRight;
	bool isBurnOut;
	bool isHBrake;
};

playerKeys* avatarKeyPresses;

class Server : public ZCom_Control
{
protected:
  // number of users currently connected
  int      m_conncount;

public:
  // constructor - gets called when the server is created with new Server(...)
  Server( int _internalport, int _udpport )
  {
    m_conncount = 0;

    // this will allocate the sockets and create local bindings
    if ( !ZCom_initSockets( true, _udpport, 0) )
    {
      //printf("Failed to initialize sockets!\n");
      // exit program immediately
      exit(255);
    }

    // string shown in log output
    ZCom_setDebugName("ZCOM_SRV");

    // maximum 8k/sec upstream and 2k/sec/connection
    ZCom_setUpstreamLimit(8000, 2000);

    //printf("Server running and listening on udp port: %d.\n", _udpport);   

	// Initialize keypress storage
	avatarKeyPresses = new playerKeys[20];

  }

  // called on incoming connections
  bool ZCom_cbConnectionRequest( ZCom_ConnID _id, ZCom_BitStream &_request, ZCom_BitStream &_reply ) 
  {
    //printf("Someone wants to connect!\n");

    // return true to allow connection
    return true;
  }

  // called when incoming connection has been established
  void ZCom_cbConnectionSpawned( ZCom_ConnID _id )
  {
	hasConnection = true;;
    //printf("Someone has connected!\n");
    // one more connected
    m_conncount++;
	 //printf("Number of connections now: %d\n", m_conncount);

  }

  // called when a connection closed
  void ZCom_cbConnectionClosed( ZCom_ConnID _id, eZCom_CloseReason _reason, ZCom_BitStream &_reasondata )
  {
    //printf("A connection has closed!\n");
    // one less connected
    m_conncount--;
    //printf("Number of connections now: %d\n", m_conncount);
  }

  // called when data has been received
  void ZCom_cbDataReceived( ZCom_ConnID _id, ZCom_BitStream &_data )
  {
    // we assume that clients will only send strings
    // so no special handling, just output of incoming data
    //printf("Received: %s\n", _data.getStringStatic());

	// Read six bools for player _id's keypresses
	avatarKeyPresses[(int)_id] = playerKeys(_data.getBool(),_data.getBool(),_data.getBool(),_data.getBool(),_data.getBool(),_data.getBool());

	if(avatarKeyPresses[(int)_id].isAcc)
	{
		throwshit = true;
	}
	if(avatarKeyPresses[(int)_id].isDec)
	{
		throwshit2 = true;
	}
	 
	ZCom_BitStream *data = new ZCom_BitStream();

  //sprintf(buf, "%i%i%i%i%i%i", isLeft, isRight, isDec, isAcc, isBurnOut, isHBrake);
  //data->addString(buf);

  // Add six bits for avatar controls
	data->addFloat(player1.mCarChassis->getWorldPosition().x,32);
	data->addFloat(player1.mCarChassis->getWorldPosition().y,32);
	data->addFloat(player1.mCarChassis->getWorldPosition().z,32);
	data->addFloat(player1.mCarChassis->getWorldOrientation().w,32);
	data->addFloat(player1.mCarChassis->getWorldOrientation().x,32);
	data->addFloat(player1.mCarChassis->getWorldOrientation().y,32);
	data->addFloat(player1.mCarChassis->getWorldOrientation().z,32);
	
	
	
	
	
    

	/*data->addFloat(0.f,32);
	data->addFloat(30.f,32);
	data->addFloat(30.f,32);
	data->addFloat(0.f,32);
	data->addFloat(0.f,32);
	data->addFloat(50.f,32);
    data->addFloat(30.f,32);*/
        
  ZCom_sendData(_id, data, eZCom_ReliableOrdered);

	/*
	  if(_data.getBool())
	  {
		throwshit = true;
	  }
	  if(_data.getBool())
	  {
		throwshit2 = true;
	  }
	  _data.getBool();
	  _data.getBool();
	  _data.getBool();
	  _data.getBool();
	*/


	//delete answer;
  }


  // unused callbacks are empty
  bool ZCom_cbZoidRequest( ZCom_ConnID _id, zU8 _requested_level, ZCom_BitStream &_reason) {return false;}
  void ZCom_cbZoidResult(ZCom_ConnID _id, eZCom_ZoidResult _result, zU8 _new_level, ZCom_BitStream &_reason) {}
  bool ZCom_cbDiscoverRequest(const ZCom_Address &_addr, ZCom_BitStream &_request, ZCom_BitStream &_reply) {return false;}
  void ZCom_cbConnectResult( ZCom_ConnID _id, eZCom_ConnectResult _result, ZCom_BitStream &_reply ) {}
  void ZCom_cbNodeRequest_Dynamic( ZCom_ConnID _id, ZCom_ClassID _requested_class, ZCom_BitStream *_announcedata, eZCom_NodeRole _role, ZCom_NodeID _net_id ) {}
  void ZCom_cbNodeRequest_Tag( ZCom_ConnID _id, ZCom_ClassID _requested_class, ZCom_BitStream *_announcedata, eZCom_NodeRole _role, zU32 _tag ) {}
  void ZCom_cbDiscovered( const ZCom_Address & _addr, ZCom_BitStream &_reply )  {}
};

//
// log output function - writes log from zoidcom to console
//

void logfunc(string str)
{
	//Vehicles_Demo::throwDynamicObject(OIS::KC_B);
}


///btRaycastVehicle is the interface for the constraint that implements the raycast vehicle
///notice that for higher-quality slow-moving vehicles, another approach might be better
///implementing explicit hinged-wheel constraints with cylinder collision, rather then raycasts


static const Vector3    CameraStart            = Vector3(0, 25, 0);
// -------------------------------------------------------------------------

Vector3   CarPosition             = Vector3(30, 3,0);

static btVector3* cameraPos = new btVector3( 100.0f, 100.0f, 100.0f); // for camera linear interpolation
static btVector3* cameraTarget = new btVector3( 10.0f, 10.0f, 10.0f);

static Real timeToUpdate = 0;

static const int gOSCPort = 7400;



Server *srv;

// -------------------------------------------------------------------------
void Vehicles_Demo::init(Ogre::Root *root, Ogre::RenderWindow *win, OgreBulletApplication *application)
{
	
	ZoidCom *zcom = new ZoidCom();
  if (!zcom)
    exit(255);

  if (!zcom->Init())
  {
    //printf("Problem initializing Zoidcom.\n");
    exit(255);
  }

  // server operates on internal port 1 and UDP port 8899
  srv = new Server( 1, 8899 );
  srv->ZCom_setUpstreamLimit(0,0);


 

	

	// [0][x] is for base
	bTypes[0][0] = "TextureMaterial/TEXFACE/CityBlockBase.tga";
	bTypes[0][1] = "CityBlockBase.mesh";
	// [1][x] is for Team 1 states
	bTypes[1][0] = "TextureMaterial/TEXFACE/CityBlockWholeT1.tga";
	bTypes[1][1] = "CityBlockWholeT1.mesh";
	bTypes[1][2] = "TextureMaterial/TEXFACE/CityBlockSlightlyDamageT1.tga";
	bTypes[1][3] = "CityBlockSlightlyT1.mesh";
	bTypes[1][4] = "TextureMaterial/TEXFACE/CityBlockModeratelyDamageT1.tga";
	bTypes[1][5] = "CityBlockModeratelyT1.mesh";
	bTypes[1][6] = "TextureMaterial/TEXFACE/CityBlockHeavilyDamageT1.tga";
	bTypes[1][7] = "CityBlockHeavilyT1.mesh";
	bTypes[1][8] = "TextureMaterial/TEXFACE/CityBlockDestroyed.tga";
	bTypes[1][9] = "CityBlockDestroyed.mesh";
	// [2][x] is for Team 2 states
	bTypes[2][0] = "TextureMaterial/TEXFACE/CityBlockWholeT2.tga";
	bTypes[2][1] = "CityBlockWholeT2.mesh";
	bTypes[2][2] = "TextureMaterial/TEXFACE/CityBlockSlightlyDamageT2.tga";
	bTypes[2][3] = "CityBlockSlightly.mesh";
	bTypes[2][4] = "TextureMaterial/TEXFACE/CityBlockModeratelyDamageT2.tga";
	bTypes[2][5] = "CityBlockModeratelyT2.mesh";
	bTypes[2][6] = "TextureMaterial/TEXFACE/CityBlockHeavilyDamageT2.tga";
	bTypes[2][7] = "CityBlockHeavilyT2.mesh";
	bTypes[2][8] = "TextureMaterial/TEXFACE/CityBlockDestroyed.tga";
	bTypes[2][9] = "CityBlockDestroyed.mesh";
	// [3][x] is for special building states
	// [4][x] is for stores

	
   /* mHelpKeys.clear();
    mHelpKeys.push_back ("Welcome to Boom Box");
    mHelpKeys.push_back ("Choose What Team You want to play as");

	
    
    mHelpKeys.push_back ("Use Arrow Key to move Car.");
	if(mTeam1 == true && mTeam2 == false)
			mHelpKeys.push_back ("You Are On Team1");
	else if(mTeam1 == false && mTeam2 == true)
			mHelpKeys.push_back ("You Are On Team2");
	else 
		mHelpKeys.push_back ("Your not on a team");*/
	//wait(10);
	



	
    // ------------------------
    // Start OgreScene
    mSceneMgr = root->createSceneManager(ST_GENERIC);
//	mSceneMgr2 = root->createSceneManager(ST_GENERIC, "secondary");
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
    mCamera->setPosition(CameraStart);
    mCamera->lookAt(CarPosition);
//	gameGUI = new GameGUI(win, mSceneMgr);

//	mCamera2 = mSceneMgr2->createCamera("Menu Cam");
//mCamera2->setNearClipDistance(0.1);
//    mCamera2->setFarClipDistance(500);
//    Viewport *vp1 = win->addViewport(mCamera2);
//    vp1->setBackgroundColour(ColourValue(0,0,0));
//    // Alter the camera aspect ratio to match the viewport
//    mCamera2->setAspectRatio(
//        Real(vp1->getActualWidth()) / Real(vp1->getActualHeight()));
//    mCamera2->setPosition(CameraStart);
//    mCamera2->lookAt(CarPosition);


	

    OgreBulletListener::init(root, win, application);
//	gameMenu = new GameMenu1(mWindow, mSceneMgr2);

	gameGUI = new GameGUI(mWindow, mSceneMgr);

	 


 //    ------------------------
//     add lights
    setBasicLight();

    // ------------------------
    // Add the Gui
//   setPhysicGUI();
	
    // ------------------------
    // Start Bullet
    initWorld();

    // ------------------------
    // Add the ground
    
    // 0.1, 0.8
    addStaticPlane(0.3, 0.8);

	
	//Add Bases


	int bTeam = 1;
	int bState = 0;

	srand(time(NULL));

	RigidBody* body;
	for(int i = 0; i <50; i++)
	{
		for(int j = 0; j<50; j++)
		{

			// Force values for now
			bTeam = 1;
			bState = 2 * (rand() % 5);

			body = addStaticTrimesh(bTypes[0][0],
					bTypes[0][1],
					Vector3(i*60,0.01,j*60), 
					Quaternion(Radian(Degree(-90)),Vector3::UNIT_X),
					0.1f, 
					0.8f,true);
			cityGrid[(50*i)+(50*j)] = addStaticTrimesh(bTypes[bTeam][bState],
					bTypes[bTeam][bState+1],
					Vector3(i*60,0.02,j*60), 
					Quaternion(Radian(Degree(-90)),Vector3::UNIT_X),
					0.1f, 
					0.8f,true);	
		}
	}

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

player1.makeCar(mSceneMgr, mWorld, Vector3(30, 3,0), 1 );
player2.makeCar(mSceneMgr, mWorld, Vector3(10, 3,0), 2 );
 

mContinue = true;
	// Start music
	/*{
		mMaxMSPHandle = new MaxMSPHandle(gOSCPort);
	}*/


}
// -------------------------------------------------------------------------
void Vehicles_Demo::keyPressed(BULLET_KEY_CODE key)
{
	
	//carNotMoved = true;
    OgreBulletListener::throwDynamicObject (key);
   OgreBulletListener::dropDynamicObject (key);

    switch(key)
    {
    case KC_LEFT: 
	//	player1.keyPressed(1);
        break;
    case KC_RIGHT: 
	//	player1.keyPressed(2);
      //  mSteeringRight = true;
        break;
    case KC_DOWN:
	//	player1.keyPressed(3);
		//mDecelerate = true;
        break;
	case KC_UP:
		//player1.keyPressed(4);
		//mAccelerate = true;
        break;
    case KC_LCONTROL:
		//player1.keyPressed(5);
        //mBurnout = true;
        break;
	case KC_SPACE:
		//player1.keyPressed(6);
		//mVehicle->getBulletVehicle()->m_wheelInfo[2].m_frictionSlip=0.01f;
		//mVehicle->getBulletVehicle()->m_wheelInfo[3].m_frictionSlip=0.01f;
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
		//player1.keyReleased(1);
   //     mSteeringLeft = false;
        break;
    case KC_RIGHT: 
		//player1.keyReleased(2);
     //   mSteeringRight = false;
        break;
    case KC_DOWN:
		//player1.keyReleased(3);
	//	mDecelerate = false;
        break;
	case KC_UP:
		//player1.keyReleased(4);
	//	mAccelerate = false;
        break;
	case KC_LCONTROL:
		//player1.keyReleased(5);
      //  mBurnout = false;
        break;
	case KC_SPACE:
		//player1.keyReleased(6);
		//mVehicle->getBulletVehicle()->m_wheelInfo[2].m_frictionSlip=gWheelFriction;
		//mVehicle->getBulletVehicle()->m_wheelInfo[3].m_frictionSlip=gWheelFriction;
    default:
        break;

    }
    return OgreBulletListener::keyReleased (key);
}
// -------------------------------------------------------------------------
bool Vehicles_Demo::frameStarted(Real elapsedTime)
{

   // processes incoming packets
	    // outstanding data will be packed up and sent from here
    srv->ZCom_processOutput();
    // all callbacks are generated from within the processInput calls
    srv->ZCom_processInput( eZCom_NoBlock );

	if(avatarKeyPresses[1].isAcc == true)
     player1.keyPressed(4);
	else
	 player1.keyReleased(4);
	if(avatarKeyPresses[1].isDec)
      player1.keyPressed(3);
	else
	 player1.keyReleased(3);
	if(avatarKeyPresses[1].isLeft)
       player1.keyPressed(1);
	else
	 player1.keyReleased(1);
	if(avatarKeyPresses[1].isRight)
      player1.keyPressed(2);
	else
	 player1.keyReleased(2);
	if(avatarKeyPresses[1].isHBrake)
player1.keyPressed(6);
	else
	 player1.keyReleased(6);
	if(avatarKeyPresses[1].isBurnOut)
		player1.keyPressed(5);
	else
	 player1.keyReleased(5);



 CEGUI::System *sys = CEGUI::System::getSingletonPtr();
//
// CEGUI::WindowManager *wmgr = CEGUI::WindowManager::getSingletonPtr();
//        CEGUI::Window *quit = wmgr->getWindow((CEGUI::utf8*)"CEGUIDemo/QuitButton");
//
//		quit->subscribeEvent(CEGUI::PushButton::EventClicked,
//			CEGUI::Event::Subscriber(&Vehicles_Demo::quit, this));
//
//
////CEGUI::Editbox * editBox = static_cast<CEGUI::Editbox*>(CEGUI::WindowManager::getSingletonPtr()->getWindow("Editbox1"));
//
////editBox->subscribeEvent(CEGUI::Editbox::EventTextAccepted, CEGUI::Event::Subscriber(&Vehicles_Demo::onTextAccepted, this));
//
//CEGUI::Listbox * listBox = static_cast<CEGUI::Listbox*>(CEGUI::WindowManager::getSingletonPtr()->getWindow("Listbox1"));
//
//listBox->subscribeEvent(CEGUI::Listbox::EventSelectionChanged, CEGUI::Event::Subscriber(&Vehicles_Demo::onSelectionChanged, this));
//
//CEGUI::Checkbox * checkBox = static_cast<CEGUI::Checkbox*>(CEGUI::WindowManager::getSingletonPtr()->getWindow("Checkbox1"));
//
//checkBox->subscribeEvent(CEGUI::Checkbox::EventCheckStateChanged, CEGUI::Event::Subscriber(&Vehicles_Demo::onCheckStateChanged, this));
//checkBox->subscribeEvent(CEGUI::Checkbox::EventMouseEnters, CEGUI::Event::Subscriber(&Vehicles_Demo::onMouseEnters, this));
//checkBox->subscribeEvent(CEGUI::Checkbox::EventMouseLeaves, CEGUI::Event::Subscriber(&Vehicles_Demo::onMouseLeaves, this));
//
//
//CEGUI::Window* chatText = wmgr->getWindow("/ChatBox/Text");
//
//
//chatText->subscribeEvent(CEGUI::Editbox::EventTextAccepted,	CEGUI::Event::Subscriber(&Vehicles_Demo::Event_ChatTextAdded,	this)); 




		//multiLineEditbox->subscribeEvent(MultiLineEditbox::EventTextChanged, Event::Subscriber(&GameGUI::onTextChanged, this));


	//}

	player1.frameStarted(elapsedTime, mCamera);
    return OgreBulletListener::frameStarted(elapsedTime) && mContinue;
	

}


bool Vehicles_Demo::Event_ChatTextAdded(const CEGUI::EventArgs& args)
{
		using namespace CEGUI;

		WindowManager& winMgr = WindowManager::getSingleton();
		Editbox* chatText = static_cast<Editbox*> (winMgr.getWindow("/ChatBox/Text"));
		addChatText(chatText->getText());

		// Clear the text in the Editbox
		chatText->setText("");
		return true;
}

void Vehicles_Demo::addChatText(const CEGUI::String& pText)
	{
		using namespace CEGUI;

		WindowManager& winMgr = WindowManager::getSingleton();
		Listbox* chatHistory = static_cast<Listbox*> (winMgr.getWindow("/ChatBox/List"));

		// If there's text then add it
		if(pText.size())
		{
			// Add the Editbox text to the history Listbox
			ListboxTextItem* chatItem;
			if(chatHistory->getItemCount() == 20)
			{
				/* We have reached the capacity of the Listbox so re-use the first Listbox item.
				   This code is a little crafty.  By default the ListboxTextItem is created with
				   the auto-delete flag set to true, which results in its automatic deletion when
				   removed from the Listbox.  So we change that flag to false, extract the item
				   from the Listbox, change its text, put the auto-delete flag back to true, and
				   finally put the item back into the Listbox. */
				chatItem = static_cast<ListboxTextItem*>(chatHistory->getListboxItemFromIndex(0));
				chatItem->setAutoDeleted(false);
				chatHistory->removeItem(chatItem);
				chatItem->setAutoDeleted(true);
				chatItem->setText(pText);
			}
			else
			{
				// Create a new listbox item
				chatItem = new ListboxTextItem(pText);
			}
			chatHistory->addItem(chatItem);
			chatHistory->ensureItemIsVisible(chatHistory->getItemCount());
		}
	}





bool Vehicles_Demo::quit(const CEGUI::EventArgs &e)
    {
        mContinue = false;
        return false;
    }

bool Vehicles_Demo::onTextAccepted(const CEGUI::EventArgs &e)
{
	// Our text has been accepted by either deactivating it or pressing tab or enter.
	//CEGUI::Editbox * editBox = static_cast<CEGUI::Editbox*>(CEGUI::WindowManager::getSingletonPtr()->getWindow("Editbox1"));
	//// So we got the text here, do something with it. Lets just..put the text back in reverse order.
	//CEGUI::String currentText = editBox->getText();

	//std::string finalString;

	//CEGUI::String::reverse_iterator ppkNode = currentText.rbegin();
	//CEGUI::String::reverse_iterator ppkEnd = currentText.rend();

	//for (; ppkNode != ppkEnd; ++ppkNode)
	//{
	//	finalString.push_back((*ppkNode));
	//}
	//editBox->setText(finalString);
	return true;
}

bool Vehicles_Demo::onSelectionChanged(const CEGUI::EventArgs &e)
{
        // The selection has changed.
	CEGUI::Listbox * listBox = static_cast<CEGUI::Listbox*>(CEGUI::WindowManager::getSingletonPtr()->getWindow("Listbox1"));
	// Get the item we selected
	CEGUI::ListboxItem * selectedItem = listBox->getFirstSelectedItem();
	selectedItem->setText("Time for Speed Bonus");
//	gMaxEngineForce *= 2;
		
	return true;
}

bool Vehicles_Demo::onCheckStateChanged(const CEGUI::EventArgs &e)
{
	// Our item has been checked or unchecked, update our item accordingly.
	updateCheckbox();
	//CarPosition             = Vector3(60, 3,0);
	//if(carNotMoved == false)
    //  mCarChassis->setShape (node, compound, 0.6, 0.6, 800, CarPosition , Quaternion::IDENTITY);
	return true;
}

bool Vehicles_Demo::onMouseEnters(const CEGUI::EventArgs &e)
{
	// The mouse has entered, update the checkbox accordingly.
	updateCheckbox();		
	return true;
}

bool Vehicles_Demo::onMouseLeaves(const CEGUI::EventArgs &e)
{
	CEGUI::Checkbox * checkBox = static_cast<CEGUI::Checkbox*>(CEGUI::WindowManager::getSingletonPtr()->getWindow("Checkbox1"));
	// Reset
	checkBox->setText("DO you Wanna Join Team 1");
	return true;
}
	
void  Vehicles_Demo::updateCheckbox()
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







// -------------------------------------------------------------------------


//#ifdef __cplusplus
//extern "C" {
//#endif
//
//#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
//INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
//#else
//int main(int argc, char *argv[])
//#endif
//{
//    // Create application object
//    Vehicles_Demo app;
//
//    try {
//        app.go();
//    } catch( Ogre::Exception& e ) {
//#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
//        MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL );
//#else
//        std::cerr << "An exception has occured: " <<
//            e.getFullDescription().c_str() << std::endl;
//#endif
//    }
//
//    return 0;
//}
//
//#ifdef __cplusplus
//}
//#endif

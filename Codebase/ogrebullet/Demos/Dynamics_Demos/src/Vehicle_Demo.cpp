// CLIENT CLIENT CLIENT CLIENT CLIENT CLIENT CLIENT 

/***************************************************************************

This source file is part of OGREBULLET
(Object-oriented Graphics Rendering Engine Bullet Wrapper)
For the latest info, see http://www.ogre3d.org/phpBB2addons/viewforum.php?f=10

Copyright (c) 2007 tuan.kuranes@gmail.com (Use it Freely, even Statically, but have to contribute any changes)



This source file is not LGPL, it's public source code that you can reuse.
-----------------------------------------------------------------------------*/
#include "Vehicle_Demo.h" 
//#include "InfoClient.h"
//#include "Player.h"

#include "Shapes/OgreBulletCollisionsBoxShape.h"
#include "Shapes/OgreBulletCollisionsCompoundShape.h"

#include "OgreBulletDynamicsWorld.h"
#include "OgreBulletDynamicsRigidBody.h"
#include "Debug/OgreBulletCollisionsDebugDrawer.h"

#include "Constraints/OgreBulletDynamicsRaycastVehicle.h"
#include <string>
#include <time.h>


#if !(OGRE_VERSION <  ((1 << 16) | (3 << 8) | 0))
using namespace OIS;
#endif 

using namespace Ogre;
using namespace OgreBulletCollisions;
using namespace OgreBulletDynamics;
//using namespace ZoidCom;
Team1 team1;

char stringtosend[4096];

Player player1;
Player player2;

CEGUI::String playerusername;
CEGUI::String playeripaddress;

bool isAcc = false;
bool isDec = false;
bool isLeft = false;
bool isRight = false;
bool isBurnOut = false;
bool isHBrake = false;

ZCom_ConnID servid;
SceneNode *chassisnode;


struct playerLocation {
	playerLocation(float t_x = 0.f, float t_y = 1.f, float t_z = 0.f,
				   float t_qw = 0.f, float t_qx = 0.f, float t_qy = 0.f, float t_qz = 0.f) :
	   px(t_x),
	   py(t_y),
	   pz(t_z),
	   qw(t_qw),
	   qx(t_qx),
	   qy(t_qy),
	   qz(t_qz) {}

	float px;
	float py;
	float pz;
	float qw;
	float qx;
	float qy;
	float qz;
};

playerLocation * avatarLocations;

#include <stdlib.h>
#include <stdio.h>

#include <zoidcom.h>

//
// the client class
//

class Client : public ZCom_Control
{
protected:
public:
  // constructor - gets called when the client is created with new Client(...)
  Client()
  {
    // this will allocate the sockets and create local bindings
    if ( !ZCom_initSockets( true, 0, 0, 0 ) )
    {
      printf("Failed to initialize sockets!\n");
      // exit program immediately
      exit(255);
    }

    // string shown in log output
    ZCom_setDebugName("ZCOM_CLI");

	avatarLocations = new playerLocation[20];
  }

protected:
  // called when the connecting ends
  void ZCom_cbConnectResult( ZCom_ConnID _id, eZCom_ConnectResult _result, ZCom_BitStream &_reply )
  {
    // connection successful?
    if (_result == eZCom_ConnAccepted)
    {
      printf("Connected! Let's send something...\n");

      // create a bitstream for sending stuff to the server
      ZCom_BitStream *data = new ZCom_BitStream();
      data->addBool(false);
	  data->addBool(false);
	  data->addBool(false);
	  data->addBool(false);
	  data->addBool(false);
	  data->addBool(false);

      // send the data to the server
      if (ZCom_sendData(_id, data, eZCom_ReliableOrdered) == true)
        printf("Data sent!\n");
      else
        printf("Error sending data!\n");

	  servid = _id;
    }
    else
    {
      printf("Connection failed!\n");
      ZoidCom::Sleep(2000);
      // when connection failed, exit program
      exit(0);
    }
  }

  // called when a connection closed
  void ZCom_cbConnectionClosed( ZCom_ConnID _id, eZCom_CloseReason _reason, ZCom_BitStream &_reasondata )
  {
    printf("Connection closed!\n");
    ZoidCom::Sleep(2000);
    exit(0);
  }

  // called when data has been received
  void ZCom_cbDataReceived( ZCom_ConnID _id, ZCom_BitStream &_data )
  {
    // we assume that clients will only send strings
    // so no special handling, just output of incoming data
   // printf("Received from server: %s\n", _data.getStringStatic());

 char buf[10];
  ZCom_BitStream *data = new ZCom_BitStream();


  // Add six bits for avatar controls
 data->addBool(isHBrake);
 data->addBool(isBurnOut);
 data->addBool(isRight);
 data->addBool(isLeft);  
 data->addBool(isDec); 
 data->addBool(isAcc);
  

  ZCom_sendData(servid, data, eZCom_ReliableOrdered);

  avatarLocations[0].px = _data.getFloat(32);	
  avatarLocations[0].py = _data.getFloat(32);
  avatarLocations[0].pz = _data.getFloat(32);
  avatarLocations[0].qw = _data.getFloat(32);
  avatarLocations[0].qx = _data.getFloat(32);
  avatarLocations[0].qy = _data.getFloat(32);
  avatarLocations[0].qz = _data.getFloat(32);

  }


  // unused callbacks are empty
  void ZCom_cbConnectionSpawned( ZCom_ConnID _id ) {}
  bool ZCom_cbConnectionRequest( ZCom_ConnID  _id, ZCom_BitStream &_request, ZCom_BitStream &_reply ){return false;}
  bool ZCom_cbZoidRequest( ZCom_ConnID _id, zU8 _requested_level, ZCom_BitStream &_reason) {return false;}
  void ZCom_cbZoidResult(ZCom_ConnID _id, eZCom_ZoidResult _result, zU8 _new_level, ZCom_BitStream &_reason) {}
  bool ZCom_cbDiscoverRequest(const ZCom_Address &_addr, ZCom_BitStream &_request, ZCom_BitStream &_reply) {return false;}
  void ZCom_cbNodeRequest_Dynamic( ZCom_ConnID _id, ZCom_ClassID _requested_class, ZCom_BitStream *_announcedata, eZCom_NodeRole _role, ZCom_NodeID _net_id ) {}
  void ZCom_cbNodeRequest_Tag( ZCom_ConnID _id, ZCom_ClassID _requested_class, ZCom_BitStream *_announcedata, eZCom_NodeRole _role, zU32 _tag ) {}
  void ZCom_cbDiscovered( const ZCom_Address & _addr, ZCom_BitStream &_reply )  {}
};


static const Vector3    CameraStart            = Vector3(0, 100, 0);
// -------------------------------------------------------------------------

Vector3   CarPosition             = Vector3(30, 3,0);

static btVector3* cameraPos = new btVector3( 100.0f, 100.0f, 100.0f); // for camera linear interpolation
static btVector3* cameraTarget = new btVector3( 10.0f, 10.0f, 10.0f);


static Real timeToUpdate = 0;

static const int gOSCPort = 7400;

 Client *cli;

// -------------------------------------------------------------------------
void Vehicles_Demo::init(Ogre::Root *root, Ogre::RenderWindow *win, OgreBulletApplication *application)
{
	gameStart = false;
	gameInit = false;
	ConnectionOccured = false;
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
	bTypes[2][3] = "CityBlockSlightlyT2.mesh";
	bTypes[2][4] = "TextureMaterial/TEXFACE/CityBlockModeratelyDamageT2.tga";
	bTypes[2][5] = "CityBlockModeratelyT2.mesh";
	bTypes[2][6] = "TextureMaterial/TEXFACE/CityBlockHeavilyDamageT2.tga";
	bTypes[2][7] = "CityBlockHeavilyT2.mesh";
	bTypes[2][8] = "TextureMaterial/TEXFACE/CityBlockDestroyed.tga";
	bTypes[2][9] = "CityBlockDestroyed.mesh";
	// [3][x] is for special building states
	// [4][x] is for stores
	bTypes[4][0] = "TextureMaterial/TEXFACE/RockStore.tga";
	bTypes[4][1] = "RockStore.mesh";
	bTypes[4][2] = "TextureMaterial/TEXFACE/JazzStore.tga";
	bTypes[4][3] = "JazzStore.mesh";
	bTypes[4][4] = "TextureMaterial/TEXFACE/HipHopStore.tga";
	bTypes[4][5] = "HipHopStore.mesh";
	
	
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
//	gameGUI = new GameGUI(win, mSceneMgr);


    OgreBulletListener::init(root, win, application);
//	gameMenu = new GameMenu1(mWindow, mSceneMgr2);

	gameGUI = new GameGUI(mWindow, mSceneMgr);

	  //add lights
    setBasicLight();

    // ------------------------
    // Add the Gui
//   setPhysicGUI();
	
    // ------------------------
    // Start Bullet
    initWorld(); 



 
	// Start music
	/*{
		mMaxMSPHandle = new MaxMSPHandle(gOSCPort);
	}*/
}
// -------------------------------------------------------------------------
void Vehicles_Demo::keyPressed(BULLET_KEY_CODE key)
{

    switch(key)
    {
    case KC_LEFT: 
		isLeft = true;
        break;
    case KC_RIGHT: 
		isRight = true;
        break;
    case KC_DOWN:
		isDec = true;
        break;
	case KC_UP:
		isAcc = true;
        break;
    case KC_LCONTROL:
		isBurnOut = true;
        break;
	case KC_SPACE:
		isHBrake = true;
	case KC_RETURN:
		{ 
			gameStart = true;
		 
		 CEGUI::WindowManager *wmgr = CEGUI::WindowManager::getSingletonPtr();
		 CEGUI::Window *w = wmgr->getWindow((CEGUI::utf8*)"Root");
		 w->hide();
		}
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
		isLeft = false;
        break;
    case KC_RIGHT: 
		isRight = false;
        break;
    case KC_DOWN:
		isDec = false;
        break;
	case KC_UP:
		isAcc = false;
        break;
	case KC_LCONTROL:
		isBurnOut = false;
        break;
	case KC_SPACE:
        isHBrake = false;
	case KC_RETURN:
		gameStart = false;
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

	 

mContinue = true;
 CEGUI::System *sys = CEGUI::System::getSingletonPtr();

  CEGUI::WindowManager *wmgr = CEGUI::WindowManager::getSingletonPtr();
        CEGUI::Window *playgame = wmgr->getWindow((CEGUI::utf8*)"Root/MenuBackground/Button2");

		playgame->subscribeEvent(CEGUI::PushButton::EventClicked,
			CEGUI::Event::Subscriber(&Vehicles_Demo::play, this));



if(gameStart == true)
{
	// initialize zoidcom with console logging function
  ZoidCom *zcom = new ZoidCom();
  if (!zcom)
    return -1;

  if (!zcom->Init())
  {
    printf("Problem initializing Zoidcom.\n");
    return -1;
  }

  // create client
 cli = new Client( );

  // create target address 
  ZCom_Address dst_udp;
  char dst_address[512] = "127.0.0.1:8899";
  dst_udp.setAddress( eZCom_AddressUDP, 0, dst_address );

  // connect to server
  printf("Connecting to %s...\n", dst_address);
  if (!cli->ZCom_Connect( dst_udp, NULL ))
  {
    printf("Client: unable to start connecting!\n");  
    exit(255);
  }
 

 //printf("Press CTRL+C to abort.\n");
 gameStart = false;
 ConnectionOccured = true;
}


if(ConnectionOccured == true)
{

//	initWorld(); 
 //    ------------------------
//

    // ------------------------
    // Add the ground
    
    // 0.1, 0.8
    addStaticPlane(0.3, 0.8);

	
	//Add Bases
	int bTeam = 1;
	int bState = 0;

	srand(time(NULL));

	RigidBody* body;
	for(int i = 0; i <10; i++)
	{
		for(int j = 0; j<10; j++)
		{
			if(		((i==0) && (j==0)) ||
					((i==1) && (j==0)) ||
					((i==2) && (j==0))
					) {}
			else {
					// Force values for now
					bTeam = (rand() % 2) + 1;
					bState = 2 * (rand() % 4);

					body = addStaticTrimesh(bTypes[0][0],
							bTypes[0][1],
							Vector3(i*60,0.01,j*60), 
							Quaternion(Radian(Degree(-90)),Vector3::UNIT_X),
							0.1f, 
							0.8f,true);
					cityGrid[(10*i)+(10*j)] = addStaticTrimesh(bTypes[bTeam][bState],
							bTypes[bTeam][bState+1],
							Vector3(i*60,0.02,j*60), 
							Quaternion(Radian(Degree(-90)),Vector3::UNIT_X),
							0.1f, 
							0.8f,true);	
			}
				
		}
	}

		// Rock
		body = addStaticTrimesh(bTypes[0][0],
						bTypes[0][1],
						Vector3((0)*60,0.01,(0)*60), 
						Quaternion(Radian(Degree(-90)),Vector3::UNIT_X),
						0.1f, 
						0.8f,true);
		cityGrid[(10*(0))+(10*(0))] = addStaticTrimesh(bTypes[4][0],
						bTypes[4][1],
						Vector3((0)*60,0.02,(0)*60), 
						Quaternion(Radian(Degree(-90)),Vector3::UNIT_X),
						0.1f, 
						0.8f,true);	

		// Jazz
		body = addStaticTrimesh(bTypes[0][0],
						bTypes[0][1],
						Vector3((1)*60,0.01,(0)*60), 
						Quaternion(Radian(Degree(-90)),Vector3::UNIT_X),
						0.1f, 
						0.8f,true);
		cityGrid[(10*(1))+(10*(0))] = addStaticTrimesh(bTypes[4][2],
						bTypes[4][3],
						Vector3((1)*60,0.02,(0)*60), 
						Quaternion(Radian(Degree(-90)),Vector3::UNIT_X),
						0.1f, 
						0.8f,true);	

		// HipHop
		body = addStaticTrimesh(bTypes[0][0],
						bTypes[0][1],
						Vector3((2)*60,0.01,(0)*60), 
						Quaternion(Radian(Degree(-90)),Vector3::UNIT_X),
						0.1f, 
						0.8f,true);
		cityGrid[(10*(2))+(10*(0))] = addStaticTrimesh(bTypes[4][4],
						bTypes[4][5],
						Vector3((2)*60,0.02,(0)*60), 
						Quaternion(Radian(Degree(-90)),Vector3::UNIT_X),
						0.1f, 
						0.8f,true);	


//player1.makeCar(mSceneMgr, mWorld, Vector3(30, 3,0), 1 );
//player2.makeCar(mSceneMgr, mWorld, Vector3(10, 3,0), 2 );
 
const Vector3 chassisShift(0, 1.0, 0);

	Quaternion chassisRotation = Quaternion(Degree(90),Vector3::UNIT_X);
    Quaternion quat2 = Quaternion(Degree(90),Vector3::UNIT_Y);
	Quaternion quat3 = Quaternion(Degree(180),Vector3::UNIT_Z);
	chassisRotation = chassisRotation * quat2 * quat3;

	float connectionHeight = 0.7f;

    mChassis = mSceneMgr->createEntity(
            "chassis" + StringConverter::toString(21),
            "avatar2.mesh");

    SceneNode *node = mSceneMgr->getRootSceneNode ()->createChildSceneNode ();
    chassisnode = node->createChildSceneNode ();

	// Manipulate model into correct game world location and dimensions 
	chassisnode->scale(Vector3 (.5f,.5f,.5f));
	//chassisnode->rotate(chassisRotation);
    chassisnode->setPosition (chassisShift);
    chassisnode->attachObject (mChassis);
	chassisnode->translate(Vector3(.925f,0.0f,0.0f));

	
 



gameInit = true;
//gameStart = false;
ConnectionOccured = false;
}

if(gameInit == true)
{

 CEGUI::WindowManager *wmgr = CEGUI::WindowManager::getSingletonPtr();
        CEGUI::Window *quit = wmgr->getWindow((CEGUI::utf8*)"CEGUIDemo/QuitButton");
		quit->show();
		quit->subscribeEvent(CEGUI::PushButton::EventClicked,
			CEGUI::Event::Subscriber(&Vehicles_Demo::quit, this));


CEGUI::Listbox * listBox = static_cast<CEGUI::Listbox*>(CEGUI::WindowManager::getSingletonPtr()->getWindow("Listbox1"));
listBox->show();
listBox->subscribeEvent(CEGUI::Listbox::EventSelectionChanged, CEGUI::Event::Subscriber(&Vehicles_Demo::onSelectionChanged, this));

CEGUI::Checkbox * checkBox = static_cast<CEGUI::Checkbox*>(CEGUI::WindowManager::getSingletonPtr()->getWindow("Checkbox1"));
checkBox->show();
checkBox->subscribeEvent(CEGUI::Checkbox::EventCheckStateChanged, CEGUI::Event::Subscriber(&Vehicles_Demo::onCheckStateChanged, this));
checkBox->subscribeEvent(CEGUI::Checkbox::EventMouseEnters, CEGUI::Event::Subscriber(&Vehicles_Demo::onMouseEnters, this));
checkBox->subscribeEvent(CEGUI::Checkbox::EventMouseLeaves, CEGUI::Event::Subscriber(&Vehicles_Demo::onMouseLeaves, this));


  cli->ZCom_processInput( eZCom_NoBlock );

  

    // outstanding data will be packed up and sent from here
    cli->ZCom_processOutput();

    // pause the program for a few milliseconds
    ZoidCom::Sleep(10);


	Quaternion chassisRotation = Quaternion(Degree(90),Vector3::UNIT_X);
    Quaternion quat2 = Quaternion(Degree(90),Vector3::UNIT_Y);
	Quaternion quat3 = Quaternion(Degree(180),Vector3::UNIT_Z);
	chassisRotation = chassisRotation * quat2 * quat3;

	
	chassisnode->setPosition(Vector3(avatarLocations[0].px,avatarLocations[0].py,avatarLocations[0].pz));
	chassisnode->setOrientation(Quaternion(avatarLocations[0].qw, avatarLocations[0].qx,avatarLocations[0].qy,avatarLocations[0].qz));
    chassisnode->rotate(chassisRotation);
	chassisnode->translate(Vector3(.925f,0.0f,0.0f));chassisnode->translate(Vector3(.925f,0.0f,0.0f));
	mCamera->setPosition(avatarLocations[0].px-15.f,50.f,avatarLocations[0].pz);


//	player1.frameStarted(elapsedTime, mCamera);
}


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



bool Vehicles_Demo::play(const CEGUI::EventArgs &e)
    {
      gameStart = true;
	  CEGUI::WindowManager *wmgr = CEGUI::WindowManager::getSingletonPtr();
	  CEGUI::Editbox       *username = static_cast<CEGUI::Editbox*>(CEGUI::WindowManager::getSingletonPtr()->getWindow("Root/MenuBackground/login"));
	  CEGUI::Editbox       *ipaddress = static_cast<CEGUI::Editbox*>(CEGUI::WindowManager::getSingletonPtr()->getWindow("Root/MenuBackground/pword"));
	  playerusername = username->getText();
	  playeripaddress = ipaddress->getText();

	  CEGUI::Window *w = wmgr->getWindow((CEGUI::utf8*)"Root");
	  w->hide();

        return false;
    }

bool Vehicles_Demo::quit(const CEGUI::EventArgs &e)
    {
        mContinue = false;
        return false;
    }

bool Vehicles_Demo::onTextAccepted(const CEGUI::EventArgs &e)
{

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

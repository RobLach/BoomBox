/***************************************************************************

This source file is part of OGREBULLET
(Object-oriented Graphics Rendering Engine Bullet Wrapper)
For the latest info, see http://www.ogre3d.org/phpBB2addons/viewforum.php?f=10

Copyright (c) 2007 tuan.kuranes@gmail.com (Use it Freely, even Statically, but have to contribute any changes)



This source file is not LGPL, it's public source code that you can reuse.
-----------------------------------------------------------------------------*/
#ifndef _OGREBULLET_Vehicles_Demo__H
#define _OGREBULLET_Vehicles_Demo__H

#include "ExampleApplication.h"
#include "MusicSystem.h"
#include "OgreBulletDynamics.h"
#include "OgreBulletListener.h"
#include "OgreBulletDynamicsRigidBody.h"
#include "GameGUI.h"
#include "Building.h"

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
	bool quit(const CEGUI::EventArgs &e);
	bool onTextAccepted(const CEGUI::EventArgs &e);
	bool onSelectionChanged(const CEGUI::EventArgs &e);
	bool onCheckStateChanged(const CEGUI::EventArgs &e);
bool onMouseEnters(const CEGUI::EventArgs &e);

bool onMouseLeaves(const CEGUI::EventArgs &e);

void updateCheckbox();

void setupViewport(RenderWindow *win, SceneManager *curr);

void swap(SceneManager *&first, SceneManager *&second);

bool Event_ChatTextAdded(const CEGUI::EventArgs& args);

void addChatText(const CEGUI::String& pText);
bool play(const CEGUI::EventArgs &e);

	GameGUI * gameGUI;

	OgreBulletDynamics::RigidBody* cityGrid[2500];
	string bTypes[5][10];

private:
   Ogre::Entity    *mChassis;
	

	bool mContinue;
	bool gameStart;
	bool gameInit;
	bool ConnectionOccured;

	MaxMSPHandle * mMaxMSPHandle;
};


#endif //_OGREBULLET_Vehicles_Demo__H

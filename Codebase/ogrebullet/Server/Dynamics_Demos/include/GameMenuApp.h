/***************************************************************************

This source file is part of OGREBULLET
(Object-oriented Graphics Rendering Engine Bullet Wrapper)
For the latest info, see http://www.ogre3d.org/phpBB2addons/viewforum.php?f=10

Copyright (c) 2007 tuan.kuranes@gmail.com (Use it Freely, even Statically, but have to contribute any changes)



This source file is not LGPL, it's public source code that you can reuse.
-----------------------------------------------------------------------------*/
#ifndef _OGREBULLET_GameMenuApp__H
#define _OGREBULLET_GameMenuApp__H

#include "ExampleApplication.h"
#include "MusicSystem.h"
#include "OgreBulletDynamics.h"
#include "OgreBulletListener.h"
#include "OgreBulletDynamicsRigidBody.h"
#include "GameGUI.h"
#include "Building.h"
#include "GameMenu1.h"

// -------------------------------------------------------------------------
class GameMenuApp : public OgreBulletListener

{
public:

GameMenuApp() : OgreBulletListener()
      {
        mName = "Boom Box Menu";
      };
    virtual ~GameMenuApp(){};


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





    GameMenu1 * gameMenu;

	

private:
    
};


#endif //_OGREBULLET_Vehicles_Demo__H

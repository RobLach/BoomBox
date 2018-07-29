/***************************************************************************

This source file is part of OGREBULLET
(Object-oriented Graphics Rendering Engine Bullet Wrapper)
For the latest info, see http://www.ogre3d.org/phpBB2addons/viewforum.php?f=10

Copyright (c) 2007 tuan.kuranes@gmail.com (Use it Freely, even Statically, but have to contribute any changes)



This source file is not LGPL, it's public source code that you can reuse.
-----------------------------------------------------------------------------*/
#ifndef _OGREBULLET_Constraints_Demo__H
#define _OGREBULLET_Constraints_Demo__H

#include "OgreBulletDynamics.h"
#include "OgreBulletListener.h"

// -------------------------------------------------------------------------
class Constraints_Demo : public OgreBulletListener 
{
public:

    Constraints_Demo() : OgreBulletListener()
      {
          mName = "Constraints Demo";
      };
    virtual ~Constraints_Demo(){};

    void init(Ogre::Root *root, Ogre::RenderWindow *win, OgreBulletApplication *application);

    void keyPressed(BULLET_KEY_CODE key);

	// my
	bool frameStarted(Ogre::Real elapsedTime);

	OgreBulletDynamics::RigidBody* addDynCube(Ogre::String in_name, Ogre::Vector3 in_pos, Ogre::Quaternion in_q, Ogre::Vector3 in_bounds, Ogre::Real in_restitution, 
				Ogre::Real in_friction, Ogre::Real in_mass);
	
	OgreBulletDynamics::RigidBody* addDynSphere(Ogre::String in_name, Ogre::Vector3 in_pos, Ogre::Quaternion in_q, Ogre::Real in_size, Ogre::Real in_restitution, 
				Ogre::Real in_friction, Ogre::Real in_mass);

	void shutdown();
};


#endif //_OGREBULLET_Constraints_Demo__H


                                           
#ifndef __building_h_
#define __building_h_

/****************************************
* building.h
*
*****************************************/

#include <iostream>
#include <zoidcom.h>
#include <string.h>
#include "Object.h"
#include "Ogre.h"

using namespace std;

// tree game object
class Building : public Object
{
	static ZCom_ClassID m_classid;
public:
	enum BuildingType { team1, team2, store, special };

protected:
	
	
	int m_health;
	zFloat	position[3];
	zFloat	orientation[4];
	BuildingType currentType;

public:
	Building(ZCom_Control *_control);
	~Building();

	static void registerClass(ZCom_Control *_control) {
		m_classid = _control->ZCom_registerClass("Building");
	}
	
	static ZCom_ClassID getClassID() { return m_classid; }

	//void setPosition(Ogre::Vector3 pos);
	//void setOrientation(Ogre::Quaternion ori);
	void TakeDamage(int damage);
};
#endif
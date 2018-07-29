                                             
#include <iostream>
#include <string.h>
#include <zoidcom.h>

using namespace std;
//#include "stdafx.h"
#include "Building.h"

/************************************************************************/
/* Building                                                             */
/************************************************************************/

// declare static member
ZCom_ClassID Building::m_classid = ZCom_Invalid_ID;

// tree constructor
Building::Building(ZCom_Control *_control) {
	m_node->registerNodeDynamic(m_classid, _control);
	this->m_health = 100;
	this->currentType = BuildingType::team1;
}

Building::~Building()
{ 
	if (m_node)
	{
		delete m_node;
		m_node = NULL;
	} 
}

//void Building::setPosition(Ogre::Vector3 pos)
//{
//	position[0] = pos.x;
//	position[1] = pos.y;
//	position[2] = pos.z;
//}
//void Building::setOrientation(Ogre::Quaternion ori)
//{
//	orientation[0] = ori.w;
//	orientation[1] = ori.x;
//	orientation[2] = ori.y;
//	orientation[3] = ori.z;
//}
void Building::TakeDamage(int damage){
	m_health -= damage;
}
                                             
#include <iostream>
#include <string.h>
#include <zoidcom.h>

using namespace std;
//#include "stdafx.h"
#include "Building.h"

/************************************************************************/
/* Building                                                       */
/************************************************************************/

// declare static member
ZCom_ClassID Building::m_classid = ZCom_Invalid_ID;

Building::Building()
{
}

// tree constructor
Building::Building(ZCom_Control *_control) {
	m_node->registerNodeDynamic(m_classid, _control);
	this->m_health = 100;
	this->currentType = BuildingType::team1;
	this->isChanged = false;
	this->buildingNum = 0;
	this->buildingTeam = 1;
	this->buildingState = 0;
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

int Building::GetIntType()
{
	if(this->currentType == BuildingType::team1)
		return 1;
	else if(this->currentType == BuildingType::team2)
		return 2;
	else if(this->currentType == BuildingType::special)
		return 3;
	else if(this->currentType == BuildingType::store)
		return 4;
	else return 3; // Will default to special... ?
}

int Building::GetIntState()
{
	if(this->m_health < 20)
		return 8;
	else if(this->m_health < 40)
		return 6;
	else if(this->m_health < 60)
		return 4;
	else if(this->m_health < 80)
		return 2;
	else return 0;
}

void Building::SetBuildingNumber(int num)
{
	this->buildingNum = num;
}

void Building::SetBuildingTeam(int num)
{
	this->buildingTeam = num;
}

void Building::SetBuildingState(int num)
{
	this->buildingState = num;
}
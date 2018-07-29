                                                                     
                                             
#ifndef __powerupitem_h_
#define __powerupitem_h_

/****************************************
* powerupitem.h
*
*****************************************/

#include <iostream>
#include <zoidcom.h>
#include <string.h>
#include "Object.h"

using namespace std;

// tree game object
class PowerupItem : public Object
{
	static ZCom_ClassID m_classid;

protected:

	zFloat	position[3];
	zFloat	orientation[4];
	
	// Add more if need be
	int damage;
	int healing;
	int speed;
	int rangeModifier;

public:
	PowerupItem(ZCom_Control *_control);
	~PowerupItem();

	static void registerClass(ZCom_Control *_control) {
		m_classid = _control->ZCom_registerClass("PowerupItem");
	}
	
	static ZCom_ClassID getClassID() { return m_classid; }

};
#endif
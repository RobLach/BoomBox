                                                                   
                                                                     
                                             
#ifndef __musicitem_h_
#define __musicitem_h_

/****************************************
* music.h
*
*****************************************/

#include <iostream>
#include <zoidcom.h>
#include <string.h>
#include "Object.h"

using namespace std;

// tree game object
class MusicItem : public Object
{
	static ZCom_ClassID m_classid;

protected:
	
	
	zFloat	position[3];
	zFloat	orientation[4];
	
	// NEEDS to be fixed, what are patterns how do we hold them
	//MusicPattern Pattern;
	
	int damage;
	int healing;

public:
	MusicItem(ZCom_Control *_control);
	~MusicItem();

	static void registerClass(ZCom_Control *_control) {
		m_classid = _control->ZCom_registerClass("MusicItem");
	}
	
	static ZCom_ClassID getClassID() { return m_classid; }

	// NEEDS to be fixed, how do we play patterns.
	//void playPattern(MusicPattern Pattern);

};
#endif
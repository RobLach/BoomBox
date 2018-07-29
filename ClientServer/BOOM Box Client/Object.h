#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <stdlib.h>
#include <iostream>

#include "zoidcom.h"

using namespace std;


/* Generic Object */
class Object
{
protected:
	ZCom_Node*	m_node;

public:
	Object() { 
		m_node = new ZCom_Node();
		killme = false;
	}
	virtual ~Object() { if (m_node) delete m_node; }
	//virtual void update() {}

	bool killme;
};


/* Van Object*/
class Van : public Object
{
	static ZCom_ClassID m_classid;

public:
	Van(ZCom_Control *_control);
	//void update();

	static void registerClass(ZCom_Control *_control) {
		m_classid = _control->ZCom_registerClass("Van");
	}
	
	static ZCom_ClassID getClassID() { return m_classid; }
};




/* Building Object */
class Building : public Object
{
	static ZCom_ClassID m_classid;

public:
	Building(ZCom_Control *_control);
	//void update();

	static void registerClass(ZCom_Control *_control) {
		m_classid = _control->ZCom_registerClass("Building");
	}
	
	static ZCom_ClassID getClassID() { return m_classid; }
};


#endif

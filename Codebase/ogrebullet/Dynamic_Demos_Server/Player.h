#pragma once
#include "Object.h"
#include <string>

class Player : public Object
{
public:
	
	~Player(void);
	static ZCom_ClassID m_classid;


	Player(ZCom_Control *_control);

	static void registerClass(ZCom_Control *_control) {
		m_classid = _control->ZCom_registerClass("Player");
	}
	

	static ZCom_ClassID getClassID() { return m_classid; }

int playerHealth;
	 
	 string userName;

void setName(string Name)
{
	userName = Name;
}

int getLife()
{
	return playerHealth;
}




};

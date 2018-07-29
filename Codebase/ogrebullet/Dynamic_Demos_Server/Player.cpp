#include "Player.h"




ZCom_ClassID Player::m_classid = ZCom_Invalid_ID;

Player::Player(ZCom_Control *_control) {
	m_node->registerNodeDynamic(m_classid, _control);
}

Player::~Player()
{

	if(m_node)
	{
		delete m_node;
		m_node = NULL;
	}
}
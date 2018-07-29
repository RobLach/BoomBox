#include "Object.h"

Van::Van(ZCom_Control *_control) {
	m_node->registerNodeDynamic(m_classid, _control);
}

Building::Building(ZCom_Control *_control) {
	m_node->registerNodeDynamic(m_classid, _control);
}

ZCom_ClassID Van::m_classid = ZCom_Invalid_ID;

ZCom_ClassID Building::m_classid = ZCom_Invalid_ID;
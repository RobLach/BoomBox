#include "Object.h"

Van::Van(ZCom_Control *_control) {
	m_node->registerNodeDynamic(m_classid, _control);
}

Building::Building(ZCom_Control *_control) {
	m_node->registerNodeDynamic(m_classid, _control);
}

/*
void Van::update() {
	while ( m_node->checkEventWaiting()) {
		eZCom_Event	eve_type;
		eZCom_NodeRole eve_senderrole;
		ZCom_ConnID eve_senderid;
		zU32 eve_sendtime;
		ZCom_BitStream *eve_data = m_node->getNextEvent(&eve_type, &eve_senderrole, &eve_senderid, &eve_sendtime);
		if (eve_type == eZCom_EventRemoved) {
			cout << "This Van has been removed from the server!" << endl;
			cout << "Deleting this Object..." << endl;
            killme = true;
		}
	}
}

void Building::update() {
	while ( m_node->checkEventWaiting()) {
		eZCom_Event		eve_type;
		eZCom_NodeRole	eve_senderrole;
		ZCom_ConnID	eve_senderid;
		zU32			eve_sendtime;
		ZCom_BitStream *eve_data = m_node->getNextEvent(&eve_type, &eve_senderrole, &eve_senderid, &eve_sendtime);
		if (eve_type == eZCom_EventRemoved) {
			cout << "This Building has been removed from the server!" << endl;
			cout << "Deleting this Object..." << endl;
            killme = true;
		}
	}
}*/

ZCom_ClassID Van::m_classid = ZCom_Invalid_ID;

ZCom_ClassID Building::m_classid = ZCom_Invalid_ID;
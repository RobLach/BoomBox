
//#include "stdafx.h"
#include "PowerupItem.h"

/************************************************************************/
/* PowerupItem                                                                 */
/************************************************************************/

// declare static member
ZCom_ClassID PowerupItem::m_classid = ZCom_Invalid_ID;

// tree constructor
PowerupItem::PowerupItem(ZCom_Control *_control) {
	m_node->registerNodeDynamic(m_classid, _control);
}

PowerupItem::~PowerupItem()
{ 
	if (m_node)
	{
		delete m_node;
		m_node = NULL;
	} 
}
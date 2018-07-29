

//#include "stdafx.h"
#include "MusicItem.h"

/************************************************************************/
/* MusicItem                                                                 */
/************************************************************************/

// declare static member
ZCom_ClassID MusicItem::m_classid = ZCom_Invalid_ID;

// tree constructor
MusicItem::MusicItem(ZCom_Control *_control) {
	m_node->registerNodeDynamic(m_classid, _control);
}

MusicItem::~MusicItem()
{ 
	if (m_node)
	{
		delete m_node;
		m_node = NULL;
	} 
}
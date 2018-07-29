/****************************************
* gameobject.cpp
*
* This file is part of the "Zoidcom Automated Networking System" application library.
* Copyright (C)2002-2004 by Jörg Rüppel. See documentation for copyright and licensing details.
*****************************************/

#include <zoidcom.h>
#include <cstdio>

#include "gameobject.h"

/************************************************************************/
/* Game Object Base                                                     */
/************************************************************************/

// handle node events
void GameObject::processNodeEvents()
{
  while (m_node->checkEventWaiting()) 
  {
    eZCom_Event       eve_type;        // event type
    eZCom_NodeRole    eve_remote_role; // role of remote sender
    ZCom_ConnID       eve_connid;      // connection id of sender

    // get next waiting event
    ZCom_BitStream *eve_data = m_node->getNextEvent(&eve_type, &eve_remote_role, &eve_connid);

    // the server object has been deleted on the server, we can delete it here, too
    if (eve_remote_role == eZCom_RoleAuthority && eve_type == eZCom_EventRemoved)
    {
      m_deleteme = true;
      printf("Node deleted on server!\n");
    }
  }
}

/************************************************************************/
/* Rock                                                                 */
/************************************************************************/

// declare static member
ZCom_ClassID Rock::m_classid = ZCom_Invalid_ID;

// rock constructor
Rock::Rock(ZCom_Control *_control) 
{
  m_node->registerNodeDynamic(m_classid, _control);
  printf("New rock!\n");
}

// register this class
void Rock::registerClass(ZCom_Control *_control) {
  m_classid = _control->ZCom_registerClass("Rock");
}

/************************************************************************/
/* Tree                                                                 */
/************************************************************************/

// declare static member
ZCom_ClassID Tree::m_classid = ZCom_Invalid_ID;

// tree constructor
Tree::Tree(ZCom_Control *_control)
{
  m_node->registerNodeDynamic(m_classid, _control);
  printf("New tree!\n");
}

// register this class
void Tree::registerClass(ZCom_Control *_control) {
  m_classid = _control->ZCom_registerClass("Tree");
}

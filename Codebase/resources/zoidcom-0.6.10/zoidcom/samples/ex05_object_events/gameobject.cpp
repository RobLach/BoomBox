/****************************************
* gameobject.cpp
*
* This file is part of the "Zoidcom Automated Networking System" application library.
* Copyright (C)2002-2004 by Jörg Rüppel. See documentation for copyright and licensing details.
*****************************************/

#include <cstdio>
#include <cstdlib>

#include <zoidcom.h>

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

    // a custom application event arrived
    if (eve_type == eZCom_EventUser)
    {
      // type of custom event is in the first 4 bits of the event
      eEventType type = (eEventType) eve_data->getInt(4);

      // authority object sent a text
      if (type == eEve_Text)
        printf("Event received: %s\n", eve_data->getStringStatic());
      // authority object sent a 16 bit number
      else if (type == eEve_Number)
        printf("Event received: %d\n", eve_data->getInt(16));
    }
  }
}

void GameObject::sendTextEvent()
{
  // only allow event sending from authority
  if (m_node->getRole() != eZCom_RoleAuthority)
    return;

  // allocate bitstream for event
  ZCom_BitStream *eve = new ZCom_BitStream;

  // fill data
  eve->addInt(eEve_Text, 4);
  eve->addString("Hello World from authority!");

  // send to all client nodes
  m_node->sendEvent(eZCom_ReliableOrdered, ZCOM_REPRULE_AUTH_2_ALL, eve);

  // zoidcom will comsume the event object, so NO DELETION here
  eve = NULL;
}

void GameObject::sendNumberEvent()
{
  // only allow event sending from authority
  if (m_node->getRole() != eZCom_RoleAuthority)
    return;

  // allocate bitstream for event
  ZCom_BitStream *eve = new ZCom_BitStream;

  // fill data
  eve->addInt(eEve_Number, 4);
  // send a random number 0-999 as 16 bit int
  eve->addInt(rand()%1000, 16);

  // send to all client nodes
  m_node->sendEvent(eZCom_ReliableOrdered, ZCOM_REPRULE_AUTH_2_ALL, eve);

  // zoidcom will comsume the event object, so NO DELETION here
  eve = NULL;
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

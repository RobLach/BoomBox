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

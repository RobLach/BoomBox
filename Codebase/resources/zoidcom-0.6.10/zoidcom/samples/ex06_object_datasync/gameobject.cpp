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
/* Tree                                                                 */
/************************************************************************/

// declare static member
ZCom_ClassID Tree::m_classid = ZCom_Invalid_ID;

// tree constructor
Tree::Tree(ZCom_Control *_control, bool _isserver)
{
  m_counter = 0;
  m_text[0] = 0;
  m_someint = 0;

  // register the variables for replication
  m_node->beginReplicationSetup(3);
  m_node->addReplicationInt((zS32*) &m_someint, 16, false, ZCOM_REPFLAG_MOSTRECENT, ZCOM_REPRULE_AUTH_2_ALL);
  m_node->addReplicationFloat(&m_counter, 23, ZCOM_REPFLAG_MOSTRECENT, ZCOM_REPRULE_AUTH_2_ALL);
  m_node->addReplicationString(m_text, 32, ZCOM_REPFLAG_MOSTRECENT, ZCOM_REPRULE_AUTH_2_ALL);
  m_node->endReplicationSetup();

  // we work with one single tree in the whole app, so unique replication is used
  m_node->registerNodeUnique(m_classid, (_isserver) ? eZCom_RoleAuthority : eZCom_RoleProxy, _control);
  printf("New tree!\n");
}

// register this class
void Tree::registerClass(ZCom_Control *_control) {
  m_classid = _control->ZCom_registerClass("Tree");
}

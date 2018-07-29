/****************************************
* objecthandler.cpp
*
* This file is part of the "Zoidcom Automated Networking System" application library.
* Copyright (C)2002-2004 by Jörg Rüppel. See documentation for copyright and licensing details.
*****************************************/

#include <cstdlib>

#include "objecthandler.h"
#include "gameobject.h"

/************************************************************************/
/* Construction & Destruction                                           */
/************************************************************************/

// construct
ObjectHandler::ObjectHandler()
{
  memset(m_objpool, 0, sizeof(GameObject*)*OBJECT_POOL_SIZE);
  m_objcount = 0;
}

// destruct
ObjectHandler::~ObjectHandler()
{
  for (int i = 0; i < OBJECT_POOL_SIZE; i++)
    if (m_objpool[i])
      delete m_objpool[i];
}

/************************************************************************/
/* Client Code                                                          */
/************************************************************************/

// adds a created object
// (for client)
void ObjectHandler::addObject(GameObject *_obj)
{
  // drop object if pool is full
  if (m_objcount >= OBJECT_POOL_SIZE)
  {
    delete _obj;
    return;
  }

  // find slot and insert object
  for (int i = 0; i < OBJECT_POOL_SIZE; i++)
    if (m_objpool[i] == NULL) {
      m_objpool[i] = _obj;
      m_objcount++;
      return;
    }
}

// this removes all objects which have m_deleteme == true
// (for the client)
void ObjectHandler::processEvents()
{
  for (int i = 0; i < OBJECT_POOL_SIZE; i++)
    if (m_objpool[i])
    {
      // check if events are waiting and process them
      m_objpool[i]->processNodeEvents();

      // check if remove event arrived
      if (m_objpool[i]->isGarbage())
      {
        delete m_objpool[i]; m_objpool[i] = NULL;
        m_objcount--;
      }
    }
}

/************************************************************************/
/* Server Code                                                          */
/************************************************************************/

// this deletes a random object
// (for the server)
void ObjectHandler::deleteRandomObject()
{
  if (m_objcount == 0)
    return;

  // may take a while with few object in a large pool but eventually it will
  // find something to delete
  while (1)
  {
    int num = rand() % OBJECT_POOL_SIZE;
    if (m_objpool[num])
    {
      delete m_objpool[num]; m_objpool[num] = NULL;
      m_objcount--;
      break;
    }
  }
}

// creates a random object
// (for the server)
void ObjectHandler::createRandomObject(ZCom_Control *_server)
{
  if (m_objcount >= OBJECT_POOL_SIZE)
    return;

  // find free slot
  int slot = -1;
  for (int i = 0; i < OBJECT_POOL_SIZE; i++)
    if (m_objpool[i] == NULL) {
      slot = i;
      break;
    }

  // 50/50 chance
  if (rand() % 100 > 50)
    m_objpool[slot] = new Rock(_server);
  else
    m_objpool[slot] = new Tree(_server);

  m_objcount++;
}

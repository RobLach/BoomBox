/****************************************
* filesender.h
*
* This file is part of the "Zoidcom Automated Networking System" application library.
* Copyright (C)2002-2004 by Jörg Rüppel. See documentation for copyright and licensing details.
*****************************************/

#include <cstdio>

#include <zoidcom.h>


// base game object
class FileSender
{
protected:
  // the node
  ZCom_Node*           m_node;

public:
  // creates and registers the node
  FileSender(ZCom_Control *_control, bool _isserver);
  // when object get deleted, just delete the node, too
  // there is no need for unregistering or anything else
  virtual ~FileSender() { if (m_node) delete m_node;  }

  // handle node events
  // checks for eZCom_EventRemoved on client and sets m_deleteme
  void processNodeEvents();

  // class registration
  static void registerClass(ZCom_Control *_control);
};


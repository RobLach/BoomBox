/****************************************
* gameobject.h
*
* This file is part of the "Zoidcom Automated Networking System" application library.
* Copyright (C)2002-2004 by Jörg Rüppel. See documentation for copyright and licensing details.
*****************************************/

#include <cstdio>

#include <zoidcom.h>


// base game object
class GameObject
{
protected:
  // the node
  ZCom_Node*           m_node;
public:
  // creates and registers the node
  GameObject() { m_node = new ZCom_Node(); }
  // when object get deleted, just delete the node, too
  // there is no need for unregistering or anything else
  virtual ~GameObject() { if (m_node) delete m_node;  }
};

// tree game object
class Tree : public GameObject
{
  // the class id for zoidcom
  static ZCom_ClassID  m_classid;

public:
  // variables for replication
  zU32                 m_someint;
  zFloat               m_counter;
  char                 m_text[32];

public:
  Tree(ZCom_Control *_control, bool _isserver);
  ~Tree() { printf("Tree deleted!\n"); }

  // class registration
  static void registerClass(ZCom_Control *_control);
  static ZCom_ClassID getClassID() { return m_classid; }
};


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
  // indicates if object is garbage
  bool                 m_deleteme;
public:
  // creates and registers the node
  GameObject() { m_node = new ZCom_Node(); m_deleteme = false; }
  // when object get deleted, just delete the node, too
  // there is no need for unregistering or anything else
  virtual ~GameObject() { if (m_node) delete m_node;  }
   
  // handle node events
  // checks for eZCom_EventRemoved on client and sets m_deleteme
  void processNodeEvents();

  // returns true if object is garbage
  bool isGarbage() { return m_deleteme; }
};

// tree game object
class Tree : public GameObject
{
  // the class id for zoidcom
  static ZCom_ClassID  m_classid;

public:
  Tree(ZCom_Control *_control);
  ~Tree() { printf("Tree deleted!\n"); }

  // class registration
  static void registerClass(ZCom_Control *_control);
  static ZCom_ClassID getClassID() { return m_classid; }
};


// rock game object
class Rock : public GameObject
{
  // the class id for zoidcom
  static ZCom_ClassID  m_classid;
public:
  Rock(ZCom_Control *_control);
  ~Rock() { printf("Rock deleted!\n"); }

  // class registration
  static void registerClass(ZCom_Control *_control);
  static ZCom_ClassID getClassID() { return m_classid; }
};

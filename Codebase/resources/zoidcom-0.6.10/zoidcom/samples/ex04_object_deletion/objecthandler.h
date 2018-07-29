/****************************************
* objecthandler.h
*
* This file is part of the "Zoidcom Automated Networking System" application library.
* Copyright (C)2002-2004 by Jörg Rüppel. See documentation for copyright and licensing details.
*****************************************/

class GameObject;
class ZCom_Control;

#define OBJECT_POOL_SIZE 128

class ObjectHandler
{
protected:
  // the object pool
  GameObject* m_objpool[OBJECT_POOL_SIZE];
  int m_objcount;
public:
  ObjectHandler();
  ~ObjectHandler();

  // adds a created object
  // (for client)
  void addObject(GameObject *_obj);

  // handle object events and delete object if necessary
  // (for the client)
  void processEvents();

  // this deletes a random object
  // (for the server)
  void deleteRandomObject();

  // creates a random object
  // (for the server)
  void createRandomObject(ZCom_Control *_server);
};

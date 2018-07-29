/****************************************
* nodeobj.h
* part of example source code
*
* This file is part of the "Zoidcom Automated Networking System" application library.
* Copyright (C)2002-2006 by Joerg Rueppel. See documentation for copyright and licensing details.
*****************************************/

#ifndef _nodeobj_h
#define _nodeobj_h

#include <allegro.h>
#include <zoidcom.h>
#include "common.h"

#define OBJ_MAX 16

// the input class
struct Input
{
  Input() { 
    up = down = left = right = false; 
  }

  // write input to bitstream
  void pack(ZCom_BitStream &_str) {
    _str.addBool(up);
    _str.addBool(down);
    _str.addBool(left);
    _str.addBool(right);
  }

  // read input from bitstream
  void unpack(ZCom_BitStream &_str) {
    up = _str.getBool();
    down = _str.getBool();
    left = _str.getBool();
    right = _str.getBool();
  }

  bool operator==(const Input& _in) {
    return (up == _in.up && down == _in.down && left == _in.left && right == _in.right);
  }

  Input& operator=(const Input& _rhs) {
    up = _rhs.up; down = _rhs.down; left = _rhs.left; right = _rhs.right;
    return *this;
  }

  bool up;
  bool down;
  bool left;
  bool right;
};

// the object is it's own interceptor at the same time
class NObject : public ZCom_NodeReplicationInterceptor, public ZCom_MoveUpdateListener<zS32>
{
public:
  ZCom_Replicate_Movement<zS32, 2> *moverep;
  ZCom_Node *node;
  

  // object data
  struct data_s
  {
    // current position
    zS32        position[2];
    // current velocity
    zFloat      velocity[2];
    // time of last received update
    zU32        current_time;

    // accumulated simulation time
    zU32        accum_time;
    
    // position in object array
    int         slot;
    // true if object is controlled locally
    bool        local;
    // true if object is garbage
    bool        deleteme;
    // true if data was sent or received
    bool        update_out, update_in;
    // last received input
    Input       last_input_received;
    // last sent input
    Input       last_input_sent;
  } data;

  NObject();
  ~NObject();

  void init(ZCom_Control *_cont);
  void draw(bool _show_spline);
  void control(Input &_input);
  void updatePhysics(zU32 _time);

  // called from server and client
  void update();

  // depending on local role, one of these gets called from update()
  void doOwner();
  void doProxy();
  void doAuth();
 
  /* update listener callbacks */
  void inputUpdated(ZCom_BitStream& _inputstream, bool _inputchanged, zU32 _client_time, zU32 _estimated_time_sent);
  void inputSent(ZCom_BitStream& _inputstream);
  void correctionReceived(zS32 *_pos, zFloat* _vel, zFloat *_acc, bool _teleport, zU32 _estimated_time_sent);
  void updateReceived(ZCom_BitStream& _inputstream, zS32 *_pos, zFloat* _vel, zFloat *_acc, zU32 _estimated_time_sent) {}

  /* interceptor callbacks */

  // this one we are interested in: let the object blink green when an update arrived
  virtual void inPostUpdate(ZCom_Node *_node, ZCom_ConnID _from, eZCom_NodeRole _remote_role, zU32 _rep_bits, zU32 _event_bits, zU32 _meta_bits);
  // and this: let the object blink red when an update was sent
  virtual void outPostUpdate(ZCom_Node *_node, ZCom_ConnID _to, eZCom_NodeRole _remote_role, zU32 _rep_bits, zU32 _event_bits, zU32 _meta_bits);
  
  virtual void outPreReplicateNode(ZCom_Node *_node, ZCom_ConnID _to, eZCom_NodeRole _remote_role) {}
  virtual void outPreDereplicateNode(ZCom_Node *_node, ZCom_ConnID _to, eZCom_NodeRole _remote_role) {}
  virtual bool outPreUpdate(ZCom_Node *_node, ZCom_ConnID _to, eZCom_NodeRole _remote_role) { return true; }
  virtual bool outPreUpdateItem(ZCom_Node *_node, ZCom_ConnID _to, eZCom_NodeRole _remote_role,  ZCom_Replicator *_info) { return true; }
  virtual bool inPreUpdate(ZCom_Node *_node, ZCom_ConnID _from, eZCom_NodeRole _remote_role) { return true; }
  virtual bool inPreUpdateItem(ZCom_Node *_node, ZCom_ConnID _from, eZCom_NodeRole _remote_role,  ZCom_Replicator *_info, zU32 _time) { return true; }
};

#endif

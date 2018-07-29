/****************************************
* nodeobj.cpp
* part of example source code
*
* This file is part of the "Zoidcom Automated Networking System" application library.
* Copyright (C)2002-2006 by Joerg Rueppel. See documentation for copyright and licensing details.
*****************************************/

#include "nodeobj.h"

NObject::NObject()
{
  node = NULL;
  moverep = NULL;
  data.local = false;
  data.position[0] = 400; data.position[1] = 300;
  data.velocity[0] = data.velocity[1] = 0;
  data.slot = -1;
  data.deleteme = false;
  data.current_time = 0;
  data.accum_time = 0;
}

// the destructor deletes the node which in result automatically deregisters it with Server or Client
NObject::~NObject()
{
  if (node)
  {
    delete node;
    node = NULL;
  }
}

// create node and setup data replication
void NObject::init(ZCom_Control *_cont)
{
  node = new ZCom_Node();
  if (!node)
  {
    sys_print("NObject::init(): unable to create ZCom_Node()");
  }

  // data replication setup
  node->beginReplicationSetup(1);

  // create the movement replicator
  moverep = new ZCom_Replicate_Movement<zS32, 2>(32, ZCOM_REPFLAG_MOSTRECENT|ZCOM_REPFLAG_SETUPPERSISTS,
    ZCOM_REPRULE_OWNER_2_AUTH|ZCOM_REPRULE_AUTH_2_PROXY);
  // set a low error threshold
  ((ZCom_RSetupMovement<zS32>*)moverep->getSetup())->setConstantErrorThreshold(0);
  // set interpolation time to 50 milliseconds
  ((ZCom_RSetupMovement<zS32>*)moverep->getSetup())->setInterpolationTime(50);
  // apply timescale
  moverep->setTimeScale((float)UPDATE_RATE/1000.0f);

  // add the replicator
  node->addReplicator(moverep, true);

  // set update listener (the methods NObject::inputUpdated, NObject::inputSent, NObject::correctionReceived,
  // and NObject::updateReceived implement the update listener interface and are called by moverep)
  moverep->setUpdateListener(this);

  // set initial position
  moverep->updateState((zS32*) &data.position[0], NULL, NULL, false);

  // done
  node->endReplicationSetup();

  // register the node with the server or client
  node->registerNodeDynamic(_cont->ZCom_getClassID("NObject"), _cont);

  // enable generation of eZCom_EventInit
  node->setEventNotification(true, false);

  // put node into zoidlevel 2
  node->applyForZoidLevel(2);

  // set the interceptor, so node can blink when update arrived
  node->setReplicationInterceptor(this);
}

// draw object
void NObject::draw(bool _show_spline)
{
  long color;

  //
  // handle flag from node interceptor
  //

  // the node received updates
  if (data.update_in)
    color = makecol(50, 150, 190);
  // the node sent updates
  else if (data.update_out)
    color = makecol(190, 20, 20);
  // no traffic
  else
    color = makecol(100, 100, 140);

  // if this is the server node, just draw a hollow rect
  if (node->getRole() == eZCom_RoleAuthority)
    rect(buffer, data.position[0]-12, data.position[1]-12, data.position[0]+12, data.position[1]+12, color);
  // if not, draw a filled rect
  else if (node->getRole() == eZCom_RoleOwner)
    rectfill(buffer, data.position[0]-10, data.position[1]-10, data.position[0]+10, data.position[1]+10, color);
  else
    circlefill(buffer, data.position[0], data.position[1], 10, color);

  // print the network id
  textprintf_centre(buffer, font, data.position[0], data.position[1]-text_height(font)/2, makecol(255,255,255), "%d", node->getNetworkID());

  // reset in/out flags
  data.update_in = data.update_out = false;

  // display move replicator spline
  if (node->getRole() == eZCom_RoleProxy && _show_spline)
  {
    zS32 point[2];

    // draw 10 points of the spline in white
    for (zFloat f = 0; f <= 1; f += 0.1f)
    {
      moverep->getSplinePoint(f, point);
      rectfill(buffer, point[0]-1, point[1]-1, point[0]+1, point[1]+1, makecol(255, 255, 255));
    }

    // draw the 4 control points in red
    for (int i = 0; i < 4; i++)
    {
      moverep->getSplineControlPoint((zU32)i, point);
      rectfill(buffer, point[0]-1, point[1]-1, point[0]+1, point[1]+1, makecol(255, 0, 0));
    }
  }
}

// takes the stored user input from the Input structure and 
// applies it to the object's physics state
// used @owner in NObject::inputSent() and @authority in 
// NObject::inputUpdated()
void NObject::control(Input &_input)
{
  // reset velocity
  data.velocity[0] = data.velocity[1] = 0;

  // vertical
  if (_input.up)
    data.velocity[1] = -4;
  else if (_input.down)
    data.velocity[1] = 4;

  // horizontal
  if (_input.left) 
    data.velocity[0] = -4; 
  else
    if (_input.right) 
      data.velocity[0] = 4;
}

// advances the object's physics state by a given amount of time
//
// as the time step is fixed in this example program, we only advance
// by multiples of SIMULATION_TIME_PER_UPDATE
//
// this is called periodically @owner from doOwner()
// this is called every time @authority from NObject::inputUpdated()
void NObject::updatePhysics(zU32 _time)
{
  // accumulate time
  data.accum_time += _time;

  // as long as we accumulated enough time for a full simulation step
  
  // OLD VERSION:
  // while (data.accum_time - SIMULATION_TIME_PER_UPDATE > 0)
  // the old version delayed the simulation of a timestep by one Process() cycle, because
  // data.accum_time needed to be at least SIMULATION_TIME_PER_UPDATE+1 to make an update
  // this was wrong and brought server and client out of sync

  // CHANGED in 0.6.6 to
  while (data.accum_time > 0 && data.accum_time >= SIMULATION_TIME_PER_UPDATE)
  {
    // remove time for this simulation step from time accumulator
    data.accum_time -= SIMULATION_TIME_PER_UPDATE;

    // add current velocity to position
    data.position[0] += data.velocity[0];
    data.position[1] += data.velocity[1];
  }
}

/************************************************************************/
/* authority code                                                       */
/************************************************************************/

// @authority, the object is only updated when input is received
// from the owner. this handling is performed in NObject::inputUpdated().
// doAuth() just prints some info when a new proxy or owner connected to the 
// authority
void NObject::doAuth()
{
  // check for node events
  while (node && node->checkEventWaiting())
  {
    eZCom_Event eve;
    ZCom_ConnID connid;
    eZCom_NodeRole remoterole;
    node->getNextEvent(&eve, &remoterole, &connid);

    if (eve == eZCom_EventInit && node->getRole() == eZCom_RoleAuthority) {
      sys_print("NObject: authority node got init for node: %d role: %d", node->getNetworkID(), remoterole);
    }
  }
}

// implements the ZCom_MoveUpdateListener interface.
// gets called on authority from ZCom_Control::processInput() when the owner sent new input data.
// - the input gets unpacked (but not applied yet!)
// - the object's physics state is advanced with the time since the last input
// - the new input data is applied _after_ the physics update
//
// this means: the authority object is updated ONLY when new input is received. a high packet rate
// (30 packets/seconds or above) should work pretty well for that. if you need to have a smooth
// display of the authority node, you need to manually interpolate.
//
// it is much better to not use the authority node for displaying. split up client and server,
// and in localhost games, connect the client to the local server and only display the client's
// nodes (i.e. the owner and proxies) instead of the server's authority nodes.
void NObject::inputUpdated(ZCom_BitStream& _inputstream, bool _inputchanged, zU32 _client_time, zU32 _estimated_time_sent)
{
  Input in;

  // CHANGED
  // for compression, this is false if no new input is there
  if (_inputchanged)
  {  
    // unpack input
    // _must_ be done, regardless if the input is used or not
    in.unpack(_inputstream);
    data.last_input_received = in;
  }
  // input has been left out because it didn't change
  else
    in = data.last_input_received;

  // check if we had this update already
  if (_client_time <= data.current_time)
    return;

  // update object for the time that passed
  // this is exploitable as speedhack if the client sends faked timestamps!
  // so do check that the sum of all (_client_time-data.current_time) doesn't
  // increase faster than the game's overall simulation time (not done here)
  if (data.current_time > 0)
    updatePhysics(_client_time-data.current_time);

  // tell move replicator about new physics state (so it can update the proxies)
  moverep->updateState(data.position, data.velocity, NULL, false);

  // remember the time
  data.current_time = _client_time;

  // apply input
  control(in);
}

/************************************************************************/
/* owner code                                                           */
/************************************************************************/

// checks if the authority object has been deleted
// gets input from the keyboard and gives it to the
// movement replicator
void NObject::doOwner()
{
  // check for node events
  while (node && node->checkEventWaiting())
  {
    eZCom_Event eve;
    node->getNextEvent(&eve, NULL, NULL);

    // this event is only received by proxy and owner nodes and means
    // that the authority is no longer registered with the server control
    // which in turn is an implicit request to delete the object here, too
    if (eve == eZCom_EventRemoved) {
      sys_print("NObject: authority node has been deleted, network ID: %d", node->getNetworkID());
      data.deleteme = true;
    }
  }

  // CHANGED in 0.6.6: updatePhysics() and moverep->updateInput() have exchanged order, now the server will receive the
  // already updated position for error checking, which is the correct way. The old version would send the un-updated position
  // resulting in the server receiving old data for error testing.

  // update physics
  // note that current input is not applied yet
  updatePhysics(SIMULATION_TIME_PER_UPDATE);

  // get keyboard input
  Input in;
  if (key[KEY_UP])   in.up    = true;
  if (key[KEY_DOWN]) in.down  = true;
  if (key[KEY_LEFT]) in.left  = true;
  if (key[KEY_RIGHT])in.right = true;

  // CHANGED
  // if input didn't change, keep old input
  if (in == data.last_input_sent)
  {
    // give empty input update to movement replicator.
    // this will tell zoidcom to stay with the last input.
    // zoidcom will optimize bandwidth doing this.
    // the current position is needed so that the server
    // can check if a correction is needed
    moverep->updateInput(data.position,  NULL);
  } else
  // input changed
  {
    // pack input update
    ZCom_BitStream *bs = new ZCom_BitStream(1);
    in.pack(*bs);

    // give input update to movement replicator
    // the current position is needed so that the server
    // can check if a correction is needed
    moverep->updateInput(data.position,  bs);
  }
}

// implements ZCom_MoveUpdateListener interface
// gets called as soon as our moverep->updateInput(data.position,  bs)
// has been sent. once sent, it is safe to assume the server will
// receive the update, so we can use it now, too.
void NObject::inputSent(ZCom_BitStream& _inputstream)
{
  // unpack the input again
  Input in;
  in.unpack(_inputstream);

  // apply it
  control(in);

  // CHANGED
  // remember the last input we sent, so that we can determine if new input is different
  data.last_input_sent = in;
}

// implements ZCom_MoveUpdateListener interface
// if the object on the server has a different position than the owner thinks it has,
// this will get called. this can happen when input updates got lost due to packet loss,
// or when the object got repositioned by the server (due to collision or anything else).
//
// the owner's position is corrected to what the server said.
// then reapply all collected input updates that happened _after_ the time stamp of the correction
//
void NObject::correctionReceived(zS32 *_pos, zFloat* _vel, zFloat *_acc, bool _teleport, zU32 _estimated_time_sent)
{
  Input input;
  zU32 time, currenttime = 0;
  ZCom_BitStream* inputstream = NULL;
  void *iter = NULL; // iterator for getNextInputHistoryEntry()

  sys_print("received correction for own node");

  // delete accumulated simulation time
  data.accum_time = 0;

  // set object to corrected position
  memcpy(data.position, _pos, sizeof(data.position));
  // set object to corrected velocity
  memcpy(data.velocity, _vel, sizeof(data.velocity));

  while(true)
  {
    // get next move
    //  ° if iter is NULL (= in the first iteration), the first
    //    interesting move will get returned
    //  ° if no more moves are available, the current simulation
    //    time will be returned, and inputstream == NULL
    inputstream = moverep->getNextInputHistoryEntry(&time, &iter);

    // process physics until time of next input
    // current time is 0 in the first iteration
    if (currenttime > 0 && time-currenttime>0)
      updatePhysics(time-currenttime);

    // no more moves
    if (!inputstream)
      break;

    // apply input
    input.unpack(*inputstream);
    control(input);

    currenttime = time;
  }
}

/************************************************************************/
/* proxy code                                                           */
/************************************************************************/

// checks if the authority has been deleted
// gets current object position & velocity from movement replicator
void NObject::doProxy()
{
  while (node && node->checkEventWaiting())
  {
    eZCom_Event eve;
    node->getNextEvent(&eve, NULL, NULL);

    // this event is only received by proxy and owner nodes and means
    // that the authority is no longer registered with the server control
    // which in turn is an implicit request to delete the object here, too
    if (eve == eZCom_EventRemoved) {
      sys_print("NObject: authority node has been deleted, network ID: %d", node->getNetworkID());
      data.deleteme = true;
    }
  }

  moverep->getExtrapolatedPosition(0, data.position);
  moverep->getExtrapolatedVelocity(0, data.velocity);
}

/************************************************************************/
/* code used for all roles                                              */
/************************************************************************/

void NObject::update()
{
  switch (node->getRole())
  {
  case eZCom_RoleOwner:
    doOwner(); break;
  case eZCom_RoleAuthority:
    doAuth(); break;
  case eZCom_RoleProxy:
    doProxy(); break;
  }
}

// interceptor callback: let the node blink when update arrives
void NObject::inPostUpdate(ZCom_Node *_node, ZCom_ConnID _from, eZCom_NodeRole _remote_role, zU32 _rep_bits, zU32 _event_bits, zU32 _meta_bits)
{
  data.update_in = true;
}

// interceptor callback: let the node blink when update got sent
void NObject::outPostUpdate(ZCom_Node *_node, ZCom_ConnID _to, eZCom_NodeRole _remote_role, zU32 _rep_bits, zU32 _event_bits, zU32 _meta_bits)
{
  data.update_out = true;
}

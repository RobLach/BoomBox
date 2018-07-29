/****************************************
* client.cpp
* part of example source code
*
* This file is part of the "Zoidcom Automated Networking System" application library.
* Copyright (C)2002-2006 by Joerg Rueppel. See documentation for copyright and licensing details.
*****************************************/

#include "common.h"
#include "client.h"
#include <string.h>
#include <allegro.h>

Client::Client( int _internalport, int _udpport )
{
  m_id = ZCom_Invalid_ID;

  // this will allocate the sockets and create local bindings
  if ( !ZCom_initSockets( true, _udpport, _internalport, CONTROL_ID_SIZE ) )
  {
    sys_print( "Client: unable to initialize the sockets" );
    m_exitnow = true;
  }
  else
    m_exitnow = false;

  ZCom_setControlID(CONTROL_ID);

  ZCom_setDebugName("ZCOM_CLI");

  // initialize object array
  for (int i = 0; i < OBJ_MAX; i++)
    objs[i] = NULL;

  m_localnode = -1;

  ZCom_registerClass("NObject", 0);

  m_packetloss = 0.0f;
  m_lag = 0;
}

Client::~Client()
{
  for (int i = 0; i < OBJ_MAX; i++)
    if (objs[i])
    {
      delete objs[i];
      objs[i] = NULL;
    }
}

void Client::changeLagAndLoss(float _lossdelta, zS32 _lagdelta)
{
  // change packet loss
  if (_lossdelta != 0.0f)
  {
    m_packetloss += _lossdelta;
    if (m_packetloss < 0) m_packetloss = 0.0f; else
      if (m_packetloss > 1) m_packetloss = 1.0f;
    ZCom_simulateLoss(0, m_packetloss);
  }

  // change lag
  if (_lagdelta != 0)
  {
    m_lag += _lagdelta;
    if (m_lag < 0) m_lag = 0; else
      if (m_lag > 400) m_lag = 400;
    ZCom_simulateLag(0, m_lag);
  }
}

void Client::draw(bool show_proxies, bool show_owners, bool show_spline)
{
  // net stats
  ZCom_ConnStats stats = ZCom_getConnectionStats(m_id);

  int dy = 560;
  int dx = 5;
  int hg = text_height(font);
  int color = makecol(255, 255, 255);
  textprintf(buffer, font, dx, dy, color, "client net stats: (in/out)"); dy += hg + 5;

  // kb/second
  textprintf(buffer, font, dx, dy, color,"kb/s:");
  textprintf_centre(buffer, font, dx + 85, dy, color, "%0.2f / %0.2f", stats.last_sec_in/1000.0f, stats.last_sec_out /1000.0f); dy += hg;

  // packets/second
  textprintf(buffer, font, dx, dy, color,"p/s:");
  textprintf(buffer, font, dx + text_length(font, "p/s:")+5, dy, color, "%d | %d (outgoing pkts lost: %d %%)", stats.last_sec_inp, stats.last_sec_outp, stats.last_sec_loss_percent); dy += hg;

  // ping
  textprintf(buffer, font, dx, dy, color,"ping: %d | simulated lag: %d ms | sim. out loss: %0.2f", stats.avg_ping, m_lag, m_packetloss);

  // draw objects
  for (int i = 0; i < OBJ_MAX; i++)
    if (objs[i] && objs[i]->node && ((objs[i]->node->getRole() == eZCom_RoleProxy && show_proxies) || (objs[i]->node->getRole() == eZCom_RoleOwner && show_owners)))
      objs[i]->draw(show_spline);
}

void Client::update()
{
  // update replicators and tell zoidcom how much ingame time has passed since the last
  // time this was called
  ZCom_processReplicators(SIMULATION_TIME_PER_UPDATE);

  // all callbacks are generated from within the processInput calls
  ZCom_processInput( eZCom_NoBlock );

  // update objects and their physics
  for (int i = 0; i < OBJ_MAX; i++)
    if (objs[i])
    {
      // random position setting to produce an error
      if (m_localnode == i && sys_keypressed(KEY_ENTER))
      {
        sys_print("client trying to change position of own object");
        objs[i]->data.position[0] = 100 + rand()%400;
        objs[i]->data.position[1] = 100 + rand()%200;
      }

      // update objects (actually, update only 'our' object by applying arrow key movement)
      // and check for node events
      objs[i]->update();

      // object wants to be deleted
      if (objs[i]->data.deleteme)
      {
        sys_print("Client: deleting node in slot %d", i);
        delete objs[i];
        objs[i] = NULL;
      }
    }

  // outstanding data will be packed up and sent from here
  ZCom_processOutput();
}

// called when initiated connection process yields a result
void Client::ZCom_cbConnectResult( ZCom_ConnID _id, eZCom_ConnectResult _result, ZCom_BitStream &_reply )
{
  sys_print( "Client: The connection process for %d returned with resultcode %d, the reply was '%s'.", _id, _result, _reply.getStringStatic() );
  if ( _result != eZCom_ConnAccepted )
    m_exitnow = true;
  else
  {
    ZCom_requestDownstreamLimit(_id, 30, 200);
    ZCom_requestZoidMode(_id, 2);
    m_id = _id;
  }
}

void Client::ZCom_cbConnectionClosed( ZCom_ConnID _id, eZCom_CloseReason _reason, ZCom_BitStream &_reasondata )
{
  sys_print( "Client: Connection with ID: %d has been closed, reason is: '%s'.", _id, _reasondata.getStringStatic() );
  m_exitnow = true;
}

void Client::ZCom_cbZoidResult(ZCom_ConnID _id, eZCom_ZoidResult _result, zU8 _new_level, ZCom_BitStream &_reason)
{
  // disconnect on failure
  if (_result != eZCom_ZoidEnabled)
  {
    sys_print("Client: Zoidmode failed, disconnecting");
    ZCom_Disconnect(_id, NULL);
    return;
  }

  sys_print("Client: Zoidlevel [%d] entered", _new_level);
}

void Client::ZCom_cbNodeRequest_Dynamic(ZCom_ConnID _id, ZCom_ClassID _requested_class, ZCom_BitStream *_announcedata, eZCom_NodeRole _role, ZCom_NodeID _net_id)
{
  // check the requested class
  if (_requested_class == ZCom_getClassID("NObject"))
  {
    sys_print("Client: Server requested creation of a new 'NObject' node. Network ID is: [%d].", _net_id);
    sys_print("Client: Role for requested node will be %s", (_role == eZCom_RoleProxy) ? "'eZCom_RoleProxy'" : "'eZCom_RoleOwner' <- This is the node we can control now!");

    // create the object
    NObject *no = new NObject();

    // this will create the object's node and register it with us
    no->init(this);

    no->data.slot = -1;

    // search for a free slot
    for (int i = 0; i < OBJ_MAX; i++)
    {
      if (objs[i] == NULL)
      {
        no->data.slot = i;
        objs[i] = no;
        ZCom_setUserData(_id, (void*) no->data.slot);

        // check if object is 'our' object
        if (_role == eZCom_RoleOwner)
        {
          no->data.local = true;
          m_localnode = i;
        }

        break;
      }
    }

    // if no free slot was found disconnect
    if (no->data.slot == -1)
    {
      delete no;
      sys_print("Client: unable to handle more objects - diconnecting");
      ZCom_Disconnect(m_id, NULL);
    }
  }
  else
    sys_print("Client: invalid class requested");
}

/************************************************************************/
/* demo recording                                                       */
/************************************************************************/

struct state_s
{
  bool isavail[OBJ_MAX];
  NObject::data_s data[OBJ_MAX];
};

static state_s statebuf;

zU32 Client::getStateSize()
{
  return sizeof(state_s);
}

char *Client::getState()
{
  for (int i = 0; i< OBJ_MAX; i++) {
    if (objs[i]) {
      memcpy(&statebuf.data[i], &objs[i]->data, sizeof(NObject::data_s));
      statebuf.isavail[i] = true;
    } else
      statebuf.isavail[i] = false;
  }
  return (char*) &statebuf;
}

void Client::setState(char *_data)
{
  state_s *state = (state_s*) _data;
  for (int i = 0; i< OBJ_MAX; i++)
    if (state->isavail[i] && objs[i])
      memcpy(&objs[i]->data, &state->data[i], sizeof(NObject::data_s));
}

/****************************************
* filesender.cpp
*
* This file is part of the "Zoidcom Automated Networking System" application library.
* Copyright (C)2002-2004 by Jörg Rüppel. See documentation for copyright and licensing details.
*****************************************/

#include <cstdio>
#include <cstdlib>

#include <zoidcom.h>

#include "filesender.h"

/************************************************************************/
/* File Sender                                                          */
/************************************************************************/

FileSender::FileSender(ZCom_Control *_control, bool _isserver)
{
  m_node = new ZCom_Node();
  m_node->registerNodeUnique(_control->ZCom_getClassID("FileSender"), (_isserver) ? eZCom_RoleAuthority : eZCom_RoleProxy, _control);

  // enable generation of eZCom_EventInit
  m_node->setEventNotification(true, false);
}

// handle node events
void FileSender::processNodeEvents()
{
  while (m_node->checkEventWaiting())
  {
    eZCom_Event       eve_type;        // event type
    eZCom_NodeRole    eve_remote_role; // role of remote sender
    ZCom_ConnID       eve_connid;      // connection id of sender

    // get next waiting event
    ZCom_BitStream *eve_data = m_node->getNextEvent(&eve_type, &eve_remote_role, &eve_connid);

    // the server object has been deleted on the server, we can delete it here, too
    if (eve_remote_role == eZCom_RoleAuthority && eve_type == eZCom_EventRemoved)
    {
      printf("Node deleted on server!\n");
    }

    if (eve_type == eZCom_EventInit && eve_remote_role == eZCom_RoleProxy)
    {
      printf("New proxy node connected! Sending file...\n");

      // send this binary
#ifdef ZCOM_PLATFORM_WIN32
      m_node->sendFile("ex08_file_transfer_server.exe", NULL, eve_connid, NULL, 1.0f);
#elif defined ZCOM_PLATFORM_LINUX || defined ZCOM_PLATFORM_MAC
      m_node->sendFile("ex08_file_transfer_server", NULL, eve_connid, NULL, 1.0f);
#endif
    }

    if (eve_type == eZCom_EventFile_Incoming)
    {
      ZCom_FileTransID fid = (ZCom_FileTransID) eve_data->getInt(ZCOM_FTRANS_ID_BITS);
      const ZCom_FileTransInfo& ftransinfo = m_node->getFileInfo(eve_connid, fid);

      // store the received file as "received_file"
      m_node->acceptFile(eve_connid, fid, "received_file", true);

      printf("Receiving file %s with size: %0.2f kb ID: %d\n", ftransinfo.path, ftransinfo.size / 1024.0f, fid);
    }

    // received every time a new file chunk is received
    if (eve_type == eZCom_EventFile_Data)
    {
      ZCom_FileTransID fid = (ZCom_FileTransID) eve_data->getInt(ZCOM_FTRANS_ID_BITS);
      const ZCom_FileTransInfo& ftransinfo = m_node->getFileInfo(eve_connid, fid);
      printf("File transfer: received: %0.2f kb, total: %0.2f kb, percent: %0.2f%%, kb/s: %0.2f\r", ftransinfo.transferred/1024.0f, ftransinfo.size/1024.0f, ((float)ftransinfo.transferred/(float)ftransinfo.size)*100.0f, ftransinfo.bps/1024.0f);
    }

    if (eve_type == eZCom_EventFile_Complete)
    {
      ZCom_FileTransID fid = (ZCom_FileTransID) eve_data->getInt(ZCOM_FTRANS_ID_BITS);
      const ZCom_FileTransInfo& ftransinfo = m_node->getFileInfo(eve_connid, fid);
      printf("\nFile transfer: finished: %s total: %0.2f kb\n", ftransinfo.path, ftransinfo.size/1024.0f);
    }

    if (eve_type == eZCom_EventFile_Aborted)
    {
      ZCom_FileTransID fid = (ZCom_FileTransID) eve_data->getInt(ZCOM_FTRANS_ID_BITS);
      const ZCom_FileTransInfo& ftransinfo = m_node->getFileInfo(eve_connid, fid);
      printf("\nFile transfer: aborted: %s \n", ftransinfo.path, ftransinfo.size/1024.0f);
    }

  }
}

void FileSender::registerClass(ZCom_Control *_control)
{
  _control->ZCom_registerClass("FileSender");
}

#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <stdlib.h>

#include "zoidcom.h"

using namespace std;

/* Generic Object */
class Object
{
protected:
	ZCom_Node*	m_node;

public:
	Object() { m_node = new ZCom_Node(); }
	virtual ~Object() { if (m_node) delete m_node; }
};





#endif

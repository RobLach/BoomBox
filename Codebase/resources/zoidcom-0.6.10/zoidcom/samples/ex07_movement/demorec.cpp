#include "demorec.h"

void demorec_loghook(const char *_log, void *_data)
{
  DemoRec *demorec = (DemoRec*) _data;
  demorec->storeLog((char*) _log);
}

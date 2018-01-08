#ifndef __LOGGER_CONTROLLER_H__
#define __LOGGER_CONTROLLER_H__

#include "common.h"
#include "loggerHandle.h"

typedef struct{
    LoggerHandle** handle;
    UInt8 handleNum;
}LoggerController;

Bool cd_logger_init(UInt8 moudleNum);
LoggerHandle* cd_logger_register_moudle(char* moudleName);
#endif

#include "logger.h"

static LoggerController* loggerController = NULL;
Bool cd_logger_init(UInt8 moudleNum)
{
    loggerController = (LoggerController*)malloc(sizeof(LoggerController));
    loggerController->handle = (LoggerHandle**)malloc(sizeof(LoggerHandle**) * moudleNum);
    loggerController->handleNum = 0;
    return True;
}

LoggerHandle* cd_logger_register_moudle(char* moudleName)
{
    if(loggerController == NULL)
    {
        return NULL;
    }

    LoggerHandle* newHandle = (LoggerHandle*)malloc(sizeof(LoggerHandle));
    memcpy(newHandle->moudleName, moudleName, 3);
    newHandle->level = 255;
    newHandle->outMode.function = cd_logger_console_print;
    newHandle->outMode.context = NULL;

    loggerController->handle[loggerController->handleNum] = newHandle;
    loggerController->handleNum++;
    return newHandle;
}

LoggerController* cd_logger_get_ctr_Ins()
{
    if(loggerController == NULL)
    {
        cd_logger_init(20);
    }
    return loggerController;
}

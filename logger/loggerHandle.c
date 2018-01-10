#include <stdio.h>
#include <stdarg.h>
#include "logger.h"

Bool cd_logger_assign_out_put_mode(LoggerHandle* handle, OutputFunction function, void* context)
{
    handle->outMode.function = function;
    handle->outMode.context = context;
    return True;
}

Bool cd_logger_switch_out_mask(LoggerHandle* handle, UInt8 outMask)
{
    handle->outMask |= outMask;
    return True;
}

Bool cd_logger_switch_call_statck_on(LoggerHandle* handle, UInt8 callStackLevel)
{
    handle->callStackLevel = callStackLevel;
    handle->outMask |= OUT_MASK_CALLST_ON;
    return True;
}

Bool cd_logger_switch_call_statck_off(LoggerHandle* handle)
{
    handle->callStackLevel = 255;
    handle->outMask &= ~OUT_MASK_CALLST_ON;
    return True;
}

Bool cd_logger_set_output_level(LoggerHandle* handle, UInt8 level)
{
    handle->level = level;
    return True;
}

void cd_logger_print(LoggerHandle* handle, UInt8 level, const char* data, ...)
{
    va_list args;
    char buff[200] = {0};
    char* info = buff;

    if(level <  handle->level)
    {
        return;
    }

    if(handle->outMask & OUT_MASK_MNAME_ON)
    {
        *info = OUT_MNAME_ID;
        info++;
        memcpy(info, handle->moudleName, 3);
        info+= 3;
    }

    if(handle->outMask & OUT_MASK_LEVEL_ON)
    {
        *info  = OUT_LEVEL_ID;
        info++;
        *info = level;
        info++;
    }

    *info = OUT_BODY_ID;
    info++;
    va_start(args, data);
    vsprintf(info, data, args);
    va_end(args);
    handle->outMode.function(buff, handle->outMode.context);
}

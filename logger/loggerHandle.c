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
    handle->outMask = outMask;
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

void cd_logger_print(LoggerHandle* handle, const char* data, ...)
{
    va_list args;
    char info[200] = {0};
    va_start(args, data);
    vsprintf(info, data, args);
    va_end(args);
    handle->outMode.function(info, handle->outMode.context);
}

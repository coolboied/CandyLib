#ifndef __LOGGER_HANDLE_H__
#define __LOGGER_HANDLE_H__
#include "common.h"
#include "loggerMode.h"

#define OUT_MASK_CALLST_ON  (0b00010000)
#define OUT_MASK_TIME_ON    (0b1000)
#define OUT_MASK_LEVEL_ON   (0b0100)
#define OUT_MASK_MNAME_ON   (0b0010)

#define OUT_MNAME_ID    (1) 
#define OUT_LEVEL_ID    (2)
#define OUT_TIME_ID     (3) 
#define OUT_BODY_ID     (255) 

typedef struct{
    char moudleName[3];
    UInt8 level;
    UInt8 callStackLevel;
    UInt8 outMask;
    OutputMode outMode;
}LoggerHandle;

Bool cd_logger_assign_out_put_mode(LoggerHandle* handle, OutputFunction function, void* context);
Bool cd_logger_switch_out_mask(LoggerHandle* handle, UInt8 outMask);
Bool cd_logger_switch_call_statck_on(LoggerHandle* handle, UInt8 callStackLevel);
Bool cd_logger_switch_call_statck_off(LoggerHandle* handle);

Bool cd_logger_set_outpur_level(LoggerHandle* handle, UInt8 level);
void cd_logger_print(LoggerHandle* handle, UInt8 level, const char* data, ...);
#endif

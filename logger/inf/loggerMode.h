#ifndef __LOGGER_MODE_H__
#define __LOGGER_MODE_H__
typedef void (*OutputFunction)(char* buff, void* context);

typedef struct{
    OutputFunction function;
    void* context;
}OutputMode;

void cd_logger_console_print(char* buff, void* targetDesc);
#endif

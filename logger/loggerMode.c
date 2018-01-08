#include <stdio.h>
#include "loggerMode.h"

void cd_logger_console_print(char* buff, void* targetDesc)
{
    printf("%s", buff);
}

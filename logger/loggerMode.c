#include <stdio.h>
#include "loggerHandle.h"
#include "loggerMode.h"

void cd_logger_console_print(char* buff, void* targetDesc)
{
    while(1)
    {
        if(*buff == OUT_MNAME_ID)
        {
            buff ++;
            char mname[4] = {0};
            memcpy(mname, buff, 3);
            printf("[%s] ", mname);
            buff += 3;
        }
        else if(*buff == OUT_LEVEL_ID)
        {
            buff ++;
            printf("%d ", (UInt8)*buff);
            buff ++;
        }
        else
        {
            buff ++;
            printf("%s", buff);
            break;
        }
    }
}

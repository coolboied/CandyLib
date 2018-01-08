#include "common.h"
#include "logger.h"

int main()
{
    cd_logger_init(20);
    LoggerHandle* loggerHd = cd_logger_register_moudle((char*)"TST");
    cd_logger_print(loggerHd, "zsquall test %d", 1);

}

#include "common.h"
#include "logger.h"

void testLogger()
{
    cd_logger_init(20);
    LoggerHandle* loggerHd = cd_logger_register_moudle((char*)"TST");

    cd_logger_set_output_level(loggerHd, 201);
    cd_logger_switch_out_mask(loggerHd, OUT_MASK_MNAME_ON | OUT_MASK_LEVEL_ON);
    cd_logger_print(loggerHd, 201, "test mname | level %d\r\n", 1);

    LoggerHandle* loggerHd1 = cd_logger_register_moudle((char*)"123");
    cd_logger_set_output_level(loggerHd1, 200);
    cd_logger_switch_out_mask(loggerHd1, OUT_MASK_LEVEL_ON);
    cd_logger_print(loggerHd1, 199, "test level %d\r\n", 199);
    cd_logger_print(loggerHd1, 200, "test level %d\r\n", 200);
    cd_logger_print(loggerHd1, 201, "test level %d\r\n", 201);

    LoggerHandle* loggerHd2 = cd_logger_register_moudle((char*)"ABC");
    cd_logger_set_output_level(loggerHd2, 201);
    cd_logger_switch_out_mask(loggerHd2, OUT_MASK_MNAME_ON );
    cd_logger_print(loggerHd2, 201, "test mname %d\r\n", 1);
    cd_logger_switch_out_mask(loggerHd2, OUT_MASK_MNAME_ON | OUT_MASK_LEVEL_ON);
    cd_logger_print(loggerHd2, 201, "test mname | level %d\r\n", 1);
}

int testList(void);
int testHashmap();
int main()
{
    testLogger();
    testList();
    testHashmap();
}

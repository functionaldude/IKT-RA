//thx to roman silberschneider for sending me his solution
#include <stdint.h>

#include "testcases.h"
#include "Logger.h"

#define WAIT_DELAY      	0x1F0000

int main()
{
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    Logger::init();

    Logger::print("Program started");
    while(1) {
        testBlinkingActLED(WAIT_DELAY);
    }
#pragma clang diagnostic pop
    return 0;
}

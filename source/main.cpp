//thx to roman silberschneider for sending me his solution
#include <stdint.h>
extern "C" {
#include "delay.h"
#include "gpio.h"
}

#include "testcases.h"
#include "Logger.h"
#include "MorseHandler.h"

#define WAIT_DELAY      	0x1F0000

int main()
{
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    Logger::init();
    MorseHandler::init();

    Logger::print("Program started");

    while(1) {
        //testBlinkingActLED(WAIT_DELAY);
        Logger::print("printing");
        delay(WAIT_DELAY);
        MorseHandler::morse_puts("SOS\0");
        Logger::print("string printed");
        delay(WAIT_DELAY*8);
    }
#pragma clang diagnostic pop
    return 0;
}

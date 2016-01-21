//thx to roman silberschneider for sending me his solution
extern "C" {
#include "piface.h"
#include "delay.h"
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

    piface_Init();
    piface_Write(PIFACE_IODIRA,0x00); // set everything as output

    Logger::print("Program started");

    while(1) {
        //TestMorseLED();
        TestKnightRider();
    }
#pragma clang diagnostic pop
    return 0;
}

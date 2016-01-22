//thx to roman silberschneider for sending me his solution
extern "C" {
#include "piface.h"
#include "delay.h"
}

#include "Logger.h"
#include "MorseHandler.h"


#include "UI.h"

int main()
{
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    Logger::init();
    MorseHandler::init();
    piface_Init();

    piface_Write(PIFACE_IODIRA,0x00); // set everything as output

    Logger::debug("Program started");

    while(1) {
        //TestMorseLED();
        TestKnightRider();
    }
#pragma clang diagnostic pop
    return 0;
}

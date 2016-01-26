extern "C" {
#include "piface.h"
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

    Logger::debug("Program started");

    /*
    while (1){
        MorseHandler::morse_puts("SOS\0");
    }
     */

    UI::start();
    //piface_SetAsOutput(PIFACE_PIN0);
    //piface_SetON(PIFACE_PIN0);
    //unsigned char rx = piface_ReadPin(PIFACE_PIN7);
    //Logger::putc(rx+'0');

#pragma clang diagnostic pop
    return 0;
}

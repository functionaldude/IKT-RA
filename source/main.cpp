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

    UI::start();
#pragma clang diagnostic pop
    return 0;
}

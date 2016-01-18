//thx to roman silberschneider for sending me his solution

#include "Logger.h"
#include "MorseHandler.h"
#include "UI.h"

int main()
{
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    Logger::init();
    MorseHandler::init();

    Logger::debug("Program started");

    while(1) {
        UI::getUserInput();
        UI::send();
    }
#pragma clang diagnostic pop
    return 0;
}

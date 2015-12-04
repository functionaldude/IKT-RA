//thx to roman silberschneider for sending me his solution
#include <stdint.h>

#include "testcases.h"
#include "helper.h"
#include "uart.h"

#define WAIT_DELAY      	0x1F0000

int main()
{
    uart_init();
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while(1) {
        uart_send(65);
        testBlinkingActLED(WAIT_DELAY);
    }
#pragma clang diagnostic pop
    return 0;
}

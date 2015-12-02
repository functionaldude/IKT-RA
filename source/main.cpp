//thx to roman silberschneider for sending me his solution
#include <stdint.h>

#include "testcases.h"
#include "helper.h"

#define WAIT_DELAY      	0x1F0000

int main()
{
    while(1)
    {
        testBlinkingActLED(WAIT_DELAY);
    }
    return 0;
}

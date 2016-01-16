/*
 * testcases.ccs
 *
 *  Created on: Nov 11, 2014
 */
#include "testcases.h"
#include "helper.h"
#include "gpio.h"

/*
#define GPIO_FSEL_ADDR 0x20200000

#define GPFSEL1_OFFS   4
#define LED_BIT_SET    18

#define GPSET0_OFFS    28
#define GPCLR0_OFFS    40
#define GPIO_PIN_OFFS  16

#define WAIT_DELAY      0x2F0000

#define mmio32(x) (*(volatile uint32_t*) (x))
*/

void testBlinkingActLED(volatile uint32_t mean_period)
{
    // set as output
    //mmio32(GPIO_FSEL_ADDR + GPFSEL1_OFFS) |= (1<<LED_BIT_SET);
    RPI_SetGpioOutput(RPI_GPIO16);
    mean_period >>= 1;

    // set to double of the period
    volatile uint32_t delay = (mean_period >> 1);

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while(1)
    {
        // if bigger then 2 times the period
        if(delay >= (mean_period << 1))
        {
            delay = (mean_period >> 1);
        }

        // switch on led
        //mmio32(GPIO_FSEL_ADDR + GPCLR0_OFFS) |= (1<<GPIO_PIN_OFFS);
        LED_ON();

        // wait 1
        delay_with_loop(delay);

        // switch off led
        //mmio32(GPIO_FSEL_ADDR + GPSET0_OFFS) |= (1<<GPIO_PIN_OFFS);
        LED_OFF();

        // wait 2
        delay_with_loop(delay);

        delay += 0x10000;

    }
#pragma clang diagnostic pop
}


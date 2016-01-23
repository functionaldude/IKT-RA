/*
 * testcases.ccs
 *
 *  Created on: Nov 11, 2014
 */
#include <stdint.h>
extern "C" {
#include "delay.h"
#include "gpio.h"
#include "piface.h"
#include "uart.h"
}

#include "Logger.h"
#include "MorseHandler.h"
#include "helper.h"


#define WAIT_DELAY      	0x1F0000

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

void TestBlinkingActLED(volatile uint32_t mean_period)
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

void TestMorseLED(void)
{
    // TESTCASE Morse-blinking LED
    //TestBlinkingActLED(WAIT_DELAY);
    Logger::print("printing");
    delay(WAIT_DELAY);
    MorseHandler::morse_puts("SOS\0");
    Logger::print("string printed");
    delay(WAIT_DELAY*8);
}

void TestKnightRider(void)
{
    //TESTCASE PiFace KnightRider
    piface_SetON(PIFACE_PIN0);
    delay(WAIT_DELAY/8);
    piface_SetOFF(PIFACE_PIN0);
    piface_SetON(PIFACE_PIN1);
    delay(WAIT_DELAY/8);
    piface_SetOFF(PIFACE_PIN1);
    piface_SetON(PIFACE_PIN2);
    delay(WAIT_DELAY/8);
    piface_SetOFF(PIFACE_PIN2);
    piface_SetON(PIFACE_PIN3);
    delay(WAIT_DELAY/8);
    piface_SetOFF(PIFACE_PIN3);
    piface_SetON(PIFACE_PIN4);
    delay(WAIT_DELAY/8);
    piface_SetOFF(PIFACE_PIN4);
    piface_SetON(PIFACE_PIN5);
    delay(WAIT_DELAY/8);
    piface_SetOFF(PIFACE_PIN5);
    piface_SetON(PIFACE_PIN6);
    delay(WAIT_DELAY/8);
    piface_SetOFF(PIFACE_PIN6);
    piface_SetON(PIFACE_PIN7);
    delay(WAIT_DELAY/8);
    piface_SetOFF(PIFACE_PIN7);
    piface_SetON(PIFACE_PIN6);
    delay(WAIT_DELAY/8);
    piface_SetOFF(PIFACE_PIN6);
    piface_SetON(PIFACE_PIN5);
    delay(WAIT_DELAY/8);
    piface_SetOFF(PIFACE_PIN5);
    piface_SetON(PIFACE_PIN4);
    delay(WAIT_DELAY/8);
    piface_SetOFF(PIFACE_PIN4);
    piface_SetON(PIFACE_PIN3);
    delay(WAIT_DELAY/8);
    piface_SetOFF(PIFACE_PIN3);
    piface_SetON(PIFACE_PIN2);
    delay(WAIT_DELAY/8);
    piface_SetOFF(PIFACE_PIN2);
    piface_SetON(PIFACE_PIN1);
    delay(WAIT_DELAY/8);
    piface_SetOFF(PIFACE_PIN1);
}

void TestPiFaceRead(void)
{
    //TESTCASE Reading from PiFace
    unsigned char rx = piface_Read(PIFACE_IODIRA);
    Logger::print("I received some shit.");
    delay(WAIT_DELAY);
    uart_putc(rx); //should be 0xFF
    uart_putc('\n');
    delay(WAIT_DELAY);
}



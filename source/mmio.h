//
// Created by Zoltán Sasvári on 16.01.16.
//

#ifndef MORSEPI_MMIO_H
#define MORSEPI_MMIO_H

#include <stdint.h>

#define GPIO_FSEL_ADDR 0x20200000

#define GPFSEL1_OFFS   4
#define LED_BIT_SET    18

#define GPSET0_OFFS    28
#define GPCLR0_OFFS    40
#define GPIO_PIN_OFFS  16

inline void mmio_write(uint32_t reg, uint32_t data)
{
    *(volatile uint32_t *)reg = data;
}

inline uint32_t mmio_read(uint32_t reg)
{
    return *(volatile uint32_t *)reg;
}

inline void LED_ON(void){
    // set as output
    uint32_t var = mmio_read(GPIO_FSEL_ADDR + GPFSEL1_OFFS);
    var |= (1<<LED_BIT_SET);
    mmio_write(GPIO_FSEL_ADDR + GPFSEL1_OFFS,var);

    // switch on led
    var = mmio_read(GPIO_FSEL_ADDR + GPCLR0_OFFS);
    var  |= (1<<GPIO_PIN_OFFS);
    mmio_write(GPIO_FSEL_ADDR + GPCLR0_OFFS,var);
}

inline void LED_OFF(void){
    // switch off led
    uint32_t var = mmio_read(GPIO_FSEL_ADDR + GPSET0_OFFS);
    var |= (1<<GPIO_PIN_OFFS);
    mmio_write(GPIO_FSEL_ADDR + GPSET0_OFFS,var);
}

#endif //MORSEPI_MMIO_H

//
// Created by Zoltán Sasvári on 16.01.16.
//

#ifndef MORSEPI_MMIO_H
#define MORSEPI_MMIO_H

#include <stdint.h>

inline void mmio_write(uint32_t reg, uint32_t data)
{
    *(volatile uint32_t *)reg = data;
}

inline uint32_t mmio_read(uint32_t reg)
{
    return *(volatile uint32_t *)reg;
}

/* Set/clear only the bits in value covered by the mask
// * This is not atomic - can be interrupted.
// */
//void bcm2835_peri_set_bits(volatile uint32_t* paddr, uint32_t value, uint32_t mask)
//{
//    uint32_t v = bcm2835_peri_read(paddr);
//    v = (v & ~mask) | (value & mask);
//}

inline void mmio_setbits(uint32_t reg, uint32_t value, uint32_t mask){
    uint32_t x = mmio_read(reg);
    x = (x & ~mask) | (value & mask);
    mmio_write(reg, x);
}

#endif //MORSEPI_MMIO_H

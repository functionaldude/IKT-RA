//
// Created by Zoltán Sasvári on 16.01.16.
//

#include "delay.h"
#include "piface.h"

void delay(volatile uint64_t value)
{
    //for(;  value != 0; value--);
    volatile uint64_t cnt = 0;
    while (cnt < value) {
        cnt++;
        piface_Read(PIFACE_GPIOB);
        if (cnt == value);
    }
}
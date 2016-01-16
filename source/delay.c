//
// Created by Zoltán Sasvári on 16.01.16.
//

#include "delay.h"

void delay(volatile uint32_t value)
{
    for(;  value != 0; value--);
}
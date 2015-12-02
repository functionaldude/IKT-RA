/*
 * helper.cc
 *
 *  Created on: Sept 28, 2015
 */
#include "helper.h"

#define 	LINES_CLR	1000


void delay_with_loop(volatile uint32_t value)
{
    for(;  value != 0; value--);
}


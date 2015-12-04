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

template<typename T> void initializeArrayWithZero(T* array, uint32_t size)
{
    for(uint32_t i=0; i<size; i++)
    {
        array[i] = 0;
    }
}


template<typename T> bool compare_array(T* arr1, T* arr2, uint32_t size)
{
    for(uint32_t i=0; i<size;i++)
    {
        if(arr1[i] != arr2[i])
        {
            return false;
        }
    }
    return true;
}
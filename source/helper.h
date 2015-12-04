/*
 * helper.h
 *
 *  Created on: Nov 11, 2014
 */

#ifndef SOURCE_INCLUDE_HELPER_H_
#define SOURCE_INCLUDE_HELPER_H_

#include <stdint.h>

template<typename T> void initializeArrayWithZero(T* array, uint32_t size);
template<typename T> bool compare_array(T* arr1, T* arr2, uint32_t size);
void delay_with_loop(volatile uint32_t value);


#endif /* SOURCE_INCLUDE_HELPER_H_ */

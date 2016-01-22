/*
 * testcases.h
 *
 *  Created on: Nov 11, 2014
 */

#ifndef SOURCE_TESTCASES_H_
#define SOURCE_TESTCASES_H_
#include <stdint.h>


void testBlinkingActLED(volatile uint32_t mean_period);
void TestMorseLED(void);
void TestKnightRider(void);
void TestPiFaceRead(void);

#endif /* SOURCE_TESTCASES_H_ */

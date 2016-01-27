//
// Created by Zoltán Sasvári on 16.01.16.
//

#ifndef MORSEPI_MORSEHANDLER_H
#define MORSEPI_MORSEHANDLER_H


#include <stdint.h>

#define UNIT 0xFF00
#define DELAY_SHORT (1*UNIT)
#define DELAY_LONG  (4*UNIT)

class MorseHandler {
private:
    //character functions
    static void A();
    static void B();
    static void C();
    static void D();
    static void E();
    static void F();
    static void G();
    static void H();
    static void I();
    static void J();
    static void K();
    static void L();
    static void M();
    static void N();
    static void O();
    static void P();
    static void Q();
    static void R();
    static void S();
    static void T();
    static void U();
    static void V();
    static void W();
    static void X();
    static void Y();
    static void Z();

    static void ONE();
    static void TWO();
    static void THREE();
    static void FOUR();
    static void FIVE();
    static void SIX();
    static void SEVEN();
    static void EIGHT();
    static void NINE();
    static void ZERO();

    static void (*characters[26]) ();
    static void (*numbers[10]) ();
    static char reverseTable[3][3][3][3][3];

    //setter functions
    static void HIGH();
    static void LOW();

    static void mark_short();
    static void mark_long();
    static void gap_inter();
    static void gap_char();

public:
    static void init();

    static void morse_puts(const char * input);
    static char morse_getc();

    static uint8_t listen();

};


#endif //MORSEPI_MORSEHANDLER_H

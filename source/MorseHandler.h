//
// Created by Zoltán Sasvári on 16.01.16.
//

#ifndef MORSEPI_MORSEHANDLER_H
#define MORSEPI_MORSEHANDLER_H

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

    //TODO: numbers

    static void (*characters[26]) ();

    //setter functions
    static void HIGH();
    static void LOW();

    static void mark_short();
    static void mark_long();
    static void gap_inter();
    static void gap_long();
    static void gap_short();


public:
    static void init();

    static void morse_puts(const char * input);

};


#endif //MORSEPI_MORSEHANDLER_H

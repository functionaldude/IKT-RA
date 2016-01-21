//
// Created by Zoltán Sasvári on 16.01.16.
//

#include "MorseHandler.h"
#include "Logger.h"

extern "C" {
#include "gpio.h"
#include "delay.h"
#include "piface.h"
}

#define DELAY_SHORT 0x1F0000
#define DELAY_LONG  0x310000

void (*MorseHandler::characters[26]) ();

void MorseHandler::init() {
    characters[0] = &MorseHandler::A;
    characters[1] = &MorseHandler::B;
    characters[2] = &MorseHandler::C;
    characters[3] = &MorseHandler::D;
    characters[4] = &MorseHandler::E;
    characters[5] = &MorseHandler::F;
    characters[6] = &MorseHandler::G;
    characters[7] = &MorseHandler::H;
    characters[8] = &MorseHandler::I;
    characters[9] = &MorseHandler::J;
    characters[10] = &MorseHandler::K;
    characters[11] = &MorseHandler::L;
    characters[12] = &MorseHandler::M;
    characters[13] = &MorseHandler::N;
    characters[14] = &MorseHandler::O;
    characters[15] = &MorseHandler::P;
    characters[16] = &MorseHandler::Q;
    characters[17] = &MorseHandler::R;
    characters[18] = &MorseHandler::S;
    characters[19] = &MorseHandler::T;
    characters[20] = &MorseHandler::U;
    characters[21] = &MorseHandler::V;
    characters[22] = &MorseHandler::W;
    characters[23] = &MorseHandler::X;
    characters[24] = &MorseHandler::Y;
    characters[25] = &MorseHandler::Z;
}


void MorseHandler::mark_short() {
    HIGH();
    delay(DELAY_SHORT);
    LOW();
}

void MorseHandler::mark_long() {
    HIGH();
    delay(DELAY_LONG);
    LOW();
}

void MorseHandler::gap_inter() {
    delay(DELAY_SHORT / 2);
}

void MorseHandler::gap_long() {
    delay(DELAY_SHORT * 2);
}

void MorseHandler::gap_short() {
    delay(DELAY_SHORT);
}

void MorseHandler::HIGH() {
    //LED_OFF();
    piface_Write(PIFACE_GPIOA,0xFF);
}

void MorseHandler::LOW() {
    //LED_ON();
    piface_Write(PIFACE_GPIOA,0x00);
}

//character functions
void MorseHandler::A() {
    mark_short();
    gap_inter();

    mark_long();
}
void MorseHandler::B() {
    mark_long();
    gap_inter();

    mark_short();
    gap_inter();

    mark_short();
    gap_inter();

    mark_short();
}
void MorseHandler::C() {
    mark_long();
    gap_inter();

    mark_short();
    gap_inter();

    mark_long();
    gap_inter();

    mark_short();
}
void MorseHandler::D() {
    mark_long();
    gap_inter();

    mark_short();
    gap_inter();

    mark_short();
}
void MorseHandler::E() {
    mark_short();
}
void MorseHandler::F() {
    mark_short();
    gap_inter();

    mark_short();
    gap_inter();

    mark_long();
    gap_inter();

    mark_short();
}
void MorseHandler::G() {
    mark_long();
    gap_inter();

    mark_long();
    gap_inter();

    mark_short();
}
void MorseHandler::H() {
    mark_short();
    gap_inter();

    mark_short();
    gap_inter();

    mark_short();
    gap_inter();

    mark_short();
}
void MorseHandler::I() {
    mark_short();
    gap_inter();

    mark_short();
}
void MorseHandler::J() {
    mark_short();
    gap_inter();

    mark_long();
    gap_inter();

    mark_long();
    gap_inter();

    mark_long();
}
void MorseHandler::K() {
    mark_long();
    gap_inter();

    mark_short();
    gap_inter();

    mark_long();
}
void MorseHandler::L() {
    mark_short();
    gap_inter();

    mark_long();
    gap_inter();

    mark_short();
    gap_inter();

    mark_short();
}
void MorseHandler::M() {
    mark_long();
    gap_inter();

    mark_long();
}
void MorseHandler::N() {
    mark_long();
    gap_inter();

    mark_short();
}
void MorseHandler::O() {
    mark_long();
    gap_inter();

    mark_long();
    gap_inter();

    mark_long();
}
void MorseHandler::P() {
    mark_short();
    gap_inter();

    mark_long();
    gap_inter();

    mark_long();
    gap_inter();

    mark_short();
}
void MorseHandler::Q() {
    mark_long();
    gap_inter();

    mark_long();
    gap_inter();

    mark_short();
    gap_inter();

    mark_long();
}
void MorseHandler::R() {
    mark_short();
    gap_inter();

    mark_long();
    gap_inter();

    mark_short();
}
void MorseHandler::S() {
    mark_short();
    gap_inter();

    mark_short();
    gap_inter();

    mark_short();
}
void MorseHandler::T() {
    mark_long();
}
void MorseHandler::U() {
    mark_short();
    gap_inter();

    mark_short();
    gap_inter();

    mark_long();
}
void MorseHandler::V() {
    mark_short();
    gap_inter();

    mark_short();
    gap_inter();

    mark_short();
    gap_inter();

    mark_long();
}
void MorseHandler::W() {
    mark_short();
    gap_inter();

    mark_long();
    gap_inter();

    mark_long();
}
void MorseHandler::X() {
    mark_long();
    gap_inter();

    mark_short();
    gap_inter();

    mark_short();
    gap_inter();

    mark_long();
}
void MorseHandler::Y() {
    mark_long();
    gap_inter();

    mark_short();
    gap_inter();

    mark_long();
    gap_inter();

    mark_long();
}
void MorseHandler::Z() {
    mark_long();
    gap_inter();

    mark_long();
    gap_inter();

    mark_short();
    gap_inter();

    mark_short();
}

void MorseHandler::morse_puts(const char *input) {
    uint16_t ctn = 0;
    while (input[ctn] != '\0'){
        characters[input[ctn++] - 'A']();
        gap_inter();
    }
}

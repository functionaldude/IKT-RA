//
// Created by Zoltán Sasvári on 18.01.16.
//

#ifndef MORSEPI_UI_H
#define MORSEPI_UI_H

#include <stdint.h>

class UI {
private:
    static char msg[1024];
    static uint16_t msg_size;
public:
    static void send();
    static void getUserInput();
};


#endif //MORSEPI_UI_H

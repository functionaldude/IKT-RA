//
// Created by Zoltán Sasvári on 18.01.16.
//

#ifndef MORSEPI_UI_H
#define MORSEPI_UI_H

#include <stdint.h>

#define BUFFER 1024

class UI {
private:
    static char msg[BUFFER];
    static char cmd[BUFFER];

    static uint8_t received;

    static void send();
    static void receive();

    static void getUserInput(char *out);

    static void startKnightRider();
public:
    static void start();
};


#endif //MORSEPI_UI_H

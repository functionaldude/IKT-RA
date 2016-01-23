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

    static void send();
    static void getUserInput(char *out);
public:
    static void start();
};


#endif //MORSEPI_UI_H

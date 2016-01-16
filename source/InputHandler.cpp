//
// Created by Zoltán Sasvári on 16.01.16.
//

#include "InputHandler.h"
extern "C"{
    #include "uart.h"
}

char InputHandler::user_input[1024];

void InputHandler::readUserInput() {
    //memset(&user_input, 0x00, 1024);
    uint16_t counter = 0;

    char c;
    while ((c = (char)uart_getc()) != '\n'){
        user_input[counter++] = c;
    }
}

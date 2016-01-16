//
// Created by Zoltán Sasvári on 16.01.16.
//

#ifndef MORSEPI_INPUTHANDLER_H
#define MORSEPI_INPUTHANDLER_H


class InputHandler {
private:
    static char user_input[1024];

public:
    static void readUserInput();
};


#endif //MORSEPI_INPUTHANDLER_H

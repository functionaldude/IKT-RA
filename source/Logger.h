//
// Created by Zoltán Sasvári on 16.01.16.
//

#ifndef MORSEPI_LOGGER_H
#define MORSEPI_LOGGER_H


class Logger {
public:
    static void init();
    static void print(const char * input);
    static void debug(const char * input);
    static void assert(bool var, const char * a_name);
};


#endif //MORSEPI_LOGGER_H

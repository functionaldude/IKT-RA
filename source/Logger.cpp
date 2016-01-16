//
// Created by Zoltán Sasvári on 16.01.16.
//

#include "Logger.h"
#include "uart.h"

void Logger::print(const char *input) {
    //TODO: optimize
    puts("LOG: ");
    puts(input);
    putc('\n');
}

//
// Created by Zoltán Sasvári on 16.01.16.
//

#include "Logger.h"
extern "C" {
    #include "uart.h"
}

void Logger::print(const char *input) {
    //TODO: optimize
    uart_puts("LOG: ");
    uart_puts(input);
    uart_putc('\n');
}

void Logger::init() {
    uart_init();
    uart_putc('\n');
}

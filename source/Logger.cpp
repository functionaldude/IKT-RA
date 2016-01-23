//
// Created by Zoltán Sasvári on 16.01.16.
//

#include "Logger.h"
extern "C" {
    #include "uart.h"
}

void Logger::print(const char *input) {
    uart_puts(input);
}


void Logger::init() {
    uart_init();
    uart_putc('\n');
}

void Logger::debug(const char *input) {
    uart_puts("DEBUG: ");
    uart_puts(input);
    uart_putc('\n');
}

void Logger::assert(bool var, const char *a_name) {
    if (!var){
        uart_puts("ASSERTION at ");
        uart_puts(a_name);
        uart_putc('\n');
    }
}

void Logger::putc(char input) {
    uart_putc(input);
}

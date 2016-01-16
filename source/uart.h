//
// Created by Zoltán Sasvári on 16.01.16.
//

#ifndef MORSEPI_UART_H
#define MORSEPI_UART_H

#include <stddef.h>
#include <stdint.h>

/*
* Initialize UART0.
*/
void uart_init(void);

/*
* Transmit a byte via UART0.
* uint8_t Byte: byte to send.
*/
void putc(uint8_t byte);

/*
* Receive a byte via UART0.
*
* Returns:
* uint8_t: byte received.
*/
uint8_t getc(void);

/*
* print a string to the UART one character at a time
* const char *str: 0-terminated string
*/
void puts(const char *str);

#endif //MORSEPI_UART_H

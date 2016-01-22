//
// Created by mate on 1/16/16.
//

#ifndef MORSEPI_SPI_H
#define MORSEPI_SPI_H


void spi_pin_init(void);
void spi_begin(void);
unsigned char spi_transfer(unsigned char value);
void spi_end(void);

#endif //MORSEPI_SPI_H


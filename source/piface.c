//
// Created by mate on 1/19/16.
//

#include "piface.h"
#include "spi.h"

void piface_Init(void){

    spi_pin_init();

    //configure for byte mode
    spi_begin();
    spi_transfer(PIFACE_STARTW);
    spi_transfer(PIFACE_IOCON);
    spi_transfer(PIFACE_BYTEMODE);
    spi_end();

    //clear everything
    spi_begin();
    spi_transfer(PIFACE_STARTW);
    spi_transfer(PIFACE_GPIOA);
    spi_transfer(0x00);
    spi_end();
    spi_begin();
    spi_transfer(PIFACE_STARTW);
    spi_transfer(PIFACE_GPIOB);
    spi_transfer(0x00);
    spi_end();

    //set A as output
    spi_begin();
    spi_transfer(PIFACE_STARTW);
    spi_transfer(PIFACE_IODIRA);
    spi_transfer(0x00);
    spi_end();

    //enable pull-up for B
    spi_begin();
    spi_transfer(PIFACE_STARTW);
    spi_transfer(PIFACE_GPPUB);
    spi_transfer(0xFF);
    spi_end();

    //reverse polarity for B
    spi_begin();
    spi_transfer(PIFACE_STARTW);
    spi_transfer(PIFACE_IPOLB);
    spi_transfer(0xFF);
    spi_end();

}

unsigned char piface_Read(unsigned char reg){
    spi_begin();
    spi_transfer(PIFACE_STARTR);
    spi_transfer(reg);
    unsigned char rx = spi_transfer(0x00);
    spi_end();
    return rx;
}

void piface_Write(unsigned char reg, unsigned char msg){
    spi_begin();
    spi_transfer(PIFACE_STARTW);
    spi_transfer(reg);
    spi_transfer(msg);
    spi_end();
}

void piface_SetAsOutput(piface_pin pin){
    unsigned char rx = piface_Read(PIFACE_IODIRA);
    piface_Write(PIFACE_IODIRA,rx&!(1<<pin));
}

void piface_SetAsInput(piface_pin pin){
    unsigned char rx = piface_Read(PIFACE_IODIRA);
    piface_Write(PIFACE_IODIRA,rx|(1<<pin));
}

void piface_SetON(piface_pin pin){
    unsigned char rx = piface_Read(PIFACE_GPIOA);
    piface_Write(PIFACE_GPIOA,rx|(1<<pin));
}

void piface_SetOFF(piface_pin pin){
    unsigned char rx = piface_Read(PIFACE_GPIOA);
    piface_Write(PIFACE_GPIOA,rx&!(1<<pin));
}

unsigned char piface_ReadPin(piface_pin pin){
    unsigned char rx = piface_Read(PIFACE_GPIOB);
    if (rx&(1<<pin))
        return 1;
    else
        return 0;
}
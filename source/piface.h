//
// Created by mate on 1/19/16.
// Will be used to control the GPIOA (Open Collector) pins of the PiFace.
//

#ifndef MORSEPI_PIFACE_H
#define MORSEPI_PIFACE_H


// Start Config Sequence
#define PIFACE_STARTW 0x40 //0100 000(no hardware addressing enabled) 0 -write
#define PIFACE_STARTR 0x41 //0100 000 1-read
#define PIFACE_BYTEMODE 0x30 //00 1-SEQOP disable 1-slew rate disabled 0000

// Register Addresses
#define PIFACE_IOCON 0x0A //IO config register - only needed for init(?)

#define PIFACE_IODIRA 0x00 //IO Direction
#define PIFACE_IPOLA 0x02 //Polarisation
#define PIFACE_GPPUA 0x0C //Pull-Up
#define PIFACE_GPIOA 0x12 //GPIO A (output) Set
#define PIFACE_OLATA 0x14 //Output latch

#define PIFACE_IODIRB 0x01 //IO Direction
#define PIFACE_IPOLB 0x03 //Polarisation
#define PIFACE_GPPUB 0x0D //Pull-Up
#define PIFACE_GPIOB 0x13 //GPIO A (output) Set
#define PIFACE_OLATB 0x15 //Output latch


//Pin Listing
typedef enum{
    PIFACE_PIN0 = 0,
    PIFACE_PIN1 = 1,
    PIFACE_PIN2,
    PIFACE_PIN3,
    PIFACE_PIN4,
    PIFACE_PIN5,
    PIFACE_PIN6,
    PIFACE_PIN7
} piface_pin;


unsigned char piface_Read(unsigned char reg);
void piface_Write(unsigned char reg, unsigned char msg);
void piface_Init(void);
void piface_SetAsOutput(piface_pin pin);
void piface_SetAsInput(piface_pin pin);
void piface_SetON(piface_pin pin);
void piface_SetOFF(piface_pin pin);
unsigned char piface_ReadPin(piface_pin pin);

#endif //MORSEPI_PIFACE_H

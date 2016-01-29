//
// Created by mate on 1/16/16.
//

#include "spi.h"

/*GPIO PINS
 */
volatile unsigned int *gpioGPFSEL0 =  (unsigned int *) 0x20200000;
volatile unsigned int *gpioGPFSEL1 =  (unsigned int *) 0x20200004;
volatile unsigned int *gpioGPSET0  =  (unsigned int *) 0x2020001C;
volatile unsigned int *gpioGPCLR0  =  (unsigned int *) 0x20200028;
volatile unsigned int *gpioGPLEV0  =  (unsigned int *) 0x20200034;


/*SPI0 ADDRESS
 */
volatile unsigned int *SPI0_CONTROL =  (unsigned int *) 0x20204000;
volatile unsigned int *SPI0_FIFO    =  (unsigned int *) 0x20204004;
volatile unsigned int *SPI0_CLK     =  (unsigned int *) 0x20204008;
volatile unsigned int *SPI0_DLEN    =  (unsigned int *) 0x2020400C;
volatile unsigned int *SPI0_LTOH    =  (unsigned int *) 0x20204010;
volatile unsigned int *SPI0_DC      =  (unsigned int *) 0x20204014;


/* Bitfields in spi_C */
#define SPI_C_LEN_LONG		25
#define SPI_C_DMA_LEN		24
#define SPI_C_CSPOL2		23
#define SPI_C_CSPOL1		22
#define SPI_C_CSPOL0		21
#define SPI_C_RX		20
#define SPI_C_RXR		19
#define SPI_C_TXD		18
#define SPI_C_RXD		17
#define SPI_C_DONE		16
#define SPI_C_LEN		13
#define SPI_C_REN		12
#define SPI_C_ADCS		11
#define SPI_C_INTR		10
#define SPI_C_INTD		 9
#define SPI_C_DMAEN		 8
#define SPI_C_TA		 7
#define SPI_C_CSPOL		 6
#define SPI_C_CLEAR_RX		 5
#define SPI_C_CLEAR_TX		 4
#define SPI_C_CPOL		 3
#define SPI_C_CPHA		 2
#define SPI_C_CS1		 1
#define SPI_C_CS0		 0


void spi_pin_init(void)
{
    unsigned int var;
    //Read current value of GPFSEL1- pin 10 & 11
    var = *gpioGPFSEL1;
    var &=~((7<<0) | (7<<3)); // set as input pins GPIO = 000
    var |= ((4<<0) | (4<<3)); // set to alt function ALT0, GPIO = 000
    //Write back updated value
    *gpioGPFSEL1 =var;

    // Read current value of GPFSEL1- pin 7,8 & 9
    var = *gpioGPFSEL0;
    var &=~((7<<21) | (7<<24) | (7<<27)); // set as input pins GPIO = 000
    var |= ((4<<21) | (4<<24) | (4<<27)); // set to alt function ALT0, GPIO = 000
    //Write back updated value
    *gpioGPFSEL0 =var;
}

void spi_begin(void)
{
    unsigned int var;

    *SPI0_CONTROL = 1 << 18; //default

    var = *SPI0_CONTROL;

    // Clear TX and RX fifos
    var |= (1 << SPI_C_CLEAR_RX) | (1 << SPI_C_CLEAR_TX);

    // set data mode = 0
    var &= ~((1 << SPI_C_CPOL) | (1 << SPI_C_CPHA));

    //set to CS0 and Chip Select Polarity=LOW
    var &= ~((1 << SPI_C_CS0) | (1 << SPI_C_CS1));
    var &= ~(1 << SPI_C_CSPOL0);

    /* Write back updated value */
    *SPI0_CONTROL = var;
    //set clock
    *SPI0_CLK = 16;

    // Set TA = 1
    var|= (1 << SPI_C_TA);
    /* Write back updated value */
    *SPI0_CONTROL =var;

}
unsigned char spi_transfer(unsigned char value)
{
    unsigned int var = 0;
    unsigned char ret = 0;

    // Wait for TXD
    while (!(var & (1 << SPI_C_TXD))) {
        var = *SPI0_CONTROL;
    }

    // Write to TX FIFO
    *SPI0_FIFO = value;

    var = *SPI0_CONTROL;
    // Wait for RXD
    while (!(var & (1 << SPI_C_RXD))) {
        var = *SPI0_CONTROL;
    }

    // Read RX FIFO
    ret = *SPI0_FIFO;
    // Clear RX FIFO
    var |= (1 << SPI_C_CLEAR_RX);
    *SPI0_CONTROL = var;

    return ret;

}
void spi_end(void)
{
    unsigned int var;
    var = *SPI0_CONTROL;
    // Wait for DONE to be set
    while (!(var & (1 << SPI_C_DONE))){
        var = *SPI0_CONTROL;
    }
    // Set TA = 0,
    var = *SPI0_CONTROL;
    var &= ~(1 << SPI_C_TA);
    /* Write back updated value */
    *SPI0_CONTROL =var;
}
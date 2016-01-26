//
// Created by Zoltán Sasvári on 18.01.16.
//

#include "UI.h"
#include "Logger.h"
#include "helper.h"
#include "MorseHandler.h"

extern "C"{
#include "uart.h"
#include "piface.h"
#include "delay.h"
}

char UI::msg[BUFFER];
char UI::cmd[BUFFER];

uint8_t UI::received;


int strcmp(const char *str1, const char *str2)
{
    int s1;
    int s2;
    do {
        s1 = *str1++;
        s2 = *str2++;
        if (s1 == 0)
            break;
    } while (s1 == s2);
    return (s1 < s2) ? -1 : (s1 > s2);
}

void *memset(void *s, int c, size_t n)
{
    unsigned char* p= (unsigned char*)s;
    while(n--)
        *p++ = (unsigned char)c;
    return s;
}

void UI::getUserInput(char *out) {

    memset(out, 0x00, BUFFER);
    uint16_t size = 0;

    while ((out[(size)++] = uart_getc()) != '\n' ){
        uart_putc((uint8_t) out[(size)-1]);
    }
    out[(size)-1] = 0x00; //remove last linebreak

    uart_putc('\n');
}

void UI::send() {
    for (uint16_t ctn = 0; msg[ctn] != 0x00; ++ctn){
        if ('a' <= msg[ctn] && msg[ctn] <= 'z') msg[ctn] = msg[ctn] - 'a' + 'A';
    }
    Logger::print("Sending message, please wait\n");
    MorseHandler::morse_puts(msg);
    Logger::print("Message successfully sent\n");
}

void UI::receive() {
    memset(msg, 0x00, BUFFER);
    uint16_t ctn = 0;
    while ((msg[ctn++] = MorseHandler::morse_getc()) != '\0');

    if (msg[0] != 0x00) received = 1;

    Logger::print(msg);
    Logger::putc('\n');
}

void UI::start() {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (1){
        Logger::print("MorsePi > ");
        getUserInput(cmd);

        if (strcmp(cmd, "send") == 0){
            Logger::print("Please input your message and press ENTER.\n");
            getUserInput(msg);
            send();
        }
        if (strcmp(cmd, "receive") == 0){
            Logger::print("Waiting for message\n");
            receive();
            if (received == 0){
                Logger::print("Timeout\n");
            } else {
                Logger::print("Message received\n");
            }
        }
        if (strcmp(cmd, "knightrider") == 0){
            uint8_t ctn = 10;
            while (ctn--){
                startKnightRider();
            }
        }
    }
#pragma clang diagnostic pop
}

void UI::startKnightRider()
{
#define WAIT_DELAY 0x1F0000
    piface_Write(PIFACE_IODIRA, 0x00);

    piface_SetON(PIFACE_PIN0);
    delay(WAIT_DELAY/8);
    piface_SetOFF(PIFACE_PIN0);
    piface_SetON(PIFACE_PIN1);
    delay(WAIT_DELAY/8);
    piface_SetOFF(PIFACE_PIN1);
    piface_SetON(PIFACE_PIN2);
    delay(WAIT_DELAY/8);
    piface_SetOFF(PIFACE_PIN2);
    piface_SetON(PIFACE_PIN3);
    delay(WAIT_DELAY/8);
    piface_SetOFF(PIFACE_PIN3);
    piface_SetON(PIFACE_PIN4);
    delay(WAIT_DELAY/8);
    piface_SetOFF(PIFACE_PIN4);
    piface_SetON(PIFACE_PIN5);
    delay(WAIT_DELAY/8);
    piface_SetOFF(PIFACE_PIN5);
    piface_SetON(PIFACE_PIN6);
    delay(WAIT_DELAY/8);
    piface_SetOFF(PIFACE_PIN6);
    piface_SetON(PIFACE_PIN7);
    delay(WAIT_DELAY/8);
    piface_SetOFF(PIFACE_PIN7);
    piface_SetON(PIFACE_PIN6);
    delay(WAIT_DELAY/8);
    piface_SetOFF(PIFACE_PIN6);
    piface_SetON(PIFACE_PIN5);
    delay(WAIT_DELAY/8);
    piface_SetOFF(PIFACE_PIN5);
    piface_SetON(PIFACE_PIN4);
    delay(WAIT_DELAY/8);
    piface_SetOFF(PIFACE_PIN4);
    piface_SetON(PIFACE_PIN3);
    delay(WAIT_DELAY/8);
    piface_SetOFF(PIFACE_PIN3);
    piface_SetON(PIFACE_PIN2);
    delay(WAIT_DELAY/8);
    piface_SetOFF(PIFACE_PIN2);
    piface_SetON(PIFACE_PIN1);
    delay(WAIT_DELAY/8);
    piface_SetOFF(PIFACE_PIN1);

    piface_Write(PIFACE_IODIRA, 0x01);

#undef WAIT_DELAY
}
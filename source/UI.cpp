//
// Created by Zoltán Sasvári on 18.01.16.
//

#include "UI.h"
#include "Logger.h"
#include "helper.h"
#include "MorseHandler.h"

extern "C"{
#include "uart.h"
}

char UI::msg[BUFFER];
char UI::cmd[BUFFER];

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
    Logger::print("Sending message, please wait\n");
    MorseHandler::morse_puts(msg);
    Logger::print("Message successfully sent\n");
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

        }
    }
#pragma clang diagnostic pop
}
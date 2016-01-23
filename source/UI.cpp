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

char UI::msg[1024];
uint16_t UI::msg_size = 0;

void UI::getUserInput() {

    while (msg[0] != 0){
        msg[--msg_size] = 0;
    }

    Logger::assert(msg_size == 0, "msg_size != 0");

    Logger::print("Please input your message and press ENTER.\n");
    while ((msg[msg_size++] = uart_getc()) != '\n');
    Logger::debug(msg);
}


void UI::send() {
    Logger::print("Sending message, please wait\n");
    MorseHandler::morse_puts(msg);
    Logger::print("Message successfully sent\n");
}
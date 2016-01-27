cmake_minimum_required(VERSION 3.3)
project(MorsePi)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        source/main.cpp
        source/init.s
        source/uart.c
        source/uart.h
        source/mmio.h
        source/delay.h
        source/delay.c
        source/Logger.cpp
        source/Logger.h
        source/MorseHandler.cpp
        source/MorseHandler.h
        source/UI.cpp
        source/UI.h
        source/spi.h
        source/spi.c
        source/piface.h
        source/piface.c)

add_executable(MorsePi ${SOURCE_FILES})
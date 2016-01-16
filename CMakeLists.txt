cmake_minimum_required(VERSION 3.3)
project(MorsePi)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        source/main.cpp
        source/testcases.cpp
        source/testcases.h
        source/helper.cpp
        source/helper.h
        source/BCM2835.h
        source/gpio.c
        source/gpio.h
        source/init.s
        source/uart.c source/uart.h source/mmio.h source/delay.h source/delay.c source/Logger.cpp source/Logger.h)

add_executable(MorsePi ${SOURCE_FILES})
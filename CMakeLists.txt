cmake_minimum_required(VERSION 3.3)
project(MorsePi)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        source/main.cpp
        source/testcases.cpp
        source/testcases.h
        source/timer.h
        source/helper.cpp
        source/helper.h
        source/BCM2835.h
        source/gpio.c
        source/gpio.h
        source/init.s)

add_executable(MorsePi ${SOURCE_FILES})
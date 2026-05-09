cmake_minimum_required(VERSION 3.22)

set(PICO_SDK_PATH $ENV{PICO_SDK_PATH})

include(${PICO_SDK_PATH}/pico_sdk_init.cmake)

project(mug_heater C CXX ASM)

pico_sdk_init()

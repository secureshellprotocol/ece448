cmake_minimum_required(VERSION 3.22)

set(PICO_SDK_PATH $ENV{PICO_SDK_PATH})

set(PICO_BOARD pico2)
set(TARGET_NAME power-pwm)

set(SRC ${CMAKE_CURRENT_SOURCE_DIR}/src)

include(${PICO_SDK_PATH}/pico_sdk_init.cmake)

project(mug_heater C CXX ASM)

pico_sdk_init()

add_executable(${TARGET_NAME}
    ${SRC}/main.c
)

target_link_libraries(${TARGET_NAME}
    pico_stdlib
    hardware_gpio
)

pico_enable_stdio_uart(${TARGET_NAME} 1)
pico_add_extra_outputs(${TARGET_NAME})

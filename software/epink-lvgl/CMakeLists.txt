cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(xenia_clock)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# add include and src files
file(GLOB_RECURSE INCLUDES "include/*.h"
                            "port/*.h"
                            "ui/*.h"
                            "net/*.h"
                            "drivers/video/*.h"
                            "drivers/sensors/*.h"
                            "drivers/i2c/*.h"
                            "drivers/clk/*.h"
                            "drivers/spi/*.h"
                            "drivers/power/*.h"
                            "drivers/input/*.h"
                            "drivers/rtc/*.h")

file(GLOB_RECURSE SOURCES "lvgl/src/*.c"
                            "font/*.c"
                            "port/*.c"
                            "ui/*.c"
                            "net/*.c"
                            "drivers/video/*.c"
                            "drivers/sensors/*.c"
                            "drivers/i2c/*.c"
                            "drivers/clk/*.c"
                            "drivers/spi/*.c"
                            "drivers/power/*.c"
                            "drivers/input/*.c"
                            "drivers/rtc/*.c")

# rest of your project
add_executable(xenia_clock main.c ${INCLUDES} ${SOURCES})

target_include_directories(xenia_clock PUBLIC . "include" "lvgl")
target_link_libraries(xenia_clock pico_stdlib
                            hardware_clocks
                            hardware_spi
                            hardware_rtc
                            hardware_i2c
                            hardware_uart)

pico_enable_stdio_usb(xenia_clock 1)
pico_enable_stdio_uart(xenia_clock 1)

pico_add_extra_outputs(xenia_clock)

# build the index html page first
add_custom_target(
    build_index ALL
    COMMAND ${PYTHON_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/net/html2doth.py
        ${CMAKE_CURRENT_SOURCE_DIR}/net/index.html
        ${CMAKE_CURRENT_SOURCE_DIR}/net/index.h

    BYPRODUCTS ${CMAKE_CURRENT_SOURCE_DIR}/net/index.h
    COMMENT "Generating index.h"
)
add_dependencies(xenia_clock build_index)

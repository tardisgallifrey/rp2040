cmake_minimum_required(VERSION 3.13)

#initialize the SDK based on PICO_SDK_PATH
#this must happen before project()
include(../pico_sdk_import.cmake)

project(oledi2c)

#initialize the Raspberry Pi Pico SDK
pico_sdk_init()

#rest of your project
include_directories(include ../dave_include)
file(GLOB SOURCES "./*.c")
add_executable(oledi2c ${SOURCES})

#Add pico_stdlib library which aggregates commonly used features
target_link_libraries(oledi2c pico_stdlib hardware_i2c)

# enable usb output, disable uart output
pico_enable_stdio_usb(oledi2c 1)

#create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(oledi2c)

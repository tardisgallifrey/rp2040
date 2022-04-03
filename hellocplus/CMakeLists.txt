cmake_minimum_required(VERSION 3.13)

#initialize the SDK based on PICO_SDK_PATH
#this must happen before project()
include(../pico_sdk_import.cmake)

project(hellocplus)

#initialize the Raspberry Pi Pico SDK
pico_sdk_init()

#rest of your project
include_directories(include)
file(GLOB SOURCES "./*.cpp")
add_executable(hellocplus ${SOURCES})

#Add pico_stdlib library which aggregates commonly used features
target_link_libraries(hellocplus pico_stdlib)

# enable usb output, disable uart output
pico_enable_stdio_usb(hellocplus 1)

#create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(hellocplus)

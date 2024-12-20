# Set minimum required CMake version and include the Pico SDK
cmake_minimum_required(VERSION 3.12)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Pull in Pico SDK (must be before project)
message(STATUS "PICO_SDK_PATH: $ENV{PICO_SDK_PATH}")
include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)
# Set the project name
project(prj CXX C)
set(CMAKE_CXX_STANDARD 17)

# Initialize the Pico SDK
pico_sdk_init()

add_executable(shift_register_example
    shift_register_leds.cpp
)

# Enable USB and UART output (optional, for debugging)
pico_enable_stdio_usb(shift_register_example 1)  # Enable USB stdout
pico_enable_stdio_uart(shift_register_example 0) # Disable UART stdout

target_compile_features(shift_register_example PUBLIC cxx_std_20)


target_link_libraries(shift_register_example
    PRIVATE
        pico_stdlib
)
pico_add_extra_outputs(shift_register_example)



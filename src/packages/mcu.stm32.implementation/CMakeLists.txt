cmake_minimum_required(VERSION 3.14)

project(libMcuStm32Implementation)

add_library(mcuStm32Implementation
		src/led_signal.cpp)

target_include_directories(mcuStm32Implementation PRIVATE ../mcu.abstractions/include)
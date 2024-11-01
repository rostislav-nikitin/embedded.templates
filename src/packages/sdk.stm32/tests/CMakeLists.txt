cmake_minimum_required(VERSION 3.14)

project(CppProject)

set(CXX_STANDARD 17)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu11 -Wall -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -O0")


# TESTS
add_executable(test_runner_bit_opertions
		test_runner_bit_operations.cpp)

add_executable(test_runner_peripheral_rcc
		../src/device_clock_config_t.cpp
		../src/peripherals/rcc.cpp
		../src/stm32g0b1re/device_clock_configs.cpp
		test_runner_peripheral_rcc.cpp)

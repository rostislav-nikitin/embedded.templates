cmake_minimum_required(VERSION 3.14)

project(CppProject)

set(CXX_STANDARD 17)
set(MACH "cortex-m0")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mcpu=${MACH} -mthumb -mfloat-abi=soft -std=gnu11 -Wall -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mcpu=${MACH} -mthumb -mfloat-abi=soft -std=c++17 -Wall -O0 -fno-stack-protector -fno-exceptions")


# NOLIB
add_executable(firmware.elf
		stm32g0_isr_vector.c
		stm32g0_startup.cpp
		syscalls_pure.c
		main.cpp)
target_link_options(firmware.elf PUBLIC -nostdlib -T stm32g0b1_ls.ld -Wl,-Map=firmware.map)

# LIBC NANO
add_executable(firmware_libc_nano.elf
		stm32g0_isr_vector.c
		stm32g0_startup.cpp
		syscalls.c
		main.cpp)
target_link_options(firmware_libc_nano.elf PUBLIC -mcpu=${MACH} -mthumb -mfloat-abi=soft --specs=nano.specs  -T stm32g0b1_ls.ld -Wl,-Map=firmware_libc_nano.map)

#LIBC NANO SEMIHOSTING
add_executable(firmware_libc_nano_sh.elf
		stm32g0_isr_vector.c
		stm32g0_startup.cpp
		main.cpp)
target_link_options(firmware_libc_nano_sh.elf PUBLIC -mcpu=${MACH} -mthumb -mfloat-abi=soft --specs=rdimon.specs  -T stm32g0b1_ls.ld -Wl,-Map=firmware_libc_nano_sh.map)

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/stm32g0b1_ls.ld" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/stm32g0b1.memory" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

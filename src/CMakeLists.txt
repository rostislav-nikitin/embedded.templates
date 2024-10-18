cmake_minimum_required(VERSION 3.14)

project(TemplateApp)

# Copy files
add_custom_target(mcu_ls_ld_link_target ALL COMMAND ${CMAKE_COMMAND} -E create_symlink "${CMAKE_CURRENT_SOURCE_DIR}/mcu_ls.ld" "${CMAKE_CURRENT_BINARY_DIR}/mcu_ls.ld")
add_custom_target(mcu_memory_link_target ALL COMMAND ${CMAKE_COMMAND} -E create_symlink "${CMAKE_CURRENT_SOURCE_DIR}/mcu.memory" "${CMAKE_CURRENT_BINARY_DIR}/mcu.memory")
#file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/mcu_ls.ld" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
#file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/mcu.memory" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

# Set C/C++ compilators flags
set(CXX_STANDARD 20)
set(MACH "cortex-m0")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mcpu=${MACH} -mthumb -mfloat-abi=soft -std=gnu11 -Wall -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mcpu=${MACH} -mthumb -mfloat-abi=soft -std=c++17 -Wall -O0 -fno-stack-protector -fno-exceptions -fno-rtti")

# Add subprojects(libraries)
add_subdirectory(packages/mcu.stm32.implementation)


# NO STDLIB
add_executable(firmware.elf
		mcu_isr_vector.c
		mcu_startup.cpp
		syscalls_pure.c
		globals.cpp
		src/app.cpp
		src/app_builder.cpp
		startup.cpp)

target_link_options(firmware.elf PUBLIC -nostdlib -T mcu_ls.ld -Wl,-Map=firmware.map)

target_include_directories(firmware.elf PRIVATE packages/mcu.abstractions/include)
target_include_directories(firmware.elf PRIVATE packages/mcu.stm32.implementation/include)
target_include_directories(firmware.elf PRIVATE packages/mcu.stm32/include)

target_link_libraries(firmware.elf mcuStm32Implementation)


# LIBC NANO
add_executable(firmware_libc_nano.elf
		mcu_isr_vector.c
		mcu_startup.cpp
		syscalls.c
		src/app.cpp
		src/app_builder.cpp
		startup.cpp)
target_link_options(firmware_libc_nano.elf PUBLIC -mcpu=${MACH} -mthumb -mfloat-abi=soft --specs=nano.specs  -T mcu_ls.ld -Wl,-Map=firmware_libc_nano.map)

target_include_directories(firmware_libc_nano.elf PRIVATE packages/mcu.abstractions/include)
target_include_directories(firmware_libc_nano.elf PRIVATE packages/mcu.stm32.implementation/include)
target_include_directories(firmware_libc_nano.elf PRIVATE packages/mcu.stm32/include)

target_link_libraries(firmware_libc_nano.elf mcuStm32Implementation)

#LIBC NANO SEMIHOSTING
add_executable(firmware_libc_nano_sh.elf
		mcu_isr_vector.c
		mcu_startup.cpp
		src/app.cpp
		src/app_builder.cpp
		startup.cpp)
target_link_options(firmware_libc_nano_sh.elf PUBLIC -mcpu=${MACH} -mthumb -mfloat-abi=soft --specs=rdimon.specs  -T mcu_ls.ld -Wl,-Map=firmware_libc_nano_sh.map)

target_include_directories(firmware_libc_nano_sh.elf PRIVATE packages/mcu.abstractions/include)
target_include_directories(firmware_libc_nano_sh.elf PRIVATE packages/mcu.stm32.implementation/include)
target_include_directories(firmware_libc_nano_sh.elf PRIVATE packages/mcu.stm32/include)

target_link_libraries(firmware_libc_nano_sh.elf mcuStm32Implementation)

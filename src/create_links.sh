#! /bin/bash

ln -s packages/sdk.stm32/mcu-toolchain.cmake mcu-toolchain.cmake
ln -s packages/sdk.stm32/syscalls.c syscalls.c
ln -s packages/sdk.stm32/syscalls_pure.c syscalls_pure.c
ln -s packages/sdk.stm32/stm32g0b1_ls.ld mcu_ls.ld
ln -s packages/sdk.stm32/mcu.memory mcu.memory  
ln -s packages/sdk.stm32/stm32g0_isr_vector.c mcu_isr_vector.c
ln -s packages/sdk.stm32/stm32g0_startup.cpp mcu_startup.cpp
		
ln -s packages/sdk.stm32/build.sh build.sh
ln -s packages/sdk.stm32/burn.sh burn.sh
ln -s packages/sdk.stm32/burn_libc_nano.sh burn_libc_nano.sh
ln -s packages/sdk.stm32/burn_libc_nano_sh.sh burn_libc_nano_sh.sh

ln -s packages/sdk.stm32/debug_server.sh debug_server.sh
ln -s packages/sdk.stm32/debug_client.sh debug_client.sh

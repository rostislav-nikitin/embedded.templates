#! /bin/bash

echo arm-none-eabi-gdb
echo target remote localhost:3333
echo monitor arm semihosting enable
echo monitor reset halt
echo monitor flash write_image erase firmware.elf
echo monitor bp
echo monitor bp 0x08000136 2 hw
echo monitor rbp all
echo monitor next

openocd -f board/st_nucleo_g0.cfg

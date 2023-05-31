make clean && make && arm-none-eabi-objdump -S -j .text firmware.elf | head -n 40 && arm-none-eabi-objdump -s -j .isr_vector firmware.elf

make clean && make all && arm-none-eabi-objdump -S -j .text firmware.elf | head -n 30 && arm-none-eabi-objdump -s -j .isr_vector firmware.elf

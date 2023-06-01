make clean && make all_semih && arm-none-eabi-objdump -S -j .text firmware_semih.elf | head -n 30 && arm-none-eabi-objdump -s -j .isr_vector firmware_semih.elf

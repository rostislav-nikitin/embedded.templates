CC := arm-none-eabi-gcc
LD := arm-none-eabi-gcc
CXX := arm-none-eabi-g++
MACH := cortex-m0
CFLAGS := -c -mcpu=$(MACH) -mthumb -mfloat-abi=soft -std=gnu11 -Wall -O0 
CXXFLAGS := -c -mcpu=$(MACH) -mthumb -mfloat-abi=soft -std=c++17 -Wall -O0 -fno-stack-protector -fno-exceptions
LDFLAGS := -nostdlib -T stm32g0b1_ls.ld -Wl,-Map=firmware.map
LDFLAGS_NANO_LIBC := -z muldefs -mcpu=$(MACH) -mthumb  -mfloat-abi=soft --specs=nano.specs -T stm32g0b1_ls.ld -Wl,-Map=firmware.map
LDFLAGS_NANO_LIBC_SH := -z muldefs -mcpu=$(MACH) -mthumb  -mfloat-abi=soft --specs=rdimon.specs -T stm32g0b1_ls.ld -Wl,-Map=firmware.map
# -ffreestanding
#-nostartfiles

#all:firmware.elf
all:firmware_libc_nano.elf
#all:firmware_libc_nano_sh.elf

firmware.elf:stm32g0_isr_vector.o stm32g0_startup.o main.o
	$(CC) $(LDFLAGS) -o $@ $^

firmware_libc_nano.elf:stm32g0_isr_vector.o stm32g0_startup.o main.o syscalls.o
	$(CC) $(LDFLAGS_NANO_LIBC) -o $@ $^

firmware_libc_nano_sh.elf:stm32g0_isr_vector.o stm32g0_startup.o main.o
	$(LD) $(LDFLAGS_NANO_LIBC_SH) -o $@ $^

main.o:main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

stm32g0_startup.o:stm32g0_startup.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

isr_vector.o:stm32g0_isr_vector.c
	$(CC) $(CFLAGS) -o $@ $^

syscalls.o:syscalls.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o *.elf *.map
	
debug:
	openocd -f board/st_nucleo_g0.cfg
	echo arm-none-eabi-gdb
	echo target remote localhost:3333
	echo monitor arm semihosting enable
	echo monitor reset halt
	echo monitor flash write_image erase firmware.elf
	echo monitor bp
	echo monitor bp 0x08000136 2 hw
	echo monitor rbp all
	echo monitor next

burn:
	openocd -f board/st_nucleo_g0.cfg -c "init;targets;halt;flash write_image erase firmware.elf;shutdown"

burn_sh:
	openocd -f board/st_nucleo_g0.cfg -c "init;targets;halt;flash write_image erase firmware_libc_nano_sh.elf;shutdown"

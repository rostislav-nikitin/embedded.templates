CPPCC=arm-none-eabi-g++
CCC=arm-none-eabi-gcc
LD=arm-none-eabi-ld
ASCC=arm-none-eabi-as

ASFLAGS=-mthumb -mcpu=cortex-m4 -mfloat-abi=hard -c
CFLAGS=-O0 -fno-stack-protector -mcpu=cortex-m4 -mfloat-abi=hard -mthumb -fno-exceptions -specs=nano.specs -specs=nosys.specs -std=gnu11 -c 
CPPFLAGS=-O0 -fno-stack-protector -mcpu=cortex-m4 -mfloat-abi=hard -mthumb -fno-exceptions -specs=nano.specs -specs=nosys.specs -std=c++11 -c 
CPPINCLUDE=-I./include -I/home/ros/.local/arm-gnu-toolchain-12.2/arm-none-eabi/include
CINCLUDE=-I./include -I/home/ros/.local/arm-gnu-toolchain-12.2/arm-none-eabi/include
LDLIBPATH=-L/home/ros/.local/arm-gnu-toolchain-12.2/arm-none-eabi/lib -L./lib
LDLIB=
#LDLIB=-lc_nano -lm
LDFLAGS= -T qemuboot.ld  -z noexecstack -nostdlib -Map=map.txt

all: firmware.elf
	arm-none-eabi-objcopy -O binary firmware.elf firmware.bin

#firmware.elf: stm32f4xx_isr.o init.o main.o arm32_aeabi_divmod.o arm32_aeabi_divmod_a32.o
firmware.elf: stm32f4xx_isr.o init.o main.o
	$(LD) $(LDFLAGS) $(LDLIBPATH) $^ $(LDLIB) -o $@

arm32_aeabi_divmod.o:arm32_aeabi_divmod.c
	$(CCC) $(CFLAGS) $(CINCLUDE) $^ -o $@
	
main.o: main.cpp
	$(CPPCC) $(CPPFLAGS) $(CPPINCLUDE) $^ -o $@

arm32_aeabi_divmod_a32.o: arm32_aeabi_divmod_a32.S
	$(CCC) $(CFLAGS) $(CINCLUDE) $^ -o $@

#startup.o: startup.s
#	$(ASCC) $(ASFLAGS) $^ -o $@

stm32f4xx_isr.o: stm32f4xx_isr.c
	$(CCC) $(CFLAGS) $^ -o $@

init.o: init.cpp
	$(CPPCC) $(CPPFLAGS) $^ -o $@

clean:
	(rm -f *.o)
	(rm -f *.elf)
	(rm -f *.bin)


#run:
#	qemu-system-arm -M stm32vldiscovery -kernel firmware.bin
#	#qemu-system-arm -M versatilepb -nographic -kernel firmware.bin

#run-debug:
#	qemu-system-arm -s -S -M stm32vldiscovery -nographic -kernel firmware.bin
#	#qemu-system-arm -s -S -M versatilepb -nographic -kernel firmware.bin

#debug:
#	arm-none-eabi-gdb --eval-command="target remote localhost:1234"

openocd:
	openocd -f board/stm32f4discovery.cfg

flash:
	arm-none-eabi-gdb --eval-command="target remote localhost:3333" --eval-command="monitor flash write_image erase firmware.elf"

debug:
	arm-none-eabi-gdb --eval-command="target remote localhost:3333"

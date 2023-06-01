CPPCC=arm-none-eabi-g++
CCC=arm-none-eabi-gcc
LD=arm-none-eabi-gcc
#LD=arm-none-eabi-ld
ASCC=arm-none-eabi-as

ASFLAGS=-mthumb -mcpu=cortex-m3 -mfloat-abi=soft
#CFLAGS=-O0 -fno-stack-protector -mcpu=cortex-m3 -mfloat-abi=softfp -mthumb -fno-exceptions -specs=nano.specs -specs=nosys.specs -std=gnu11 -c 
CFLAGS=-O0 -fno-stack-protector -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -fno-exceptions -std=gnu11 -Wall -c 
#CPPFLAGS=-O0 -fno-stack-protector -mcpu=cortex-m3 -mfloat-abi=softfp -mthumb -fno-exceptions -specs=nano.specs -specs=nosys.specs -std=c++11 -c 
CPPFLAGS=-O0 -fno-stack-protector -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -fno-exceptions -std=c++11 -c 
CPPINCLUDE=
#CPPINCLUDE=-I./include -I/home/ros/.local/arm-gnu-toolchain-12.2/arm-none-eabi/include
CINCLUDE=
#CINCLUDE=-I./include -I/home/ros/.local/arm-gnu-toolchain-12.2/arm-none-eabi/include
LDLIBPATH=
#LDLIBPATH=-L/home/ros/.local/arm-gnu-toolchain-12.2/arm-none-eabi/lib -L./lib
LDLIB=
#LDLIB=-lc_nano -lm
LDFLAGS= -T qemuboot.ld -Wl,-Map=map.txt --specs=nano.specs -mthumb -mcpu=cortex-m3 -mfloat-abi=soft
LDFLAGS_SEMIH= -T qemuboot.ld -Wl,-Map=map.txt --specs=rdimon.specs -mthumb -mcpu=cortex-m3 -mfloat-abi=soft
#LDFLAGS= -T qemuboot.ld  -z noexecstack -nostdlib -Map=map.txt

all: firmware.elf
	arm-none-eabi-objcopy -O binary firmware.elf firmware.bin

all_semih: firmware_semih.elf
	arm-none-eabi-objcopy -O binary firmware_semih.elf firmware_semih.bin
#firmware.elf:  stm32f1xx_isr.o init.o main.o syscalls.o arm32_aeabi_divmod.o arm32_aeabi_divmod_a32.o
firmware.elf:  stm32f4xx_isr.o init_c.o init_cpp.o main.o syscalls.o
	$(LD) $(LDFLAGS) $(LDLIBPATH) $^ $(LDLIB) -o $@

firmware_semih.elf:  stm32f4xx_isr.o init_c_semih.o init_cpp.o main.o
	$(LD) $(LDFLAGS_SEMIH) $(LDLIBPATH) $^ $(LDLIB) -o $@

main.o: main.cpp
	$(CPPCC) $(CPPFLAGS) $(CPPINCLUDE) $^ -o $@

syscalls.o: syscalls.c
	$(CCC) $(CFLAGS) $^ -o $@

#arm32_aeabi_divmod.o:arm32_aeabi_divmod.c
#	$(CCC) $(CFLAGS) $(CINCLUDE) $^ -o $@
#	
#arm32_aeabi_divmod_a32.o: arm32_aeabi_divmod_a32.S
#	$(CCC) $(CFLAGS) $(CINCLUDE) $^ -o $@
#
#startup.o: startup.s
#	$(ASCC) $(ASFLAGS) $^ -o $@

stm32f1xx_isr.o: stm32f1xx_isr.c
	$(CCC) $(CFLAGS) $^ -o $@

stm32f4xx_isr.o: stm32f4xx_isr.c
	$(CCC) $(CFLAGS) $^ -o $@

init_c.o: init_c.c
	$(CCC) $(CFLAGS) $^ -o $@

init_c_semih.o: init_c.c
	$(CCC) $(CFLAGS) -DSEMIH $^ -o $@
	
init_cpp.o: init_cpp.cpp
	$(CPPCC) $(CPPFLAGS) $^ -o $@

clean:
	(rm -f *.o)
	(rm -f *.elf)
	(rm -f *.bin)
	
run:
	qemu-system-arm -M stm32vldiscovery -kernel firmware.bin
	#qemu-system-arm -M versatilepb -nographic -kernel firmware.bin

run-debug:
	qemu-system-arm -s -S -M stm32vldiscovery -kernel firmware.bin
	#qemu-system-arm -s -S -M stm32vldiscovery -nographic -kernel firmware.bin
	#qemu-system-arm -s -S -M versatilepb -nographic -kernel firmware.bin

#debug:
#	arm-none-eabi-gdb --eval-command="target remote localhost:1234"
#
#flash:
#	openocd -f board/stm32vldiscovery.cfg


openocd:
	openocd -f board/stm32f4discovery.cfg

flash:
	arm-none-eabi-gdb --eval-command="target remote localhost:3333" --eval-command="monitor flash write_image erase firmware.elf"

debug:
	arm-none-eabi-gdb --eval-command="target remote localhost:3333"

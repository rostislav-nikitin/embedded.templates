CPPCC=arm-none-eabi-g++
CCC=arm-none-eabi-gcc
LD=arm-none-eabi-ld
ASCC=arm-none-eabi-as

ASFLAGS=-c
CFLAGS=-O0 -g -fno-stack-protector -mthumb -fno-exceptions -specs=nano.specs -specs=nosys.specs -c 
CPPFLAGS=-O0 -g -fno-stack-protector -mthumb -fno-exceptions -specs=nano.specs -specs=nosys.specs -std=c++11 -c 
CPPINCLUDE=-I./include -I/home/ros/.local/arm-gnu-toolchain-12.2/arm-none-eabi/include
CINCLUDE=-I./include -I/home/ros/.local/arm-gnu-toolchain-12.2/arm-none-eabi/include
LDLIBPATH=-L/home/ros/.local/arm-gnu-toolchain-12.2/arm-none-eabi/lib -L./lib
LDLIB=-lc_nano -lm
LDFLAGS= -T qemuboot.ld  -z noexecstack

all: firmware.elf
	arm-none-eabi-objcopy -O binary firmware.elf firmware.bin

firmware.elf: startup.o init.o main.o arm32_aeabi_divmod.o arm32_aeabi_divmod_a32.o
	$(LD) $(LDFLAGS) $(LDLIBPATH) $^ $(LDLIB) -o $@

arm32_aeabi_divmod.o:arm32_aeabi_divmod.c
	$(CCC) $(CFLAGS) $(CINCLUDE) $^ -o $@
	
main.o: main.cpp
	$(CPPCC) $(CPPFLAGS) $(CPPINCLUDE) $^ -o $@

arm32_aeabi_divmod_a32.o: arm32_aeabi_divmod_a32.S
	$(CCC) $(CFLAGS) $(CINCLUDE) $^ -o $@

startup.o: startup.s
	$(ASCC) $(ASFLAGS) $^ -o $@

init.o: init.cpp
	$(CPPCC) $(CPPFLAGS) $^ -o $@

clean:
	(rm -f *.o)
	(rm -f *.elf)
	(rm -f *.bin)
	
run:
	#qemu-system-arm -M stm32vldiscovery -kernel firmware.bin
	qemu-system-arm -M versatilepb -nographic -kernel firmware.bin

run-debug:
	qemu-system-arm -s -S -M versatilepb -nographic -kernel firmware.bin

debug:
	arm-none-eabi-gdb --eval-command="target remote localhost:1234"


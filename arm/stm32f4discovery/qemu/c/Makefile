all: firmware.bin

firmware.bin: firmware.elf
	arm-none-eabi-objcopy -O binary firmware.elf firmware.bin

firmware.elf: main.o data_init.o startup.o
	arm-none-eabi-ld -T qemuboot.ld main.o data_init.o startup.o -o firmware.elf

main.o:
	arm-none-eabi-gcc -c main.c -o main.o

data_init.o:
	arm-none-eabi-gcc -c data_init.c -o data_init.o

startup.o:
	arm-none-eabi-as -c startup.s -o startup.o

clean:
	(rm -f *.o) || true
	(rm -f *.elf) || true
	(rm -f *.bin) || true

run:
	qemu-system-arm -M versatilepb -nographic -kernel firmware.bin

run-debug:
	qemu-system-arm -s -S -M versatilepb -nographic -kernel firmware.bin

debug:
	arm-none-eabi-gdb --eval-command="target remote localhost:1234"

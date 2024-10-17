ENTRY(ResetExceptionHandler)

INCLUDE stm32g0b1.memory

/*
MEMORY
{
	FLASH(rx):ORIGIN =0x08000000,LENGTH =512K
	SRAM(rwx):ORIGIN =0x20000000,LENGTH =144K
}
*/
 __max_heap_size = 0x10000;
 __max_stack_size = 0x10000;

 _min_heap_size = 0x10000;
 _min_stack_size = 0x10000;

SECTIONS
{
	.text :
	{
		*(.isr_vector)
		*(.text)
		*(.text.*)
		*(.init)
		*(.fini)
		*(.rodata)
		*(.rodata.*)
		. = ALIGN(4);
		end_of_text = .;
	}> TEXT

	data_load_address = LOADADDR(.data);

	.data :
	{
		start_of_data = .;
		*(.data)
		*(.data.*)
		
		
		*libc_a-__call_atexit.o(.init_array)
		*libc_a-__call_atexit.o(.init_array.*)

		start_of_init_array = .;
		*crtbegin.o(.init_array)
		*(.init_array)
		end_of_init_array = .;

		*crtbegin.o(.fini_array)

		. = ALIGN(4);
		end_of_data = .;
	}> DATA AT> ROM1

/*
	.init_array_libc :
	{
		*libc_a-__call_atexit.o(.init_array)
		*libc_a-__call_atexit.o(.init_array.*)
	}> SRAM1 AT> ROM1


	init_array_load_address = LOADADDR(.init_array);
	.init_array :
	{
		start_of_init_array = .;
		*crtbegin.o(.init_array)
		end_of_init_array = .;
	}> SRAM1 AT> ROM1

	.fini_array :
	{
		*crtbegin.o(.fini_array)
	}> SRAM1 AT> ROM1
*/
	.bss :
	{
		start_of_bss = .;
		__bss_start__ = .;
		*(.bss)
		*(.bss.*)
		*(COMMON)
		. = ALIGN(4);
		end_of_bss = .;
		__bss_end__ = .;
		. = ALIGN(4);
		end = .;
		__end__ = .;
	}> BSS
}

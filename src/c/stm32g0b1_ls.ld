ENTRY(ResetExceptionHandler)

MEMORY
{
	FLASH(rx):ORIGIN =0x08000000,LENGTH =512K
	SRAM(rwx):ORIGIN =0x20000000,LENGTH =144K
}

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
	}> FLASH

	data_load_address = LOADADDR(.data);

	.data :
	{
		start_of_data = .;
		*(.data)
		*(.data.*)
		. = ALIGN(4);
		end_of_data = .;
	}> SRAM AT> FLASH

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
	}> SRAM
}

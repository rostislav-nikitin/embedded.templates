INCLUDE qemuboot.memory

ENTRY(Reset_Handler)
SECTIONS
{
	.isr_vector :
	{
		*(.isr_vector)
	} > REGION_TEXT
	.init_array :
	{
		/*/home/ros/.local/arm-gnu-toolchain-12.2/bin/../lib/gcc/arm-none-eabi/12.2.1/crtbegin.o(.init_array)*/
		/home/ros/.local/arm-gnu-toolchain-12.2/bin/../lib/gcc/arm-none-eabi/12.2.1/thumb/v7-m/nofp/crtbegin.o(.init_array)
	} > REGION_TEXT
	.init_array_cpp :
	{
		init_array_start = .;
		*(.init_array)
		init_array_end = .;

	} > REGION_TEXT
	. = ALIGN(4);
	.text : 
	{
		*(.text)
		*(.text.*)
		. = ALIGN(4);
	} > REGION_TEXT
	.eh_frame : 
	{
		*(.eh_frame)
	} > REGION_TEXT
	.ARM.exidx : {
/*	    	__exidx_start = .; */
	    	*(.ARM.exidx* .gnu.linkonce.armexidx.*)
/*	    	__exidx_end = .; */
	} > REGION_DEBUG
	.ARM.attribute :
	{
		*(.ARM.attribute)
	} > REGION_DEBUG
	.ARM.attributes :
	{
		*(.ARM.attributes)
	} > REGION_DEBUG
	.note.GNU-stack :
	{
		*(.note.GNU-stack)
		*(.note.GNU-stack.*)
	} > REGION_DEBUG
	. = ALIGN(4);
	.rodata : 
	{
		*(.rodata)
		*(.rodata.*)
		. = ALIGN(4);
		rodata_end = .;
	} > REGION_RODATA
	.data : AT(rodata_end)
	{
		data_start = .;
		*(.data)
		*(.data.*)
		. = ALIGN(4);
		data_end = .;
	} > REGION_DATA
	data_size = SIZEOF(.data);
	data_load_start = LOADADDR(.data);

	.bss : AT(data_end)
	{
		bss_start = .;
		__bss_start__ = bss_start;
		*(.bss)
		*(.bss.*)
		__bss_end__ = .;
	} > REGION_BSS
	bss_size = SIZEOF(.bss);
	. = ALIGN(4);
	end = .;
	/*. = . + 0x1000;
	stack_top = .;*/

}

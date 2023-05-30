INCLUDE qemuboot.memory

ENTRY(Reset_Handler)
SECTIONS
{
	.isr_vector :
	{
		init.o(.isr_vector)
		. = ALIGN(4);
	} > REGION_TEXT
/*	.startup :
	{
		startup.o(.text)
	} > REGION_TEXT*/
	.init_array :
	{
		init_array_start = .;
		*(.init_array)
		. = ALIGN(4);
		init_array_end = .;
	} > REGION_TEXT
	.text : 
	{
		*(.text)
		*(.text.*)
		. = ALIGN(4);
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
		*(.bss)
		. = ALIGN(4);
	} > REGION_BSS
	bss_size = SIZEOF(.bss);

	. = ALIGN(4);
	/*. = . + 0x1000;
	stack_top = .;*/

}

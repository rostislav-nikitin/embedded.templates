INCLUDE qemuboot.memory

ENTRY(main)
SECTIONS
{
	.isr_vector :
	{
		init.o(.isr_vector)
	} > REGION_TEXT
	. = ALIGN(4);
/*	.startup :
	{
		startup.o(.text)
	} > REGION_TEXT*/
	.init_array :
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
	} > REGION_TEXT
	.ARM.exidx : {
/*	    __exidx_start = .; */
	    *(.ARM.exidx* .gnu.linkonce.armexidx.*)
/*	    __exidx_end = .; */
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
	.rodata : 
	{
		*(.rodata)
		*(.rodata.*)
		rodata_end = .;
	} > REGION_RODATA
	.data : AT(rodata_end)
	{
		data_start = .;
		*(.data)
		*(.data.*)
		data_end = .;
	} > REGION_DATA
	data_size = SIZEOF(.data);
	data_load_start = LOADADDR(.data);

	.bss : AT(data_end)
	{
		bss_start = .;
		*(.bss)
	} > REGION_BSS
	bss_size = SIZEOF(.bss);

	. = ALIGN(8);
	. = . + 0x1000;
	stack_top = .;

}

#include <cstring>
#include <algorithm>
#include <cstdint>

#define STACK (0x00000000U)

extern char data_start[];
extern char data_load_start[];
extern char data_size[];

extern char bss_start[];
extern char bss_size[];

typedef void(*function_type)();

extern function_type init_array_start[];
extern function_type init_array_end[];

void Default_Handler(void);

void ResetHandler(void) __attribute__((weak, alias("Default_Handler")));

uint32_t __attribute__ ((section(".isr_vector"))) isr_vector[32] =
{
	STACK,
	(uint32_t)&ResetHandler
};

void Default_Handler(void)
{
}

void copy_data(void);
void clear_bss(void);
void call_static_ctors(void);


extern "C" void init(void)
{
	copy_data();
	clear_bss();
	call_static_ctors();
}

void copy_data(void)
{
	for(int i = 0; i < (size_t)data_size; i++)
	{
		data_start[i] = data_load_start[i];
	}
}

void clear_bss(void)
{
	for(int i = 0; i < (size_t)bss_size; i++)
	{
		bss_start[i] = 0;
	}
}

void call_static_ctors(void)
{
	for(function_type fn = init_array_start[0]; fn < init_array_end[0]; fn++)
	{
		fn();
	}
	
	//(*fn)();
/*	std::for_each(init_array_start,
			init_array_end,
			[](const function_type pf)
			{
				pf();
			});
*/			
}


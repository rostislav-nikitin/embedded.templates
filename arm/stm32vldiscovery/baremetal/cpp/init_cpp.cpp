#include <cstddef>
#include <cstdint>

extern char data_start[];
extern char data_load_start[];
extern char data_size[];

extern char bss_start[];
extern char bss_size[];

typedef void(*function_type)();

extern function_type init_array_start[];
extern function_type init_array_end[];

int main(void);
void init(void);
void copy_data(void);
void clear_bss(void);
void call_static_ctors(void);

/*
extern "C" void Reset_Handler(void)
{
	init();
	main();
	while(1);
}
*/

extern "C" void __init_cpp(void)
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
	uint32_t init_array_size = init_array_end - init_array_start;
	for(int i = 0; i < init_array_size; i++)
	{
		function_type fn = init_array_start[i];
		fn();
	}
	/*for(function_type fn = init_array_start[0]; fn < init_array_end[0]; fn++)
	{
		fn();
	}*/
	
	//(*fn)();
/*	std::for_each(init_array_start,
			init_array_end,
			[](const function_type pf)
			{
				pf();
			});
*/			
}


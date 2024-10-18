#include <cstdint>
#include <algorithm>

extern uint8_t end_of_text;
extern uint8_t data_load_address;
extern uint8_t start_of_data;
extern uint8_t end_of_data;
extern uint8_t start_of_bss;
extern uint8_t end_of_bss;
extern uint8_t init_array_load_address;
extern uint8_t start_of_init_array;
extern uint8_t end_of_init_array;

extern uint32_t x;

int main();
extern "C" void __libc_init_array(void);
extern "C" void initialise_monitor_handles(void);

/**
 * Copy .data section to the RAM
 */
static void init_data()
{
	for(uint8_t *data_at_flash = &data_load_address, *data_at_ram = &start_of_data; data_at_ram < &end_of_data; ++data_at_flash, ++data_at_ram)
		*data_at_ram = *data_at_flash;
}

/**
 * Zero .bss section in the RAM
 */
static void init_bss()
{
	for(uint8_t *bss_at_ram = &start_of_bss; bss_at_ram < &end_of_bss; ++bss_at_ram)
		*bss_at_ram = 0;
}

/**
 * Init C++ static .ctors(call them one-by-one)
 */
typedef void (*static_ctor)(void);

static void init_static_ctors()
{
/*		
	// Copy init_array data to RAM
	for(uint8_t *rom = &init_array_load_address, *ram = &start_of_init_array; ram < &end_of_init_array; ++rom, ++ram)
		*ram = *rom;
*/
	// Call static .ctors
	for(uint32_t *ctorPtr = (uint32_t *)&start_of_init_array; ctorPtr != (uint32_t *)&end_of_init_array; ++ctorPtr)
	{
		static_ctor ctor = (static_ctor)(*ctorPtr);
		ctor();
	}

/*	
	std::for_each((static_ctor)&start_of_init_array, (static_ctor)&end_of_init_array, 
		[](static_ctor ctor)
		{
			//ctor();
		});
*/
}


extern "C" void ResetExceptionHandler()
{
	init_data();
	init_bss();
	// Iniitialize libc
	__libc_init_array();
	// Initialize semihosting monitor
	initialise_monitor_handles();
	// Initialize C++ static constructors
	init_static_ctors();
	// Run main()
	main();
	// Init standard library code
}


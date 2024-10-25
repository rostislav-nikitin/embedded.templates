#include <iostream>

#include "../include/device_clock_config_t.hpp"
#include "../include/peripherals/rcc.hpp"

extern device_clock_config_t device_clock_configs[];

int main(int argc, char* argv[])
{
	Peripherals::Rcc rcc;
	rcc.setClockEnabled("GPIOF", true);
	std::cout 
	    << "GPIOA clock enabled: " << rcc.getClockEnabled("GPIOA") << ";"
	    << "GPIOF clock enabled: " << rcc.getClockEnabled("GPIOF") << std::endl;


	return EXIT_SUCCESS;
}

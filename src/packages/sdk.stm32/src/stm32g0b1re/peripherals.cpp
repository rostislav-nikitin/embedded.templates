#include "memory_map.hpp"
#include "../peripherals/rcc.hpp"


namespace Peripherals
{
	RCC &rcc = *reinterpret_cast<RCC *>(RccBaseAddress);
}


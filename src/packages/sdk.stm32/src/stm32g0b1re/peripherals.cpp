#include "memory_map.hpp"
#include "../peripherals/rcc.hpp"


namespace Peripheral
{
	RCC &rcc = *reinterpret_cast<RCC *>(RccBaseAddress);
}


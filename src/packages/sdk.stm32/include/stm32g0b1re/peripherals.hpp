#ifndef __PERIPHERAL_HPP__
#define __PERIPHERAL_HPP__

#include "memory_map.hpp"
#include "../peripherals/rcc.hpp"


namespace Peripheral
{
	RCC &rcc = *reinterpret_cast<RCC *>(RccBaseAddress);
}

#endif

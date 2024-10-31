#ifndef __PERIPHERAL_HPP__
#define __PERIPHERAL_HPP__

#include "memory_map.hpp"
#include "../peripherals/rcc.hpp"


namespace Peripherals
{
	Rcc &rcc = *reinterpret_cast<Rcc *>(RccBaseAddress);
}

#endif

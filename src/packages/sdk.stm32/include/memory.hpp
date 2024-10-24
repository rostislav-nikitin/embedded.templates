#ifndef __MEMORY_HPP__
#define __MEMORY_HPP__

#include <cstdint>

namespace Memory
{
	volatile inline uint32_t& memory(const uint32_t address);
}

#endif

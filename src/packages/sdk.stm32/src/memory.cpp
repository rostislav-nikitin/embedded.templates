#include "../include/memory.hpp"

namespace Memory
{
	volatile inline uint32_t& memory(const uint32_t address)
	{
		return *reinterpret_cast<uint32_t *>(address);
	}
}

#ifndef __MEMORY_MAP_HPP__
#define __MEMORY_MAP_HPP__

#include "../types.hpp"

namespace MemoryMap
{
	u32 const constexpr AhbBaseAddress = 0x40020000UL;

	u32 const constexpr RccOffset = 0x00001000UL;
	u32 const constexpr RccBaseAddress = AhbBase + RccOffset;

	u32 const constexpr RccClockControlRegisterOffset = 0x00;
	u32 const constexpr RccClockControlRegisterAddress = RccBaseAddress + RccClockControlRegisterOffset;

	//...
	
	u32 const constexpr RccIoPortEnableRegisterOffset = 0x34;
	u32 const constexpr RccIoPortEnableRegisterAddress = RccBaseAddress + RccIoPortEnableRegisterOffset;
	Bit const constexpr RccIoPortEnableGpioABit = Bit::Bit0;
	Bit const constexpr RccIoPortEnableGpioBBit = Bit::Bit1;
	Bit const constexpr RccIoPortEnableGpioCBit = Bit::Bit2;
	Bit const constexpr RccIoPortEnableGpioDBit = Bit::Bit3;
	Bit const constexpr RccIoPortEnableGpioEBit = Bit::Bit4;
	Bit const constexpr RccIoPortEnableGpioFBit = Bit::Bit5;
}

#endif

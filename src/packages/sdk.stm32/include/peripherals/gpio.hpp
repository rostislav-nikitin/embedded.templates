#ifndef __PERIPHERALS_GPIO_HPP__
#define __PERIPHERALS_GPIO_HPP__

#include <cstdint>
#include <cstring>
#include <algorithm>

#include "../bit_operations.hpp"
#include "../memory.hpp"

namespace Peripherals
{
	class Gpio
	{
	private:
		uint32_t modeRegister_;
		uint32_t outputTypeRegister_;
		uint32_t outputSpeedRegister_;
		uint32_t pullUpPullDownRegister_;
		uint32_t inputDataRegister_;
		uint32_t outputDataRegister_;
		uint32_t bitSetResetRegister_;
		uint32_t configurationLockRegister_;
		uint32_t alternateFunctionLowRegister_;
		uint32_t alternateFunctionHiRegister_;
		uint32_t bitResetRegister_;
	};
}

#endif

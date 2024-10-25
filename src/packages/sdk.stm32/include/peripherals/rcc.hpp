#ifndef __PERIPHERALS_RCC_HPP__
#define __PERIPHERALS_RCC_HPP__

#include <cstring>
#include <algorithm>

#include "../device_clock_config_t.hpp"
#include "../bit_operations.hpp"

namespace Peripherals
{
	class Rcc
	{
	public:
		void setClockEnabled(char const *id, bool value);
		bool getClockEnabled(char const *id);
		void setReset(char const *id, bool value);
		bool getReset(char const *id);
		void setSleepModeClockEnabled(char const *id, bool value);
		bool getSleepModeClockEnabled(char const *id);
	private:
		device_clock_config_t &getDeviceClockConfig(char const *id);
	};
}

#endif

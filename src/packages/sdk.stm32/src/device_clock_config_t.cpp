#include <cstddef>
#include "../include/device_clock_config_t.hpp"

bool operator==(device_clock_config_t const &a, device_clock_config_t const &b)
{
	if(a.id == NULL && b.id == NULL)
		return true;

	return 
		a.id == b.id && 
		a.resetRegisterAddress == b.resetRegisterAddress && a.resetBit == b.resetBit &&
		a.clockEnableRegisterAddress == b.clockEnableRegisterAddress && a.clockEnableBit == b.clockEnableBit &&
		a.sleepModeClockEnableRegisterAddress == b.sleepModeClockEnableRegisterAddress &&
		a.sleepModeClockEnableBit == b.sleepModeClockEnableBit;
}

bool operator!=(device_clock_config_t const &a, device_clock_config_t const &b)
{
	return !(a == b);
}

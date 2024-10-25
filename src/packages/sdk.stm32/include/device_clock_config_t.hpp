#ifndef __DEVICE_CLOCK_CONFIG_HPP__
#define __DEVICE_CLOCK_CONFIG_HPP__

#include <cstdint>

struct device_clock_config_t
{
    const char * id;
	uint32_t resetRegisterAddress;
	uint32_t resetBit;
    uint32_t clockEnableRegisterAddress;
    uint32_t clockEnableBit;
	uint32_t sleepModeClockEnableRegisterAddress;
	uint32_t sleepModeClockEnableBit;
};


bool operator==(device_clock_config_t const &a, device_clock_config_t const &b);
bool operator!=(device_clock_config_t const &a, device_clock_config_t const &b);

#endif

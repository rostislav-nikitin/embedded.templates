#include "../../include/peripherals/rcc.hpp"
#include <iostream>

extern device_clock_config_t device_clock_configs[];

namespace Peripherals
{
	void Rcc::setReset(char const *id, bool value)
	{
	    auto &deviceClockConfig = getDeviceClockConfig(id);
	    if(deviceClockConfig != device_clock_config_t{NULL})
			BIT_SET(deviceClockConfig.resetRegisterAddress, deviceClockConfig.resetBit);
	}
	bool Rcc::getReset(char const *id)
	{
	    auto &deviceClockConfig = getDeviceClockConfig(id);
	    if(deviceClockConfig != device_clock_config_t{NULL})
			return BIT_GET(deviceClockConfig.resetRegisterAddress, deviceClockConfig.resetBit);

	    return false;
	}

	void Rcc::setClockEnabled(char const *id, bool value)
	{
	    auto &deviceClockConfig = getDeviceClockConfig(id);
	    if(deviceClockConfig != device_clock_config_t{NULL})
			BIT_SET(deviceClockConfig.clockEnableRegisterAddress, deviceClockConfig.clockEnableBit);
	}
	bool Rcc::getClockEnabled(char const *id)
	{
	    auto &deviceClockConfig = getDeviceClockConfig(id);
	    if(deviceClockConfig != device_clock_config_t{NULL})
			return BIT_GET(deviceClockConfig.clockEnableRegisterAddress, deviceClockConfig.clockEnableBit);

	    return false;
	}

	void Rcc::setSleepModeClockEnabled(char const *id, bool value)
	{
	    auto &deviceClockConfig = getDeviceClockConfig(id);
	    if(deviceClockConfig != device_clock_config_t{NULL})
			BIT_SET(deviceClockConfig.sleepModeClockEnableRegisterAddress, deviceClockConfig.sleepModeClockEnableBit);
	}
	bool Rcc::getSleepModeClockEnabled(char const *id)
	{
	    auto &deviceClockConfig = getDeviceClockConfig(id);
	    if(deviceClockConfig != device_clock_config_t{NULL})
			return BIT_GET(deviceClockConfig.sleepModeClockEnableRegisterAddress, deviceClockConfig.sleepModeClockEnableBit);

	    return false;
	}

	::device_clock_config_t &Rcc::getDeviceClockConfig(char const *id)
	{
	    device_clock_config_t end{NULL};
	    auto result = std::find_if(device_clock_configs, &end,
		[id](device_clock_config_t const &deviceClockConfig)
		{
		    //std::cout << deviceClockConfig.id << std::endl;
		    return strcmp(deviceClockConfig.id, id) == 0;
		});
	    return *result;
	}
}

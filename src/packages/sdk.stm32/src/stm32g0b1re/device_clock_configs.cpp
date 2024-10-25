#include <cstddef>

#include "../../include/stm32g0b1re/memory_map.hpp"
#include "../../include/device_clock_config_t.hpp"

device_clock_config_t device_clock_configs[] =
{
    {
        .id = "GPIOA",
        .resetRegisterAddress = RccIoPortResetRegisterAddress,
        .resetBit = RccIoPortResetGpioABit,
        .clockEnableRegisterAddress = RccIoPortClockEnableRegisterAddress,
        .clockEnableBit = RccIoPortClockEnableGpioABit,
		.sleepModeClockEnableRegisterAddress = RccIoPortSleepModeClockEnableRegisterAddress,
		.sleepModeClockEnableBit = RccIoPortSleepModeClockEnableGpioABit
    },
    {
        .id = "GPIOB",
        .resetRegisterAddress = RccIoPortResetRegisterAddress,
        .resetBit = RccIoPortResetGpioBBit,
        .clockEnableRegisterAddress = RccIoPortClockEnableRegisterAddress,
        .clockEnableBit = RccIoPortClockEnableGpioBBit,
		.sleepModeClockEnableRegisterAddress = RccIoPortSleepModeClockEnableRegisterAddress,
		.sleepModeClockEnableBit = RccIoPortSleepModeClockEnableGpioBBit
	},
    {
        .id = "GPIOC",
        .resetRegisterAddress = RccIoPortResetRegisterAddress,
        .resetBit = RccIoPortResetGpioCBit,
        .clockEnableRegisterAddress = RccIoPortClockEnableRegisterAddress,
        .clockEnableBit = RccIoPortClockEnableGpioCBit,
		.sleepModeClockEnableRegisterAddress = RccIoPortSleepModeClockEnableRegisterAddress,
		.sleepModeClockEnableBit = RccIoPortSleepModeClockEnableGpioCBit
	},
    {
        .id = "GPIOD",
        .resetRegisterAddress = RccIoPortResetRegisterAddress,
        .resetBit = RccIoPortResetGpioDBit,
        .clockEnableRegisterAddress = RccIoPortClockEnableRegisterAddress,
        .clockEnableBit = RccIoPortClockEnableGpioDBit,
		.sleepModeClockEnableRegisterAddress = RccIoPortSleepModeClockEnableRegisterAddress,
		.sleepModeClockEnableBit = RccIoPortSleepModeClockEnableGpioDBit
	},
    {
        .id = "GPIOE",
        .resetRegisterAddress = RccIoPortResetRegisterAddress,
        .resetBit = RccIoPortResetGpioEBit,
        .clockEnableRegisterAddress = RccIoPortClockEnableRegisterAddress,
        .clockEnableBit = RccIoPortClockEnableGpioEBit,
		.sleepModeClockEnableRegisterAddress = RccIoPortSleepModeClockEnableRegisterAddress,
		.sleepModeClockEnableBit = RccIoPortSleepModeClockEnableGpioEBit
	},
    {
        .id = "GPIOF",
        .resetRegisterAddress = RccIoPortResetRegisterAddress,
        .resetBit = RccIoPortResetGpioFBit,
        .clockEnableRegisterAddress = RccIoPortClockEnableRegisterAddress,
        .clockEnableBit = RccIoPortClockEnableGpioFBit,
		.sleepModeClockEnableRegisterAddress = RccIoPortSleepModeClockEnableRegisterAddress,
		.sleepModeClockEnableBit = RccIoPortSleepModeClockEnableGpioFBit
	},
	{NULL}
};

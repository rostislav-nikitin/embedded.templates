#ifndef __CLOCK_CONFIGURATION_HPP__
#define __CLOCK_CONFIGURATION_HPP__


struct device_clock_config_t
{
    const char * Name;
    uint32_t DeviceEnableRegisterAddress;
    uint32_t DeviceEnableBit;
};

static device_clock_config_t device_clock_configs[] =
{
    {
        .Name = "GPIOA",
        .DeviceEnableRegisterAddress = 0x00000004,
        .DeviceEnableBit = 0x00000001
    }
};

#endif

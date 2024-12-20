#ifndef __MEMORY_MAP_HPP__
#define __MEMORY_MAP_HPP__

#define AhbBaseAddress 0x40020000
#define IoPortsBaseAddress 0x50000000

// RCC
#define RccOffset 0x00001000
#define RccBaseAddress (AhbBaseAddress + RccOffset)

#define RccClockControlRegisterOffset 0x00
#define RccClockControlRegisterAddress (RccBaseAddress + RccClockControlRegisterOffset)

//...
#define RccIoPortResetRegisterOffset 0x24
#define RccIoPortResetRegisterAddress (RccBaseAddress + RccIoPortResetRegisterOffset)
#define RccIoPortResetGpioABit 0U
#define RccIoPortResetGpioBBit 1U
#define RccIoPortResetGpioCBit 2U
#define RccIoPortResetGpioDBit 3U
#define RccIoPortResetGpioEBit 4U
#define RccIoPortResetGpioFBit 5U
	
#define RccIoPortClockEnableRegisterOffset 0x34
#define RccIoPortClockEnableRegisterAddress (RccBaseAddress + RccIoPortClockEnableRegisterOffset)
#define RccIoPortClockEnableGpioABit 0U
#define RccIoPortClockEnableGpioBBit 1U
#define RccIoPortClockEnableGpioCBit 2U
#define RccIoPortClockEnableGpioDBit 3U
#define RccIoPortClockEnableGpioEBit 4U
#define RccIoPortClockEnableGpioFBit 5U

#define RccIoPortSleepModeClockEnableRegisterOffset 0x34
#define RccIoPortSleepModeClockEnableRegisterAddress (RccBaseAddress + RccIoPortSleepModeClockEnableRegisterOffset)
#define RccIoPortSleepModeClockEnableGpioABit 0U
#define RccIoPortSleepModeClockEnableGpioBBit 1U
#define RccIoPortSleepModeClockEnableGpioCBit 2U
#define RccIoPortSleepModeClockEnableGpioDBit 3U
#define RccIoPortSleepModeClockEnableGpioEBit 4U
#define RccIoPortSleepModeClockEnableGpioFBit 4U

// GPIO
#define GpioAOffset 0x0000
#define GpioBOffset 0x0400
#define GpioCOffset 0x0800
#define GpioDOffset 0x0C00
#define GpioEOffset 0x1000
#define GpioFOffset 0x1400

#define GpioABaseAddress (IoPortsBaseAddress + GpioAOffset)
#define GpioBBaseAddress (IoPortsBaseAddress + GpioBOffset)
#define GpioCBaseAddress (IoPortsBaseAddress + GpioCOffset)
#define GpioDBaseAddress (IoPortsBaseAddress + GpioDOffset)
#define GpioEBaseAddress (IoPortsBaseAddress + GpioEOffset)
#define GpioFBaseAddress (IoPortsBaseAddress + GpioFOffset)

#endif

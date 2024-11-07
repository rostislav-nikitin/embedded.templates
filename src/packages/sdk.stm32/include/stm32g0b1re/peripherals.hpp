#ifndef __PERIPHERAL_HPP__
#define __PERIPHERAL_HPP__

#include "memory_map.hpp"
#include "../peripherals/rcc.hpp"
#include "../peripherals/gpio.hpp"


namespace Peripherals
{
	Rcc &rcc = *reinterpret_cast<Rcc *>(RccBaseAddress);

	Gpio &gpioA = *reinterpret_cast<Gpio *>(GpioABaseAddress);
	Gpio &gpioB = *reinterpret_cast<Gpio *>(GpioBBaseAddress);
	Gpio &gpioC = *reinterpret_cast<Gpio *>(GpioCBaseAddress);
	Gpio &gpioD = *reinterpret_cast<Gpio *>(GpioDBaseAddress);
	Gpio &gpioE = *reinterpret_cast<Gpio *>(GpioEBaseAddress);
	Gpio &gpioF = *reinterpret_cast<Gpio *>(GpioFBaseAddress);
}

#endif

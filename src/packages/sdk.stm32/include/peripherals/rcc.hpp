#ifndef __PERIPHERALS_RCC_HPP__
#define __PERIPHERALS_RCC_HPP__

#include "../types.hpp"
#include "../register_helper.hpp"

namespace Peripheral
{
	class Rcc
	{
	public:
		void ioPortGpioAEnable();
		void ioPortGpioADisable();
		void ioPortGpioBEnable();
		void ioPortGpioBDisable();
		void ioPortGpioCEnable();
		void ioPortGpioCDisable();
		void ioPortGpioDEnable();
		void ioPortGpioDDisable();
		void ioPortGpioEEnable();
		void ioPortGpioEDisable();
		void ioPortGpioFEnable();
		void ioPortGpioFDisable();
	};
}

#endif

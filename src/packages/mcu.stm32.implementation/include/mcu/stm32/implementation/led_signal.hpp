#ifndef __MCU_STM32_IMPLEMENTATION_LED_SIGNAL_HPP__
#define __MCU_STM32_IMPLEMENTATION_LED_SIGNAL_HPP__

#include <mcu/abstractions/isignal.hpp>

namespace Mcu
{
	namespace Stm32
	{
		namespace Implementation
		{
			class LedSignal : public Mcu::Abstractions::ISignal
			{
			public:
				virtual bool getValue() override;
	
				virtual void enable() override;
				virtual void disable() override;
				virtual bool toggle() override;
			};
		}
	}
}

#endif
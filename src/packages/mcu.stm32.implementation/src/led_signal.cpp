#include "../include/mcu/stm32/implementation/led_signal.hpp"

namespace Mcu
{
	namespace Stm32
	{
		namespace Implementation
		{
			bool LedSignal::getValue()
			{
				return true;
			}

			void LedSignal::enable()
			{
			}
			void LedSignal::disable()
			{
			}
			bool LedSignal::toggle()
			{
				return true;
			}
		}
	}
}

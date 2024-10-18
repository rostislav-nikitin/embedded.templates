#ifndef __MCU_ABSTRACTIONS_ISIGNAL_HPP__
#define __MCU_ABSTRACTIONS_ISIGNAL_HPP__

namespace Mcu
{
	namespace Abstractions
	{
		class ISignal
		{
		public:
			virtual bool getValue() = 0;

			virtual void enable() = 0;
			virtual void disable() = 0;
			virtual bool toggle() = 0;
		};
	}
}

#endif

#ifndef __PERIPHERALS_GPIO_HPP__
#define __PERIPHERALS_GPIO_HPP__

#include <cstdint>
#include <cstring>
#include <algorithm>

#include "../bit_operations.hpp"
#include "../memory.hpp"

namespace Peripherals
{
	class Gpio
	{
	public:


		typedef uint32_t PinNumber;



		class Pin
		{
		public:
			enum class Mode : uint8_t
			{
				Input = 				0x0,
				GeneralPurposeOutput = 	0x1,
				AlternateFunction = 	0x2,
				Analog = 				0x3
			};

			enum class OutputType  : uint8_t
			{
				PushPull = 	0x0,
				OpenDrain =	0x1
			};

			enum class OutputSpeed : uint8_t
			{
				VeryLow = 	0x0,
				Low = 		0x1,
				High = 		0x2,
				VeryHigh = 	0x3
			};

			enum class PullUpPullDown : uint8_t
			{
				NoPull		= 0x0,
				PullUp 		= 0x1,
				PullDown 	= 0x2
			};

			enum class BitValue : uint8_t
			{
				Reset = 	0x0,
				Set = 		0x1
			};

			enum class Action : uint8_t
			{
				NoAction = 	0x0,
				Action = 	0x1
			};
/*
			enum class ResetOutput : uint8_t
			{
				NoAction = 	0x0,
				Reset = 	0x1
			};

			enum class SetOutput : uint8_t
			{
				NoAction = 	0x0,
				Set = 		0x1
			};
*/

			enum class Lock : uint8_t
			{
				Unlocked = 	0x0,
				Locked = 	0x1
			};

			enum class AlternateFunction : uint8_t
			{
				Af0 = 0x0,
				Af1 = 0x1,
				Af2 = 0x2,
				Af3 = 0x3,
				Af4 = 0x4,
				Af5 = 0x5,
				Af6 = 0x6,
				Af7 = 0x7
			};
/*
			enum class Reset : uint8_t
			{
				NoAction = 	0x0,
				Reset = 	0x1
			};
*/
			
			Pin(Gpio &gpio, PinNumber pinNumber);

			Pin &setMode(Mode);
			Pin &setOutputType(OutputType);
			Pin &setOutputSpeed(OutputSpeed);
			Pin &setPullUpPullDown(PullUpPullDown);
			Pin &resetOutput(Action);
			Pin &setOutput(Action);
			Pin &lockConfig(Lock);
			Pin &setAlternateFunction(AlternateFunction);
			Pin &reset(Action);

			bool getValue();
			void setValue(bool value);

			void set();
			void reset();
			void toggle();

		private:
			Gpio &gpio_;
		   	PinNumber pinNumber_ = 0;
			
		};

		
	Pin operator[](PinNumber pinNumber);
	Pin getPin(PinNumber pinNumber);

	private:
		uint32_t modeRegister_;
		uint32_t outputTypeRegister_;
		uint32_t outputSpeedRegister_;
		uint32_t pullUpPullDownRegister_;
		uint32_t inputDataRegister_;
		uint32_t outputDataRegister_;
		uint32_t bitSetResetRegister_;
		uint32_t configurationLockRegister_;
		uint32_t alternateFunctionLowRegister_;
		uint32_t alternateFunctionHiRegister_;
		uint32_t bitResetRegister_;
	};
}

#endif

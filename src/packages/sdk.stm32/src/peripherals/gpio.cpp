#include "../../include/peripherals/gpio.hpp"

namespace Peripherals
{
	//GPIO::Pin
	Gpio::Pin::Pin(Gpio &gpio, PinNumber pinNumber) : 
		gpio_(gpio), pinNumber_(pinNumber)
	{
	}

	Gpio::Pin &Gpio::Pin::setMode(Mode)
	{
		return *this;
	}
	Gpio::Pin &Gpio::Pin::setOutputType(OutputType)
	{
		return *this;
	}
	Gpio::Pin &Gpio::Pin::setOutputSpeed(OutputSpeed)
	{
		return *this;
	}
	Gpio::Pin &Gpio::Pin::setPullUpPullDown(PullUpPullDown)
	{
		return *this;
	}
	Gpio::Pin &Gpio::Pin::resetOutput(Action)
	{
		return *this;
	}
	Gpio::Pin &Gpio::Pin::setOutput(Action)
	{
		return *this;
	}
	Gpio::Pin &Gpio::Pin::lockConfig(Lock)
	{
		return *this;
	}
	Gpio::Pin &Gpio::Pin::setAlternateFunction(AlternateFunction)
	{
		return *this;
	}
	Gpio::Pin &Gpio::Pin::reset(Action)
	{
		return *this;
	}
			
	bool Gpio::Pin::getValue()
	{
		return {};
	}
	void Gpio::Pin::setValue(bool value)
	{
	}

	void Gpio::Pin::set()
	{
	}

	void Gpio::Pin::reset()
	{
	}

	void Gpio::Pin::toggle()
	{
	}


	// GPIO	
	Gpio::Pin Gpio::operator[](PinNumber pinNumber)
	{
		return getPin(pinNumber);
	}
	Gpio::Pin Gpio::getPin(PinNumber pinNumber)
	{
		return Pin(*this, pinNumber);
	}
}

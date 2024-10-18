#ifndef __APP_HPP__
#define __APP_HPP__

//#include <mcu/stm32/stm32g0b1re/peripheral.hpp>
#include <mcu/abstractions/isignal.hpp>
#include <mcu/stm32/implementation/led_signal.hpp>

class App
{
public:
	App();

	void run();
private:
	Mcu::Abstractions::ISignal *ledSignal_;
};

#endif

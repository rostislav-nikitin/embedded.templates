#include "../include/app.hpp"

App::App() :
	ledSignal_(new Mcu::Stm32::Implementation::LedSignal())
{
	//ledSignal_ = Mcu::Stm32::Implementation::LedSignal(Mcu::Stm32::Peripheral::GpioA5);
}

void App::run()
{
	while(1)
	{
		// Wait
		for(int i = 0; i < 100000; ++i);

		// Toggle Signal
		ledSignal_->toggle();
	}
}

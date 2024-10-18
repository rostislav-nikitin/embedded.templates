
// Composition(Preferable)
class UartTransceiver : public Mcu::Abstractions::Transceiver
{																			 ///
	UartTransceiver(Mcu::Stm32::Peripherals::Uart &uart);
}
// Init
UartTransceiver(Mcu::Stm32::Peripherals::uart1);

// Inheritance
class UartTransceiver : public Mcu::Abstractions::ITransceiver<UartTransceiver>, protected Mcu::Stm32::Peripherals::Uart
{
 
}

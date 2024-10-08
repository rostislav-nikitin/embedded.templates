#include <stdint.h>
#include <stdbool.h>

#define RAM_BEGIN 0x20000000
#define RAM_SIZE (144UL * 1024UL)
#define STACK_BEGIN (RAM_BEGIN + RAM_SIZE)

extern uint8_t end_of_text;
extern uint8_t data_load_address;
extern uint8_t start_of_data;
extern uint8_t end_of_data;
extern uint8_t start_of_bss;
extern uint8_t end_of_bss;

int main();
void __libc_init_array(void);
extern void initialise_monitor_handles(void);

// Default dummy handler
void DefaultHandler();

// Exception handlers
void ResetExceptionHandler();

__attribute__((weak, alias("DefaultHandler")))
void NmiExceptionHandler();

__attribute__((weak, alias("DefaultHandler")))
void HardFaultExceptionHandler();

__attribute__((weak, alias("DefaultHandler")))
void SvcExceptionHandler();

__attribute__((weak, alias("DefaultHandler")))
void PendSvExceptionHandler();

__attribute__((weak, alias("DefaultHandler")))
void SysTickExceptionHandler();

// Interrupt handlers
__attribute__((weak, alias("DefaultHandler")))
void WwdgInterruptHandler();

__attribute__((weak, alias("DefaultHandler")))
void PvdInterruptHandler();

__attribute__((weak, alias("DefaultHandler")))
void RtcTampInterruptHandler();

__attribute__((weak, alias("DefaultHandler")))
void FlashInterruptHandler();

__attribute__((weak, alias("DefaultHandler")))
void RccCrsInterruptHandler();

__attribute__((weak, alias("DefaultHandler")))
void Exti0To1InterruptHandler();

__attribute__((weak, alias("DefaultHandler")))
void Exti2To3InterruptHandler();

__attribute__((weak, alias("DefaultHandler")))
void Exti4To15InterruptHandler();

__attribute__((weak, alias("DefaultHandler")))
void Ucpd1Ucpd2UsbInterruptHandler();

__attribute__((weak, alias("DefaultHandler")))
void Dma1Channel1InterruptHandler();

__attribute__((weak, alias("DefaultHandler")))
void Dma1Channel2And3InterruptHandler();

__attribute__((weak, alias("DefaultHandler")))
void Dma1Channel4And5And6And7DmaMuxDma2Channel1Ane2And3And4And5InterruptHandler();

__attribute__((weak, alias("DefaultHandler")))
void AdcCompInterruptHandler();

__attribute__((weak, alias("DefaultHandler")))
void Tim1BrkUpTrgComInterruptHandler();

__attribute__((weak, alias("DefaultHandler")))
void Tim1CcInterruptHandler();

__attribute__((weak, alias("DefaultHandler")))
void Tim2InterruptHandler();

__attribute__((weak, alias("DefaultHandler")))
void Tim3Tim4InterruptHandler();

__attribute__((weak, alias("DefaultHandler")))
void Tim6DacLpTim1InterruptHandler();

__attribute__((weak, alias("DefaultHandler")))
void Tim7LpTim2InterruptHandler();

__attribute__((weak, alias("DefaultHandler")))
void Tim14InterruptHandler();

__attribute__((weak, alias("DefaultHandler")))
void Tim15InterruptHandler();

__attribute__((weak, alias("DefaultHandler")))
void Tim16FdCanIt0InterruptHandler();

__attribute__((weak, alias("DefaultHandler")))
void Tim17FdCanIt1InterruptHandler(); 

__attribute__((weak, alias("DefaultHandler")))
void I2C1InterruptHandler();

__attribute__((weak, alias("DefaultHandler")))
void I2C2I2C3InterruptHandler();

__attribute__((weak, alias("DefaultHandler")))
void SPI1InterruptHandler();

__attribute__((weak, alias("DefaultHandler")))
void Spi2Spi3InterruptHandler();

__attribute__((weak, alias("DefaultHandler")))
void Usart1InterruptHandler();

__attribute__((weak, alias("DefaultHandler")))
void Usart2LpUart2InterruptHandler();

__attribute__((weak, alias("DefaultHandler")))
void Usart3Usart4Usart5Usart6LpUart1InterruptHandler();

__attribute__((weak, alias("DefaultHandler")))
void CecInterruptHandler();

__attribute__((weak, alias("DefaultHandler")))
void AesRngInterruptHandler();

// ISR vector
__attribute__((section(".isr_vector")))
uint32_t isrVector[] = 
{
	STACK_BEGIN,
	// Exception handlers
	(uint32_t) &ResetExceptionHandler,
	(uint32_t) &NmiExceptionHandler,
	(uint32_t) &HardFaultExceptionHandler,
	0, 0, 0, 0, 0, 0, 0,
	(uint32_t) &SvcExceptionHandler,
	0, 0,
	(uint32_t) &PendSvExceptionHandler,
	(uint32_t) &SysTickExceptionHandler,
	// Interrupt handlers
	(uint32_t) &WwdgInterruptHandler,
	(uint32_t) &PvdInterruptHandler,
	(uint32_t) &RtcTampInterruptHandler,
	(uint32_t) &FlashInterruptHandler,
	(uint32_t) &RccCrsInterruptHandler,
	(uint32_t) &Exti0To1InterruptHandler,
	(uint32_t) &Exti2To3InterruptHandler,
	(uint32_t) &Exti4To15InterruptHandler,
	(uint32_t) &Ucpd1Ucpd2UsbInterruptHandler,
	(uint32_t) &Dma1Channel1InterruptHandler,
	(uint32_t) &Dma1Channel2And3InterruptHandler,
	(uint32_t) &Dma1Channel4And5And6And7DmaMuxDma2Channel1Ane2And3And4And5InterruptHandler,
	(uint32_t) &AdcCompInterruptHandler,
	(uint32_t) &Tim1BrkUpTrgComInterruptHandler,
	(uint32_t) &Tim1CcInterruptHandler,
	(uint32_t) &Tim2InterruptHandler,
	(uint32_t) &Tim3Tim4InterruptHandler,
	(uint32_t) &Tim6DacLpTim1InterruptHandler,
	(uint32_t) &Tim7LpTim2InterruptHandler,
	(uint32_t) &Tim14InterruptHandler,
	(uint32_t) &Tim15InterruptHandler,
	(uint32_t) &Tim16FdCanIt0InterruptHandler,
	(uint32_t) &Tim17FdCanIt1InterruptHandler, 
	(uint32_t) &I2C1InterruptHandler,
	(uint32_t) &I2C2I2C3InterruptHandler,
	(uint32_t) &SPI1InterruptHandler,
	(uint32_t) &Spi2Spi3InterruptHandler,
	(uint32_t) &Usart1InterruptHandler,
	(uint32_t) &Usart2LpUart2InterruptHandler,
	(uint32_t) &Usart3Usart4Usart5Usart6LpUart1InterruptHandler,
	(uint32_t) &CecInterruptHandler,
	(uint32_t) &AesRngInterruptHandler
};


void ResetExceptionHandler()
{
	// Copy .data section to the RAM
	for(uint8_t *data_at_flash = &data_load_address, *data_at_ram = &start_of_data; data_at_ram < &end_of_data; ++data_at_flash, ++data_at_ram)
		*data_at_ram = *data_at_flash;
	
	// Zero .bss section
	for(uint8_t *bss_at_ram = &start_of_bss; bss_at_ram < &end_of_bss; ++bss_at_ram)
		*bss_at_ram = 0;
	
	// Iniitialize libc
	__libc_init_array();
	
	// Initialize semihosting monitor
	initialise_monitor_handles();

	// Run main()
	main();
	// Init standard library code
}

void DefaultHandler()
{
	while(true);
}

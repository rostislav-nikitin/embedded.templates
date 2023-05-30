#include <stdint.h>
#include <stddef.h>

#define SRAM_START	(0x20000000U)
#define SRAM_SIZE	(8U * 1024U)
#define SRAM_END	((SRAM_START) + (SRAM_SIZE))
#define STACK_START 	SRAM_END

void Default_Handler(void);

//STACK
//void Reset_Handler(void);
void Reset_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void NMI_Handler(void)			__attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void)		__attribute__((weak, alias("Default_Handler")));
//
void SVC_Handler(void)			__attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void)		__attribute__((weak, alias("Default_Handler")));
//
void PendSV_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void WWDG_Handler(void)			__attribute__((weak, alias("Default_Handler")));
void PVD_Handler(void)			__attribute__((weak, alias("Default_Handler")));
void TAMPER_STAMP_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void RTC_WKUP_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void FLASH_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void RCC_Handler(void)			__attribute__((weak, alias("Default_Handler")));
void EXTI0_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void EXTI1_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void EXTI2_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void EXTI3_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void EXTI4_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void DMA1_Channel1_Handler(void)	__attribute__((weak, alias("Default_Handler")));
void DMA1_Channel2_Handler(void)	__attribute__((weak, alias("Default_Handler")));
void DMA1_Channel3_Handler(void)	__attribute__((weak, alias("Default_Handler")));
void DMA1_Channel4_Handler(void)	__attribute__((weak, alias("Default_Handler")));
void DMA1_Channel5_Handler(void)	__attribute__((weak, alias("Default_Handler")));
void DMA1_Channel6_Handler(void)	__attribute__((weak, alias("Default_Handler")));
void DMA1_Channel7_Handler(void)	__attribute__((weak, alias("Default_Handler")));
void ADC1_Handler(void)			__attribute__((weak, alias("Default_Handler")));
//
void EXTI9_5_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void TIM1_BRK_TIM15_Handler(void)	__attribute__((weak, alias("Default_Handler")));
void TIM1_UP_TIM16_Handler(void)	__attribute__((weak, alias("Default_Handler")));
void TIM1_TRG_COM_TIM17_Handler(void)	__attribute__((weak, alias("Default_Handler")));
void TIM1_CC_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void TIM2_Handler(void)			__attribute__((weak, alias("Default_Handler")));
void TIM3_Handler(void)		 	__attribute__((weak, alias("Default_Handler")));
void TIM4_Handler(void)		 	__attribute__((weak, alias("Default_Handler")));
void I2C1_EV_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void I2C1_ER_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void I2C2_EV_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void I2C2_ER_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void SPI1_Handler(void)		 	__attribute__((weak, alias("Default_Handler")));
void SPI2_Handler(void)		 	__attribute__((weak, alias("Default_Handler")));
void USART1_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void USART2_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void USART3_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void EXTI15_10_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void RTC_Alarm_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void CEC_Handler(void)		 	__attribute__((weak, alias("Default_Handler")));
void TIM12_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void TIM13_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void TIM14_Handler(void)		__attribute__((weak, alias("Default_Handler")));
//
void FSMC_Handler(void)		 	__attribute__((weak, alias("Default_Handler")));
//
void TIM5_Handler(void)		 	__attribute__((weak, alias("Default_Handler")));
void SPI3_Handler(void)		 	__attribute__((weak, alias("Default_Handler")));
void UART4_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void UART5_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void TIM6_DAC_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void TIM7_Handler(void)		 	__attribute__((weak, alias("Default_Handler")));
void DMA2_Channel1_Handler(void)	__attribute__((weak, alias("Default_Handler")));
void DMA2_Channel2_Handler(void)	__attribute__((weak, alias("Default_Handler")));
void DMA2_Channel3_Handler(void)	__attribute__((weak, alias("Default_Handler")));
void DMA2_Channel4_5_Handler(void)	__attribute__((weak, alias("Default_Handler")));
void Channel5_Handler(void)		__attribute__((weak, alias("Default_Handler")));

uint32_t __attribute__ ((section(".isr_vector"))) isr_vector[77] =
{
	(uint32_t)STACK_START,
	(uint32_t)&Reset_Handler,
	(uint32_t)&NMI_Handler,
	(uint32_t)&HardFault_Handler,
	(uint32_t)&MemManage_Handler,
	(uint32_t)&BusFault_Handler,
	(uint32_t)&UsageFault_Handler,
	0,
	0,
	0,
	0,
	(uint32_t)&SVC_Handler,
	(uint32_t)&DebugMon_Handler,
	0,
	(uint32_t)&PendSV_Handler,
	(uint32_t)&SysTick_Handler,
	(uint32_t)&WWDG_Handler,
	(uint32_t)&PVD_Handler,
	(uint32_t)&TAMPER_STAMP_Handler,
	(uint32_t)&RTC_WKUP_Handler,
	(uint32_t)&FLASH_Handler,
	(uint32_t)&RCC_Handler,
	(uint32_t)&EXTI0_Handler,
	(uint32_t)&EXTI1_Handler,
	(uint32_t)&EXTI2_Handler,
	(uint32_t)&EXTI3_Handler,
	(uint32_t)&EXTI4_Handler,
	(uint32_t)&DMA1_Channel1_Handler,
	(uint32_t)&DMA1_Channel2_Handler,
	(uint32_t)&DMA1_Channel3_Handler,
	(uint32_t)&DMA1_Channel4_Handler,
	(uint32_t)&DMA1_Channel5_Handler,
	(uint32_t)&DMA1_Channel6_Handler,
	(uint32_t)&DMA1_Channel7_Handler,
	(uint32_t)&ADC1_Handler,
	0,
	0,
	0,
	0,
	(uint32_t)&EXTI9_5_Handler,
	(uint32_t)&TIM1_BRK_TIM15_Handler,
	(uint32_t)&TIM1_UP_TIM16_Handler,
	(uint32_t)&TIM1_TRG_COM_TIM17_Handler,
	(uint32_t)&TIM1_CC_Handler,
	(uint32_t)&TIM2_Handler,
	(uint32_t)&TIM3_Handler,
	(uint32_t)&TIM4_Handler,
	(uint32_t)&I2C1_EV_Handler,
	(uint32_t)&I2C1_ER_Handler,
	(uint32_t)&I2C2_EV_Handler,
	(uint32_t)&I2C2_ER_Handler,
	(uint32_t)&SPI1_Handler,
	(uint32_t)&SPI2_Handler,
	(uint32_t)&USART1_Handler,
	(uint32_t)&USART2_Handler,
	(uint32_t)&USART3_Handler,
	(uint32_t)&EXTI15_10_Handler,
	(uint32_t)&RTC_Alarm_Handler,
	(uint32_t)&CEC_Handler,
	(uint32_t)&TIM12_Handler,
	(uint32_t)&TIM13_Handler,
	(uint32_t)&TIM14_Handler,
	0,
	0,
	(uint32_t)&FSMC_Handler,
	0,
	(uint32_t)&TIM5_Handler,
	(uint32_t)&SPI3_Handler,
	(uint32_t)&UART4_Handler,
	(uint32_t)&UART5_Handler,
	(uint32_t)&TIM6_DAC_Handler,
	(uint32_t)&TIM7_Handler,
	(uint32_t)&DMA2_Channel1_Handler,
	(uint32_t)&DMA2_Channel2_Handler,
	(uint32_t)&DMA2_Channel3_Handler,
	(uint32_t)&DMA2_Channel4_5_Handler,
	(uint32_t)&Channel5_Handler
};

void Default_Handler(void)
{
}

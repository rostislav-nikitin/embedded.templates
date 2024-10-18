#include <stdio.h>
#include <stdlib.h>
#include <cstdint>

class Rcc
{
private:
	static uint32_t constexpr const RccBaseAddress = 0x40021000UL;
	static uint32_t constexpr const RccIopEnROffset = 0x34UL;

	static uint32_t constexpr const GioAEnBit = 0;
public:
	void enableGpioA()
	{
		//printf("%s\n", __PRETTY_FUNCTION__);
		volatile uint32_t *rccIopEnR = reinterpret_cast<uint32_t *>(RccBaseAddress + RccIopEnROffset);
		*rccIopEnR |= (1UL << GioAEnBit);
		//printf("RCCPtr=%p, RCCValue=%ld\n", rccIopEnR, *rccIopEnR);
	}
	
};

//PA5
#define IOPORT_BASE 0x50000000
#define GPIOA_OFFSET 0x00000000

class Gpio
{
public:
	void setMode()
	{
		mode_ &= ~(0x03UL << (5UL * 2UL));
		mode_ |= (0x01UL << (5UL * 2UL));
		//mode_ = 0x01UL;
		//printf("Mode=%ld\n", mode_);
	}
	void setType()
	{
		type_ |= (0x00UL << 5UL);
		//printf("Type=%ld\n", type_);
	}
	void setSpeed()
	{
		speed_ |= (0x00UL << (5UL * 2UL));
	}
	void setPullUpDown()
	{
		pullUpDown_ |= (0x00UL << (5UL * 2UL));
	}
	void setOdr()
	{
		odr_ |= (0x01UL << 5UL);
	}
	void resetOdr()
	{
		odr_ &= ~(0x01UL << 5UL);
	}
	uint32_t getOdr()
	{
		return odr_;
	}
private:
	volatile uint32_t mode_;
	volatile uint32_t type_;
	volatile uint32_t speed_;
	volatile uint32_t pullUpDown_;
	volatile uint32_t idr_;
	volatile uint32_t odr_;
	volatile uint32_t setReset_;
	volatile uint32_t lock_;
	volatile uint32_t alternateFunctionLow_;
	volatile uint32_t alternateFunctionHight_;
	volatile uint32_t bitReset_;
};

class Led
{
public:
};

int main()
{
    //printf("Started.\n");
	Rcc rcc;
	rcc.enableGpioA();

	Gpio &gpioA = *reinterpret_cast<Gpio *>(IOPORT_BASE + GPIOA_OFFSET);
	//printf("GPIO ADDR=%p\n", &gpioA);
	gpioA.setMode();
	gpioA.setType();
	gpioA.setSpeed();
	gpioA.setPullUpDown();
	gpioA.resetOdr();


    while(1)
    {
		gpioA.resetOdr();
		for(uint32_t i = 0; i < 1330000; ++i);
		gpioA.setOdr();
		for(uint32_t i = 0; i < 1330000; ++i);

		//printf("ODR=%ld\n", gpioA.getOdr());
    }
}

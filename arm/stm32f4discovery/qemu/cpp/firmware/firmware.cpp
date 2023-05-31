#include <iostream>
#include <cstdint>
#include <limits>

template<typename TAddressType, typename TValueType>
	class Application
	{
	public:

	};


template <typename TAddressType, typename TValueType, TAddressType address, TValueType bit>
	class Pin
	{
	public:
		static void set()
		{
			//*reinterpret_cast<TValueType *>(address) |= bit;
			std::cout << __PRETTY_FUNCTION__ << std::endl;
		}
		static void reset()
		{
			//*reinterpret_cast<TValueType *>(address) ^= bit;
		}
	};

template <typename TAddressType, typename TValueType, TAddressType address>
	class Port
	{
	public:
		Port()// : _pin_0{}
		{
		}
		void init()
		{
			//_pin_0::set();
			typedef Pin<TAddressType, TValueType, address, 0> PortPin0;
			PortPin0::set();
		}
	private:
		//Pin<TAddressType, TValueType, address, 0> _pin_0;
	};

template <typename TPinType>
	class AccessPinTest
	{
		public:
			void test()
			{
				TPinType::set();
			}
	};
int main()
{
	typedef Port<std::uint32_t, std::uint32_t, 10> PortA;
	PortA port{};
	//port.init();

	typedef Pin<std::uint32_t, std::uint32_t, 10, 0> Pin0;

	AccessPinTest<Pin0> accessPinTest{};
	accessPinTest.test();


	return 0;
}

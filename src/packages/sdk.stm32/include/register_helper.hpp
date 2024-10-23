#ifndef __REGISTER_HELPER_HPP__
#define __REGISTER_HELPER_HPP__

#include "types.h"

namespace Memory
{
	template<typename RegType>
	class RegHelper
	{
		constexpr static inline void 
		template <RegType *reg, int bit>
		constexpr static inline void setBit() const
		{
			*reg |= (1UL << bit);
		}
	};

	RegHelper<u32>::setBit<0>();

	template<typename Reg>
	class RegisterHelper
	{
	public:
		RegisterHelper(Reg* reg) : reg_(reg)
		{
		}

		// Bit
		void bitSetValue(Bit bit, bool value)
		{
			//assert(bit <= sizeof(value) * 8
			*reg_ |= ((value ? 1UL : 0UL) << bit);
		}
		bool bitGetValue(Bit bit)
		{
			return *reg & (1UL << bit);
		}

		void bitSet(Bit bit)
		{
			bitSetValue(bit, true);
		}
		void bitReset(Bit bit)
		{
			bitSerValue(bit, false);
		}
		bool bitToggle(Bit bit)
		{
			bool value = !bitGetValue(bit);

			bitSetValue(bit, value);

			return value;
		}

		// Bit Group
		void bitGroupSetValue(Bit startBit, u8 length, Reg value);
		Reg bitGroupGetValue(Bit startBit, u8 length);

		void bitGroupSet(Bit startBit, u8 length);
		void bitGroupReset(Bit startBit, u8 length);
		void bitGroupToggle(Bit startBit, u8 length);
	private:
		Reg* reg_;
	};
}

#endif

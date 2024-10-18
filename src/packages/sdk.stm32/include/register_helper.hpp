#ifndef __REGISTER_HELPER_HPP__
#define __REGISTER_HELPER_HPP__

#include "types.h"

namespace Memory
{

	template<reg_t reg>
	class RegisterHelper
	{
		// Bit
		void bitSetValue(Bit bit, bool value);
		bool bitGetValue(Bit bit);

		void bitSet(Bit bit);
		void bitReset(Bit bit);
		void bitToggle(Bit bit);

		// Bit Group
		void bitGroupSetValue(Bit startBit, u8 length, u32 value);
		u32 bitGroupGetValue(Bit startBit, u8 length);

		void bitGroupSet(Bit startBit, u8 length);
		void bitGroupReset(Bit startBit, u8 length);
		void bitGroupToggle(Bit startBit, u8 length);

	};
}

#endif

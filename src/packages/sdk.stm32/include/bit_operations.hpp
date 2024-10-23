#include <cstdint>
#include <iostream>

#define BIT_GET(value, bit) (value & (1UL << (bit)))
#define BIT_RESET(value, bit) (value &= ~(1UL << (bit)))
#define BIT_SET(value, bit) (value |= (1UL << (bit)))
#define BIT_TOGGLE(value, bit) (value ^= (1UL << (bit)))

#define BIT_GROUP_RESET(value, bit, size) (value &= ~((1UL << size) - 1))
#define BIT_GROUP_SET(value, bit, size, bit_group_value) (BIT_GROUP_RESET(value, (bit), (size))) |= (bit_group_value)

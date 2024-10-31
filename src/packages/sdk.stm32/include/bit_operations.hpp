#include <cstdint>

#define BIT_GET(value, bit) (value & (1UL << (bit)))
#define BIT_GET_PTR(ptr, bit) (BIT_GET(*(ptr), (bit)))
#define BIT_GET_ADDR(addr, bit) (BIT_GET_PTR(reinterpret_cast<uint32_t *>(addr), (bit)))

#define BIT_RESET(value, bit) (value &= ~(1UL << (bit)))
#define BIT_RESET_PTR(ptr, bit) (BIT_RESET(*(ptr), (bit)))
#define BIT_RESET_ADDR(addr, bit) (BIT_RESET_PTR(reinterpret_cast<uint32_t *>(addr), (bit))

#define BIT_SET(value, bit) (value |= (1UL << (bit)))
#define BIT_SET_PTR(ptr, bit) (BIT_SET(*(ptr), (bit)))
#define BIT_SET_ADDR(addr, bit) (BIT_SET_PTR(reinterpret_cast<uint32_t *>(addr), (bit)))

#define BIT_TOGGLE(value, bit) (value ^= (1UL << (bit)))
#define BIT_TOGGLE_PTR(ptr, bit) (BIT_TOGGLE(*(ptr), (bit)))
#define BIT_TOGGLE_ADDR(addr, bit) (BIT_TOGGLE_PTR(reinterpret_cast<uint32_t *>(addr), (bit)))

#define BIT_GROUP_RESET(value, bit, size) (value &= ~((1UL << size) - 1))
#define BIT_GROUP_RESET_PTR(ptr, bit, size) (BIT_GROUP_RESET(*(ptr), (bit), (size)))
#define BIT_GROUP_RESET_ADDR(addr, bit, size)(BIT_GROUP_RESET_PTR(reinterpret_cast<uint32_t *>(addr), (bit), (size)))

#define BIT_GROUP_SET(value, bit, size, bit_group_value) (BIT_GROUP_RESET(value, (bit), (size))) |= (bit_group_value)
#define BIG_GROUP_SET_PTR(ptr, bit, size, bit_group_value) (BIT_GROUP_SET(*(ptr), (bit), (size), (bit_group_value)))
#define BIT_GROUP_SET_ADDR(addr, bit, size, bit_group_value) (BIT_GROUP_SET_PTR(reinterpret_cast<uint32_t *>(addr), (bit), (size), (bit_group_value)))

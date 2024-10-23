#include <gtest/gtest.h>
#include <bitset>

#include "../include/bit_operations.hpp"

int main(int argc, char *argv[])
{
	std::bitset<32> out;
	int a = 0x00000000;
	out = a;
	std::cout << out << std::endl;
	BIT_SET(a, 0);
	out = a;
	std::cout << out << std::endl;
	BIT_SET(a, 2);
	out = a;
	std::cout << out << std::endl;
	BIT_RESET(a, 2);
	out = a;
	std::cout << out << std::endl;
	BIT_GROUP_SET(a, 0, 2, 2);
	out = a;
	std::cout << out << std::endl;
	BIT_GROUP_RESET(a, 0, 2);
	out = a;
	std::cout << out << std::endl;
}

#include <cstdint>
#include <iostream>

template<typename T1, int M>
T1 test()
{
	std::cout << M << std::endl;
	return T1();
}

template<int M>
struct test2
{
	template<typename T1>
	static T1 test2Fn(T1 inval)
	{
		std::cout << M << std::endl;
		return T1();
	}
};

int main()
{
  std::cout << "Hello world!" << std::endl;
  test<int, 10>();
  test2<20>::test2Fn(20U);
  int x = 10;
  int y = x * x;
  return y;
}

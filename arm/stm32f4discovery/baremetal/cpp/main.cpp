#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>
#include <cstdint>

unsigned char * const UART0_TX = (unsigned char *)0x40013804;


template<typename T>
T add(T x, T y)
{
	return x + y;
}


char x;
char y = 49;
char z = 55;


void print(const char *str)
{

	while(*str != '\0')
	{
		*UART0_TX = *str;
		str++;
	}
	*UART0_TX = '\n';
}

void printBss()
{

	*UART0_TX = x;
	*UART0_TX = '\n';
}
void printData()
{
	*UART0_TX = y;
	*UART0_TX = '\n';
}


class TestClass
{
private:

	char *local_var;
	static char *static_var;
public:
	TestClass()
	{
		local_var = "local_var\n";
	}

	void TestMethod(void)
	{
		print(__PRETTY_FUNCTION__);
		print(local_var);
		print(static_var);
		print("End TestMethod");
	}
};

char *TestClass::static_var = "static_var\n";


TestClass staticTestClass;

/*extern "C" void * _sbrk(int incr) {
   // [snip...]
	print(__PRETTY_FUNCTION__);
}*/

/*tern "C" unsigned __aeabi_uidivmod(unsigned numerator, unsigned denominator)
{
	print(__PRETTY_FUNCTION__);
	return 1;
}*/

int main(void)
{
	char buffer[32];

	x = add(40, 8);

	//x = 200 % 3 + 49;

	printf("[print]Hello world!\n");
	printf("[printf]Hello world!\n");
	printf("[print]Post Hello world!\n");

	//printBss();
	//printData();

	TestClass testClassInst;
	//testClassInst.TestMethod();
	
	//staticTestClass.TestMethod();

	printf("Before sprintf");
	sprintf(buffer, "INT=%d\n", 3U);
	//sprintf(buffer, "s=", "Test");
	printf(buffer);
	printf("Aftersprintf");



	return 0;
}

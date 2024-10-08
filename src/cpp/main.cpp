#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

int const a = 5;
int const b = 10;
char const c = 'a';

int x = 0;

int y = a;

int z;

class Test
{
public:
    Test();
};

Test::Test()
{
    ++x;
}

class Test2
{
public:
	Test2();
};

Test2::Test2()
{
	++x;
}


Test test;
Test2 test2;

int main()
{
    printf("Hello world!\n");
    while(1)
    {
		printf("TEST TEST TEST\n");
    }
}

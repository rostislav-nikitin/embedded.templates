#include <iostream>

class Base
{
public:
	virtual void test()
	{
		
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
};

class A : public virtual Base
{
public:
	virtual void test() override
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
};

class B : public virtual  Base
{
public:
	virtual void test() override
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
};

class C: public A, public B
{
public:
	virtual void test() override
	{
		A::test();
	}
};

void call_base(Base& base)
{
	base.test();
}

int main()
{
	/*
	A a{};
	a.test();
	B b{};
	b.test();
	Base base {b};
	base.test();
	((Base)base).test();

	call_base(a);
	*/
/*
	Base *a = new A();
	a->test();

	A *a2 = new A();
	((Base *)a2)->test();

	Base *a3 = dynamic_cast<Base *>(a2);
	a3->Base::test();
*/

	 C c{};
	 c.test();

	 Base &baseC = c;
	 baseC.test();
}

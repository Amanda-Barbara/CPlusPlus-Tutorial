#include<iostream>

class Base
{
public:
	virtual ~Base(){}
	virtual void Print()
	{
		std::cout<< "Hello Base." <<std::endl;
	}
};

class Derived1 : public Base
{
public:
	virtual void Print()
	{
		std::cout<< "Hello Derived1 from Base." <<std::endl;
	}
};

class Derived2 : public Base
{
public:
	virtual void Print()
	{
		std::cout<< "Hello Derived2 from Base." <<std::endl;
	}
};

int main(int argc, char **argv)
{
	Base* p = new Derived1();
	p->Print(); // Normal Paint
	delete p;

	p = new Derived2();
	p->Print(); // Colorfullly Paint
	delete p;
	
	return 0;
}

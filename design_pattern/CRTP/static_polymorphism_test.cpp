#include <iostream>

template<class T>
class Base
{
public:
	void InterfaceAPI()
	{
		static_cast<T&>(*this).Print(); //使用static_cast进行类型的强制转换，缺点是类型转换不安全。
	}

	void Print()
	{
		std::cout<< "Paint" <<std::endl;
	}
};

class Derived1 : public Base<Derived1>
{
public:
	void Print()
	{
		std::cout<< "Hello Derived1 from Base." <<std::endl;
	}
};

class Derived2 : public Base<Derived2>
{
public:
	void Print()
	{
		std::cout<< "Hello Derived2 from Base." <<std::endl;
	}
};

int main(int argc, char **argv)
{
	Base<Derived1> d1;
	d1.InterfaceAPI();

	Base<Derived2> d2;
	d2.InterfaceAPI();
	
	return 0;
}

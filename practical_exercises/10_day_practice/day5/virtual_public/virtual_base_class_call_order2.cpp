#include <iostream>
using namespace std;

class A {
public:
    int a; //initialize an indeterminate value
	void show()
	{
		printf("Hello from A, the value a is %d.\n", a);
	}
};

class B : virtual public A {
};

class C : virtual public A {
};

class D : public B, public C {
};

int main()
{
	D object;
	object.show();
    printf("sizeof(A): %d.\n", sizeof(A));
    printf("sizeof(B): %d.\n", sizeof(B));
    printf("sizeof(D): %d.\n", sizeof(D));
    return 0;
}

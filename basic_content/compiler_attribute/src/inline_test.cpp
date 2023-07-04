#include <iostream>

using namespace std;

inline __attribute__((always_inline)) int add(int *a)
{
    // return (*a)++; //返回值还是3，
    return ++(*a);
}

int main()
{
    int ia = 3;
    cout << add(&ia) << endl;
    cout<<"Hello World";

    return 0;
}

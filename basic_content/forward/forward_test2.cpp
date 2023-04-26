// forward example
#include <utility>      // std::forward
#include <iostream>     // std::cout
#include <typeinfo>

// function with lvalue and rvalue reference overloads:
void overloaded (int& x) {printf("[lvalue]: %d.\n", x);}
void overloaded (const int& x) {printf("const [lvalue]: %d.\n", x);}
void overloaded (int&& x) {printf("[rvalue]: %d.\n", x);}

// function template taking rvalue reference to deduced type:
template <class T> 
void wrapper (T&& x) {
//   std::cout << typeid(x).name() << std::endl;
//   std::cout << typeid(std::forward<T>(x)).name() << std::endl;
  overloaded (x);                   // always an lvalue
  overloaded (std::forward<T>(x));  // rvalue if argument is rvalue
}

int main () {
  int a = 111;
  const int b = 999;
  const int& c = b;
//   std::cout << "calling wrapper with lvalue: ";
  wrapper (a);
  wrapper(b); //最终执行的都是overloaded (const int& x)
  wrapper(c);
  wrapper(std::move(a));
//   std::cout << '\n';

//   std::cout << "calling wrapper with rvalue: ";
  wrapper (0);
//   std::cout << '\n';

  return 0;
}
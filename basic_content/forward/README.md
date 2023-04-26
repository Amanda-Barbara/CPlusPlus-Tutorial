# `forward`讲解

## [`std::forward`与`std::move`](./forward_test.cpp)
```c++
template <class T> T&& forward (typename remove_reference<T>::type& arg) noexcept; //typename 告诉编译器remove_reference<T>::type是一个类型而不一个变量
template <class T> T&& forward (typename remove_reference<T>::type&& arg) noexcept;
```
* `std::forward`与`std::move`都是函数模板，`std::forward`会根据传入的参数进行模板参数类型推断，而`std::move`会把传入的参数强制进行右值转换；
* `std::forward`类型推断规则如下
```text
If a call to wrapper() passes an rvalue int, then T is deduced to int (not int&, const int&, or int&&), and std::forward ensures that an rvalue reference is passed to overloaded (int&& x).
If a call to wrapper() passes a const lvalue int, then T is deduced to const int&, and std::forward ensures that a const lvalue reference is passed to overloaded (const int& x).
If a call to wrapper() passes a non-const lvalue int, then T is deduced to int&, and std::forward ensures that a non-const lvalue reference is passed to overloaded (int& x).
```

```c++
#include <utility>      // std::forward
// function with lvalue and rvalue reference overloads:
void overloaded (int& x) {printf("[lvalue]: %d.\n", x);}
void overloaded (const int& x) {printf("const [lvalue]: %d.\n", x);}
void overloaded (int&& x) {printf("[rvalue]: %d.\n", x);}
template <class T> 
void wrapper (T&& x) {
  overloaded (x);                   // always an lvalue
  overloaded (std::forward<T>(x));  // rvalue if argument is rvalue
}
int main () {
  int a = 111;
  const int b = 999;
  const int& c = b;
  wrapper (a);
  wrapper(b); //最终执行的都是overloaded (const int& x)
  wrapper(c);
  wrapper(std::move(a));
  wrapper (0);
  return 0;
}
```
* 程序输出结果如下：
```text
[lvalue]: 111.
[lvalue]: 111.
const [lvalue]: 999.
const [lvalue]: 999.
const [lvalue]: 999.
const [lvalue]: 999.
[lvalue]: 111.
[rvalue]: 111.
[lvalue]: 0.
[rvalue]: 0.
```

## 参考链接
* 1 [`cppreference`之`forward`讲解](https://en.cppreference.com/w/cpp/utility/forward)
* 2 [`cplusplus`之`forward`讲解](https://cplusplus.com/reference/utility/forward/)

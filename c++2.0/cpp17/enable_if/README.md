# [`std::enable_if`类模板](./enable_if_test.cpp)

## `std::enable_if`类模板定义
* 如果`Cond`为`true`，则类型`T`作为`std::enable`类模板的`enable_if::type`成员启用；否则，`enable_if::type`是`void`类型。
```c++
template <bool Cond, class T = void> struct enable_if;
```
与下面代码等价
```c++
template<bool Cond, class T = void> 
struct enable_if {};
template<class T> 
struct enable_if<true, T> { typedef T type; };
```
* `is_even(3.0)`将会报错，这是因为is_even是一个模板函数，没有针对模板参数是浮点类型的实现

## 参考链接
* 1 [`cplusplus`之`std::enable_if`教程](https://cplusplus.com/reference/type_traits/enable_if/)
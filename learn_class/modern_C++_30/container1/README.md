# 常用容器总结

## [`std::fill`函数模板](./vector_fill_test.cpp)
```c++
template <class ForwardIterator, class T>  void fill (ForwardIterator first, ForwardIterator last, const T& val);
```
* 目前仅支持`vector`类型模板从起始位置到终止位置的元素赋值

## [实现不同容器类型的`std::advance`功能](./advance_implementation_test.cpp)
* `advance_impl`函数模板实现了不同

## [`stl`容器中的`std::advance`函数模板](./list_advance_test.cpp)
```c++
template <class InputIterator, class Distance>  void advance (InputIterator& it, Distance n);
```
* `std::advance`将迭代器向前移动n个元素位置。

## [`vector`之`assign`属性用法](./vector_assign_test.cpp)
* `assign`使用不同的构造函数实现了多种不同的用法对数组进行赋值操作

## [`vector`之`erase`属性用法](./vector_erase_test.cpp)
* 删除指定位置元素，也可以删除指定起始位置到终止位置之间的元素并返回原地址数组

## 参考链接
* 1 [`cppreference`之`vector`的`assign`属性讲解](https://en.cppreference.com/w/cpp/container/vector/assign)
* 2 [`cplusplus`之`std::fill`函数模板讲解](https://cplusplus.com/reference/algorithm/fill/)
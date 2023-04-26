# 常用容器总结

## [`stl`容器中的`std::advance`函数模板](./list_advance_test.cpp)
```c++
template <class InputIterator, class Distance>  void advance (InputIterator& it, Distance n);
```
* 将迭代器向前移动n个元素位置。

## [`vector`之`assign`属性用法](./vector_assign_test.cpp)
* `assign`使用不同的构造函数实现了多种不同的用法

## [`vector`之`erase`属性用法](./vector_erase_test.cpp)
* 删除指定位置元素，也可以删除指定起始位置到终止位置之间的元素并返回一个新的

## 参考链接
* 1 [`cppreference`之`vector`的`assign`属性讲解](https://en.cppreference.com/w/cpp/container/vector/assign)
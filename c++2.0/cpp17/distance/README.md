# `std::distance`函数模板
## `std::distance`函数模板定义
* 函数模板`std::distance`的返回值类型是`iterator_traits<InputIterator>::difference_type`，计算从起始位置到终止位置的距离。
```c++
template<class InputIterator>  
typename iterator_traits<InputIterator>::difference_type distance (InputIterator first, InputIterator last);
```


## 参考链接
* 1 [`cpprefernce`之`std::distance`函数模板教程](https://en.cppreference.com/w/cpp/iterator/distance)
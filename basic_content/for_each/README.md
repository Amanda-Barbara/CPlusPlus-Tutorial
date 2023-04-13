# `for_each`

## 使用迭代器迭代自定义函数[](./for_each_test.cpp)
* 自定义函数可以包含如下类型但可能不仅限于此：
```c++
auto print = [](const int& n) { std::cout << n << ' '; }; //函数定义
[](int &n) { n++; } //lambda表达式
void operator()(int n) { sum += n; } //重载operator()运算符
```

## 参考链接
* 1 [`cppreference.com`之`for_each`讲解](https://en.cppreference.com/w/cpp/algorithm/for_each)
* 2 []()
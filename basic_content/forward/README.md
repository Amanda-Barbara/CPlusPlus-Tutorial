# `forward`讲解

## [`std::forward`与`std::move`](./forward_test.cpp)
* `std::forward`会根据传入的参数进行模板参数类型推断，而`std::move`会把传入的参数强制进行右值转换；
* `std::forward`与`std::move`本质上都是类型转换函数；


## 参考链接
* 1 [`cppreference`之`forward`讲解](https://en.cppreference.com/w/cpp/utility/forward)
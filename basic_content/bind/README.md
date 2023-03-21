# `std::bind`与`std::function`
* `std::function`是构建通用功能的多态函数装饰器的类模板，`std::bind`绑定到具体函数的函数模板

```c++
std::map<const char , std::function<double(double, double)>> dispTable{  // (1)
        {'+', add },                                         // (2)
        {'-', Sub() },                                       // (3)
        {'*', std::bind(multThree, 1, std::placeholders::_1, std::placeholders::_2) },             // (4)
        {'/',[](double a, double b){ return a / b; }}};      // (5)

std::cout << "3.5 + 4.5 = " << dispTable['+'](3.5, 4.5) << '\n';
std::cout << "3.5 - 4.5 = " << dispTable['-'](3.5, 4.5) << '\n';
std::cout << "3.5 * 4.5 = " << dispTable['*'](3.5, 4.5) << '\n';
std::cout << "3.5 / 4.5 = " << dispTable['/'](3.5, 4.5) << '\n';
```

* [参考示例](src/bind_function_test.cpp)


## 参考链接
* 1 [`std::function`与`std::bing`以及`type erasure`类型擦除教程](https://www.modernescpp.com/index.php/type-erasure)


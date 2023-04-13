# 运算符重载

## [`operator[]`运算符重载](./operator_overloading_test.cpp)
```c++
s["张三"] = 2188.88;
s.operator[]("李四") = 3000; //按照函数的调用方式进行赋值操作
```

## [`operator()`、`double()`、`std::string()`重载](./operator_overloading_test2.cpp)
```c++
operator double() const {return double(11);}
operator std::string() const { return "I am a foo!"; }
void operator()(int n) { sum += n; }
```

## 参考链接
* 1 [`cppreference`之`operator`运算符重载](https://en.cppreference.com/w/cpp/language/operators)
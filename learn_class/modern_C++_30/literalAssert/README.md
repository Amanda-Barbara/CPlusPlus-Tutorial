# 断言
* 断言是对某种假设条件进行检查

## 静态断言[](./assert.cpp)
* `assert`断言是在程序运行时进行检查是否合法，编译时期不检查；`static_assert`断言则是在编译时就检查语句是否正确；
```c++
const int alignment=5;
printf("(alignment & (alignment - 1)) = %d\n. ", (alignment & (alignment - 1))); //输出结果为4
assert((alignment & (alignment - 1)) == 0); //在程序运行时检查，编译时不检查。
static_assert((alignment & (alignment - 1)) == 3, "Alignment must be power of two"); //在程序编译时检查。
```


## 参考链接
* 1 [`cppreference`之`static_assert`断言](https://en.cppreference.com/w/cpp/language/static_assert)
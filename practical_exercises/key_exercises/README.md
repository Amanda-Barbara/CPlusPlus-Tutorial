## 重点实战练习

├── [中括号重载.cpp](中括号重载.cpp)
├── [时钟++运算符重载.cpp](时钟++运算符重载.cpp)
├── [运算符重载之强制转换.cpp](运算符重载之强制转换.cpp)
└── [重载圆括号的时钟.cpp](重载圆括号的时钟.cpp)

├── [函数模板.cpp](函数模板.cpp)

├── [动态数组.cpp](动态数组.cpp)

├── [字典插入与查找.cpp](字典插入与查找.cpp)

├── [异常捕获.cpp](异常捕获.cpp)

├── [类模板之栈.cpp](类模板之栈.cpp)

├── [类模板特化之数组.cpp](类模板特化之数组.cpp)

├── [继承与封装.cpp](继承与封装.cpp)

├── [读写文件综合题.cpp](读写文件综合题.cpp)
├── [输入输出运算符重载.cpp](输入输出运算符重载.cpp)
├── [输入输出重载.cpp](输入输出重载.cpp)
├── [输出格式.cpp](输出格式.cpp)

## 运算符重载
* `new`、`delete`、`size_t`是操作符，而不是函数
```text
void* MyClass::operator new(size_t size) {
   return malloc(size);
}

void MyClass::operator delete(void* ptr) {
   free(ptr);
}
inline MatStep::operator size_t() const
{
    CV_DbgAssert( p == buf );
    return buf[0];
}
```


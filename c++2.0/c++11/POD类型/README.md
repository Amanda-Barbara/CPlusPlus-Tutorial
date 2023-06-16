# `POD`类型
* POD（Plain Old Data）是C++中非常重要的一个概念，用来描述一个类型的属性其中Plain表示这个类型是个平凡的类型，Old表示其与C的兼容性。C++11中将POD划分为两个基本概念：平凡的（trival）和标准布局（standardlayout）

## `POD`的好处
```text
1 字节赋值，我们可以放心的使用memset和memcpy对POD类型进行初始化和拷贝。
2 提供对C内存的兼容。POD类型的数据在C与C++间的操作总是安全的。
3 保证了静态初始化的安全有效。POD类型的对象初始化往往更简单。
```

## 参考链接
* 1 [`POD`类型讲解](https://blog.csdn.net/Jxianxu/article/details/80524526)
* 2 [`std::is_pod`代码示例](https://cplusplus.com/reference/type_traits/is_pod/)
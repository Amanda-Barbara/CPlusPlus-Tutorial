# tuple用法总结

## `tuple`类模板
* `C++`中，`std::vector`、`std::list`、`std::map`、`std::set`等容器都只能存储同一种类型，属于同质容器。而`std::tuple`类模板弥补了`std::pair`只能存储两种类型对象的缺陷，可以像`class`或`struct`一样存储不同类型的对象，只是访问的方式不同。

## 参考链接
* 1 [`cpprefernce`之`tuple`教程](https://en.cppreference.com/w/cpp/utility/tuple)
* 2 [走近`std::tuple`，揭秘`C++`元组的底层实现原理](https://zhuanlan.zhihu.com/p/356954012)
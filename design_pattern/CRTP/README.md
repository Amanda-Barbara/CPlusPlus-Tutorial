# **CRTP**奇异递归模板模式

## 静态多态与动态多态
* 动态多态更加灵活，适合更复杂的应用场景。静态多态是编译期实现的多态，性能更强。
### [动态多态](./dynamic_porlymorphism_test.cpp)
* 动态多态，即在运行时，也即代码执行时表现出来的多种状态。
* 在语法层面，是通过使用virtual标记基类的函数，然后在派生类中重写此函数。在代码执行时，通过基类指针或引用的真实派生类型来调用派生类中的实现。
* 在实现层面，主要是通过虚函数表来实现的。基类有virtual函数，则有一个虚函数表，那么派生类也会有一上自己的虚函数表。调用虚函数时，与指针类型无关，而与指针指向的具体是哪一个对象，调用的时候就会去查找相应对象的虚函数表，找到并执行相应虚函数。

#### 动态多态优缺点分析
* 优点
```text
增加新的实现，不用修改以前的代码，减少对过往功能可靠性的影响。
实现接口保持一致，可以更方便地添加新的实现。
```

* 缺点
```text
动态多态是通过虚函数表来实现的，每个派生类实现的虚函数并不固定，所以虚函数表大小并不固定，这就导致每次虚函数的调用，都需要有一个查找虚函数表的过程，这就导致调用虚函数的性能会降低。
虚函数表与普通成员函数的内存分配并不是在一起的，也就是说虚函数表的设计并不是Cache友好型设计，这就导致CPU的流水线在执行代码时，代码的命中效率会降低，降低虚函数的调用性能。
```
### [静态多态](./static_polymorphism_test.cpp)
* 静态多态，是指在编译期间实现的多态。
* 静态多态主要是通过一种CRTP(curiously recurring template pattern)技术来实现的，即一个类`X`派生自以`X`自身为模板形参的类模板实例。
下面的代码，主要依靠模板实例化时才编译，以及派生类可以访问基类模板类中的成员及方法。需要注意的是，派生类函数的调用是通过强制类型转换来实现的，这里的强制转换是不安全的，所以派生类实现无法访问派生类中的其他成员。
* 有人将函数重载理解为静态多态，但是函数重载要求形参不同，这与虚函数实现的多态有较大差异。此处讲的静态多态，与虚函数实现的动态多态类型，函数名相同，函数参数也相同。


## [模板特化](./template_specilization.cpp)

## [模板偏特化](./template_partial_specilization.cpp)

## [实现**静态多态**](./object_counter.cpp)
* 第一个示例实现统一的`Interface`接口，看懂了这个基本就把静态多态掌握了。
* 第二个示例是统计派生类对象的个数。


## 参考链接
* 1 [模板特化与偏特化](https://www.jianshu.com/p/4be97bf7a3b9)
* 2 [奇异递归模板模式](https://zhuanlan.zhihu.com/p/460497652)
* 3 [`C++`的动态多态与静态多态讲解](https://blog.csdn.net/feihe0755/article/details/117662440)
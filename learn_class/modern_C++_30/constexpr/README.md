# `constexp`关键字总结

## 一般的`static`类内成员变量
```c++
class A {
public:
	static int i1;
	static bool b1;
	static char c1;

	static float f1;
	static double d1;
	
	//以下错误，不能将一般static类型的变量在类内初始化,只能进行声明
	//static int i2 = 2;
	//static bool b2 = true;
	//static char c2 = 'c';
	//static float f2 = 3.1;
	//static double d2 = 3.2;
};
int A::i1 = 1;
bool A::b1 = true;
char A::c1 = 'c';
float A::f1 = 3.3;
double A::d1 = 3.4;

```
## `static const` 类内成员变量
```c++
class A {
public:
	static const int i1;
	static const bool b1;
	static const char c1;

	static const float f1;
	static const double d1;
	//整形类型的static const变量可以在类内初始化
	static const int i2 = 2;
	static const bool b2 = true;
	static const char c2 = 'c';
	//以下错误，不能将static const类型的变量在类内初始化,只能进行声明
	//static const float f2 = 3.1;
	//static const double d2 = 3.2;
};
const int A::i1 = 1;
const bool A::b1 = true;
const char A::c1 = 'c';
const float A::f1 = 3.3;
const double A::d1 = 3.4;

```
## `static constexp` 类内成员变量
```c++
class A {
public:
	static const int i1;
	static const bool b1;
	static const char c1;

	static const float f1;
	static const double d1;
	//整形类型的static const变量可以在类内初始化
	static const int i2 = 2;
	static const bool b2 = true;
	static const char c2 = 'c';
	//以下错误，不能将static const类型的变量在类内初始化,只能进行声明
	//static const float f2 = 3.1;
	//static const double d2 = 3.2;
};
const int A::i1 = 1;
const bool A::b1 = true;
const char A::c1 = 'c';
const float A::f1 = 3.3;
const double A::d1 = 3.4;

```

## 参考链接
* 1 [`static constexp`关键字使用](https://blog.csdn.net/mxyhktk/article/details/112016564)

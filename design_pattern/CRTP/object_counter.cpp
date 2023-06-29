#include <iostream>


template <class Derived> 
struct Base
{
    void Interface() {
        static_cast<Derived*>(this)->Implementation(); 
        /*
        把Base类对象通过static_cast关键字强制转换为Derived类的对象指针，
        然后再调用Derived类对象指针的成员函数Implementation.
        如果继承自Base类的派生类Derived没有实现Implementation，则会调用Base类的Implementation接口函数。
        */        
    }
    void Implementation(){printf("base class implementation.\n");}

};

// 不声明DerivedTest为模板类
struct DerivedTest : Base<DerivedTest> {
    void Implementation(){printf("derived class implementation.\n");}; //注释之后就会调用Base类的Implementation接口函数。
};

// 声明DerivedTestTemp为模板类
template <typename T>
class DerivedTestTemp : public Base<DerivedTestTemp<T>> {};// 没有实现Implementation函数，则会调用Base类的Implementation函数。




template <class Derived>
class ObjectCounter {
 private:
  inline static std::size_t count{0};

 protected:
  ObjectCounter() { ++count; }
  ObjectCounter(const ObjectCounter&) { ++count; }
  ObjectCounter(ObjectCounter&&) { ++count; }
  ~ObjectCounter() { --count; }

 public:
  static std::size_t CountLive() { return count; }
};

// template <typename T>
// class X : public ObjectCounter<X<T>> {};

// class Y : public ObjectCounter<Y> {};

template <typename T>
class MyVector: public ObjectCounter<MyVector<T>> {}; //声明和定义新类型

class MyCharString : public ObjectCounter<MyCharString> {}; //声明和定义新类型

template <>
class MyVector<std::string> : public ObjectCounter<MyVector<std::string>> {}; //声明和定义新类型

int main() {

  DerivedTest derivedTest;
  derivedTest.Interface();
  DerivedTestTemp<int> derivedTestTemp;
  derivedTestTemp.Interface();
  

  MyVector<int> v1, v2;
  MyVector<std::string> s;
  MyCharString s1;
  std::cout << "number of MyVector<int>: " << MyVector<int>::CountLive() << "\n";
  std::cout << "number of MyVector<std::string>: " << s.CountLive() << "\n";
  std::cout << "number of MyCharString: " << MyCharString::CountLive() << "\n";

  return 0;
}
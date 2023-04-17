#include <iostream>

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
class MyVector : public ObjectCounter<MyVector<T>> {}; //声明和定义新类型

class MyCharString : public ObjectCounter<MyCharString> {}; //声明和定义新类型

int main() {
  MyVector<int> v1, v2;
  MyCharString s1;

  std::cout << "number of MyVector<int>: " << MyVector<int>::CountLive()
            << "\n";

  std::cout << "number of MyCharString: " << MyCharString::CountLive() << "\n";
  return 0;
}
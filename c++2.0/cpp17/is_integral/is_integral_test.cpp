// is_integral example
#include <iostream>
#include <type_traits>

int main() {
  std::cout << std::boolalpha; //把输出流中的bool类型的对象解析成true或者false字符串，而不是输出1或者0的字符
  std::cout << "is_integral:" << std::endl;
  std::cout << "char: " << std::is_integral<char>::value << std::endl;
  std::cout << "int: " << std::is_integral<int>::value << std::endl;
  std::cout << "float: " << std::is_integral<float>::value << std::endl;
  return 0;
}
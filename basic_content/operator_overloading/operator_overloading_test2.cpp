

#include <string>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
 

struct Sum
{
    int sum = 0;
    void operator()(int n) { sum += n; }
};

 
class Foo {
public:
    operator double() const {return double(11);}
    operator std::string() const { return "I am a foo!"; }
};


int main()
{
    Foo foo;
    printf("overloading of operator std::string() %s\n", foo.operator std::string().c_str()); // Will print "I am a foo!".
    printf("overloading of operator std::string() %s\n", std::string(foo).c_str()); // Will print "I am a foo!".
    printf("overloading of operator double() %f\n", double(foo));
    printf("overloading of operator double() %f\n", foo.operator double());
    
    std::vector<int> v = {1, 2, 3, 4, 5};
    Sum s = std::for_each(v.begin(), v.end(), Sum());
    printf("The sum is %d.\n", s.sum);
    
    return 0;
}
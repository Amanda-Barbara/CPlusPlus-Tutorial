#include <iostream>
#include <cstring>
using namespace std;

struct Person
{ //职工基本信息的结构
    double salary;
    char *name;
};
class SalaryManaege
{
    Person *employ; //存放职工信息的数组
    int max;        //数组下标上界
    int n;          //数组中的实际职工人数
public:
    SalaryManaege(int Max = 0)
    {
        max = Max;
        n = 0;
        employ = new Person[max];
    }
    //返回引用特性是可以直接在放在左值，直接使用
    double &operator[](char *Name)
    { //重载[]，返回引用
        Person *p;
        for (p = employ; p < employ + n; p++)
            //如果存在处理
            if (strcmp(p->name, Name) == 0)
                return p->salary;
        //不存在情况处理
        p = employ + n++;
        p->name = new char[strlen(Name) + 1];
        strcpy(p->name, Name);
        p->salary = 0;
        return p->salary;
    }

    void display()
    {
        for (int i = 0; i < n; i++)
            cout << employ[i].name << "   " << employ[i].salary << endl;
    }
    ~SalaryManaege() {
        delete employ;
    }
};

int main()
{
    SalaryManaege s(4);
    s["张三"] = 2188.88;
    s.operator[]("李四") = 3000; //按照函数的调用方式进行赋值操作
    s["里斯"] = 1230.07;
    s["王无"] = 3200.97;
    cout << "张三\t" << s["张三"] << endl;
    cout << "里斯\t" << s["里斯"] << endl;
    cout << "李四\t" << s["李四"] << endl;
    cout << "王无\t" << s["王无"] << endl;

    cout << "-------下为display的输出--------\n\n";
    s.display();

    int a,b,c=0;
    c=b=a=10;
    printf("a,b,c : %d,%d,%d\n.", a,b,c);
    return 0;
}




// #include <string>
// #include <stdio.h>
// #include <algorithm>
// #include <iostream>
// #include <vector>
 

// struct Sum
// {
//     int sum = 0;
//     void operator()(int n) { sum += n; }
// };

 
// class Foo {
// public:
//     operator double() const {return double(11);}
//     operator std::string() const { return "I am a foo!"; }
// };


// int main()
// {
//     Foo foo;
//     printf("overloading of operator std::string() %s\n", std::string(foo).c_str()); // Will print "I am a foo!".
//     printf("overloading of operator double() %f\n", double(foo));
    
//     std::vector<int> v = {1, 2, 3, 4, 5};
//     Sum s = std::for_each(v.begin(), v.end(), Sum());
//     printf("The sum is %d.\n", s.sum);
    
//     return 0;
// }
#include <iostream>
using namespace std;

#define exp(s) printf("test s is:%s\n",s)
#define exp1(s) printf("test s is:%s\n",#s)
#define exp2(s) #s 
#define exp3(s) s
int main() {
    exp("hello"); //像函数一样调用
    exp1(hello); //hello虽然是一个未定义的，但是可以通过宏定义把未定义的hello转换为字符串hello
    int a = 10; 
    exp1(a); //把int类型的变量a字符串化为"a"
    exp1(reg "fa" off); //把未定义的reg "fa" off字符串化为reg "fa" off
    exp1(exp); //把exp当作形参s，并打印出exp
    cout << exp3(3) << endl; //打印出常量3
    // cout << exp3(gaga) << endl; //由于gaga未定义，编译未通过
    cout << exp2(gaga) << endl; //把未定义的gaga字符串化
    string str = exp2(   bac );
    cout<<str<<" "<<str.size()<<endl;
    /**
     * 忽略传入参数名前面和后面的空格。
     */
    string str1 = exp2( asda  bac );
    /**
     * 当传入参数名间存在空格时，编译器将会自动连接各个子字符串，
     * 用每个子字符串之间以一个空格连接，忽略剩余空格。
     */
    cout<<str1<<" "<<str1.size()<<endl;
    return 0;
}
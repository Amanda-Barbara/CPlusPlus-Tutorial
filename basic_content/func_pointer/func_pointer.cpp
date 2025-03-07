/**
 * @file func_pointer.cpp
 * @brief 函数指针的使用！
 * @author 光城
 * @version v1
 * @date 2019-07-20
 */

#include<iostream>
using namespace std;

/**
 * @brief 定义了一个变量pFun，这个变量是个指针，指向返回值和参数都是空的函数的指针！
 */
void (*pFun)(int); 

/**
 * @brief typedef关键字表示的是一种类型别名，代表一种新类型，不是变量！所以与上述的pFun不一样！
 * pFun是一个函数，而经过typedef关键字修饰过的func则是一个函数指针类型。可以把符合的参数类型的函数赋值给func
 */
typedef void (*func)(void);  

void myfunc(void)
{
    cout<<"asda"<<endl;
}

void glFun(int a){ cout<<a<<endl;} 
int main(){
    func pfun = myfunc;/*赋值*/  
    pfun();/*调用*/  
    pFun = glFun; 
    (*pFun)(2); 
}

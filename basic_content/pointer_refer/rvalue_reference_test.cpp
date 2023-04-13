#include <iostream>
#include <utility>

int s=101;

int&& foo(){return static_cast<int&&>(s);} //返回值为右值引用

int main() {
    int i=foo();   //右值引用作为右值，在赋值运算符的右侧
    printf("address of i: %p.\n", &i);
    int&& j=foo(); //j是具名引用。因此运算符左侧的右值引用作为左值
    printf("address of j: %p.\n", &j);
    int* p=&j;     //取得j的内存地址
    int ii = 99;
    int &&jj=99; //jj也是具名引用，因此运算符左侧的右值引用变量jj也是作为左值使用，jj有地址
    printf("address of jj: %p.\n", &jj);
    printf("address of ii: %p.\n", &ii);
    int &&k=std::move(ii);  //std::move定义于<utility>，k的地址与ii相同。
    printf("address of ii: %p.\n", &ii);
    printf("address of k: %p.\n", &k);
    for (size_t i = 0; i < 1000000000; i++)
    {
        printf("address of ii: %p.\n", &ii);
    }
    
    return 0;
}
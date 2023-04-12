#include<iostream>
#include<stdio.h>

using namespace std;


#define COMPILER_CONCAT_(a, b) 	a##b
#define COMPILER_CONCAT(a, b) 	COMPILER_CONCAT_(a, b)
#define COMPILER_ASSERT(e) 		enum { COMPILER_CONCAT(compiler_assert_, __COUNTER__) = 1/((e) ? 1 : 0) }


/// 使用方法
#define A		(1)
#define B		(2)

COMPILER_ASSERT(A == 1);	///< 可以编译通过
// COMPILER_ASSERT(A == B);	///< 编译报错

int main() {
    printf("%d \n", __COUNTER__);
    printf("%d \n", __COUNTER__);
    printf("%d \n", __COUNTER__);

}

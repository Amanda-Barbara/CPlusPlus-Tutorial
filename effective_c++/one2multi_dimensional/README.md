# 一维数组转多维的高效实现方式

## [`c++`实现一维数组转换为多维](./convertOneToMultiDim.cpp)
```c++
const int row = 2;
const int col = 4;
float buffer[row*col] = {0,1,2,4,8,9,7,12};
// long long int(&output0)[row][col] = *((long long int(*)[row][col])buffer); //强制类型转换的引用会导致单位存储的内存占用的字节数会变化进而导致新数组根据索引取值的错位
float(*output0)[col] = *((float(*)[row][col])buffer); //向系统申请了新的内存资源用来存储output0的地址，不够高效
float(&output0_ref)[row][col] = *((float(*)[row][col])buffer);
float(&output1)[1][col] =*((float(*)[1][col])(buffer + col));
```
* `float(&output0)[row][col] = *((float(*)[row][col])buffer);`上述代码通过`c++`实现的一维到多维的高效转换具有如下优势：
1. 代码简洁，节省了使用`for`循环的方式来编排数据的摆放。
2. 节省了空间的使用，使用`buffer`的引用避免了内存的开销。

* `buffer`、`output0`、`output0_ref`、`output1`的变量及其存储地址信息

![](data/oneToMultiDimTest.png)

![](data/oneToMultiDimTest2.PNG)

* 执行结果
```text
output0[0,0]: 0.000000; output0_ref[0,0]: 0.000000; output1[0,0]: 8.000000.
output0[0,1]: 1.000000; output0_ref[0,1]: 1.000000; output1[0,1]: 9.000000.
output0[0,2]: 2.000000; output0_ref[0,2]: 2.000000; output1[0,2]: 7.000000.
output0[0,3]: 4.000000; output0_ref[0,3]: 4.000000; output1[0,3]: 12.000000.
output0[1,0]: 8.000000; output0_ref[1,0]: 8.000000; output1[0,0]: 8.000000.
output0[1,1]: 9.000000; output0_ref[1,1]: 9.000000; output1[0,1]: 9.000000.
output0[1,2]: 7.000000; output0_ref[1,2]: 7.000000; output1[0,2]: 7.000000.
output0[1,3]: 12.000000; output0_ref[1,3]: 12.000000; output1[0,3]: 12.000000.
address of the buffer : 0x7fffffffd310
address of the output0 : 0x7fffffffd310
address of the output0_ref : 0x7fffffffd310
address of the output1 : 0x7fffffffd320
buffer=7fffffffd310, output0=7fffffffd310, output0_ref=7fffffffd310, output1=7fffffffd320
buffer=140737488343824, output0=140737488343824, output0_ref=140737488343824, output1=140737488343840
```

* 待解读`int(*)[]`用法
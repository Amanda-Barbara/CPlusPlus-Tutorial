# `std::barrier`类模板解析

## 不使用`std::barrier`
```c++
//sync_point.arrive_and_wait();
```
程序执行结果如下：
```text
Starting...
  anil worked1
  carl worked1
  anil cleaned2
  anil worked3
  carl cleaned2
  carl worked3
  busara worked1
  busara cleaned2
  busara worked3
```
每个工人各做自己的事情，互不打扰，做完一件就立马显示，没有集体协作(数据交互)的交互

## `std::barrier`
```c++
sync_point.arrive_and_wait();
```
程序执行结果
```text
Starting...
  anil worked1
  carl worked1
  busara worked1
... 123done
Cleaning123 up...
  busara cleaned2
  carl cleaned2
  anil cleaned2
... done
  anil worked3
  carl worked3
  busara worked3
... done
```
每个工人各做自己的事情，当做完第一件事情的时候就会等待其他没有做完第一件事的工人，
如果三个工人都做完了第一件事情，才会去做第二件事情，这样就有集体协作(数据交互)的交互。
## 参考链接
* 1 [std::barrier](https://en.cppreference.com/w/cpp/thread/barrier)
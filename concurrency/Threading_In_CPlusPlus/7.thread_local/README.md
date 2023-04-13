# `thread_local`

* 被`thread_local`关键字修饰的变量在每个创建的线程（包括主线程）则享受单独的存储空间，与其他线程不共享被`thread_local`修饰的变量。
```c++
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
 
thread_local unsigned int rage = 1; 
// unsigned int rage = 1; 
std::mutex cout_mutex;
 
void increase_rage(const std::string& thread_name)
{
    ++rage; // modifying outside a lock is okay; this is a thread-local variable
    std::lock_guard<std::mutex> lock(cout_mutex);
    for(int i=0;i<100;i++)
    {
        ++rage;
    }
    std::cout << "Rage counter for " << thread_name << ": " << rage << '\n';
}
 
int main()
{
    std::thread a(increase_rage, "a"), b(increase_rage, "b"), c(increase_rage, "c");
 
    {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Rage counter for main: " << rage << '\n';
    }
 
    a.join();
    b.join();
    c.join();
}
```
```text
Rage counter for a: 102
Rage counter for b: 102
Rage counter for main: 1
Rage counter for c: 102
```

* 在线程函数内部声明带有`thread_local`关键字的变量，不会影响线程各自对变量的单独操作，但该变量离开线程函数时如果再使用则会编译报错，应为`thread_local`没有改变变量的作用域，只是改变了被`thread_local`关键字修饰变量的存储域。
```c++
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
 

// unsigned int rage = 1; 
std::mutex cout_mutex;
 
void increase_rage(const std::string& thread_name)
{
    thread_local unsigned int rage = 1; 
    ++rage; // modifying outside a lock is okay; this is a thread-local variable
    std::lock_guard<std::mutex> lock(cout_mutex);
    for(int i=0;i<100;i++)
    {
        ++rage;
    }
    std::cout << "Rage counter for " << thread_name << ": " << rage << '\n';
}
 
int main()
{
    std::thread a(increase_rage, "a"), b(increase_rage, "b"), c(increase_rage, "c");
 
    //取消如下代码注释再运行则会报错。
    // {
    //     std::lock_guard<std::mutex> lock(cout_mutex);
    //     std::cout << "Rage counter for main: " << rage << '\n';
    // }
 
    a.join();
    b.join();
    c.join();
}
```
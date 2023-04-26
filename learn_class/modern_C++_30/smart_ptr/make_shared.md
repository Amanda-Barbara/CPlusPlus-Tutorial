# `make_shared`创建共享指针

## 函数模板`make_shared`
```c++
template <class T, class... Args>  
shared_ptr<T> make_shared (Args&&... args);
```


## 参考链接
* 1 [`cplusplus`之`make_shared`讲解](https://cplusplus.com/reference/memory/make_shared/)
* 2 [`cppreference`之`make_shared`讲解](https://en.cppreference.com/w/cpp/memory/shared_ptr/make_shared)
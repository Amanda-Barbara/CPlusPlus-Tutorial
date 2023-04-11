#include <type_traits>
#include <iostream>
#include <map>
#include <mutex>
#include <stdio.h>

using namespace std;

// struct Manager;

// int Register(const std::string& name, bool can_override) {  // NOLINT(*)
//   Manager* m = Manager::Global();
//   std::lock_guard<std::mutex> lock(m->mutex);
//   if (m->fmap.count(name)) {
//     std << "Global PackedFunc " << name << " is already registered";
//   }

//   int* r = new int();
//   r->name_ = name;
//   m->fmap[name] = r;
//   return *r;
// }


struct Manager {
  // map storing the functions.
  // We deliberately used raw pointer.
  // This is because PackedFunc can contain callbacks into the host language (Python) and the
  // resource can become invalid because of indeterministic order of destruction and forking.
  // The resources will only be recycled during program exit.
  std::map<std::string, int*> fmap;
  // mutex
  std::mutex mutex;

  Manager() {}

  static Manager* Global() {
    // We deliberately leak the Manager instance, to avoid leak sanitizers
    // complaining about the entries in Manager::fmap being leaked at program
    // exit.
    Manager* inst = new Manager();
    return inst;
  }
};


int main()
{
   Manager* m1 = Manager::Global();
   Manager* m2 =  m1->Global();
   Manager* m3(m1);
   printf("变量m1的地址: %p\n", m1);    // 输出变量m1的地址
   printf("变量m2的地址: %p\n", m2);    // 输出变量m2的地址
   printf("变量m2的地址: %p\n", m3);    // 输出变量m3的地址
   return 0;
}
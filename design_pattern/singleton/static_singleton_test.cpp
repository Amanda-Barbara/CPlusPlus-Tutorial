#include <type_traits>
#include <iostream>
#include <map>
#include <mutex>
#include <stdio.h>

using namespace std;

struct Manager
{
    // map storing the functions.
    // We deliberately used raw pointer.
    // This is because PackedFunc can contain callbacks into the host language (Python) and the
    // resource can become invalid because of indeterministic order of destruction and forking.
    // The resources will only be recycled during program exit.
    std::map<std::string, int *> fmap;
    // mutex
    std::mutex mutex;

    Manager() {}

    static Manager *Global()
    {
        // We deliberately leak the Manager instance, to avoid leak sanitizers
        // complaining about the entries in Manager::fmap being leaked at program
        // exit.
        // Manager *inst = new Manager(); 
        static Manager *inst = new Manager();
        return inst;
    }
};

int Register(const std::string &name, bool can_override){
    // NOLINT(*)

}

int main()
{
    Manager *m1 = Manager::Global();
    Manager *m2 = m1->Global();
    Manager *m3(m1);

    std::string key_value = "zjw";
    std::string& name = key_value;
    std::lock_guard<std::mutex> lock(m1->mutex);
    if (m1->fmap.count("zjw"))
    {
        cout << "Global PackedFunc " << name << " is already registered";
    }

    int *r = new int(999);
    //   r->name_ = name;
    m1->fmap[name] = r;
    printf("value of r is %d.\n", *(m1->fmap[name]));
    
    printf("存储变量m1的地址: %p\n", &m1); // 输出变量m1的地址
    printf("存储变量m2的地址: %p\n", &m2); // 输出变量m2的地址
    printf("存储变量m2的地址: %p\n", &m3); // 输出变量m3的地址

    printf("变量m1的地址: %p\n", m1); // 输出变量m1的地址
    printf("变量m2的地址: %p\n", m2); // 输出变量m2的地址
    printf("变量m2的地址: %p\n", m3); // 输出变量m3的地址

    return 0;
}
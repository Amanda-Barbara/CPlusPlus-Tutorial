#include <iostream> 
#include <stdio.h>
using namespace std; 

class Apple 
{ 
    int i; 
    public: 
    Apple() 
    { 
        i = 0; 
        cout << "Inside Constructor\n"; 
    } 
    ~Apple() 
    { 
        cout << "Inside Destructor\n"; 
    } 
}; 
static Apple obj2;
// printf("obj.i : %d\n.", obj2.i);
// obj.i = 3;
int main() 
{ 
    int x = 0; 
    if (x==0) 
    { 
        static Apple obj; 
    } 
    cout << "End of main\n"; 
} 


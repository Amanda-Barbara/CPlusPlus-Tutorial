#include <vector>
#include <iostream>
 
 
void print_container(const std::vector<int>& c) 
{
    for (int i : c)
        std::cout << i << " ";
    std::cout << '\n';
}
 
int main( )
{
    std::vector<int> c{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32};
    // print_container(c);
    // printf("address and capacity of vector c : %p, %d.\n", &c, c.capacity());
 
    // c.erase(c.begin());
    // print_container(c);
    // printf("address and capacity of vector c : %p, %d.\n", &c, c.capacity());
 
    // c.erase(c.begin() + 2, c.begin() + 5);
    // print_container(c);
    // printf("address and capacity of vector c : %p, %d.\n", &c, c.capacity());
 
    // Erase all even numbers
    for (std::vector<int>::iterator it = c.begin()+10; it != c.end(); ++it)
    {
        // it = c.erase(it);
        // ++it;
        if (*it % 2 == 0)
            it = c.erase(it);
        
    }
    print_container(c);
    printf("address and capacity of vector c : %p, %d.\n", &c, c.capacity());

    return 0;
}
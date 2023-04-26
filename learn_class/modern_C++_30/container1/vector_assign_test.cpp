#include <vector>
#include <iostream>
#include <string>
 
int main()
{
    std::vector<char> characters;
 
    auto print_vector = [&]()
    {
        for (char c : characters)
            std::cout << c << ' ';
        std::cout << '\n';  
    };
 
    characters.assign(5, 'a');
    print_vector(); //output is "a a a a a "
 
    const std::string extra(6, 'b');
    characters.assign(extra.begin()+1, extra.end()-1);
    print_vector(); //output is "b b b b "
 
    characters.assign({'C', '+', '+', '1', '1'});
    print_vector(); //output is "C + + 1 1"

    char mychars[] = {'z', 'j', 'w'};
    characters.assign(mychars,mychars+3);   // assigning from array.
    print_vector(); //output is "z j w"
    return 0;
}
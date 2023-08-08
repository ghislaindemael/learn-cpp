#include <iostream>
#include <string>

int main()
{
    std::string_view names[]{ "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};
    std::cout << "Enter a name: ";
    std::string input { };
    std::cin >> input;

    bool found { false };
    for(std::string_view sv : names){
        if(sv == input){
            std::cout << sv << " was found !";
            found = true;
        }
    }

    if(!found){
        std::cout << input << " was not found.";
    }

    return 0;
}
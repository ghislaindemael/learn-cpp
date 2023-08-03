#include <iostream>

int main()
{
    char c { 97 };

    while (c <= 122){
        std::cout << c << ' ' << static_cast<int>(c) << "\n";
        ++c;
    }


    return 0;
}
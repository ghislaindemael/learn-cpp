#include <iostream>


void printString(const char* str)
{

    while (*str != '\0')
    {
        std::cout << *str;
        ++str;
    }
}

int main()
{
    printString("Hello world!");

    std::cout << '\n';

    return 0;
}
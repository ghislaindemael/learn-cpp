#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    int value = { };
    std::cin >> value;
    value = value * 2;
    std::cout << "Double that number is: " << value;

    return 0;
}
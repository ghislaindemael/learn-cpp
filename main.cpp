#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    int value = { };
    std::cin >> value;

    std::cout << "Double " << value << " is: " << value * 2 << "\n";
    std::cout << "Triple " << value << " is: " << value * 3 << "\n";

    return 0;
}
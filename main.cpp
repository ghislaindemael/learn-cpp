#include <iostream>

int main()
{

    int val1 = { };
    int val2 = { };

    std::cout << "Enter an integer: ";
    std::cin >> val1;
    std::cout << "Enter another integer: ";
    std::cin >> val2;


    std::cout << val1 << " + " << val2 << " is " << val1 + val2 << ".\n";
    std::cout << val1 << " - " << val2 << " is " << val1 - val2 << ".\n";

    return 0;
}
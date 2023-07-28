#include "add.h"
#include <iostream>

int main()
{
    int x{ 3 };
    int y{ 12 };

    std::cout << x << " + " << y << " is " << add(x, y) << '\n';
    return 0;
}
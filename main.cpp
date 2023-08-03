#include <iostream>

int main()
{
    // outer loops between 1 and 5
    int outer{ 1 };
    while (outer <= 5)
    {
        int counter { 1 };

        while (counter <= 10 - (2*outer))
        {
            std::cout << ' ';
            ++counter;
        }

        int inner{ outer };
        while (inner >= 1)
        {
            std::cout << inner << ' ';
            --inner;
        }

        // print a newline at the end of each row
        std::cout << '\n';
        ++outer;
    }

    return 0;
}
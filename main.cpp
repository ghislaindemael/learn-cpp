#include <iostream>

int main()
{
    // outer loops between 1 and 5
    int outer{ 5 };
    while (outer >= 1)
    {
        // inner loops between 1 and outer
        int inner{ outer };
        while (inner >= 1)
        {
            std::cout << inner << ' ';
            --inner;
        }

        // print a newline at the end of each row
        std::cout << '\n';
        --outer;
    }

    return 0;
}
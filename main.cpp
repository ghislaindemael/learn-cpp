#include <iostream>
#include <string>

int main()
{
    double highestTemp[365]{};
    for (double & i : highestTemp) {
        i = 0.0;
    }
    std::cout << highestTemp[54];



    return 0;
}
#include <iostream>
#include <functional>
#include <cmath>

int sumOfDigits(int number){
    int dig = static_cast<int>(std::log10(number) + 1);
    if(dig <= 0){
        return 0;
    }
    std::cout << number << " -> " << dig << "\n";

    int curDigit { number / static_cast<int>(pow(10, dig - 1)) };
    std::cout << "Top num -> " << curDigit << "\n";
    return curDigit + sumOfDigits(number % static_cast<int>(pow(10, dig - 1)));
}

int main()
{
    int number { 123456789 };
    std::cout << sumOfDigits(number);


    return 0;
}
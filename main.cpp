#include <iostream>
#include <functional>

int factorial(int n){
    if(n == 0 || n == 1){
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main()
{
    std::cout << "Factorial of 7 is: " << factorial(7) << "\n";

    return 0;
}
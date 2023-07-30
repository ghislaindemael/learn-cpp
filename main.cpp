#include <iostream>

int askForNumber(){
    std::cout << "Enter a number between 0 and 9 : ";
    int x {};
    std::cin >> x;
    if (x < 0 || x > 9)
        askForNumber();
    else
        return x;
}

bool isPrime(int n){
    return n == 2 || n == 3 || n == 5 || n == 7;
}

int main()
{
    int choice = askForNumber();
    if(isPrime(choice))
        std::cout << "The digit " << choice << " is prime.";
    else
        std::cout << "The digit " << choice << " is not prime.";
    return 0;
}
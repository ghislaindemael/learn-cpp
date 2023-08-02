#include <iostream>

int askForInt(){
    std::cout << "Enter an integer: ";
    int i {};
    std::cin >> i;
    return i;
}

int isEven(int x){
    return (x % 2 == 0);
}

int main()
{
    int i { askForInt() };
    if (isEven(i)){
        std::cout << i << " is even.";
    } else {
        std::cout << i << " is odd.";
    }

    return 0;
}
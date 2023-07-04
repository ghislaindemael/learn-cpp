#include <iostream>

int doubleNumber(int num){
    return num * 2;
}

int getNumberFromUser(){
    std::cout << "Enter an integer: ";
    int val { };
    std::cin >> val;
    return val;
}

int main()
{
    int choice { getNumberFromUser() };
    int doubled { doubleNumber(choice) };
    std::cout << "Double of " << choice << " is " << doubled <<".\n";

    return 0;
}
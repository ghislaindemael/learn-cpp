#include <iostream>
#include "io.h"

int readNumber(){
    std::cout << "Input an integer: ";
    int choice {};
    std::cin >> choice;
    return choice;
}

void writeAnswer(int x){
    std::cout << "The sum of the two numbers is: " << x;
}
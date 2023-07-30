#include <iostream>

double askForDouble(){
    std::cout << "Enter a double value: ";
    double d {};
    std::cin >> d;
    return d;
}

char askForOperator(){
    std::cout << "Enter one of the following: +, -, *, or /: ";
    char o {};
    std::cin >> o;
    return o;
}

int main()
{
    double d1 = askForDouble();
    double d2 = askForDouble();
    char o = askForOperator();

    if (o == '+')
        std::cout << d1 << " + " << d2 << " is " << d1 + d2;
    else if (o == '-')
        std::cout << d1 << " - " << d2 << " is " << d1 - d2;
    else if (o == '*')
        std::cout << d1 << " * " << d2 << " is " << d1 * d2;
    else if (o == '/')
        std::cout << d1 << " / " << d2 << " is " << d1 / d2;

    return 0;
}
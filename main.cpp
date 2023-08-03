#include <iostream>

int askForInt(){
    std::cout << "Enter an integer: ";
    int i {};
    std::cin >> i;
    return i;
}

char askForOperator(){
    std::cout << "Enter one of the following (+, -, *, /, %): ";
    char o {};
    std::cin >> o;
    return o;
}

int main()
{
    int i1 { askForInt() };
    int i2 { askForInt() };
    int result {};

    switch (askForOperator()) {
        case '+':
            result = i1 + i2;
            break;
        case '-':
            result = i1 - i2;
            break;
        case '*':
            result = i1 * i2;
            break;
        case '/':
            result = i1 / i2;
            break;
        case '%':
            result = i1 % i2;
            break;
    }

    std::cout << "The result is " << result << "\n";


    return 0;
}
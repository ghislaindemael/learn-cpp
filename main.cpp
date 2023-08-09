#include <iostream>
#include <functional>

using ArithmeticFunction = std::function<int(int, int)>;

int askForInt(){
    std::cout << "Enter an integer: ";
    int x { };
    std::cin >> x;
    return x;
}

char askForOper(){
    char o{};
    do {
        std::cout << "Enter one of the following (+, -, *, /): ";
        std::cin >> o;
    } while (o != '+' && o != '-' && o != '*' && o != '/');
    return o;
}

int add(int x, int y){
    return x + y;
}

int subtract(int x, int y){
    return x - y;
}

int mult(int x, int y){
    return x * y;
}

int divide(int x, int y){
    return x / y;
}

ArithmeticFunction getArithmeticFunction(char op){
    switch (op) {
        case '+': return &add;
        case '-': return &subtract;
        case '*': return &mult;
        case '/': return &divide;
    }
    return nullptr;
}

int main()
{
    int a { askForInt() };
    char op { askForOper() };
    int b { askForInt() };

    ArithmeticFunction fcn {getArithmeticFunction(op)};

    std::cout << a << ' ' << op << ' ' << b << " = " << fcn(a,b);

    return 0;
}
#include <iostream>

char askForChar(){
    std::cout << "Enter a single character: ";
    char x {};
    std::cin >> x;
    return x;
}


int main()
{
    char ch = askForChar();
    std::cout << "You entered '" << ch << "', which has ASCII value " << static_cast<int>(ch) << ".";
    return 0;
}
#include <iostream>
#include <string>

std::string askForName(){
    std::cout << "Enter your full name: ";
    std::string x {};
    std::getline(std::cin >> std::ws, x);
    return x;
}

int askForAge(){
    std::cout << "Enter your age: ";
    int age {};
    std::cin >> age;
    return age;

}

int main()
{
    std::string name = askForName();
    int age = askForAge();
    int sum = age + std::ssize(name);
    std::cout << "Your name + length of name is: " << sum;
    return 0;
}
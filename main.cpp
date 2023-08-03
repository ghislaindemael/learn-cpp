#include <iostream>

int askForInt(){
    std::cout << "Enter an integer: ";
    int x { };
    std::cin >> x;
    return x;
}

int sumTo(int x){
    int sum { 0 };
    for( int i { x }; i >=0 ; --i){
        sum += i;
    }
    return sum;
}

int main()
{

    std::cout << sumTo(askForInt());

    return 0;
}
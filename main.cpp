#include <iostream>

int askForInt(){
    std::cout << "Enter an integer: ";
    int x { };
    std::cin >> x;
    return x;
}

void fizzbuzz(int x){
    for(int i { 1 }; i <= x; ++i){

        if(i % 3 == 0 && i % 5 == 0){
            std::cout << "fizzbuzz" << "\n";
        } else if (i % 3 == 0) {
            std::cout << "fizz" << "\n";
        } else if (i % 5 == 0){
            std::cout << "buzz" << "\n";
        } else {
            std::cout << i << "\n";
        }
    }
}

int main()
{

    fizzbuzz(askForInt());

    return 0;
}
#include <iostream>

int askForInt(){
    std::cout << "Enter an integer: ";
    int x { };
    std::cin >> x;
    return x;
}

void fizzbuzzpop(int x){
    for(int i { 1 }; i <= x; ++i){
        std::string fbp { };
        if(i % 3 == 0){
            fbp.append("fizz");
        }
        if(i % 5 == 0){
            fbp.append("buzz");
        }
        if(i % 7 == 0){
            fbp.append("pop");
        }
        if (fbp.empty()){
            std::cout << i << "\n";
        } else {
            std::cout << fbp << "\n";
        }
    }
}

int main()
{

    fizzbuzzpop(askForInt());

    return 0;
}
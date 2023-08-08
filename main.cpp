#include <iostream>
#include <iterator> // for std::size

int main()
{
    int divArray[]{3, 5, 7, 11, 13, 17, 19};
    std::string wordArray[]{ "fizz","buzz", "pop", "bang", "jazz", "pow", "boom" };

    for(int i { 1 }; i <= 150; ++i){
        bool semiPrime = true;
        for(int j { 0 }; j < 7; ++j){
            if(i % divArray[j] == 0){
                semiPrime = false;
                std::cout << wordArray[j];
            }
        }
        if(semiPrime){
            std::cout << i;
        }
        std::cout << "\n";
    }



    return 0;
}
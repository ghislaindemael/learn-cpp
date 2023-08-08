#include <iostream>
#include <string>

namespace {
    enum Animal{
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,

        numOfAnimals
    };
}

int main()
{
    int numOfLegs[numOfAnimals]{2, 4, 4, 4, 2, 0};

    std::cout << "An elephant has " << numOfLegs[elephant] << " legs.";

    return 0;
}
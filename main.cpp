#include <iostream>

enum class Animal {
    pig,
    chicken,
    goat,
    cat,
    dog,
    duck,
};

std::string_view getAnimalName(Animal a){
    using enum Animal;
    switch (a) {
        case pig: return "pig";
        case chicken: return "chicken";
        case goat: return "goat";
        case cat: return "cat";
        case dog: return "dog";
        case duck: return "duck";
        default: return "???";
    }
}

int getNumberOfLegs(Animal a){
    using enum Animal;
    switch (a) {
        case pig:
        case goat:
        case cat:
        case dog:
            return 4;
        case chicken:;
        case duck:
            return 2;
        default:
            return 0;
    }
}

void printNumberOfLegs(Animal a){
    std::cout << "A " << getAnimalName(a) << " has " << getNumberOfLegs(a) << " legs.\n";
}


int main()
{
    printNumberOfLegs(Animal::cat);
    printNumberOfLegs(Animal::chicken);

    return 0;
}
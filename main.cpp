#include <iostream>
#include <string>

struct Fraction {
    int numerator {};
    int denominator {};
};

int askForFracPart(bool numerator){
    std::cout << "Enter a value for the " << (numerator ? "numerator" : "denominator") << ": ";
    int x {};
    std::cin >> x;
    return x;
}

Fraction multiplyFractions(Fraction f1, Fraction f2){
    return {f1.numerator * f2.numerator, f1.denominator * f2.denominator};
}

std::string printFrac(Fraction f){
    return std::to_string(f.numerator) + "/" + std::to_string(f.denominator);
}

int main()
{
    Fraction f1 {askForFracPart(true), askForFracPart(false)};
    Fraction f2 {askForFracPart(true), askForFracPart(false)};

    std::cout << "Your fractions multiplied together: " << printFrac(multiplyFractions(f1, f2));
    return 0;
}
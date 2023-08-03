#include <bitset>
#include <iostream>

int askForInt(){
    std::cout << "Enter an integer: ";
    int i {};
    std::cin >> i;
    return i;
}

int askforLarger(){
    std::cout << "Enter a larger integer: ";
    int i {};
    std::cin >> i;
    return i;
}

int main()
{
    int smaller { askForInt() };
    int larger { askforLarger() };

    if(smaller > larger){
        std::cout << "Swapping the values\n";
        int temp { larger };
        larger = smaller;
        smaller = temp;
    } //temp dies here

    std::cout << "The smaller value is " << smaller << "\n";
    std::cout << "The larger value is " << larger << "\n";

    return 0;
} //smaller and larger die here
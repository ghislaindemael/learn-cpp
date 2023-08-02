#include <bitset>
#include <iostream>

int askForInt255(){
    std::cout << "Enter an integer between 0 and 255: ";
    int i {};
    std::cin >> i;
    return i;
}

int main()
{
    int i { askForInt255() };

    int b0 { i / 128};
    i %= 128;
    int b1 { i / 64};
    i %= 64;
    int b2 { i / 32};
    i %= 32;
    int b3 { i / 16};
    i %= 16;
    int b4 { i / 8};
    i %= 8;
    int b5 { i / 4};
    i %= 4;
    int b6 { i / 2};
    i %= 2;
    int b7 { i / 1};
    i %= 1;

    std::cout << b0 << b1 << b2 << b3 << b4 << b5 << b6 << b7;

    return 0;
}
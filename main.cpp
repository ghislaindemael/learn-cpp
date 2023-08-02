#include <bitset>
#include <iostream>

// "rotl" stands for "rotate left"
std::bitset<4> rotl(std::bitset<4> bits)
{
    bool firstBit = bits.test(3);
    bits <<=1;
    bits.set(0,firstBit);
    return bits;
}

int main()
{
    std::bitset<4> bits1{ 0b0001 };
    std::cout << rotl(bits1) << '\n';

    std::bitset<4> bits2{ 0b1001 };
    std::cout << rotl(bits2) << '\n';

    return 0;
}
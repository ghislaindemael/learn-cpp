#include <iostream>

int main()
{
    unsigned short x{ 65535 }; // largest 16-bit unsigned value possible
    std::cout << "x was: " << x << '\n';

    x = 65536; // 65536 is out of our range, so we get modulo wrap-around
    std::cout << "x is now: " << x << '\n';

    x = 65537; // 65537 is out of our range, so we get modulo wrap-around
    std::cout << "x is now: " << x << '\n';

    unsigned short y{ 0 }; // smallest 2-byte unsigned value possible
    std::cout << "y was: " << y << '\n';

    y = -1; // -1 is out of our range, so we get modulo wrap-around
    std::cout << "y is now: " << y << '\n';

    y = -2; // -2 is out of our range, so we get modulo wrap-around
    std::cout << "y is now: " << y << '\n';

    return 0;
}
#include <algorithm> // std::sort
#include <cstddef> // std::size_t
#include <iostream>
#include <string>
#include <vector>

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}


int main()
{
    int a { 5 };
    int b { 10 };
    swap(a, b);
    std::cout << a << ' ' << b << "\n";

    return 0;
}
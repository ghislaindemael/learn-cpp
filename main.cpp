#include <iostream>
#include <iterator>

int* findValue(int* ptr1, int* ptr2, int num){
    int* ptr { ptr1 };
    while(ptr != ptr2){
        if(*ptr == num){
            return ptr;
        }
        ++ptr;
    }
    return ptr2;
}

int main()
{
    int arr[]{ 2, 5, 4, 10, 8, 22, 16, 40 };

    // Search for the first element with value 20.
    int* found{ findValue(std::begin(arr), std::end(arr), 20) };

    // If an element with value 20 was found, print it.
    if (found != std::end(arr))
    {
        std::cout << *found << '\n';
    }

    return 0;
}
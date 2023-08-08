#include <iostream>
#include <iterator>
#include <utility>

int main()
{
    int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
    constexpr int length{ static_cast<int>(std::size(array)) };

    for (int startIndex{ 0 }; startIndex < length; ++startIndex) {
        for(int nestedIndex { 0 }; nestedIndex < length - 1; ++nestedIndex){
            if(array[nestedIndex] > array[nestedIndex + 1]){
                std::swap(array[nestedIndex], array[nestedIndex + 1]);
            }
        }
    }

    // Now that the whole array is sorted, print our sorted array as proof it works
    for (int index{ 0 }; index < length; ++index) {
        std::cout << array[index] << ' ';
    }
    std::cout << '\n';

    return 0;
}
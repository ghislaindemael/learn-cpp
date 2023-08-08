#include <iostream>
#include <string>

int main()
{
    constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };

    int toSearch {};
    do {
        std::cout << "Enter a number between 1 and 9: ";
        std::cin >> toSearch;

        if (std::cin.fail())
        {
            std::cin.clear(); // reset any error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer
        }
    } while (toSearch < 1 || toSearch > 9);

    for(int i {0}; i < 9; ++i){
        std::cout << array[i] << ' ';
    }
    std::cout << "\n";

    for(int i {0}; i < 9; ++i){
        if(array[i] == toSearch){
            std::cout << "The number " << toSearch << " has index " << i << "\n";
        }
    }



    return 0;
}
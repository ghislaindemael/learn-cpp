#include <iostream>

int askForHeight(){
    std::cout << "Enter the height of the tower in meters: ";
    int h {};
    std::cin >> h;
    return h;
}

int main()
{
    constexpr double gravity = 9.8;
    int tower = askForHeight();
    int seconds { 0 };
    bool exit { false };
    double height;

    while (!exit) {
        height = tower - ((gravity * seconds * seconds) / 2);
        if (height < 0) {
            std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
            exit = true;
        } else {
            std::cout << "At " << seconds << " seconds, the ball is at height: " << height << " meters.\n";
            seconds = seconds + 1;
        }
    }


    return 0;
}
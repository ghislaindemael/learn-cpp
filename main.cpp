#include <cassert>
#include <iostream>
#include "random.h"

int askForInt(){
    int x{ };
    do {
        std::cin >> x;
        if(std::cin.fail()){
            std::cout << "Please enter a valid input.\n";
            std::cin.clear();
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    while (x <= 0 || x > 100);
    return x;
}

bool playAgain(){
    char c {};
    do {
        std::cout << "Would you like to play again (y/n)? ";
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    while (c != 'y' && c != 'n');
    return c == 'y';
}

bool highLow(int toFind, int guess){
    if(guess > toFind){
        std::cout << "Your guess is too high.\n";
        return false;
    } else if (guess < toFind){
        std::cout << "Your guess is too low.\n";
        return false;
    } else {
        return true;
    }
}

int main()
{
start:
    std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess it.\n";
    int number { Random::get(1, 100)};
    bool found { false };

    for(int i { 1 }; i <= 7; ++i){
        std::cout << "Guess #" << i << ": ";
        int guess { askForInt() };

        if(highLow(number, guess)){
            found = true;
            break;
        }
    }

    if(found){
        std::cout << "Correct! You win!";
    } else {
        std::cout << "Sorry, you lose. The correct number was " << number << ".\n";
    }
    
    if(playAgain()){
        goto start;
    }

    return 0;
}
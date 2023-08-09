#include <iostream>
#include <array>
#include <algorithm>
#include <random>

namespace {
    enum Rank{
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING,
        ACE,

        NUM_RANKS
    };

    enum Suit{
        CLUBS,
        DIAMONDS,
        HEARTS,
        SPADES,

        NUM_SUITS
    };
}

struct Card{
    Rank rank {};
    Suit suit {};
};

void printCard(Card& c){
    switch (c.rank) {
        case TWO: std::cout << 2; break;
        case THREE: std::cout << 3; break;
        case FOUR: std::cout << 4; break;
        case FIVE: std::cout << 5; break;
        case SIX: std::cout << 6; break;
        case SEVEN: std::cout << 7; break;
        case EIGHT: std::cout << 8; break;
        case NINE: std::cout << 9; break;
        case TEN: std::cout << 10; break;
        case JACK: std::cout << 'J'; break;
        case QUEEN: std::cout << 'Q'; break;
        case KING: std::cout << 'K'; break;
        case ACE: std::cout << 'A'; break;
        default: std::cout << '?'; break;
    }

    switch (c.suit) {
        case CLUBS: std::cout << 'C'; break;
        case DIAMONDS: std::cout << 'D'; break;
        case HEARTS: std::cout << 'H'; break;
        case SPADES: std::cout << 'S'; break;
        default: std::cout << '?'; break;
    }
}

std::array<Card, 52> createDeck(){
    std::array<Card, 52> cards {};
    int index { 0 };

    for(int s {0}; s < 4; ++s){
        for(int r {0}; r < 13; ++r){
            cards[index].suit = static_cast<Suit>(s);
            cards[index].rank = static_cast<Rank>(r);
            ++index;
        }
    }
    return cards;
}

void printDeck(std::array<Card, 52>& deck){
    for (Card c : deck) {
        printCard(c);
        std::cout << ' ';
    }
    std::cout << '\n';
}

void shuffleDeck(std::array<Card, 52>& deck){
    static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

    std::shuffle(deck.begin(), deck.end(), mt);
}

int getCardValue(Card c){
    int val { c.rank + 2};
    if (val >= 11 && val <= 13){
        val = 10;
    }
    if(val == 14){
        val = 11;
    }
    return val;
}

int main()
{
    std::array<Card, 52> deck { createDeck() };
    printDeck(deck);
    shuffleDeck(deck);
    printDeck(deck);

    for (Card c : deck) {
        std::cout << getCardValue(c);
        std::cout << ' ';
    }


    return 0;
}
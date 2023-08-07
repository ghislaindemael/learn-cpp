#include <iostream>
#include <string>

enum MonsterType {
    Ogre,
    Dragon,
    Orc,
    GiantSpider,
    Slime
};

struct Monster {
    MonsterType type {};
    std::string name {};
    int health {};
};

void printMonster(Monster& m){
    std::cout << "This ";

    switch (m.type) {
        case Ogre: std::cout << "Ogre"; break;
        case Dragon: std::cout << "Dragon"; break;
        case Orc: std::cout << "Orc"; break;
        case GiantSpider: std::cout << "Giant Spider"; break;
        case Slime: std::cout << "Slime"; break;
    }

    std::cout << " is named " << m.name << " and has " << m.health << " health.\n";
}

int main()
{
    Monster ogre { MonsterType::Ogre, "Torg", 145};
    printMonster(ogre);
    Monster slime { MonsterType::Slime, "Blurp", 23};
    printMonster(slime);
    return 0;
}
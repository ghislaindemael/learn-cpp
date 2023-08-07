#include <iostream>

namespace Monster {
    enum MonsterType {
        orc,
        goblin,
        troll,
        ogre,
        skeleton,
    };
}

int main()
{

    Monster::MonsterType troll {Monster::troll };
    std::cout << troll;

    return 0;
}
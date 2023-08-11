#include <iostream>
#include <string>
#include <string_view>
#include <cmath>
#include <array>
#include "random.h"

class Monster {
public:
    enum Type {
        Dragon,
        Goblin,
        Orc,
        Skeleton,
        Troll,
        Vampire,
        Zombie,

        num_types
    };
private:
    Type type;
    std::string name;
    std::string roar;
    int hitPoints;
public:
    Monster(Type i_t, std::string_view i_n, std::string_view i_r, int i_h) :
    type { i_t }, name { i_n }, roar { i_r }, hitPoints { i_h }{}
    std::string getTypeString(){
        switch (type) {
            case Dragon: return "dragon";
            case Goblin: return "goblin";
            case Orc: return "orc";
            case Skeleton: return "skeleton";
            case Troll: return "troll";
            case Vampire: return "vampire";
            case Zombie: return "zombie";
            default: return "";
        }
    }
    void print(){
        std::cout << name << " the " << getTypeString() << " has " << hitPoints << " HP and says " << roar << ".\n";
    }
};

namespace MonsterGenerator {
    Monster generate(){
        int maxIndex { Monster::Type::num_types - 1 };
        auto type{ static_cast<Monster::Type>(Random::get(0, maxIndex)) };
        int hitPoints{ Random::get(1, 100) };

        static constexpr std::array s_names{ "Blarg", "Moog", "Pksh", "Tyrn", "Mort", "Hans" };
        static constexpr std::array s_roars{ "*ROAR*", "*peep*", "*squeal*", "*whine*", "*hum*", "*burp*" };

        auto name { s_names[Random::get<std::size_t>(0, s_names.size() - 1)] };
        auto roar { s_roars[Random::get<std::size_t>(0, s_roars.size() - 1)] };

        return Monster{ type, name, roar, hitPoints };
    }
}

int main()
{
    Monster m{ MonsterGenerator::generate() };
    m.print();

    return 0;
}
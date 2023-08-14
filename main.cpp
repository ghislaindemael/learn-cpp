#include <iostream>
#include <string>
#include <utility>
#include <array>
#include <random>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

int getRandomNumber(int min, int max)
{
    static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) }; // static used for efficiency, so we only calculate this value once
    // evenly distribute the random number across our range
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

class Creature {
protected:
    std::string m_name {};
    char m_symbol {};
    int m_health {};
    int m_strength {};
    int m_gold {};
public:
    Creature(std::string i_name, char i_symbol, int i_health, int i_strength, int i_gold)
    : m_name { std::move(i_name) }, m_symbol { i_symbol }, m_health { i_health }, m_strength { i_strength }, m_gold { i_gold } {}
    std::string_view getName(){
        return m_name;
    }
    char getSymbol(){
        return m_symbol;
    }
    int getHealth(){
        return m_health;
    }
    int getStrength() const {
        return m_strength;
    }
    int getGold(){
        return m_gold;
    }
    void reduceHealth(int d){
        m_health -= d;
    }
    bool isDead(){
        return m_health <= 0;
    }
    void addGold(int g){
        m_gold += g;
    }
};

class Player : public Creature {
    int m_level { 1 };
public:
    Player(std::string i_name) : Creature(std::move(i_name), '@', 10, 1, 0) {}
    void levelUp(){
        ++m_level;
        ++m_strength;
        std::cout << "You are now level " << m_level <<".\n";
    }
    int getLevel(){
        return m_level;
    }
    bool hasWon(){
        return m_level == 20;
    }
};

class Monster : public Creature {
public:
    enum Type {
        DRAGON,
        ORC,
        SLIME,
        num_types
    };
private:
    static const Creature& getDefaultCreature(Type type)
    {
        static const std::array<Creature, static_cast<std::size_t>(Type::num_types)> monsterData{
                { { "dragon", 'D', 20, 4, 100 },
                  { "orc", 'o', 4, 2, 25 },
                  { "slime", 's', 1, 1, 10 } }
        };

        return monsterData.at(static_cast<std::size_t>(type));
    }
public:
    Monster(Type t) : Creature{ getDefaultCreature(t) } {}
    static Monster getRandomMonster()
    {
        int num{ getRandomNumber(0, static_cast<int>(Type::num_types) - 1) };
        return Monster{ static_cast<Type>(num) };
    }
};

char askForAction(){
    char a {};
    do {
        std::cout << "(R)un or (F)ight: ";
        std::cin >> a;
        std::cin.ignore();
    } while (a != 'r' && a != 'f');
    return a;
}

bool manageToFlee(){
    return static_cast<bool>(getRandomNumber(0, 1));
}

void attackMonster(Player& p, Monster& m) {
    int damage { p.getStrength() };
    m.reduceHealth(damage);
    std::cout << "You hit the " << m.getName() << " for " << damage << " damage.\n";
}

void attackPlayer(Monster& m, Player& p) {
    int damage{ m.getStrength() };
    p.reduceHealth(damage);
    std::cout << "The " << m.getName() << " hit you for " << damage << " damage.\n";
}

bool playTheDungeon(Player& player) {
    bool isFinished { false };
    while (true){
        Monster monst { Monster::getRandomMonster() };
        std::cout << "You have encountered a " << monst.getName() << " (" << monst.getSymbol() << ").\n";
        while(!monst.isDead()){
            switch (askForAction()) {
                case 'f': {
                    attackMonster(player, monst);
                    if(monst.isDead()){
                        std::cout << "You killed the " << monst.getName() << ".\n";
                        int gold { monst.getGold() };
                        std::cout << "You have found " << gold << " gold.\n";
                        player.addGold(gold);
                        player.levelUp();
                    } else {
                        attackPlayer(monst, player);
                    }
                    break;
                }
                case 'r':{
                    if(manageToFlee()){
                        std::cout << "You successfully fled.\n";
                    } else {
                        std::cout << "You failed to flee.\n";
                        attackPlayer(monst, player);
                    }
                    monst.reduceHealth(monst.getHealth());
                    break;
                }
            }
            if(player.isDead()){
                return false;
            }
            if(player.hasWon()){
                return true;
            }
        }
    }
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
    std::rand(); // get rid of first result

    std::cout << "Enter your name: ";
    std::string name {};
    std::cin >> name;
    std::cout << "Welcome, " << name << '\n';

    Player player { name };

    if (playTheDungeon(player)){
        std::cout << "Congrats ! You won !\n";
    } else {
        std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << " gold.\n";
        std::cout << "Too bad you can’t take it with you!\n";
    }

    return 0;
}



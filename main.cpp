#include <iostream>
#include <utility>

class Fruit {
    std::string m_name {};
    std::string m_color {};
public:
    Fruit(std::string i_nam, std::string i_col) : m_name { std::move(i_nam) }, m_color { std::move(i_col) } {};
    std::string_view getName() const {
        return m_name;
    }
    std::string_view getColor() const {
        return m_color;
    }
};

class Apple : public Fruit {
public:
    explicit Apple(std::string i_col = "red") : Fruit("apple", std::move(i_col)) {}
    explicit Apple(const std::string& i_name, std::string i_col)
        :Fruit(i_name, std::move(i_col)) {}
};

class GrannySmith : public Apple {
public:
    explicit GrannySmith() : Apple { "granny smith", "green" } {}
};

class Banana : public Fruit {
public:
    explicit Banana(std::string i_col = "yellow") : Fruit("banana", std::move(i_col)) {}
};

int main()
{
    Apple a{ "red" };
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}
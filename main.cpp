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
    double m_fiber { 0.0 };
public:
    Apple(std::string i_nam, std::string i_col, double i_fib)
        : Fruit(std::move(i_nam), std::move(i_col)), m_fiber { i_fib } {}
    double getFiber() const {
        return m_fiber;
    }
};

class Banana : public Fruit {
public:
    Banana(std::string i_nam, std::string i_col) : Fruit(std::move(i_nam), std::move(i_col)) {}
};

std::ostream& operator<<(std::ostream& out, const Apple& apple)
{
    out << "Apple (" << apple.getName() << ", " << apple.getColor() << ", " << apple.getFiber() << ")\n";
    return out;
}

std::ostream& operator<<(std::ostream& out, const Banana& banana)
{
    out << "Banana (" << banana.getName() << ", " << banana.getColor() << ")\n";
    return out;
}

int main()
{
    const Apple a{ "Red delicious", "red", 4.2 };
    std::cout << a << '\n';

    const Banana b{ "Cavendish", "yellow" };
    std::cout << b << '\n';

    return 0;
}
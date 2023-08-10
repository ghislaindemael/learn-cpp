#include <iostream>
#include <cassert>

class Ball {
    std::string_view m_color { "black" };
    double m_radius { 10.0 };
public:
    Ball() = default;
    Ball(double d){
        m_radius = d;
    }
    Ball(std::string_view s){
        m_color = s;
    }
    Ball(std::string_view s, double d){
        m_color = s;
        m_radius = d;
    }
    void print(){
        std::cout << "color: " << m_color << ", radius: " << m_radius << "\n";
    }
};

int main()
{
    Ball def{};
    def.print();

    Ball blue{ "blue" };
    blue.print();

    Ball twenty{ 20.0 };
    twenty.print();

    Ball blueTwenty{ "blue", 20.0 };
    blueTwenty.print();

    return 0;
}
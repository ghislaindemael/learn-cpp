#include <iostream>
#include <string>
#include <string_view>
#include <cmath>

class Point2d {
    double m_x { 0.0 };
    double m_y { 0.0 };
public:
    Point2d() = default;
    Point2d(double i_x, double i_y) : m_x { i_x }, m_y { i_y } {};
    void print(){
        std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
    }

    friend double distanceFrom(Point2d& p1, Point2d p2);
};

double distanceFrom(Point2d& p1, Point2d p2) {
    return std::sqrt((p1.m_x - p2.m_x)*(p1.m_x - p2.m_x) + (p1.m_y - p2.m_y)*(p1.m_y - p2.m_y));
}

int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();
    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';

    return 0;
}
#include <iostream>
#include <vector>

struct Point{
    int p1 { 0 };
    int p2 { 0 };
};

std::ostream& operator<<(std::ostream& out, Point p){
    out << "Point(" << p.p1 << ", " << p.p2 << ")";
    return out;
}

class Shape {
public:
    virtual std::ostream& print(std::ostream& out) const = 0;
    friend std::ostream& operator<<(std::ostream& out, const Shape& p){
        return p.print(out);
    }
    virtual ~Shape() = default;
};

class Circle : public Shape {
    Point m_cp {};
    int m_radius {};
public:
    Circle(Point i_cp, int i_radius) : m_cp { i_cp }, m_radius { i_radius } {}
    std::ostream& print(std::ostream& out) const override {
        out << "Circle (" << m_cp << ", radius" << m_radius << ")";
        return out;
    }
    int getRadius() const {
        return m_radius;
    }
};

class Triangle : public Shape {
    Point m_p1 {};
    Point m_p2 {};
    Point m_p3 {};
public:
    Triangle(Point i_p1, Point i_p2, Point i_p3) : m_p1 { i_p1 }, m_p2 { i_p2 }, m_p3 { i_p3 } {}
    std::ostream& print(std::ostream& out) const override {
        out << "Triangle (" << m_p1 << ", " << m_p2 << ", " << m_p3 << ")";
        return out;
    }
};

int getLargestRadius(const std::vector<Shape*>& v)
{
    int largestRadius{ 0 };

    // Loop through all the shapes in the vector
    for (const auto* element : v)
    {
        // // Ensure the dynamic cast succeeds by checking for a null pointer result
        if (auto * c{ dynamic_cast<const Circle*>(element) })
        {
            largestRadius = std::max(largestRadius, c->getRadius());
        }
    }

    return largestRadius;
}

int main()
{
    std::vector<Shape*> v{
            new Circle{Point{ 1, 2 }, 7},
            new Triangle{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }},
            new Circle{Point{ 7, 8 }, 3}
    };

    for (const auto* element : v) // element will be a Shape*
        std::cout << *element << '\n';

    std::cout << "The largest radius is: " << getLargestRadius(v) << '\n';

    for (const auto* element : v)
        delete element;

    return 0;
}
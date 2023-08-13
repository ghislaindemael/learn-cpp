#include <iostream>
#include <numeric>

class Fraction {
    int m_num { 0 };
    int m_den { 1 };
public:
    Fraction() = default;
    Fraction(int i_n, int i_d = 1) : m_num { i_n }, m_den { i_d } { reduce(); }

    void reduce()
    {
        int gcd{ std::gcd(m_num, m_den) };
        if (gcd) // Make sure we don't try to divide by 0
        {
            m_num /= gcd;
            m_den /= gcd;
        }
    }

    friend Fraction operator*(Fraction f, int m);
    friend Fraction operator*(int m, Fraction f);
    friend Fraction operator*(Fraction f1, Fraction f2);
    friend std::ostream& operator<< (std::ostream& out, const Fraction& f);
    friend std::istream& operator>> (std::istream& in, Fraction& f);

};

Fraction operator*(Fraction f, int m) {
    return { f.m_num * m, f.m_den } ;
}

Fraction operator*(int m, Fraction f) {
    return { f.m_num * m, f.m_den };
}

Fraction operator*(Fraction f1, Fraction f2) {
    return { f1.m_num * f2.m_num, f1.m_den * f2.m_den };
}

std::ostream &operator<<(std::ostream &out, const Fraction &f) {
    return out << f.m_num << '/' << f.m_den;
}

std::istream& operator>>(std::istream& in, Fraction& f)
{
    in >> f.m_num;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '/');
    in >> f.m_den;
    f.reduce();
    return in;
}

int main()
{
    Fraction f1;
    std::cout << "Enter fraction 1: ";
    std::cin >> f1;

    Fraction f2;
    std::cout << "Enter fraction 2: ";
    std::cin >> f2;

    std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n'; // note: The result of f1 * f2 is an r-value

    return 0;
}
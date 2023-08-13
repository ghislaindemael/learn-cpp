#include <iostream>
#include <numeric>

class Fraction {
    int m_num { 0 };
    int m_den { 1 };
public:
    Fraction(int i_n, int i_d = 1) : m_num { i_n }, m_den {i_d } { reduce(); }

    void print(){
        std::cout << m_num << '/' << m_den << '\n';
    }
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

};

Fraction operator*(Fraction f, int m) {
    Fraction toReturn { f.m_num * m, f.m_den };
    toReturn.reduce();
    return toReturn ;
}

Fraction operator*(int m, Fraction f) {
    Fraction toReturn { f.m_num * m, f.m_den };
    toReturn.reduce();
    return toReturn ;
}

Fraction operator*(Fraction f1, Fraction f2) {
    Fraction toReturn { f1.m_num * f2.m_num, f1.m_den * f2.m_den };
    toReturn.reduce();
    return toReturn ;
}

int main()
{
    Fraction f1{2, 5};
    f1.print();

    Fraction f2{3, 8};
    f2.print();

    Fraction f3{ f1 * f2 };
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{ 2 * f2 };
    f5.print();

    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();

    Fraction f7{0, 6};
    f7.print();

    return 0;
}
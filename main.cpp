#include <iostream>
#include <stdexcept>

class Fraction {
    int m_num { 0 };
    int m_denom { 1 };
public:
    Fraction(int i_num, int i_denom) : m_num { i_num }, m_denom { i_denom } {
        try {
            if(m_denom == 0){
                throw std::runtime_error("Your fraction is invalid.");
            }
        } catch (std::runtime_error()){
            std::cout << "Your fraction is invalid.";
        }
    }
    void print(){
        std::cout << m_num << "/" << m_denom;
    }
};

int askForInt(){
    std::cout << "Enter an integer: ";
    int x {};
    std::cin >> x;
    return x;
}

int main(){

    try
    {
        Fraction f{ askForInt(), askForInt() };
        std::cout << "Your fraction is: ";
        f.print();
        std::cout << "\n";
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
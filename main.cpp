#include <iostream>
#include <cassert>
#include <cstdint>

class RGBA {
    std::uint8_t m_red;
    std::uint8_t m_green;
    std::uint8_t m_blue;
    std::uint8_t m_alpha;
public:

    RGBA(std::uint8_t i_r = 0, std::uint8_t i_g = 0, std::uint8_t i_b = 0, std::uint8_t i_a = 255)
    : m_red { i_r }
    , m_green { i_g }
    , m_blue { i_b }
    , m_alpha { i_a }
    {}

    void print(){
        std::cout
        << "r=" << static_cast<int>(m_red)
        << " g=" << static_cast<int>(m_green)
        << " b=" << static_cast<int>(m_blue)
        << " a=" << static_cast<int>(m_alpha)
        << "\n";
    }
};

int main()
{
    RGBA teal{ 0, 127, 127 };
    teal.print();

    return 0;
}
#include <iostream>

class IntPair {
public:
    int i1 {};
    int i2 {};

    void print(){
        std::cout << "Pair(" << i1 << ", " << i2 <<")\n";
    }

    void set(int i, int j){
        i1 = i;
        i2 = j;
    }
};

int main()
{
    IntPair p1;
    p1.set(1, 1); // set p1 values to (1, 1)

    IntPair p2 { 2, 2 }; // initialize p2 values to (2, 2)

    p1.print();
    p2.print();

    return 0;
}
#include <iostream>
#include <cassert>

class Stack {
    int array[10]{};
    int size { 0 };
public:
    void reset(){
        for(int i : array){
            i = 0;
        }
        size = 0;
    }
    bool push(int p){
        if(size < 10){
            array[size] = p;
            ++size;
            return true;
        }
        return false;
    }
    int pop(){
        assert(size > 0);
        int v { array[size - 1] };
        array[size - 1] = 0;
        --size;
        return v;
    }
    void print(){
        std::cout << "( ";
        for(int i : array){
            if (i != 0) {
                std::cout << i << ' ';
            }
        }
        std::cout << ")\n";
    }
};

int main()
{
    Stack stack;
    stack.print();

    stack.push(5);
    stack.push(3);
    stack.push(8);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();

    stack.print();

    return 0;
}
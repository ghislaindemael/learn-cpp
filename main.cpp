#include <iostream>
#include <cassert>
#include "random.h"

constexpr int g_consoleLines{ 15 };

class Direction
{
public:
    enum Type
    {
        up,
        down,
        left,
        right,
        max_directions,
    };

    Direction(Type type) :m_type(type){}

    Type getType() const
    {
        return m_type;
    }

    Direction operator-() const
    {
        switch (m_type)
        {
            case up:    return Direction{ down };
            case down:  return Direction{ up };
            case left:  return Direction{ right };
            case right: return Direction{ left };
        }

        assert(0 && "Unsupported direction was passed!");
        return Direction{ up };
    }

    friend std::ostream& operator<<(std::ostream& stream, Direction dir)
    {
        switch (dir.getType())
        {
            case Direction::up:     return (stream << "up");
            case Direction::down:   return (stream << "down");
            case Direction::left:   return (stream << "left");
            case Direction::right:  return (stream << "right");
            default:                return (stream << "unknown direction");
        }
    }

    static Direction getRandomDirection()
    {
        Type random{ static_cast<Type>(Random::get(0, Type::max_directions - 1)) };
        return Direction{ random };
    }

private:
    Type m_type{};
};

struct Point
{
    int x{};
    int y{};

    friend bool operator==(Point p1, Point p2)
    {
        return p1.x == p2.x && p1.y == p2.y;
    }

    friend bool operator!=(Point p1, Point p2)
    {
        return !(p1 == p2);
    }

    Point getAdjacentPoint(Direction dir) const
    {
        switch (dir.getType())
        {
            case Direction::up:     return Point{ x, y - 1 };
            case Direction::down:   return Point{ x, y + 1 };
            case Direction::left:   return Point{ x - 1, y };
            case Direction::right:  return Point{ x + 1, y };
        }

        return *this;
    }
};

class Tile {
    int m_num { 0 };
public:
    Tile() = default;
    int getNum() const{
        return m_num;
    }
    void setNum(int i){
        m_num = i;
    }
    bool isEmpty() const{
        return m_num == 0;
    }
};

class Board {
    Tile board[4][4]{};
public:
    Board(){
        for(int i { 0 }; i < 4; ++i){
            for(int j { 0 }; j < 4; ++j){
                board[i][j].setNum(4*i + j + 1);
            }
        }
        board[3][3].setNum(0);
    }
    Tile getTile(int i, int j){
        return board[i][j];
    }
    bool isSolved(){
        for(int i { 0 }; i < 4; ++i){
            for(int j { 0 }; j < 4; ++j){
                int toCheck { 4*i + j + 1 };
                if(toCheck < 16) {
                    if (board[i][j].getNum() != toCheck) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    Point getEmptyTilePos() const
    {
        for (int x = 0; x < 4; ++x)
            for (int y = 0; y < 4; ++x)
                if (board[x][y].isEmpty())
                    return { x,y };

        assert(0 && "There is no empty tile in the board!!!");
        return { -1,-1 };
    }

    static bool isValidTilePos(Point pt)
    {
        return (pt.x >= 0 && pt.x < 4)
               && (pt.y >= 0 && pt.y < 4);
    }

    void swapTiles(Point pt1, Point pt2)
    {
        std::swap(board[pt1.y][pt1.x], board[pt2.y][pt2.x]);
    }

    bool moveTile(Direction dir)
    {
        Point emptyTile{ getEmptyTilePos() };
        Point adj{ emptyTile.getAdjacentPoint(-dir) };

        if (!isValidTilePos(adj))
            return false;

        swapTiles(adj, emptyTile);
        return true;
    }

    void randomize()
    {
        for (int i = 0; i < 1000; ++i)
        {
            bool success = moveTile(Direction::getRandomDirection());
            if (!success)
                --i;
        }
    }

};

std::ostream &operator<<(std::ostream &out, const Tile &t) {
    if(!t.isEmpty()){
        out << t.getNum();
    } else {
        out << " ";
    }
    out << "\t";
    return out;
}

std::ostream &operator<<(std::ostream &out, Board& b) {
    for(int i { 0 }; i < g_consoleLines; ++i){
        out << "\n";
    }
    for(int i { 0 }; i < 4; ++i){
        for(int j { 0 }; j < 4; ++j){
            out << b.getTile(i, j) << "\t";
        }
        out << "\n";
    }
    return out;
}




namespace UserInput{
    char askForCommand() {
        char c {};
        do {
            std::cout << "Enter one of the following (z/q/s/d/p): ";
            std::cin >> c;
            std::cin.ignore();
        } while (c != 'z' && c != 'q' && c != 's' && c != 'd' && c != 'p');
        std::cout << c << " is a valid command !\n";
        return static_cast<char>(c);
    };

    Direction charToDirection(char ch)
    {
        switch (ch)
        {
            case 'z': return Direction{ Direction::up };
            case 's': return Direction{ Direction::down };
            case 'q': return Direction{ Direction::left };
            case 'd': return Direction{ Direction::right };
        }

        assert(0 && "Unsupported direction was passed!");
        return Direction{ Direction::up };
    }
}

int main()
{
    Board board{};
    board.randomize();
    std::cout << board;

    while (!board.isSolved())
    {
        char ch{ UserInput::askForCommand() };

        // Handle non-direction commands
        if (ch == 'p')
        {
            std::cout << "\n\nBye!\n\n";
            return 0;
        }

        // Handle direction commands
        Direction dir{ UserInput::charToDirection(ch) };

        bool userMoved{ board.moveTile(dir) };
        if (userMoved)
            std::cout << board;
    }

    std::cout << "\n\nYou won!\n\n";
    return 0;
}
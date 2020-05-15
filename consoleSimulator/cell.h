#ifndef CELL_H
#define CELL_H

#include <string>
using namespace std;

enum Color {
    white,      // Empty/unused cell
    blue,       // Data in memory
    red,        // Stack
    yellow,     // Contains an instruction
    orange      // Instruction inside this cell is being executed
};


class Cell
{
private:
    int value = 0;
    bool empty = true;
    Color color = Color::white;

    bool containsAnInstruction = false;
    string instruction = "";

public:
    // - Constructors -
    Cell() {}

    // - Get & Set -
    void setValue(int val) {
        empty = false;
        value = val;
        color = Color::blue;
    }
    int getValue() const {
        return value;
    }
    void setInstruction(string val) {
        containsAnInstruction = true;
        instruction = val;
    }
    bool containsInstruction() const {
        return containsAnInstruction;
    }
    bool isEmpty() const {
        return empty;
    }


};

#endif // CELL_H

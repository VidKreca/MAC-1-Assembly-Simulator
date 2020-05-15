#ifndef MAC1_H
#define MAC1_H

#include <iostream>
#include <string>

#include "cell.h"

using namespace std;


class Simulator
{
private:
    string IR = ""; // Instruction register
    int PC = 0;     // Program counter
    int SP = 0;     // Stack pointer
    int AC = 0;     // Acumulator
    // MAR - Memory Address Register
    // MBR - Memory Buffer Register

    int size = 160;
    Cell *memory;


public:
    // Helpr methods
    bool validateIndex(int index) const {
        return (index >= 0 && index < size);
    }

    // - Constructors -
    Simulator();

    // - Destructor -
    ~Simulator();

    // - Get & Set -
    Cell getCell(int index) const {
        if (validateIndex(index))
            return memory[index];
        else
            throw "Invalid index";
    }
    void setCell(int index) {
        if (validateIndex(index))
            memory[index].setValue(AC);
    }
    void setCell(int index, int val) {
        if (validateIndex(index))
            memory[index].setValue(val);
    }
    void setCell(int index, string val) {
        if (validateIndex(index))
            memory[index].setInstruction(val);
    }

    int getSize() const { return size; }
    string getIR() const { return IR; }
    int getPC() const { return PC; }
    int getSP() const { return SP; }
    int getAC() const { return AC; }
    void setIR(string val) { IR = val; }
    void setPC(int val) { PC = val; }
    void setSP(int val) { SP = val; }
    void setAC(int val) { AC = val; }

    // - Methods -





};

#endif // MAC1_H

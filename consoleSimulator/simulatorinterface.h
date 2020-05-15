#ifndef SIMULATORINTERFACE_H
#define SIMULATORINTERFACE_H

#include "simulator.h"


class SimulatorInterface
{
private:
    Simulator *sim;

public:
    // - Constructors -
    SimulatorInterface(Simulator *sim);

    // - Methods -
    void print() const;

    // === Commands ===
    // - Basic -
    void LOCO(int val) {
        sim->setIR("LOCO");
        sim->setAC(val);
    }
    // - Direct -
    // Load direct: ac := m[x]
    void LODD(unsigned int address) {
        sim->setIR("LODD");
        if (!sim->getCell(address).containsInstruction()) {
            int value = sim->getCell(address).getValue();
            sim->setAC(value);
        } else
            throw "Reading a cell containing an instruction.";
    }
    // Store direct: m[x] := ac
    void STOD(unsigned int address) {
        sim->setIR("STOD");
        if (!sim->getCell(address).containsInstruction())
            sim->setCell(address);
        else
            throw "Writing to a cell containing an instruction.";
    }
    // Add direct: ac := ac + m[x]
    void ADDD(unsigned int address) {
        if (!sim->getCell(address).containsInstruction()) {
            int currentAC = sim->getAC();
            currentAC += sim->getCell(address).getValue();
            sim->setAC(currentAC);
        } else
            throw "Reading from cell containing an instruction.";
    }
    // Subtract direct: ac := ac - m[x]
    void SUBD(unsigned int address) {
        if (!sim->getCell(address).containsInstruction()) {
            int currentAC = sim->getAC();
            currentAC -= sim->getCell(address).getValue();
            sim->setAC(currentAC);
        } else
            throw "Reading from cell containing an instruction.";
    }
};

#endif // SIMULATORINTERFACE_H

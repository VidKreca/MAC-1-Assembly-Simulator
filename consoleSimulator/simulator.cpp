#include "simulator.h"

Simulator::Simulator()
{
    memory = new Cell[size];
}

Simulator::~Simulator() {
    delete[] memory;
}





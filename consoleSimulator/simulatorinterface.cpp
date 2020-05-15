#include "simulatorinterface.h"

SimulatorInterface::SimulatorInterface(Simulator *sim) : sim(sim)
{

}



// - Methods -------------------------------------------------------
inline void printLine(int length, bool newLine = false) {
    for (int i = 0; i < length; i++)
        cout << '-';
    if (newLine) cout << endl;
}
void SimulatorInterface::print() const {
    int cellSize = 5;
    int rows = 20;
    int columns = sim->getSize() / rows;

    // Print a line at the top
    printLine((columns+1)*(cellSize+1));

    // Print the table with values
    for (int y = 0; y < rows; y++) {
        cout << endl << y << ((y >= 10) ? " |" : "  |");
        for (int x = y; x < columns*rows; x += rows) {
            string cellValue = (sim->getCell(x).isEmpty()) ? "x" : to_string(sim->getCell(x).getValue());
            cout << " " << cellValue << "   |";
        }
    }
    cout << endl;
    printLine((columns+1)*(cellSize+1), true);
    cout << "IR: " << sim->getIR() << "   PC: " << sim->getPC() << endl;
    cout << "SP: " << sim->getSP() << "   AC: " << sim->getAC() << endl;
    cout << endl << endl;
}

#include <iostream>

#include "simulator.h"
#include "simulatorinterface.h"

using namespace std;

int main()
{
    Simulator sim;
    SimulatorInterface interface(&sim);

    string input = "";
    while(1) {
        system("cls");
        interface.print();

        getline(cin, input);
        interface.LOCO(11);
        interface.STOD(10);
        interface.LOCO(1);
        interface.LODD(10);
    }

    return 0;
}

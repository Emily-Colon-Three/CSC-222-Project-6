#include <iostream>
#include "Employee.h"
#include "ProductionWorker.h"
#include "ShiftSupervisor.h"
#include "TeamLeader.h"

using namespace std;

int main()
{
    cout << "Testing Employee Class:\n";

    Employee bob("Robert", 999, 4, 9, 2026);

    cout << bob.getName() << endl;
    cout << bob.getNumber() << endl;
    cout << bob.getDateHired() << endl;

    bob.printEmployee(); // Should match with prior info.

    cout << "Testing ProductionWorker Class:\n";

    ProductionWorker sara("Sara", 6, 3, 14, 2025, DAYSHIFT, 15.00);
    ProductionWorker james("James", 7, 2, 16, 2026, NIGHTSHIFT, 19.00);

    sara.printProductionWorker();
    james.printProductionWorker();

    cout << "Testing ShiftSupervisor Class:\n";

    ShiftSupervisor paul("Paul", 15, 3, 19, 2024, 50000.00, 5000.00);

    paul.printShiftSupervisor();

    cout << "Testing TeamLeader Class:\n";

    TeamLeader napoleon("Napoleon", 18, 5, 5, 2020, NIGHTSHIFT, 25.00, 100.00, 30, 35);

    napoleon.printTeamLeader();
    return 0;
}

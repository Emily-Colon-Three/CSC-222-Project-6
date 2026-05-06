// Here, main serves as the client program. It allows the user to create objects
#include <iostream>
#include "Employee.h"
#include "ProductionWorker.h"
#include "ShiftSupervisor.h"
#include "TeamLeader.h"
#include <exception>

using namespace std;

int main()
{
    // Choosing class
    int choice;
    bool isValid = false;
    bool cont = false;

    string nameInput;
    int numInput;
    int monthInput;
    int dayInput;
    int yearInput;
    int shiftInput;

    do {
        cout << "Which kind of employee would you like to create?\n";
        cout << "1. Employee (Default)\n";
        cout << "2. Production Worker\n";
        cout << "3. Shift Supervisor\n";
        cout << "4. Team Leader\n";

        cin >> choice;

        switch (choice)
        {
        case 1: // Chose to make regular Employee
            {
                Employee userMade("", 0, 0, 0, 0);

                cout << "What will you make the Employee's name?\n";
                cin >> nameInput;
                userMade.setName(nameInput);

                // Employee Number input (with validation)
                do {
                    cout << "What Employee Number will they have? (0-9999)\n";
                    cin >> numInput;
                    try {
                        userMade.setNumber(numInput);
                        cont = true;
                    } catch (const Employee::InvalidEmployeeNumber& e) {
                        cerr << "Error: " << e.what() << endl;
                    }
                } while (cont == false);
                cont = false;

                cout << "What month were they hired on?\n";
                cin >> monthInput;
                cout << "What day were they hired on?\n";
                cin >> dayInput;
                cout << "What year were they hired on?\n";
                cin >> yearInput;
                userMade.setDateHired(monthInput, dayInput, yearInput); // Sets custom employee's date hired to user input.

                // Final Employee object report is printed
                userMade.printEmployee();
            }

        case 2: // ProductionWorker chosen
            {
                ProductionWorker userMade("", 0, 0, 0, 0, 1, 0.0);

                cout << "What will be the production worker's name?\n";
                cin >> nameInput;
                userMade.setName(nameInput);

                // Employee Number input (with validation)
                do {
                    cout << "What Employee Number will they have? (0-9999)\n";
                    cin >> numInput;
                    try {
                        userMade.setNumber(numInput);
                        cont = true;
                    } catch (const Employee::InvalidEmployeeNumber& e) {
                        cerr << "Error: " << e.what() << endl;
                    }
                } while (cont == false);
                cont = false;

                cout << "What month were they hired on?\n";
                cin >> monthInput;
                cout << "What day were they hired on?\n";
                cin >> dayInput;
                cout << "What year were they hired on?\n";
                cin >> yearInput;
                userMade.setDateHired(monthInput, dayInput, yearInput); // Sets custom employee's date hired to user input.

                // Shift input (with validation)
                do {
                    cout << "Do they work Day shifts (1) or Night shifts (2)?\n";
                } while (cont == false);
                cont = false;
            }
        }
    } while (cont == true);

    return 0;
}

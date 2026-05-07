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
    // Variables for moving through menus and looping until validation is complete
    int choice;
    bool isValid = false;
    bool cont = false;
    char willContinue;

    // Variables for user input values
    string nameInput;
    int numInput;
    int monthInput;
    int dayInput;
    int yearInput;
    int shiftInput;
    float payInput;
    int hoursInput;

    // Main client loop which allows multiple objects to be created during the same session of runtime.
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
                        cont = true; // Will only happen if the number is set without exception
                    } catch (const Employee::InvalidEmployeeNumber& e) {
                        cerr << "Error: " << e.what() << endl;
                    }
                } while (cont == false);
                cont = false; // Sets continue boolean back to false to be re-used later

                cout << "What month were they hired on? (1-12)\n";
                cin >> monthInput;
                cout << "What day were they hired on? (1-31)\n";
                cin >> dayInput;
                cout << "What year were they hired on?\n";
                cin >> yearInput;
                userMade.setDateHired(monthInput, dayInput, yearInput); // Sets custom employee's date hired to user input.

                // Final Employee object report is printed
                userMade.printEmployee();

                break;
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
                    } catch (const ProductionWorker::InvalidEmployeeNumber& e) {
                        cerr << "Error: " << e.what() << endl;
                    }
                } while (cont == false);
                cont = false;

                cout << "What month were they hired on? (1-12)\n";
                cin >> monthInput;
                cout << "What day were they hired on? (1-31)\n";
                cin >> dayInput;
                cout << "What year were they hired on?\n";
                cin >> yearInput;
                userMade.setDateHired(monthInput, dayInput, yearInput); // Sets custom employee's date hired to user input.

                // Shift input (with validation)
                do {
                    cout << "Do they work Day shifts (1) or Night shifts (2)?\n";
                    cin >> shiftInput;

                    try {
                        userMade.setShift(shiftInput);
                        cont = true;
                    } catch (const ProductionWorker::InvalidShift& e) {
                        cerr << "Error: " << e.what() << endl;
                    }
                } while (cont == false);
                cont = false;

                // Pay per hour input (with validation)
                do {
                    cout << "How much do they earn per hour of work?\n$";
                    cin >> payInput;

                    try {
                        userMade.setWage(payInput);
                        cont = true;
                    } catch (const ProductionWorker::InvalidPayRate& e) {
                        cerr << "Error: " << e.what() << endl;
                    }
                } while (cont == false);
                cont = false;

                userMade.printProductionWorker();

                break;
            }

        case 3:
            {
                ShiftSupervisor userMade("", 0, 0, 0, 0, 0.0, 0.0);

                cout << "What will you make the Shift Supervisor's name?\n";
                cin >> nameInput;
                userMade.setName(nameInput);

                // Employee Number input (with validation)
                do {
                    cout << "What Employee Number will they have? (0-9999)\n";
                    cin >> numInput;

                    try {
                        userMade.setNumber(numInput);
                        cont = true;
                    } catch (const ShiftSupervisor::InvalidEmployeeNumber& e) {
                        cerr << "Error: " << e.what() << endl;
                    }
                } while (cont == false);
                cont = false;

                cout << "What month were they hired on? (1-12)\n";
                cin >> monthInput;
                cout << "What day were they hired on? (1-31)\n";
                cin >> dayInput;
                cout << "What year were they hired on?\n";
                cin >> yearInput;
                userMade.setDateHired(monthInput, dayInput, yearInput); // Sets custom employee's date hired to user input.

                cout << "What is the annual salary of the Shift Supervisor?\n$";
                cin >> payInput;
                userMade.setSalary(payInput);

                cout << "What is the Shift Supervisor's production bonus?\n$";
                cin >> payInput;
                userMade.setBonus(payInput);

                userMade.printShiftSupervisor();

                break;
            }

        case 4:
            {
                TeamLeader userMade("", 0, 0, 0, 0, 1, 0.0, 0.0, 0, 0);

                cout << "What will you make the Team Leader's name?\n";
                cin >> nameInput;
                userMade.setName(nameInput);

                // Employee Number input (with validation)
                do {
                    cout << "What Employee Number will they have? (0-9999)\n";
                    cin >> numInput;

                    try {
                        userMade.setNumber(numInput);
                        cont = true;
                    } catch (const TeamLeader::InvalidEmployeeNumber& e) {
                        cerr << "Error: " << e.what() << endl;
                    }
                } while (cont == false);
                cont = false;

                cout << "What month were they hired on? (1-12)\n";
                cin >> monthInput;
                cout << "What day were they hired on? (1-31)\n";
                cin >> dayInput;
                cout << "What year were they hired on?\n";
                cin >> yearInput;
                userMade.setDateHired(monthInput, dayInput, yearInput); // Sets custom employee's date hired to user input.

                // Shift input (with validation)
                do {
                    cout << "Do they work Day shifts (1) or Night shifts (2)?\n";
                    cin >> shiftInput;

                    try {
                        userMade.setShift(shiftInput);
                        cont = true;
                    } catch (const TeamLeader::InvalidShift& e) {
                        cerr << "Error: " << e.what() << endl;
                    }
                } while (cont == false);
                cont = false;

                // Pay per hour input (with validation)
                do {
                    cout << "How much do they earn per hour of work?\n$";
                    cin >> payInput;

                    try {
                        userMade.setWage(payInput);
                        cont = true;
                    } catch (const TeamLeader::InvalidPayRate& e) {
                        cerr << "Error: " << e.what() << endl;
                    }
                } while (cont == false);
                cont = false;

                cout << "What is the bonus value for this Team Leader?\n$";
                cin >> payInput;
                userMade.setBonus(payInput);

                cout << "How many hours are required for this Team Leader's training?\n";
                cin >> hoursInput;
                userMade.setReqHrs(hoursInput);

                cout << "How many hours has the Team Leader attended?\n";
                cin >> hoursInput;
                userMade.setAttHrs(hoursInput);

                userMade.printTeamLeader();

                break;
            }

        default:
            {
                cout << "You did not enter a real option.\n";
            }
        }

        cout << "Would you like to make a new employee? (Y/N)\n";
        cin >> willContinue;
        if (willContinue == 'Y' || willContinue == 'y')
        {
            cont = true;
        }

    } while (cont == true);

    return 0;
}

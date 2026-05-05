#include "ShiftSupervisor.h"
#include <string>
#include <iostream>
#include <iomanip>

/*
    Summary: Creates a ShiftSupervisor object using data from the parameters, passing in some and utilizing an initializer list for the base (Employee) class.
    Parameters: Employee's name, name, their number, num, the date of their hiring represented by m (month), d (day), and y(year).Then the annual salary and bonus are salary and bonus, respectively.
    Return: None
    Preconditions: No defaults; inputs are needed for all parameters.
    Postconditions: A new object of the ShiftSupervisor class is created. Mutator functions of the class are called to do so.
*/
ShiftSupervisor::ShiftSupervisor(std::string name, int num, int m, int d, int y, float salary, float bonus) : Employee(name, num, m, d, y)
{
    this->setSalary(salary);
    this->setBonus(bonus);
}

// No return, takes in float of a new annual salary to set for the ShiftSupervisor object. It will reject and print an error for negative salaries.
void ShiftSupervisor::setSalary(float newSalary)
{
    if (newSalary >= 0)
    {
        this->annualSalary = newSalary;
    }
    else
    {
        std::cout << "Salary Input Cannot be Negative.\n";
    }
}

// No return, takes in float for the dollars in the new production bonus for a ShiftSupervisor object. It rejects and gives an error for bonuses which are negative.
void ShiftSupervisor::setBonus(float newBonus)
{
    if (newBonus >= 0)
    {
        this->annualProductionBonus = newBonus;
    }
    else
    {
        std::cout << "Bonus Input Cannot be Negative.\n";
    }
}

/*
    Summary: Prints out the data of a ShiftSupervisor object, first the base Employee data using printEmployee.
    Parameters: None
    Return: None
    Preconditions: Data should be filled into object and correct before use. <iomanip> used.
    Postconditions: Uses console to print report, specifically cout.
*/
void ShiftSupervisor::printShiftSupervisor()
{
    this->printEmployee();

    std::cout << "This employee is a Shift Supervisor." << std::endl;
    std::cout << "Annual Salary: $" << std::fixed << std::setprecision(2) << this->getSalary() << std::endl;
    std::cout << "Annual Production Bonus: $" << std::fixed << std::setprecision(2) << this->getBonus() << std::endl;
}

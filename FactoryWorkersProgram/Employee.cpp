#include "Employee.h"
#include <string>
#include <iostream>

/*
    Summary: Constructs an Employee object, given the information of its name, employee number, and the month, day, and year of their hiring.
    Parameters: new employee's name, name, their number, num, the month they were hired, m, the day they were hired, d, and the year they were hired, y.
    Return: None.
    Preconditions: None.
    Postconditions: A new Employee object is created with the given data in the parameters, and the 3 mutator functions of the class are called.
*/
Employee::Employee(std::string name, int num, int m, int d, int y)
{
    this->setName(name);
    this->setNumber(num);
    this->setDateHired(m, d, y);
}

// Sets the employee's name, updating the variable
void Employee::setName(std::string newName)
{
    this->name = newName;
}

// Sets employee's number, updating number data member.
void Employee::setNumber(int newNum)
{
    this->number = newNum;
}

// Sets the employee's monthHired, dayHired, and yearHired variables, composing the date of their hiring.
void Employee::setDateHired(int m, int d, int y)
{
    this->monthHired = m;
    this->dayHired = d;
    this->yearHired = y;
}

/*
    Summary: Prints and reports the information of an Employee.
    Parameters: None
    Return: None
    Preconditions: Employee should contain proper information, with the month, day, and year being all real and not out of order.
    Postconditions: Information of the Employee object is printed to screen using cout object.
*/
void Employee::printEmployee() const
{
    std::cout << "Employee Name: " << this->name << std::endl;
    std::cout << "Employee Number: " << this->number << std::endl;
    std::cout << "Date Hired: " << this->getDateHired() << std::endl;
}

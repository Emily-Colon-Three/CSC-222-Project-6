#include "ProductionWorker.h"
#include <iostream>
#include <string>
#include <iomanip>

/*
    Summary: Constructs a new ProductionWorker object, laying on top of the usual Employee base class constructor with the addition of a shift and hourly wage.
    Parameters: Name of ProductionWorker, name, their employee number, num, their month, day, and year of being hired, m, d, and y, and finally an int representing the type of shift and a float for dollars paid per hour.
    Return: None
    Preconditions: Needs input for all parameters, no default is provided.
    Postconditions: A new ProductionWorker object is created with the given data, using some memory.
*/
ProductionWorker::ProductionWorker(std::string name, int num, int m, int d, int y, int shift, float wage) : Employee(name, num, m, d, y)
{
    this->setShift(shift);
    this->setWage(wage);
}

// Gets the shift of the worker and returns it in string form, optimal for printing.
std::string ProductionWorker::getShift() const
{
    if (this->timeOfShift == DAYSHIFT)
    {
        return "Day Shift";
    }
    else if (this->timeOfShift == NIGHTSHIFT)
    {
        return "Night Shift";
    }
    else
    {
        return ""; // Blank string for invalid shift data.
    }
}

// Sets the shift of the ProductionWorker object to either 1 or 2, day or night. If the input is not either, an error is printed and no change is made, validating input. Returns nothing.
void ProductionWorker::setShift(int newShift)
{
    if (newShift >= DAYSHIFT && newShift <= NIGHTSHIFT) // Only works with actual shift values
    {
        this->timeOfShift = newShift;
    }
    else
    {
        std::cout << "Shift Input Invalid." << std::endl; // Rejects invalid input with error message
    }
}

// Changes the pay per hour of a ProductionWorker object to the input, returning nothing. Does not change if input is invalid, i.e. negative and less than 0.
void ProductionWorker::setWage(float newWage)
{
    if (newWage >= 0)
    {
        this->payPerHour = newWage;
    }
    else
    {
        std::cout << "Wage Input Cannot be Negative.\n";
    }
}

/*
    Summary: Prints out a report of the ProductionWorker object's information, including that laid out as a part of its base class, Employee.
    Parameters: None
    Return: None
    Preconditions: Object must have correct and updated information for report to be accurate.
    Postconditions: Prints a report to console using cout object.
*/
void ProductionWorker::printProductionWorker() const
{
    this->printEmployee(); // Prints base employee information

    std::cout << "This employee is a Production Worker." << std::endl;
    std::cout << "Time of Work: " << this->getShift() << std::endl;
    std::cout << std::fixed << std::setprecision(2) << "Wage Earned per Hour: $" << this->getWage() << std::endl;
}

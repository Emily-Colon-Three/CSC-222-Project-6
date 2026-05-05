#include "TeamLeader.h"
#include "ProductionWorker.h"
#include <string>
#include <iostream>
#include <iomanip>

/*
    Summary: Constructs a new TeamLeader object, using the ProductionWorker class constructor as a base. In the brackets, the derived-specific data is kept.
    Parameters: the name, employee number, month hired, day hired, and year hired first, then the shift worked and hourly pay, then finally the monthly bonus, required training hours, and completed training hours.
    Return: None
    Preconditions: No defaults, all input is defined.
    Postconditions: A new object of class TeamLeader is created. ProductionWorker constructor called in the process.
*/
TeamLeader::TeamLeader(std::string name, int num, int m, int d, int y, int shift, float wage, float bonus, int reqHrs, int attHrs) : ProductionWorker(name, num, m, d, y, shift, wage)
{
    this->setBonus(bonus);
    this->setReqHrs(reqHrs);
    this->setAttHrs(attHrs);
}

// Mutator function with no return, passing in a float for a new monthly bonus in dollars. If the input is not 0 or more, it will not be used and an error is printed. Otherwise, the monthly bonus changes.
void TeamLeader::setBonus(float newBonus)
{
    if (newBonus >= 0)
    {
        this->monthlyBonus = newBonus;
    }
    else
    {
        std::cout << "Input Cannot be Negative.\n";
    }
}

// Mutator function which changes the required hours data member of a TeamLeader object to a value passed in via parameters. No return is given.
void TeamLeader::setReqHrs(int newHours)
{
    this->requiredHours = newHours;
}

// Mutator function which changes the data member for number of training hours attended to an integer passed in through parameters. No return featured.
void TeamLeader::setAttHrs(int newHours)
{
    this->attendedHours = newHours;
}

/*
    Summary: Prints out a report of the information stored in a TeamLeader object.
    Parameters: None
    Return: None
    Preconditions: Object is filled with proper data. iomanip used.
    Postconditions: Uses the console to print information, calls printProductionWorker().
*/
void TeamLeader::printTeamLeader() const
{
    this->printProductionWorker();

    std::cout << "This Worker is a Team Leader.\n";
    std::cout << "Monthly Bonus: $" << std::fixed << std::setprecision(2) << this->getBonus() << std::endl;
    std::cout << "Hours of Training Required: " << this->getReqHrs() << std::endl;
    std::cout << "Hours of Training Attended: " << this->getAttHrs() << std::endl;
}

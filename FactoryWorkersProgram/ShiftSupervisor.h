#ifndef SHIFTSUPERVISOR_H
#define SHIFTSUPERVISOR_H
#include "Employee.h"
#include <string>

class ShiftSupervisor : public Employee
{
private:
    float annualSalary;
    float annualProductionBonus;

public:
    ShiftSupervisor(std::string name, int num, int m, int d, int y, float salary, float bonus);

    inline float getSalary() const
    {
        return this->annualSalary;
    }
    inline float getBonus() const
    {
        return this->annualProductionBonus;
    }

    void setSalary(float newSalary);
    void setBonus(float newBonus);

    void printShiftSupervisor();
};
#endif // SHIFTSUPERVISOR_H

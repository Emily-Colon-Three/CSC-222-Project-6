#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H
#include "Employee.h"
#include <string>

const int DAYSHIFT = 1;
const int NIGHTSHIFT = 2;

class ProductionWorker : public Employee
{
private:
    int timeOfShift;
    float payPerHour;

public:
    ProductionWorker(std::string name, int num, int m, int d, int y, int shift, float wage);

    std::string getShift() const;
    inline float getWage() const
    {
        return this->payPerHour;
    }

    void setShift(int newShift);
    void setWage(float newWage);

    void printProductionWorker() const;
};
#endif // PRODUCTIONWORKER_H

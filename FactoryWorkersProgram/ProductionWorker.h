#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H
#include "Employee.h"
#include <string>
#include <exception>

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

    // Exception class for exceptions where a given ProductionWorker object's shift is invalid, neither 1 nor 2.
    class InvalidShift : public std::exception
    {
    private:
        std::string message;

    public:
        InvalidShift(const std::string& msg) : message(msg) {}

        const char* what() const noexcept override
        {
            return message.c_str();
        }
    };
};
#endif // PRODUCTIONWORKER_H

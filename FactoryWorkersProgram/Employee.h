#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <exception>

class Employee
{
private:
    std::string name;
    int number;

    int yearHired;
    int monthHired;
    int dayHired;

public:
    Employee(std::string name, int num, int m, int d, int y);

    void setName(std::string newName);
    void setNumber(int newNum);
    void setDateHired(int m, int d, int y);

    // Accessor functions
    inline std::string getName() const
    {
        return name;
    }
    inline int getNumber() const
    {
        return number;
    }
    inline std::string getDateHired() const
    {
        std::string date = std::to_string(monthHired) + '/' + std::to_string(dayHired) + '/' + std::to_string(yearHired); // Formats date in mm/dd/yyyy
        return date;
    }

    void printEmployee() const;

    class InvalidEmployeeNumber : public std::exception
    {
    private:
        std::string message;

    public:
        InvalidEmployeeNumber(const std::string& msg) : message(msg) {}

        const char* what() const noexcept override
        {
            return message.c_str();
        }
    };
};
#endif // EMPLOYEE_H

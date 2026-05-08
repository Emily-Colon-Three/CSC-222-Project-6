/* This header file acts as the definition and declaration of the NumberArray class. This class serves as a dynamically allocated array of doubles, having member functions to access data
from these NumberArray objects and make calculations based off of it. Additionally, it has built-in protections to ensure copying and assigning objects causes no memory leaks or errors.*/
#ifndef DATE_H
#define DATE_H

class NumberArray{
private:
    int size;
    double* data;

public:
    NumberArray(); // Overloaded, this one has no parameters.
    NumberArray(int);

    NumberArray(const NumberArray& other); // Copy constructor

    ~NumberArray();

    NumberArray& operator=(const NumberArray& right); // Overloaded assignment operator

    void setNumber(int, double);

    inline double getNumber(int index)
    {
        if (index < size && index >= 0) // Index validation
        {
            return data[index];
        }
        else
        {
            return 0;
        }
    }

    double getMin() const;
    double getMax() const;
    double getAverage() const;

    void print() const;
};

#endif // DATE_H

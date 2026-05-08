#include "NumberArray.h"
#include <iostream>

const int DEFAULT_SIZE = 10;

NumberArray::NumberArray()
{
    NumberArray::size = DEFAULT_SIZE;

    NumberArray::data = new double[size]; // Dynamically allocates memory according to given size.

    for (int i = 0; i < NumberArray::size; i++)
    {
        NumberArray::data[i] = 0.0; // Assigns value to default for all indices in the array
    }
}

NumberArray::NumberArray(int s = DEFAULT_SIZE) // s means size in this case
{
    NumberArray::size = s;

    NumberArray::data = new double[size]; // Dynamically allocates memory according to given size.

    for (int i = 0; i < NumberArray::size; i++)
    {
        NumberArray::data[i] = 0.0; // Assigns value to default for all indices in the array
    }
}

/*
    Summary: A constructor function overload which copies the contents of a NumberArray object into a brand new one, creating a deep copy.
    Parameters: A constant reference to the array being copied, called "other".
    Return: None
    Preconditions: Nothing of particular importance; the class makes sure no objects have uninitialized data.
    Postconditions: A new NumberArray object is created with identical data to the one in the parameters. The object copied from will not be changed due to its constant nature, ensuring no accidental changes.
*/
NumberArray::NumberArray(const NumberArray& other)
{
    NumberArray::size = other.size; // Syncs sizes

    NumberArray::data = new double[size];

    for (int i = 0; i < NumberArray::size; i++) // Loops through all the elements to copy data from other to the new object
    {
        NumberArray::data[i] = other.data[i];
    }
}

NumberArray::~NumberArray()
{
    delete[] NumberArray::data; // Frees up all allocated memory from data

    std::cout << "Memory de-allocated.\n"; // Prints message confirming memory release
}

/*
    Summary: Acts as a more advanced version of the default assignment operator; it makes an object identical yet separate to a specified NumberArray object, checking for self-assignment.
    Parameters: A constant reference to the object on the right hand side of the assignment operator is passed in, called "right".
    Return: A pointer to the object having right's data assigned to it, this.
    Preconditions: None
    Postconditions: The memory of the left, or changed object, is cleared away, allocated for the size of the right object, then filled with data copied over from the right. Nothing changes in the case of self-assignment.
*/
NumberArray& NumberArray::operator=(const NumberArray& right)
{
    // Checks for self-assignment
    if (this == &right)
    {
        return *this;
    }

    // De-allocate memory of this object
    delete[] data;

    // Allocate new memory (size could vary, after all)
    size = right.size;
    data = new double[size];

    // Copy over the data from the right side of assignment into this object
    for (int i = 0; i < size; i++)
    {
        data[i] = right.data[i];
    }

    return *this;
}

void NumberArray::setNumber(int i, double val)
{
    if (i < NumberArray::size && i >= 0)
    {
        NumberArray::data[i] = val; // Only sets the value if index is valid, avoiding undefined behavior
    }
}

double NumberArray::getMin() const
{
    double min = NumberArray::data[0]; // Minimum value initialized to very first index, before the rest of the search finds the true minimum, if it is not the lowest.

    for (int i = 1; i < NumberArray::size; i++) // Starts at 1 because 0 already checked
    {
        if (NumberArray::data[i] < min)
        {
            min = NumberArray::data[i];
        }
    }

    return min; // Once the minimum is found, full array searched, it is returned.
}

double NumberArray::getMax() const
{
    double max = NumberArray::data[0]; // Max first set to the initial value

    for (int i = 1; i < NumberArray::size; i++)
    {
        if (NumberArray::data[i] > max)
        {
            max = NumberArray::data[i]; // If larger than the max, the element becomes new maximum value
        }
    }

    return max;
}

double NumberArray::getAverage() const
{
    double average = 0;

    for (int i = 0; i < NumberArray::size; i++)
    {
        average += NumberArray::data[i]; // Value is added to average
    }

    average /= NumberArray::size; // Average divided by size of array, the number of values in it.

    return average; // Average, now found, is returned.
}

void NumberArray::print() const
{
    for (int i = 0; i < NumberArray::size; i++)
    {
        std::cout << NumberArray::data[i] << " "; // Prints out elements with space between them
    }

    std::cout << std::endl; // Adds a final return
}

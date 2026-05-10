/* This header file acts as the definition and declaration of the NumberArray class. This class serves as a dynamically allocated array of an abstract type, having member functions to access data
from these NumberArray objects and make calculations based off of it. Additionally, it has built-in protections to ensure copying and assigning objects causes no memory leaks or errors.
It is a template class, having definitions and implementation grouped together in the header.*/
#ifndef DATE_H
#define DATE_H

#include <exception>

const int DEFAULT_SIZE = 10; // Default size of NumberArray array

template <typename T>
class NumberArray{
private:
    int size;
    T* data;

public:
    // Constructs NumberArray object with the default number of elements and the memory needs of the typename T at that element count. No return or parameters, default overload.
    NumberArray()
    {
        NumberArray::size = DEFAULT_SIZE;

        NumberArray::data = new T[size]; // Dynamically allocates memory according to given size.

        for (int i = 0; i < NumberArray::size; i++)
        {
            NumberArray::data[i] = 0; // Assigns value to default for all indices in the array
        }
    }

    // Constructs a NumberArray object with parameterized size, defaulting to default size. Allocated memory for s elements of type T, where s means "size". No Return.
    NumberArray(int s = DEFAULT_SIZE) // s means size in this case
    {
        NumberArray::size = s;

        NumberArray::data = new T[size]; // Dynamically allocates memory according to given size.

        for (int i = 0; i < NumberArray::size; i++)
        {
            NumberArray::data[i] = 0; // Assigns value to default for all indices in the array
        }
    }

    /*
        Summary: A constructor function overload which copies the contents of a NumberArray object into a brand new one, creating a deep copy.
        Parameters: A constant reference to the array being copied, called "other".
        Return: None
        Preconditions: Nothing of particular importance; the class makes sure no objects have uninitialized data.
        Postconditions: A new NumberArray object is created with identical data to the one in the parameters. The object copied from will not be changed due to its constant nature, ensuring no accidental changes.
    */
    NumberArray(const NumberArray<T>& other)
    {
        this->size = other.size; // Syncs sizes

        this->data = new T[size];

        for (int i = 0; i < NumberArray::size; i++) // Loops through all the elements to copy data from other to the new object
        {
            this->data[i] = other.data[i];
        }
    }

    // Destructs NumberArray object and de-allocates its memory, before printing a message to the terminal with cout. No return or parameters.
    ~NumberArray()
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
    NumberArray<T>& operator=(const NumberArray<T>& right)
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
        data = new T[size];

        // Copy over the data from the right side of assignment into this object
        for (int i = 0; i < size; i++)
        {
            data[i] = right.data[i];
        }

        return *this;
    }

    // Changes the value at the index, i, of the parameters,to the value of type T, val (value). No return.
    void setNumber(int i, T val)
    {
        if (i < this->size && i >= 0)
        {
            NumberArray::data[i] = val;
        }
        else
        {
            throw std::out_of_range("Index outside range of array.");
        }
    }

    // Accesses the number in NumberArray at a given index specified in the parameters, int index. Return is the value.
    inline T getNumber(int index)
    {
        if (index < this->size && index >= 0)
        {
            return data[index];
        }
        else
        {
            throw std::out_of_range("Index outside range of array.");
        }
    }

    // Searches through the NumberArray object to find the lowest value, returning that value in type T. No parameters.
    T getMin() const
    {
        T min = NumberArray::data[0]; // Minimum value initialized to very first index, before the rest of the search finds the true minimum, if it is not the lowest.

        for (int i = 1; i < NumberArray::size; i++) // Starts at 1 because 0 already checked
        {
            if (NumberArray::data[i] < min)
            {
                min = NumberArray::data[i];
            }
        }

        return min; // Once the minimum is found, full array searched, it is returned.
    }

    // Finds the largest value across all elements of NumberArray object, returning it in the type T. No parameters.
    T getMax() const
    {
        T max = NumberArray::data[0]; // Max first set to the initial value

        for (int i = 1; i < NumberArray::size; i++)
        {
            if (NumberArray::data[i] > max)
            {
                max = NumberArray::data[i]; // If larger than the max, the element becomes new maximum value
            }
        }

        return max;
    }

    // Uses all elements of NumberArray to find the average across all its values, returned in type double. No parameters.
    double getAverage() const
    {
        double average = 0.0;

        for (int i = 0; i < NumberArray::size; i++)
        {
            average += NumberArray::data[i]; // Value is added to average
        }

        average /= NumberArray::size; // Average divided by size of array, the number of values in it.

        return average; // Average, now found, is returned.
    }

    // Uses cout to print each element of the NumberArray. No parameters, no return.
    void print() const
    {
        for (int i = 0; i < NumberArray::size; i++)
        {
            std::cout << NumberArray::data[i] << " "; // Prints out elements with space between them
        }

        std::cout << std::endl; // Adds a final return
    }
};

#endif // DATE_H

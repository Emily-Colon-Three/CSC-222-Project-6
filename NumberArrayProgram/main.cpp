#include <iostream>
#include <random>
#include "NumberArray.h"

using namespace std;

NumberArray scopeTransfer(int size);

int main()
{
    // Testing round 1: Default construction
    NumberArray arr1;

    arr1.print();

    // Testing round 2: parameterized construction
    NumberArray arr2(5);

    arr2.print();

    // Round 3: fill with values, get max min and avg
    arr2.setNumber(0, 2.0);
    arr2.setNumber(1, 3.6);
    arr2.setNumber(2, 4.5);
    arr2.setNumber(3, 2.2);
    arr2.setNumber(4, 6.7);

    arr2.print();
    cout << arr2.getMin() << endl;
    cout << arr2.getMax() << endl;
    cout << arr2.getAverage() << endl;

    // Round 4: Indexes
    NumberArray arr4;

    // Valid
    arr4.setNumber(2, 4.0);
    arr4.setNumber(0, 2.8);
    arr4.setNumber(9, 9.8);

    cout << arr4.getNumber(2) << endl << arr4.getNumber(0) << endl << arr4.getNumber(9) << endl;

    //Invalid
    arr4.setNumber(-1, 5.0);
    arr4.setNumber(10, 3.2);

    cout << arr4.getNumber(-1) << endl << arr4.getNumber(10) << endl;

    // Round 5: Random numbers
    random_device rd;
    mt19937 engine(rd());

    uniform_int_distribution<int> dist(0, 10);

    NumberArray arr5(5);

    for (int i = 0; i < 5; i++)
    {
        arr5.setNumber(i, dist(rd));
    }

    arr5.print();
    cout << arr5.getMin() << endl << arr5.getAverage() << endl << arr5.getMax() << endl;

    // Copy constructor test
    NumberArray og(5);

    og.setNumber(0, 2.2);
    og.setNumber(1, 3.6);
    og.setNumber(2, 0.1);
    og.setNumber(3, 7.9);
    og.setNumber(4, 4.7);

    NumberArray ogCopy(og);

    og.print();
    ogCopy.print();

    og.setNumber(0, 1.0); // Modifies original NumberArray

    og.print();
    ogCopy.print();

    // Assignment Operator test
    NumberArray left(3);
    NumberArray right(3);

    right.setNumber(0, 1.0);
    right.setNumber(1, 2.0);
    right.setNumber(2, 3.0);

    left = right;

    left.print();
    right.print();

    right.setNumber(0, 0.5);

    left.print();
    right.print();

    left.setNumber(2, 3.5);

    left.print();
    right.print();

    // Assignment operator: size differences
    NumberArray small(2);
    NumberArray large(10);

    small.setNumber(0, 2.5);
    small.setNumber(1, 3.5);

    large = small;

    small.print();
    large.print();

    // Self-assignment handled properly
    NumberArray ex(1);
    ex.setNumber(0, 9.9);

    ex = ex;

    ex.print();

    // Destructor and Lifetimes (block scope)
    NumberArray inMain(5);
    inMain = scopeTransfer(5);

    return 0;
}

// Creates a temporary NumberArray object of size specified in the parameter, before returning it to let it escape the block scope.
NumberArray scopeTransfer(int size)
{
    NumberArray temp(size);
    temp.setNumber(0, 8.4);

    return temp;
}

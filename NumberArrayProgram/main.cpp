#include <iostream>
#include <random>
#include "NumberArray.h"
#include <exception>

using namespace std;

int main()
{
    int choice;
    bool validChoice = false;

    int sizeInput;

    cout << "Will you create a number array of integers or doubles?\n";
    cout << "1. Integers\n";
    cout << "2. Doubles\n";

    // Makes the user make a valid choice
    while (validChoice == false)
    {
        cin >> choice;

        if (choice == 1 || choice == 2)
        {
            validChoice = true;
        }
        else
        {
            cout << "Invalid choice. Try again.\n";
        }
    }

    cout << "What size will your number array be?\n";
    cin >> sizeInput;

    if (choice == 1)
    {
        NumberArray<int> numArr(sizeInput);

        // Fills array with known values
        for (int i = 0; i < sizeInput; i++)
        {
            int input;

            cout << "What value will you give for element " << i << "?\n";
            cin >> input;

            numArr.setNumber(i, input);
        }

        int indexInput;
        validChoice = false;

        // Index access testing
        while (validChoice == false)
        {
            try {
                cout << "Access an index of the array:\n";
                cin >> indexInput;

                cout << numArr.getNumber(indexInput) << endl;

                validChoice = true;
            } catch (const out_of_range& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }

        NumberArray<int> arrCopy(numArr);
        cout << "Copy made of array. Elements of copy:\n";

        for (int i = 0; i < sizeInput; i++)
        {
            cout << arrCopy.getNumber(i) << endl;
        }
    }
    else
    {
        NumberArray<double> numArr(sizeInput);

        // Fills array with known values
        for (int i = 0; i < sizeInput; i++)
        {
            double input;

            cout << "What value will you give for element " << i << "?\n";
            cin >> input;

            numArr.setNumber(i, input);
        }

        int indexInput;
        validChoice = false;

        // Index access testing
        while (validChoice == false)
        {
            try {
                cout << "Access an index of the array:\n";
                cin >> indexInput;

                cout << numArr.getNumber(indexInput) << endl;

                validChoice = true;
            } catch (const out_of_range& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }

        NumberArray<double> arrCopy(numArr);
        cout << "Copy made of array. Elements of copy:\n";

        for (int i = 0; i < sizeInput; i++)
        {
            cout << arrCopy.getNumber(i) << endl;
        }
    }

    return 0;
}

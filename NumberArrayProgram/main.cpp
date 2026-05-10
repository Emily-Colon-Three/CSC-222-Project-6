#include <iostream>
#include <random>
#include "NumberArray.h"

using namespace std;

int main()
{
    NumberArray<int> no1(2);
    no1.setNumber(0, 1);
    no1.setNumber(1, 5);

    NumberArray<int> no2(no1);

    cout << no2.getNumber(0) << " " << no2.getNumber(1) << endl;

    return 0;
}

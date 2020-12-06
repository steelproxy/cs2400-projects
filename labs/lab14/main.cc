#include <iostream>
#include "my_int.h"

using namespace std;

int main()
{
    my_int value1;
    my_int value2;

    value1.input(cin);

    value1.output(cout);

    if (is_prime(value1))
        cout << "  is a prime number  \n";
    else
        cout << " is not a prime number \n";

    value2.input(cin);

    if(value1 > value2) // check if value1 is larger using operator overload
    {
        cout << "First value is larger." << endl;
    }
    else
    {
        cout << "Second value is larger or equal." << endl;
    }

    return 0;
}
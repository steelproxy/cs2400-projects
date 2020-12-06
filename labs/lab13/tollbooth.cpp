/**
 *   @file: tollbooth.cpp
 * @author: Collin Rodes
 *   @date: 11/17/20
 *  @brief: Program keeps track of cars and money collected at a tollbooth.
 */

#include <iostream>
#include <iomanip>

using namespace std;

class Tollbooth
{
public:
    Tollbooth(); // default constructor, initializes to zero

    void display(ostream &outStream); // displays car count and money collected

    void payCar();   // increments car count and money collected
    void nopayCar(); // increments only car count

private:
    int cars;               // number of cars passed through
    double money_collected; // amount of money collected
};

Tollbooth::Tollbooth()
{
    this->cars = 0; // initialize both to zero
    this->money_collected = 0;
}

void Tollbooth::display(ostream &outStream)
{
    outStream << " Cars: " << this->cars << endl;                                        // displays car count
    outStream << "Money: " << setprecision(2) << fixed << this->money_collected << endl; // displays money collected to second decimal place
}

void Tollbooth::payCar()
{
    this->cars++;                  // increment car count
    this->money_collected += 0.50; // increment money collected by toll fee of .50c
}

void Tollbooth::nopayCar()
{
    this->cars++; // increment only car count, nobody paid
}

int main()
{
    Tollbooth ohio_highway;
    char user_input; // used to store user input for prompt

    do
    {
        cout << "P - paid  N - Not paid  Q - Quit -> ";
        cin >> user_input; // get user input
        switch (user_input)
        {
        case 'p':
            ohio_highway.payCar(); // car paid
            break;

        case 'n':
            ohio_highway.nopayCar(); // car did not pay
            break;
        }
    } while (user_input != 'q');

    ohio_highway.display(cout); // display car count and money collected

    return 0;
}
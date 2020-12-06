/**
 *   @file: counter.cpp
 * @author: Collin Rodes
 *   @date: 11/17/20
 *  @brief: Program for testing Counter class.
 */

#include <iostream>

using namespace std;

class Counter
{
public:
    Counter();             // default constructor, initializes to zero
    Counter(int newValue); // alternative constructor, initializes to newValue

    void increment(); // increments value
    int getValue();   // returns value

private:
    int value; // total count
};

Counter::Counter()
{
    this->value = 0; // initialize counter to zero
}

Counter::Counter(int newValue)
{
    this->value = newValue; // initialize counter to newValue
}

void Counter::increment()
{
    this->value++; // increment value
}

int Counter::getValue()
{
    return this->value; // return value
}

int main()
{
    Counter newCounter(9); // new counter with value of 9

    if (newCounter.getValue() < 10) // if its value is less than 10
    {
        cout << "Original value: " << newCounter.getValue() << endl;
        newCounter.increment();
        cout << "     New value: " << newCounter.getValue() << endl;
    }

    return 0;
}
/**
 *    @file: main.cc
 *  @author: Collin Rodes
 *    @date: 9/22/20
 *   @brief: Program records temperature highs and lows, then upon entering a sentinel value, prints the highest and lowest recorded temperatures.
 *
 */

#include <iostream>

#define UNUSED_VALUE -101                                           // macro with unique value for initially assigning high and low temps
#define SENTINEL_VALUE -100                                          // macro for sentinal value (stops execution)

using namespace std;

int main(int argc, char** argv)
{
    int high_temp = UNUSED_VALUE;                                   // variable to store highest temperature
    int low_temp = UNUSED_VALUE;                                    // variable to store lowest temperature
    int input = 0;                                                  // buffer for user input
    while (input != SENTINEL_VALUE)                                   
    {
        cout << "Please input temperature high: " << endl;
        cin >> input;                                               // get user input for temperature high
        if(high_temp == UNUSED_VALUE && input != SENTINEL_VALUE)    // if the loop has not been run (high_temp is set to UNUSED_VALUE),
        {                                                           // accept initial value, only checking to see that it is not the SENTINEL_VALUE
            high_temp = input;              
        }
        else if(input > high_temp && input != SENTINEL_VALUE)       // if user inputted high is greater than recorded, and input does not equal SENTINEL_VALUE
        {                                                           // store it as the highest recorded temperature
            high_temp = input;
        }
        else if (input == SENTINEL_VALUE)                           // if input is equal to SENTINEL_VALUE, quit loop.
        {
            break;
        }
        cout << "Please input temperature low: " << endl;
        cin >> input;                                               // get user input for temperature low
        if(low_temp == UNUSED_VALUE)                                // if the loop has not been run (low_temp is set to UNUSED_VALUE),   
        {                                                           // accept initial value, only checking to see that it is not the SENTINEL_VALUE
            low_temp = input; 
        }
        else if ((input < low_temp) && input != SENTINEL_VALUE)     // if user inputted low is less than recorded, and input does not equal SENTINEL_VALUE
        {                                                           // store it as the lowest recorded temperature
            low_temp = input;
        }
        else if (input == SENTINEL_VALUE)                           // if input is equal to SENTINEL_VALUE, quit loop.
        {
            break;
        }
    }
    if(high_temp < SENTINEL_VALUE || low_temp < SENTINEL_VALUE)     // exit if user does not provide any highs or lows
        return -1;
    cout << "Record high: " << high_temp << endl;                   // print record highs and lows
    cout << "Record low: " << low_temp << endl;
}
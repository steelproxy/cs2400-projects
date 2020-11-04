/**
 *    @file: lab8.cpp
 *  @author: Collin Rodes
 *    @date: 10/20/20
 *   @brief: Program finds the lowest, highest, and average temperatures from a file of 30 recorded daily lows.
 *
 */

#include <iostream>
#include <fstream>
#include <iomanip>

#define LOW_TEMPS_FILE "athens_low_temps.txt" // low temperature file
#define LOW_TEMPS_FILE_LEN 30                 // file always contains 30 integers

using namespace std;

int find_lowest(int temp_array[]) // finds the lowest integer in an array of LOW_TEMPS_FILE_LEN length
{
    int lowest_found = temp_array[0]; // stores the lowest value found, initialized to the first element in array

    for (int index = 1; index < LOW_TEMPS_FILE_LEN; index++) // for every element of the temp_array
    {
        if (temp_array[index] < lowest_found) // if the value stored in the current index of temp_array is less than the last found lowest
        {
            lowest_found = temp_array[index]; // set it as the new lowest
        }
    }

    return lowest_found; // return the lowest found
}

int find_highest(int temp_array[]) // finds the highest integer in an array of LOW_TEMPS_FILE_LEN length
{
    int highest_found = temp_array[0]; // stores the highest value found, initialized to the first element in array

    for (int index = 1; index < LOW_TEMPS_FILE_LEN; index++) // for every element of the temp_array
    {
        if (temp_array[index] > highest_found) // if the value stored in the current index of temp_array is greater than the last found highest
        {
            highest_found = temp_array[index]; // set it as the new highest
        }
    }

    return highest_found; // return the highest found
}

double find_average(int temp_array[]) // finds the average values of all integers in an array of LOW_TEMPS_FILE_LEN length
{
    int total = 0; // stores the sum of all integers in temp_array

    for (int index = 0; index < LOW_TEMPS_FILE_LEN; index++) // for every element of the temp_array
    {
        total += temp_array[index]; // add the integer stored at the current index of temp_array to the total
    }

    return total / static_cast<double>(LOW_TEMPS_FILE_LEN); // return the total divided by the number of elements, casted to a double for readability and precision
}

int main()
{
    int low_temps[LOW_TEMPS_FILE_LEN]; // stores temps read from the data file
    ifstream low_temps_file;           // ifstream for reading from the data file

    low_temps_file.open(LOW_TEMPS_FILE, ios::in); // open the data file
    if (low_temps_file.fail())                    // if it fails to open
    {
        cout << "Unable to open low temps file: " << LOW_TEMPS_FILE << endl;
        return 1; // return error
    }

    cout << "Reading from: " << LOW_TEMPS_FILE << "..." << endl;
    for (int index = 0; index < LOW_TEMPS_FILE_LEN; index++) // read every value from the data file in to low_temps
    {
        low_temps_file >> low_temps[index]; // assign value retreived from data file to current index of low_temps
    }

    cout << " Lowest temperature found: " << setw(4) << find_lowest(low_temps) << endl;
    cout << "Highest temperature found: " << setw(4) << find_highest(low_temps) << endl;
    cout << "Average temperature found: " << setw(4) << find_average(low_temps) << endl;

    low_temps_file.close(); // close file so it can be accessed later
    return 0;               // return success
}
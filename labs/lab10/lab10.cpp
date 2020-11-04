/**
 *    @file: lab10.cpp
 *  @author: Collin Rodes
 *    @date: 10/27/20
 *   @brief: Program finds the highest and lowest cost of auto parts, with the cost and names stored in seperate files.
 **
 */

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>

#define PART_NAMES_FILENAME "data2.txt" // macro for the second data file
#define PART_COSTS_FILENAME "data1.txt" // macro for the first data file
#define DATA_LINES 6                    // number of lines in either file

using namespace std;

size_t find_largest_index(double part_costs[], unsigned int len) // finds and returns the index of the largest value of part_costs[], within a specified length
{
    double max;           // stores the last known largest value
    size_t max_index = 0; // stores the last known index of the largest value

    max = part_costs[0];                         // initialize max as the first element just so we have some data to compare with
    for (size_t index = 1; index < len; index++) // for every element of part_costs, skipping element 0;
    {
        if (part_costs[index] > max) // if the value of part_costs at the current index is larger than the last known largest value
        {
            max = part_costs[index]; // set max as the new largest value
            max_index = index;       // set max_index as the index of the new largest value
        }
    }

    return max_index; // return the index of the largest value
}

size_t find_smallest_index(double part_costs[], unsigned int len) // finds and returns the index of the smallest value of part_costs[], within a specified length
{
    double min;           // stores the last known smallest value
    size_t min_index = 0; // stores the last known index of the smallest value

    min = part_costs[0];                         // initialize min as the first element just so we have some data to compare
    for (size_t index = 1; index < len; index++) // for every element of part_costs, skipping element 0
    {
        if (part_costs[index] < min) // if the value of part_costs[] at the current index is smaller than the last known smallest value
        {
            min = part_costs[index]; // set min as the new smallest value
            min_index = index;       // set min_index as the index of the new smallest value
        }
    }

    return min_index; // return the index of the smallest value
}

void print_highest_lowest(string part_names[], double part_costs[]) // prints the name and cost of the most and least expensive parts provided an array of names and costs
{
    size_t min_index; // stores the index of the smallest value of part_costs
    size_t max_index; // stores the index of the largest value of part_costs

    min_index = find_smallest_index(part_costs, DATA_LINES); // find the smallest index of part_costs
    max_index = find_largest_index(part_costs, DATA_LINES);  // find the largest index of part_costs

    cout << "The name of the most expensive part is " << part_names[max_index]
         << " ($" << setprecision(2) << fixed << part_costs[max_index] << ")" << endl;

    cout << "The name of the least expensive part is " << part_names[min_index]
         << " ($" << setprecision(2) << fixed << part_costs[min_index] << ")" << endl;
}

int main()
{
    ifstream part_names_file; // file stream for reading from the data file with part names
    ifstream part_costs_file; // file stream for reading from the data file with part costs
    string part_names[6];     // stores part names recieved from part_names_file
    double part_costs[6];     // stores costs recieved from part_costs_file

    part_names_file.open(PART_NAMES_FILENAME, ios::in); // open the part names file
    if (part_names_file.fail())                         // if it fails to open
    {
        cout << "Unable to open file: " << PART_NAMES_FILENAME << endl;
        return 1; // return error
    }

    part_costs_file.open(PART_COSTS_FILENAME, ios::in); // open the part costs file
    if (part_costs_file.fail())                         // if it fails to open
    {
        cout << "Unable to open file: " << PART_COSTS_FILENAME << endl;
        return 1; // return error
    }

    getline(part_names_file, part_names[0]);                                      // read the first line of the part names file into the first element of part_names
    for (size_t index = 1; index < DATA_LINES && !part_names_file.eof(); index++) // for every index of part_names, while we are less than the length of the array, and not at the end of the file
    {
        getline(part_names_file, part_names[index]); // get a line from the parts file and insert it in part_names
    }

    part_costs_file >> part_costs[0];                                             // read the first double from the part costs file into the first element of part_costs
    for (size_t index = 1; index < DATA_LINES && !part_costs_file.eof(); index++) // for every index of part_costs, while we are less than the length of the array, and not at the end of the file
    {
        part_costs_file >> part_costs[index]; // get a double from the costs file and insert it in part_costs
    }

    print_highest_lowest(part_names, part_costs); // print the least and most expensive parts

    part_names_file.close(); // close part names file so it can be accessed later
    part_costs_file.close(); // close part costs file so it can be accessed later

    return 0;
}
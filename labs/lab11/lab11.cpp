/**
 *    @file: lab10.cpp
 *  @author: Collin Rodes
 *    @date: 11/3/20
 *   @brief: Program processes an input file and converts characters to uppercase, obscures digits with an astericks and sends text to an output file.
 **
 */

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <fstream>

using namespace std;

void display_usage(string path) // displays program usage information provided path of program
{
    cout << "   " << path << " <input file> <output file>" << endl;
}

char process_text(char input) // processes text to make alphabetical characters uppercase, and digits in to astericks
{
    if (isalpha(input)) // if character is a letter
    {
        return toupper(input); // return the uppercase equivalency
    }
    else if (isdigit(input)) // else if character is a digit
    {
        return '*'; // return an asterick
    }
    else // otherwise
    {
        return input; // return the original character
    }
}

int main(int argc, char **argv)
{
    ifstream _input_file;  // input file stream for reading from the input file
    ofstream _output_file; // output file stream for writing to the output file
    char input_buffer;     // character buffer for reading and processing characters read from _input_file

    if (argc > 3) // if there is more than 3 arguments
    {
        cout << "Too many arguments! Exiting..." << endl;
        display_usage(argv[0]); // display program usage information
        return 1;
    }
    else if (argc < 3) // if there is less than 3 arguments
    {
        cout << "Not enough arguments! Exiting..." << endl;
        display_usage(argv[0]); // display program usage information
        return 1;
    }

    _input_file.open(argv[1], ios::in); // open the input file
    if (_input_file.fail())             // if it fails to open
    {
        cout << "Unable to open input file! Exiting..." << endl;
        return 1; // return error
    }

    _output_file.open(argv[2], ios::out); // open the output file
    if (_output_file.fail())              // if it fails to open
    {
        cout << "Unable to open output file! Exiting..." << endl;
        _input_file.close(); // close the input file so it can be accessed later
        return 1;            // return error
    }

    cout << "Reading from: " << argv[1] << endl;

    input_buffer = _input_file.get(); // get a character from the input file
    while (!_input_file.eof())        // while the input file is not at the end of file
    {
        _output_file.put(process_text(input_buffer)); // put the processed text into the output file
        input_buffer = _input_file.get();             // get another character from the input file
    }

    cout << "Processed file outputted to: " << argv[2] << "." << endl;
}
/**
 *    @file: lab7.cpp
 *  @author: Collin Rodes
 *    @date: 10/6/20
 *   @brief: Program filters a character from an input file and puts the result into a seperate output file.s
 *
 */

#include <iostream>
#include <fstream>

using namespace std;

void get_filenames(string& reference_input_filename, string& reference_output_filename)                 // Function recieves user input for input/output filenames, then assigns those values to the reference
{                                                                                                       // parameters reference_input_filename and reference_output_filename
    cout << "Please enter the full path of the input file: " << endl;
    getline(cin, reference_input_filename);                                                             // get input path
    cout << "Please enter the full path of the output file: " << endl;
    getline(cin, reference_output_filename);                                                            // get output path
}

void filter_input(string input_filename, string output_filename, char character_to_remove)              // Function filters a character from an input file, of which the filename is input_filename, 
{                                                                                                       // then outputs the result to an output file, of which the filename is output_filename
    ifstream raw_input_file;                                                                            // stream for the input file
    ofstream filtered_output_file;                                                                      // stream for the output file
    char last_input;                                                                                    // buffer for storing character read from input file

    raw_input_file.open(input_filename, ifstream::in);                                                  // open input file (read only)
    if(raw_input_file.fail())                                                                           // if it fails print an error
    {
        cout << "Unable to open input file!" << endl;
        return;
    }

    filtered_output_file.open(output_filename, ofstream::out);                                          // open output file
    if(filtered_output_file.fail())                                                                     // if it fails print an error
    {
        raw_input_file.close();                                                                         // close input file so other programs can use it
        cout << "Unable to open output file!" << endl;
        return;
    }

    last_input = raw_input_file.get();                                                                  // get a character and assign result to last_input
    while(!raw_input_file.eof())                                                                        // while there is more to be read from the input file
    {
        if(last_input == character_to_remove)                                                           // if the character recieved is the one we are trying to filter, return to top of loop and get next character
        { 
            last_input = raw_input_file.get();                                                          // have to grab another character after a filftered character is found so the loop doesnt keep hitting the continue statement
            continue;  
        }                                                             
        filtered_output_file.put(last_input);                                                           // write character in last_input to output file
        last_input = raw_input_file.get();                                                              // get a character and assign result to last_input
    }

    raw_input_file.close();                                                                             // close input file so other programs can use it
    filtered_output_file.close();                                                                       // close output file so other programs can use it

    cout << "Outputted to: " << output_filename << endl;
}

int main(int argc, char** argv)
{
    string input_filename;                                                                              // string for storing input filename
    string output_filename;                                                                             // string for storing output filename
    char filter_character;

    get_filenames(input_filename, output_filename);                                                     // get both filenames (function assigns the values to user input)

    cout << "Please enter the character that you would like to filter out of the input file: " << endl;
    filter_character = cin.get();                                                                       // get a character and store result in filter_character

    filter_input(input_filename, output_filename, filter_character);                                    // filter the input

    return 0;
}
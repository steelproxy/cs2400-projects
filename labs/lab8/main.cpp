/**
 *    @file: lab8.cpp
 *  @author: Collin Rodes
 *    @date: 10/13/20
 *   @brief: Program encrypts a decrypts files using a caesar cypher.
 *
 */

#include <iostream>
#include <fstream>

using namespace std;

void display_menu(unsigned int key_value) // displays menu options for user
{
    cout << "Options: " << endl;
    cout << "Set key value (currently " << key_value << "): k" << endl;
    cout << "Encrypt file:                e" << endl;
    cout << "Decrypt file:                d" << endl;
    cout << "Quit:                        q" << endl;
}

unsigned int get_key_value() // gets a value from the user to use as the key
{
    unsigned int key_value; // stores key value recieved from user

    cout << "Please enter a key value (1-10): " << endl;
    cin >> key_value;                    // read key value from user
    if (key_value < 1 || key_value > 10) // if the key is not (1-10)
    {
        cout << "Invalid key value entered!" << endl;
        return 0; // return error
    }

    return key_value; // return the key value
}

unsigned int encrypt_file(unsigned int key_value) // encrypts a file using a caesar cypher and outputs it elsewhere
{
    ifstream unencrypted_input_file; // input stream for reading the unencrypted input file
    ofstream encrypted_output_file;  // output stream for writing to the encrypted output file
    string input_file_path;          // string for storing path of unencrypted input file
    string output_file_path;         // string for storing path of encrypted output file
    char encryption_buffer;          // character buffer for storing and shifting characters recieved from unencrypted input file

    cout << "Please enter the path to the input file you would like to encrypt: " << endl;
    getline(cin, input_file_path);                         // get the input file path
    unencrypted_input_file.open(input_file_path, ios::in); // open the input file
    if (unencrypted_input_file.fail())                     // if it fails to open
    {
        cout << "Unable to open input file!" << endl;
        return 0; // return an error
    }

    cout << "Please enter the path to the output file: " << endl;
    getline(cin, output_file_path);                        // get the output file path
    encrypted_output_file.open(output_file_path, ios::in); // open the output file
    if (encrypted_output_file.fail())                      // if it fails to open
    {
        cout << "Unable to open the output file!" << endl;
        return 0; // return an error
    }

    encryption_buffer = unencrypted_input_file.get(); // get a character from the input file
    while (!unencrypted_input_file.eof())             // read while we arent at the end of the file
    {
        encrypted_output_file.put(encryption_buffer + key_value); // put the shifted value of the encryption buffer into the output file
        encryption_buffer = unencrypted_input_file.get();         // get a new character from the input file
    }

    unencrypted_input_file.close(); // close both files so they are accessible
    encrypted_output_file.close();
    cout << "Encryption successful, outputted to: " << output_file_path << endl;
    return 1; // return success
}

unsigned int decrypt_file(unsigned int key_value)
{
    ifstream encrypted_input_file;    // input stream for the encrypted input file
    ofstream unencrypted_output_file; // output stream for the decrypted output file
    string input_file_path;           // string for storing path of encrypted input file
    string output_file_path;          // string for storing path of decrypted output file
    char encryption_buffer;           // character buffer for storing and shifting characters recieved from encrypted input file

    cout << "Please enter the path to the input file you would like to decrypt: " << endl;
    getline(cin, input_file_path);                       // get input file path
    encrypted_input_file.open(input_file_path, ios::in); // open input file
    if (encrypted_input_file.fail())                     // if it fails to open
    {
        cout << "Unable to open input file!" << endl;
        return 0; // return an error
    }

    cout << "Please enter the path to the output file: " << endl;
    getline(cin, output_file_path);                          // get output file path
    unencrypted_output_file.open(output_file_path, ios::in); // open output file
    if (unencrypted_output_file.fail())                      // if output file fails to open
    {
        cout << "Unable to open the output file!" << endl;
        return 0; // return an error
    }

    encryption_buffer = encrypted_input_file.get(); // get a character from input file
    while (!encrypted_input_file.eof())             // read while we are not at end of file
    {
        unencrypted_output_file.put(encryption_buffer - key_value); // put the unshifted value of the encryption buffer in the output file
        encryption_buffer = encrypted_input_file.get();             // get a new character
    }

    encrypted_input_file.close(); // close both files so they are accessible
    unencrypted_output_file.close();
    cout << "Decryption successful, outputted to: " << output_file_path << endl;
    return 1; // return success
}

int main()
{
    unsigned int key_value = 0; // stores the key value for encrpytion/decryption
    string user_choice;         // stores the user input for menu options

    for (;;)
    {
        display_menu(key_value); // display options

        getline(cin, user_choice); // get user input for choice
        if (user_choice == "k")    // if the user would like to set the key value
        {
            key_value = 0;
            while (key_value < 1) // continuously prompt until a valid value is returned
            {
                key_value = get_key_value();
            }
        }
        else if (user_choice == "e") // if the user would like to encrypt a file
        {
            if (key_value < 1) // if the key value has not been set
            {
                cout << "Key value has not been set, cannot encrypt!" << endl;
                continue; // restart loop
            }
            encrypt_file(key_value); // encrypt file with key value
        }
        else if (user_choice == "d") // if the user would like to decrypt a file
        {
            if (key_value < 1) // if the key value has not been set
            {
                cout << "Key value has not been set, cannot decrypt!" << endl;
                continue; // restart loop
            }
            decrypt_file(key_value); // decrypt file with key value
        }
        else if (user_choice == "q") // if user would like to quit
        {
            return 0; // quit
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }
    }
}
/**
 *   @file: lab12.cpp
 * @author: Collin Rodes
 *   @date: 11/10/20
 *  @brief: Program reads information about employees from a file and prints a report containing their ID, first/last name, and salary, as well as the total payroll.
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;

struct Employee // struct type for single employee
{
    int id;            // employee ID
    string first_name; // employee first name
    string last_name;  // employee last name
    double salary;     // employee salary
};

void display_usage(string path) // displays usage information of program with path
{
    cout << "    Usage: " << path << " [employee file]" << endl;
}

int find_longest_name(vector<Employee> all_employees) // finds the longest full name out of all employees provided a vector of employees
{
    size_t max = all_employees[0].first_name.size() + all_employees[0].last_name.size(); // use the first element of the vector to compare, size of full name = first + last name characters

    for (size_t index = 1; index < all_employees.size(); index++) // for every employee in the vector
    {
        if ((all_employees[index].first_name.size() + all_employees[index].last_name.size()) > max) // if the name at the current index of the vector is larger than the last known longest
        {
            max = all_employees[index].first_name.size() + all_employees[index].last_name.size(); // store it as the new max
        }
    }

    return static_cast<int>(max) + 1; // return the longest name found (+1 for the whitespace in between them)
}

double get_total_payroll(vector<Employee> all_employees) // calculates the total payroll from a vector of employees
{
    double total_payroll = 0; // used to store the total amount of money in payroll

    for (size_t index = 0; index < all_employees.size(); index++) // for every employee in the vector
    {
        total_payroll += all_employees[index].salary; // add current employees salary to the payroll
    }

    return total_payroll; // return the total payroll
}

void print_employees(vector<Employee> all_employees) // prints a report on employees contained in vector
{
    int longest_name = find_longest_name(all_employees); // stores the longest name out of all employees in the vector, for formatting purposes
    int employee_alignment;                              // used to calculate space needed between last name and salary

    cout << "ID      Name" << setw(longest_name + 6) << "Salary" << endl; // setw(longest_name + 6) to align salary (6 is the length of 'salary'), assumed ID will always be 4 digits
    for (int dashes = 0; dashes < longest_name + 18; dashes++)            // print enough dashes to cover bottom of previous line (18 is the length of 'ID      Name' + 'salary')
    {
        cout << "-";
    }
    cout << endl; // print newline after dashes

    for (size_t index = 0; index < all_employees.size(); index++) // for every employee in the vector
    {
        employee_alignment = longest_name - (all_employees[index].first_name.size() + all_employees[index].last_name.size()); // calculate the space needed between the last name and salary
                                                                                                                              // of the current employee for consistent formatting
        cout << setw(4) << all_employees[index].id << "    ";                                                                 // print employee ID to 4 width
        cout << all_employees[index].first_name << " ";                                                                       // print employee first name
        cout << all_employees[index].last_name << "    ";                                                                     // print employee last name
        cout << setw(employee_alignment) << setprecision(2) << fixed << "$" << all_employees[index].salary << endl;           // print salary to previously calculated width and to two decimal places
    }

    cout << endl
         << "Total Payroll: $" << setprecision(2) << fixed << get_total_payroll(all_employees) << endl; // print the total payroll to two decimal places
}

void load_employees(ifstream &employee_file, vector<Employee> &all_employees) // loads employee information from a file into a vector of employees
{
    Employee new_employee; // used to store the information about each employee from the file

    while (!employee_file.eof())
    {
        employee_file >> new_employee.id;         // get employee id from file
        employee_file >> new_employee.first_name; // get employee first name from file
        employee_file >> new_employee.last_name;  // get employee last name from file
        employee_file >> new_employee.salary;     // get employee salary from file
        all_employees.push_back(new_employee);    // push the employee in to the vector of employees
    }
}

int main(int argc, char **argv)
{
    ifstream employee_file;         // input stream for reading from employee file
    vector<Employee> all_employees; // vector used to store all employees

    if (argc > 2) // if there are too many arguments
    {
        cout << "Too many arguments! Exiting..." << endl;
        display_usage(argv[0]); // display usage info
        return 1;               // return error
    }
    else if (argc < 2) // if there is not enough arguments
    {
        cout << "Too few arguments! Exiting..." << endl;
        display_usage(argv[0]); // display usage info
        return 1;               // return error
    }

    employee_file.open(argv[1], ios::in); // open the employee file
    if (employee_file.fail())             // if the employee file fails to open
    {
        cout << "Unable to open file: " << argv[1] << ". Exiting..." << endl;
        return 1; // return error
    }

    load_employees(employee_file, all_employees); // load all employees from file into vector
    print_employees(all_employees);               // print employee reports

    employee_file.close(); // close employee file so it can be accessed later

    return 0; // return success
}
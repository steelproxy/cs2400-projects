/**
  * * Simple class to illustrate separate compilation and const
  * parameters
  * 
  * Written by Mal Gunasekera
  * Modified by David M. Chelberg, Nasseef Abukamail
  * last-modified: November 21, 2020
  */
 
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "my_int.h"

using namespace std;

/**
 * Function: my_int
 *           Constructor initializes the val to x
 * Params:   x - the value for the val
 */
my_int::my_int(int x)
{
    val = x;
}

/**
   * Function: my_int       
   *           Constructor initializes the val to 0      
   * Params:   none      
                                       
   * Uses:     none           
   */
my_int::my_int()
{
    val = 0;
}

/**
   * Function: set
   *           Sets the val to x
   * Params:   x - the new value for the val
   */
void my_int::set(int a)
{
    val = a;
}

/**
   * Function: output
   *           display the val on fout. if fout is a  output stream
   *           then fout is already  connected to a file
   * Params:   fout -- the output stream
   */
void my_int::output(ostream &fout) const
{
    fout << " The value is equal to " << val << endl;
}

/**
   * Function: get_int
   *           returns the val
   * @return:  The int value
   */
int my_int::get_int()
{
    return val;
}

/**************
   * Function: input
   *           reads and stores a value from inp. if inp is a input 
   *           stream, then inp is already connected to a file.User enters 
   *           a value and ask the user to re-enter the data if the
   *           user enters an incorrect value.
   * Params:   inp -- the input stream
   */
void my_int::input(istream &inp)
{
    cout << "Enter a positive value greater than 1  ";
    inp >> val;
    while (val <= 1)
    {
        cout << "Entered an Invalid value \n";
        cout << "Enter a positive value greater than 1 \n";
        inp >> val;
    }
}

/**
 * Function: is_prime
 *           object num contains a valid positive value
 *           returns true if num is prime; otherwise
 *           returns false
 * @param:   num  - the value to be checked for prime
 * @return:  true/false
 */
bool is_prime(my_int &num)
{
    double limit;
    int n; //divisor
    bool prime = true;

    limit = sqrt(static_cast<double>(num.get_int()));

    n = 2;

    while (n <= limit && prime)
    {
        if (num.get_int() % n == 0)
            prime = false;
        else
            n++;
    }
    return prime;
}

bool operator >(const my_int &r1, const my_int &r2)
{
    if(r1.val > r2.val)
    {
        return true;
    }
    return false;
}
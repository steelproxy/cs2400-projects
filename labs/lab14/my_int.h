#ifndef MY_INT_H
#define MY_INT_H

#include <iostream>

class my_int
{
public:
    /**
   * Function: my_int
   *           Constructor initializes the val to x
   * @params:   x - the value for the val
   */
    my_int(int x);

    /**
   * Function: my_int       
   *           Constructor initializes the val to 0      
   * @arams:   none         
   */
    my_int();

    /**
   * Function: set
   *      Sets the val to x
   * @arams:   x - the new value for the val
   */

    void set(int x);

    /**
   * Function: >
   *      operator overload for checking if r1's val is greeater than r2's val
   * @arams:   r1 - first operand of > r2 - second operand of >
   */
    friend bool operator>(const my_int &r1, const my_int &r2);

    /*
   * Function: input
   *           reads and stores a value from inp. if inp is a input 
   *           stream, then inp is already connected to a file.User enters 
   *           a value and ask the user to re-enter the data if the
   *           user enters an incorrect value.
   * @arams:   inp -- the input stream
   */
    void input(std::istream &inp);

    /**************
   * Function: output
   *           display the val on fout. if fout is a  output stream
   *           then fout is already  connected to a file
   * @arams:   fout -- the output stream
   */
    void output(std::ostream &fout) const;

    /**
   * Function: get_int
   *           returns the val
   * @arams:   none
   * @return: the value of int
   */
    int get_int();

private:
    int val; // Variable to hold value for class
};

/**
 * Function: is_prime
 *           object num contains a valid positive value
 *           returns true if num is prime; otherwise
 *           returns false
 * @arams:   num  - the value to be checked for prime
 * @return:  true/false
 */
bool is_prime(my_int &num);


#endif
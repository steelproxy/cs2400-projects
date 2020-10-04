/**
 *    @file: prog5.cc
 *  @author: Collin Rodes
 *    @date: 9/8/20
 *   @brief: Program prints conversions of two predefined temperature values to their respective units (C and F).
 *
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
   double ctof;  // equivalent Celsius temperature
   double ftoc;  // equivalent Fahrenheit temperature.
 
   int fah = 56;  //declare and initialize at the same time - page 48
   int cel = 20;

   ctof = ((cel * 9) / 5) + 32;
   ftoc = ((fah - 32) * 5) / 9;

   cout.setf(ios::fixed, ios::floatfield);
   cout << setprecision(1);
   cout << cel << " degrees Celsius in Fahrenheit is " << ctof << endl;
   cout << fah << " degrees Fahrenheit in Celsius is " << ftoc << endl;

   return (EXIT_SUCCESS);
}

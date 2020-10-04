/**
 *    @file: prog1.cc
 *  @author: Collin Rodes
 *    @date: 9/8/20
 *   @brief: Program prints sum of two predefined integers, then displays the larger of the two.
 *
 */

#include <cstdlib>
#include <iostream>

using namespace std;

const int INT1 = 15;
const int INT2 = 20;

int main() {
  cout << "Sum of " << INT1 << " and " << INT2 << " is " << INT1 + INT2 << endl;
  cout << "Product is " << INT1 * INT2 << endl;
  if (INT1 < INT2)
    cout << INT2 << " is bigger" << endl;
  else
    cout << INT1 << " is bigger" << endl;
  return (EXIT_SUCCESS);
}

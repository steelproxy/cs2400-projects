/**
 *    @file: prog1.cc
 *  @author: Collin Rodes
 *    @date: 9/8/20
 *   @brief: Program reads input and prints it multiplied by 2.
 *
 */
#include <iostream>
#include <cstdlib>

using namespace std;

int main() 
{
  
  int i;

  while (cin >> i) {
    cout << i << " times 2 = " << (i * 2) << endl;
  }
  return (EXIT_SUCCESS);
}

/*This program computes the summation of pi from 0 to 3 using 
 *functions multiply, add, and subtract accordingly.
 *
 *Author: Steen Sia
 *Last updated: October 26, 2016
 */

#include <iostream>
#include "fraction.h"
#include <cmath>

using namespace std;

int main(){

  //Fraction objects for k = 0;
  Fraction fsumm_zero; //The total of pi when k = 0;
  Fraction fdef_zero; //Default constructors used to store an answer after operation is used.
  Fraction fdef1_zero;
  Fraction fdef2_zero;
  Fraction f_zero(1, pow(16, 0)); //Fraction objects for k = 0;
  Fraction f1_zero(4, 8*0 + 1);
  Fraction f2_zero(2, 8*0 + 4);
  Fraction f3_zero(1, 8*0 + 5);
  Fraction f4_zero(1, 8*0 + 6);

  //Fraction objects for k = 1;
  Fraction fsumm_one; //The total of pi when k = 1;
  Fraction fdef_one;
  Fraction fdef1_one;
  Fraction fdef2_one;
  Fraction f_one(1, pow(16, 1)); //Fraction objects for k = 1;
  Fraction f1_one(4, 8*1 + 1);
  Fraction f2_one(2, 8*1 + 4);
  Fraction f3_one(1, 8*1 + 5);
  Fraction f4_one(1, 8*1 + 6);

  //Fraction objects for k = 2;
  Fraction fsumm_two; //The total of pi when k = 2;
  Fraction fdef_two;
  Fraction fdef1_two;
  Fraction fdef2_two;
  Fraction f_two(1, pow(16, 2)); //Fraction objects for k = 2;
  Fraction f1_two(4, 8*2 + 1);
  Fraction f2_two(2, 8*2 + 4);
  Fraction f3_two(1, 8*2 + 5);
  Fraction f4_two(1, 8*2 + 6);

  //Fraction objects for k = 3;
  Fraction fsumm_three; //The total of pi when k = 3;
  Fraction fdef_three;
  Fraction fdef1_three;
  Fraction fdef2_three;
  Fraction f_three(1, pow(16, 3)); //Fraction objects for k = 3;
  Fraction f1_three(4, 8*3 + 1);
  Fraction f2_three(2, 8*3 + 4);
  Fraction f3_three(1, 8*3 + 5);
  Fraction f4_three(1, 8*3 + 6);

  //Fraction objects to use as a overall running total for the previous totals for k=0-3.
  Fraction summ;
  Fraction summ1;
  Fraction summ2;

  //Calculates the sum of pi if k = 0.

  fdef_zero = f1_zero.subtract(f2_zero);

  fdef1_zero = fdef_zero.subtract(f3_zero);

  fdef2_zero = fdef1_zero.subtract(f4_zero);

  fsumm_zero = f_zero.multiply(fdef2_zero);
  
  cout << "The result of pi when k is zero, is computed by: " << endl;
  cout << f_zero.to_string() << " * " << "(" << f1_zero.to_string() << " - " << f2_zero.to_string() << " - "  
       << f3_zero.to_string()  << " - "<< f4_zero.to_string() << ")" << " = " << fsumm_zero.to_string() << " or about: " << fsumm_zero.to_double() << endl; 
  //cout << endl;
  
  //Calculates the sum of pi if k = 1.

  fdef_one = f1_one.subtract(f2_one);

  fdef1_one = fdef_one.subtract(f3_one);
  
  fdef2_one = fdef1_one.subtract(f4_one);

  fsumm_one = f_one.multiply(fdef2_one);

  cout << "The result of pi when k = 1, is computed by: " << endl;
  cout << f_one.to_string() << " * " << "(" << f1_one.to_string() << " - " << f2_one.to_string() << " - "  
       << f3_one.to_string()  << " - "<< f4_one.to_string() << ")" << " = " << fsumm_one.to_string() << " or about: " << fsumm_one.to_double() << endl;  
  //cout << endl;

 //Calculates the sum of pi if k = 2. 

  fdef_two = f1_two.subtract(f2_two);

  fdef1_two = fdef_two.subtract(f3_two);

  fdef2_two = fdef1_two.subtract(f4_two);

  fsumm_two = f_two.multiply(fdef2_two);

  cout << "The result of pi when k is two, is computed by: " << endl;
  cout << f_two.to_string() << " * " << "(" << f1_two.to_string() << " - " << f2_two.to_string() << " - "  
       << f3_two.to_string()  << " - "<< f4_two.to_string() << ")" << " = " << fsumm_two.to_string() << " or about: " << fsumm_two.to_double() << endl;  
  //cout << endl;

  //Calculates the sum of pi if k = 3.

  fdef_three = f1_three.subtract(f2_three);

  fdef1_three = fdef_three.subtract(f3_three);

  fdef2_three = fdef1_three.subtract(f4_three);

  fsumm_three = f_three.multiply(fdef2_three);

  cout << "The result of pi when k is three, is computed by: " << endl;
  cout << f_three.to_string() << " * " << "(" << f1_three.to_string() << " - " << f2_three.to_string() << " - "  
       << f3_three.to_string()  << " - "<< f4_three.to_string() << ")" << " = " << fsumm_three.to_string() << " or about: " << fsumm_three.to_double() << endl;  
  //cout << endl;

  //Computes the summation by adding the previous sums from 0-3.
  
  summ = fsumm_zero.add(fsumm_one);

  summ1 = summ.add(fsumm_two);

  summ2 = summ1.add(fsumm_three);

  cout << "The summation of pi from zero to three is: " << endl << "(" << fsumm_zero.to_string() << " + " << fsumm_one.to_string() << " + " << fsumm_two.to_string() << " + " << fsumm_three.to_string() << ") = " << summ2.to_string() << " or about: " << summ2.to_double() << endl;

}

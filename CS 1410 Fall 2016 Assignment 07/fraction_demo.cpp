/* This program creates and uses Fraction objects
 * and tests the objects with functions such as add,
 * subtract, multiply, and divide.
 *
 * Authors: Erin Parker & Steen Sia
 * Last updated: October 26, 2016
 */

#include <iostream>
#include "fraction.h"
using namespace std;

int main() {

  // My Fraction objects
  Fraction fdef; //Object using default constructor
  Fraction f1(2, 3);
  Fraction f2(3, -4);
  Fraction f3(5, 6);
  Fraction f4(7, -8);

  // My examples

  cout << "The default fraction is: " << fdef.to_string() << endl;
  cout << "Fraction f1 is: " << f1.to_string() << endl;
  cout << "Fraction f2 is: " << f2.to_string() << endl;
  cout << "Fraction f3 is: " << f3.to_string() << endl;
  cout << "Fraction f4 is: " << f4.to_string() << endl;
  
  //Default fraction case examples
  cout << "The rule of zero is: anything multiplied or divided by 0 is equal to 0." << endl;
  fdef = fdef.multiply(f3);

  cout << fdef.to_string() << " multiplied by "
       << f3.to_string() << " equals " << fdef.to_string()
       << endl;

  fdef = fdef.divide(f4);

  cout << fdef.to_string() << " divided by "
       << f4.to_string() << " equals " << fdef.to_string()
       << endl; 

  //Fraction f1 case examples
  cout << "Case examples for each fraction object: " << endl;

  fdef = f1.add(f2);

  cout << f1.to_string() << " plus "
       << f2.to_string() << " equals " << fdef.to_string()
       << endl;

  fdef = f1.subtract(f3);

  cout << f1.to_string() << " minus "
       << f3.to_string() << " equals " << fdef.to_string()
       << endl;
  
  fdef = f1.multiply(f4);

  cout << f1.to_string() << " multiplied by "
       << f4.to_string() << " equals " << fdef.to_string()
       << endl;
  
  //Display the floating-point number value of the fraction.
  double close = fdef.to_double();

  cout << "The real number closest to " << fdef.to_string()
       << " is " << close << endl;

  //Fraction f2 case examples
  fdef = f2.divide(f1);

  cout << f2.to_string() << " divided by "
       << f1.to_string() << " equals " << fdef.to_string()
       << endl;

  fdef = f2.add(f3);

  cout << f2.to_string() << " plus "
       << f3.to_string() << " equals " << fdef.to_string()
       << endl;
  
  fdef = f2.subtract(f4);

  cout << f2.to_string() << " minus "
       << f4.to_string() << " equals " << fdef.to_string()
       << endl;
  
  double close2 = fdef.to_double();

  cout << "The real number closest to " << fdef.to_string()
       << " is " << close2 << endl;
  
  //Fraction f3 case examples
  fdef = f3.multiply(f1);

  cout << f3.to_string() << " multiplied by "
       << f1.to_string() << " equals " << fdef.to_string()
       << endl;

  fdef = f3.divide(f2);

  cout << f3.to_string() << " divided by "
       << f2.to_string() << " equals " << fdef.to_string()
       << endl;

  fdef = f3.add(f4);

  cout << f3.to_string() << " plus "
       << f4.to_string() << " equals " << fdef.to_string()
       << endl;

  double close3 = fdef.to_double();

  cout << "The real number closest to " << fdef.to_string()
       << " is " << close3 << endl;

  //Fraction f4 case examples
  fdef = f4.subtract(f1);

  cout << f4.to_string() << " minus "
       << f1.to_string() << " equals " << fdef.to_string()
       << endl;

  fdef = f4.multiply(f2);

  cout << f4.to_string() << " multiplied by "
       << f2.to_string() << " equals " << fdef.to_string()
       << endl;
  
  fdef = f4.divide(f3);

  cout << f4.to_string() << " divided by "
       << f3.to_string() << " equals " << fdef.to_string()
       << endl;
  
  double close4 = fdef.to_double();

  cout << "The real number closest to " << fdef.to_string()
       << " is " << close4 << endl;

}

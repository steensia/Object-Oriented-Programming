/* This source file contains implementations of the Fraction
 * member functions.
 *
 * Authors: Erin Parker & Steen Sia
 * Last updated: October 26, 2016
 */

#include "fraction.h"
#include <sstream>

Fraction::Fraction()
{
  numerator = 0;
  denominator = 1;
}
Fraction::Fraction(long long _numerator, long long _denominator)
{
  numerator = _numerator;
  denominator = _denominator;

  reduce();

  //Ensures that the negative sign is placed in the numerator
  //for any negative fraction.
  if(denominator < 0 && numerator > 0)
    {
      numerator = numerator * (-1);
      denominator = denominator * (-1);
    }
}
  // Reduce the fraction (as required by the class contract)
  // using our private helper function.

void Fraction::reduce() 
{
  // Compute the GCD using a well-known algorithm.

  long long gcd = numerator;
  long long remainder = denominator;

  while(remainder != 0) {
    long long temp = remainder;
    remainder = gcd % remainder;
    gcd = temp;
  }

  // Divide both the numerator and denominator by the GCD.

  numerator /= gcd;
  denominator /= gcd;
}

string Fraction::to_string() 
  {
    stringstream buffer;
    buffer << numerator << "/" << denominator;
    
    return buffer.str();
  }

double Fraction::to_double()
{
  double n = numerator;
  double d = denominator;
  double close_value;

  close_value = n / d;
  
  return close_value;
}

Fraction Fraction::add(Fraction other) 
{
  // Compute the sum.
  
  long long sum_numerator;
  long long sum_denominator;
  
  sum_numerator = numerator * other.denominator + other.numerator * denominator;
  
  sum_denominator = denominator * other.denominator;

  // Create the resulting fraction.
  
  Fraction result(sum_numerator, sum_denominator);

  // Return it.
  
  return result;
}

Fraction Fraction::subtract(Fraction other) 
{
  // Compute the difference.
  
  long long diff_numerator;
  long long diff_denominator;
  
  diff_numerator = numerator * other.denominator - other.numerator * denominator;
  
  diff_denominator = denominator * other.denominator;

  // Create the resulting fraction.
  
  Fraction result(diff_numerator, diff_denominator);

  // Return it.
  
  return result;
}
Fraction Fraction::multiply(Fraction other)
{
  // Compute the product.
  
  long long product_numerator;
  long long product_denominator;
  
  product_numerator   = numerator * other.numerator;
  product_denominator = denominator * other.denominator;

  // Create the resulting fraction.
  
  Fraction result(product_numerator, product_denominator);

  // Return it.
  
  return result;
}
Fraction Fraction::divide(Fraction other)
{
  // Compute the quotient.
  
  long long quotient_numerator;
  long long quotient_denominator;
  
  quotient_numerator = numerator * other.denominator;
  quotient_denominator = denominator * other.numerator;

  // Create the resulting fraction.
  
  Fraction result(quotient_numerator, quotient_denominator);

  // Return it.
  
  return result;
}

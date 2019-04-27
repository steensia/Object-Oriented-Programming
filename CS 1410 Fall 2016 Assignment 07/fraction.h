/* The Fraction class represents a single rational number with a 
 * numerator and a denominator.
 *
 * Notes:
 *   --If a Fraction object is negative, its numerator is negative.  
 *   --A Fraction object should not have a non-positive denominator. 
 *   --A Fraction object is always stored using its most-reduced form.
 *   --The user of a Fraction object may not change its numerator or 
 *     denominator.
 *   --Additional Fraction objects can be formed by multiplying or 
 *     adding a Fraction object with another Fraction object.
 *   --Fractions objects can be converted to strings and doubles.
 *
 * Authors: Erin Parker & Steen Sia
 * Last updated: October 26, 2016
 */

#include <string>
using namespace std;

class Fraction {

private:
  long long numerator;
  long long denominator;
  
  /* This function reduces this fraction object.  It first
   * computes the greatest common divisor (GCD) of the numerator
   * and denominator.  Then, it divides both the numerator
   * and denominator by that GCD.
   *
   *Parameters: 
   *none
   *
   *Return:
   *none
   */
  void reduce();
  
public:
  /* Fraction default constructor
   *
   * Sets the fraction to 0/1 (which is 0).
   */
  Fraction(); 

  /* Fraction constructor
   *
   * Sets the fraction using the supplied values.
   * A denominator of 0 is not allowed -- although this is not checked.
   * (We need to learn about exceptions first.)
   *
   * Parameters:
   *   long long _numerator -- some numerator
   *   long long _denominator -- some denominator
   */
  Fraction(long long _numerator, long long _denominator);
  
  /*This function puts the object all together to a string 
   *to help create a text representation of the object.
   *
   *Parameters: 
   *none
   *
   *Return:
   *string -- the fraction in a string
   */
  string to_string();
  
  /*This function creates a double that approximates the real
   *value of a Fraction object.
   *
   *Parameters: 
   *none
   *
   *Return:
   *double -- the estimate value of the fraction
   */
  double to_double();
  
  /*This function sums up two different fractions and places the 
   *result into another fraction object.
   *
   *Parameters: 
   *Fraction -- other fraction object to compare
   *
   *Return:
   *Fraction -- the third fraction object containing the sum
   */
  Fraction add(Fraction other);
  
  /*This function subtracts two different fractions and stores 
   *the difference into another fraction object.
   *
   *Parameters: 
   *Fraction -- other fraction object to compare
   *
   *Return:
   *Fraction -- the third fraction object containing the product
   */ 
  Fraction subtract(Fraction other);

 /*This function multiplies two different fractions and places 
  *the product into another fraction object.
  *
  *Parameters: 
  *Fraction -- other fraction object to compare
  *
  *Return:
  *Fraction -- the third fraction object containing the product
  */ 
  Fraction multiply(Fraction other);

/*This function divides two different fractions and stores 
  *the quotient into another fraction object.
  *
  *Parameters: 
  *Fraction -- other fraction object to compare
  *
  *Return:
  *Fraction -- the third fraction object containing the product
  */ 
  Fraction divide(Fraction other);
};

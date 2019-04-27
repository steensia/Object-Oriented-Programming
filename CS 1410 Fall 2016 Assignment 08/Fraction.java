package assign8;

/**The Fraction class represents a single rational number with a 
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
 * @author Erin Parker & Steen Sia
 * @version November 2, 2016
 */
public class Fraction {

	private long numerator;
	private long denominator;

	/**This function reduces this fraction object.  It first
	 * computes the greatest common divisor (GCD) of the numerator
	 * and denominator.  Then, it divides both the numerator
	 * and denominator by that GCD.
	 *
	 * @param none
	 * @return none 
	 */  
	private void reduce() {
	// Compute the GCD using a well-known algorithm.
		
	long gcd = numerator;
	long remainder = denominator;
		
		while(remainder != 0) {
			long temp = remainder;
			remainder = gcd % remainder;
			gcd = temp;
		}

	// Divide both the numerator and denominator by the GCD.		
	numerator /= gcd;
	denominator /= gcd;
	}		
	
	/**Default Fraction constructor
	 *
	 * Sets the fraction to 0/1 (which is 0).
	 * @param none
	 * @return none
	 */
	public Fraction(){
		numerator = 0;
		denominator = 1;
	}
	
	/**Fraction constructor
	 *
	 * Sets the fraction using the supplied values.
	 * A denominator of 0 is not allowed -- although this is not checked.
	 *
	 * @param numerator -- some numerator
	 * @param denominator -- some denominator
	 */
	public Fraction(long _numerator, long _denominator){
		numerator = _numerator;
		denominator = _denominator;
		
		reduce();

		//Ensures that the negative sign is placed in the numerator
		//for any negative fraction.
		
		if(denominator < 0 && numerator > 0)
		{
			numerator = numerator * (-1);
			denominator = Math.abs(denominator);
		}	
	}

	/**This function puts the object all together to a string 
	 * to help create a text representation of the object.
	 *
	 * @param none
	 * @return the fraction in a string
	 */
	public String toString(){
		return numerator + "/" + denominator;	
	}
	
	/**This function creates a double that approximates the real
	 * value of a Fraction object.
	 *
	 * @param none
	 * @return the estimate value of the fraction
	 */
	public double toDouble(){
	  double n = numerator;
	  double d = denominator;
	  double closeValue;

	  closeValue = n / d;
	  
	  return closeValue;
	}
	
	 /**This function sums up two different fractions and places the 
	  * result into another fraction object.
	  *
	  * @param Fraction -- other fraction object to compare
	  * @return Fraction -- the third fraction object containing the sum
	  */
	public Fraction add(Fraction other){
	  // Compute the sum.
	  
	  long sumNumerator;
	  long sumDenominator;
	  
	  sumNumerator = numerator * other.denominator + other.numerator * denominator;
	  
	  sumDenominator = denominator * other.denominator;

	  // Create the resulting fraction.
	  
	  Fraction result = new Fraction(sumNumerator, sumDenominator);

	  // Return it.
	  
	  return result;
	}
	
	/**This function subtracts two different fractions and stores 
	 * the difference into another fraction object.
	 *
	 * @param Fraction -- other fraction object to compare
	 * @return Fraction -- the third fraction object containing the sum
	 */
	public Fraction subtract(Fraction other){
	  // Compute the difference.
	  
	  long diffNumerator;
	  long diffDenominator;
	  
	  diffNumerator = numerator * other.denominator - other.numerator * denominator;
	  
	  diffDenominator = denominator * other.denominator;
	  
	  Fraction result = new Fraction(diffNumerator, diffDenominator);
	  
	  return result;
	}
	
	/**This function multiplies two different fractions and places 
	 * the product into another fraction object.
	 *
	 * @param Fraction -- other fraction object to compare
	 * @return Fraction -- the third fraction object containing the sum
	 */
	public Fraction multiply(Fraction other){
	  // Compute the product.
	  
	  long productNumerator;
	  long productDenominator;
	  
	  productNumerator   = numerator * other.numerator;
	  productDenominator = denominator * other.denominator;
	  
	  Fraction result = new Fraction(productNumerator, productDenominator);
	  
	  return result;
	}
	
	/**This function divides two different fractions and stores 
	 * the quotient into another fraction object.
	 *
	 * @param Fraction -- other fraction object to compare
	 * @return Fraction -- the third fraction object containing the sum
	 */
	public Fraction divide(Fraction other){
	  // Compute the quotient.
	  
	  long quotientNumerator;
	  long quotientDenominator;
	  
	  quotientNumerator = numerator * other.denominator;
	  quotientDenominator = denominator * other.numerator;
	  
	  Fraction result = new Fraction(quotientNumerator, quotientDenominator);

	  return result;
	}
	
	public static void main(String[] args) {
		Fraction fdef = new Fraction(); //Object using default constructor
		Fraction fdef1 = new Fraction();
		Fraction f1 = new Fraction(2, 3);
		Fraction f2 = new Fraction(3, -4);
		Fraction f3 = new Fraction(5, 6);
		Fraction f4 = new Fraction(7, -8);

		// My examples
		System.out.println("The default fraction is: " + fdef.toString());
		System.out.println("Fraction f1 is: " + f1.toString());
		System.out.println("Fraction f2 is: " + f2.toString());
		System.out.println("Fraction f3 is: " + f3.toString());
		System.out.println("Fraction f4 is: " + f4.toString());
		
		//Default fraction case examples
		System.out.println("The rule of zero is: anything multiplied or divided by 0 is equal to 0.");
		fdef = fdef1.multiply(f3);
		
		System.out.println(fdef1.toString() + " multiplied by " + f3.toString() + " equals " + fdef.toString());  
		  
		fdef = fdef1.divide(f4);

		System.out.println(fdef1.toString() + " divided by " + f4.toString() + " equals " + fdef.toString());
		
		//Fraction f1 case examples
		System.out.println("Case examples for each fraction object: ");
		
		fdef = f1.add(f2);
		
		System.out.println(f1.toString() + " plus " + f2.toString() + " equals " + fdef.toString());
		
		fdef = f1.subtract(f3);
		
		System.out.println(f1.toString() + " minus " + f3.toString() + " equals " + fdef.toString());
		  
		fdef = f1.multiply(f4);

		System.out.println(f1.toString() + " multiplied by " + f4.toString() + " equals " + fdef.toString());
		  
		//Display the floating-point number value of the fraction.
		System.out.println("The real number closest to " + fdef.toString() + " is " + fdef.toDouble());
		
		//Fraction f2 case examples
		fdef = f2.divide(f1);
		  
		System.out.println(f2.toString() + " divided by " + f1.toString() + " equals " + fdef.toString());
		
		fdef = f2.add(f3);
		
		System.out.println(f2.toString() + " plus " + f3.toString() + " equals " + fdef.toString());
		
		fdef = f2.subtract(f4);
		
		System.out.println(f2.toString() + " minus " + f4.toString() + " equals " + fdef.toString());
		
		System.out.println("The real number closest to " + fdef.toString() + " is " + fdef.toDouble());
		
		//Fraction f3 case examples
		fdef = f3.multiply(f1);
		
		System.out.println(f3.toString() + " multiplied by " + f1.toString() + " equals " + fdef.toString());
		
		fdef = f3.divide(f2);
		
		System.out.println(f3.toString() + " divided by " + f2.toString() + " equals " + fdef.toString());
		
		fdef = f3.add(f4);

		System.out.println(f3.toString() + " plus " + f4.toString() + " equals " + fdef.toString());

		System.out.println("The real number closest to " + fdef.toString() + " is " + fdef.toDouble());
		
		//Fraction f4 case examples
		fdef = f4.subtract(f1);

		System.out.println(f4.toString() + " minus " + f1.toString() + " equals " + fdef.toString());
		
		fdef = f4.multiply(f2);
		
		System.out.println(f4.toString() + " multiplied by " + f2.toString() + " equals " + fdef.toString());
		  
		fdef = f4.divide(f3);
		
		System.out.println(f4.toString() + " divided by " + f3.toString() + " equals " + fdef.toString());
		
		System.out.println("The real number closest to " + fdef.toString() + " is " + fdef.toDouble());
	}		

}

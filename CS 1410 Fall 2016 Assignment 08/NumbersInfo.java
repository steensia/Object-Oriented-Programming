package assign8;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class NumbersInfo {
	/**This program opens the numbers.txt file, reads each
	 * number inside and outputs: the count of numbers in the
	 * file, the count of negative numbers, the average, the 
	 * largest number, and the file closest to zero.
	 * 
	 * @author Steen Sia
	 * @version November 2, 2016
	 */
	public static void main(String[] args) {
		
		File textFile = new File("numbers.txt");
		Scanner s = null;
		
		//Notifies the user if the text file does not exist.
		try{
		s = new Scanner(textFile);
		} 
		catch(FileNotFoundException e) {
			System.out.println(e.getMessage());
			System.exit(0);
		}
		//Puts the numbers in the file to a list.
		ArrayList<Double> numbers = new ArrayList<Double>();
		
		while(s.hasNextDouble()){
			numbers.add(s.nextDouble());
		}
		s.close();
		
		System.out.println("The count of all numbers in the file is " + numbers.size() + ".");
		System.out.println("The count of negative numbers in the file " + findNegative(numbers) + ".");
		System.out.println("The average of all numbers in the file is " + average(numbers) + ".");
		System.out.println("The largest number in the file is " + findLargest(numbers) + ".");
		System.out.println("The number in the file that is closest to 0 is " + findClosest(numbers)+ ".");
	}		
		/**Determines the count of negative numbers in the file.
		 * 
		 * @param numbers - numbers inside the file.
		 * @return the count of negative numbers.
		 */
		public static int findNegative(ArrayList<Double> numbers){
			int count = 0;
			for(int i = 0; i < numbers.size(); i++){
				if(numbers.get(i) < 0){
					count++;
				}					
			}
			return count;
		}
		
		/**Determines the average of all the numbers in the file.
		 * 
		 * @param numbers - numbers inside the file.
		 * @return the average in the file.
		 */
		public static double average(ArrayList<Double> numbers){
			double sum = 0;
			int count = 0;
			for(int i = 0; i < numbers.size(); i++){
				sum += numbers.get(i);
				count++;								
			}
			return sum / count;
		}
		
		/**Determines the largest number in the file.
		 * 
		 * @param numbers - numbers inside the file.
		 * @return the largest number.
		 */
		public static double findLargest(ArrayList<Double> numbers){
			double largest = numbers.get(0);
			for(int i = 1; i < numbers.size(); i++){
				if(numbers.get(i) > largest){
					largest = numbers.get(i);
				}					
			}
			return largest;
		}
		
		/**Determines the number that is closest to zero.
		 * 
		 * @param numbers - numbers inside the file.
		 * @return the number closest to zero.
		 */
		public static double findClosest(ArrayList<Double> numbers){
			double closest = numbers.get(0);
			for(int i = 1; i < numbers.size(); i++){
				if(Math.abs(numbers.get(i)) < Math.abs(closest)){
					closest = numbers.get(i);
				}					
			}
			return closest;
		}
		
}

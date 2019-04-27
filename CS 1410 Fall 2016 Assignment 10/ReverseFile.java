package assign10;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


/**This program manipulates the StringStack class by
 * reading a file and outputting a text file the 
 * strings in reverse order.
 * 
 * @author Steen Sia
 * @version November 16, 2016
 */
public class ReverseFile {

	public static void main(String[] args) {
		StringStack stackList = new StringStack();
		
		File textFile = new File("input.txt");
		Scanner s = null;

		try{
		s = new Scanner(textFile);
		} 
		catch(FileNotFoundException e) {
			System.out.println(e.getMessage());
			System.exit(0);
		}
	
		while(s.hasNext()){
			stackList.push(s.next());			
		}
		
		s.close();

	// Enclose creation and use of PrintWriter in a try-catch for handling errors.
	try {
	   PrintWriter out = new PrintWriter(new File("output.txt"));
	   for(int i = stackList.size() - 1; i >= 0; i--){
			out.println(stackList.pop());
		}
	   
	   out.close();
	}
	catch(FileNotFoundException e) {
	   e.printStackTrace();
	}

}
}

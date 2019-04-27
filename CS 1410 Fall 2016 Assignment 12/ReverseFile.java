package assign12;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * This program manipulates the StringStackLL class by reading a file and
 * outputting a text file the strings in reverse order.
 * 
 * @author Steen Sia
 * @version November 30, 2016
 */
public class ReverseFile {

	public static void main(String[] args) {
		Stack stackList = new StringStackLL();

		File textFile = new File("input.txt");
		Scanner s = null;

		// throws an error exception when the text file is not found.
		try {
			s = new Scanner(textFile);
		} catch (FileNotFoundException e) {
			System.out.println(e.getMessage());
			System.exit(0);
		}
		// pushes the string to the stack while the text file still contains a string
		while (s.hasNext()) {
			stackList.push(s.next());
		}

		s.close();

		// throw and error exception if the file isn't found.
		try {
			PrintWriter out = new PrintWriter(new File("output.txt"));
			// pops the strings in from bottom to top elements of the linked list.
			for (int i = stackList.size(); i > 0; i--) {
				out.println(stackList.pop());
			}
			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

	}
}

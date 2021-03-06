package assign10;
/** This program demonstrates the StringStack class
 * 	by utilizing the member functions such as pop, peek,
 *  push, size, and toString.
 * 
 * @author Steen Sia
 * @version November 16, 2016
 */
public class StringStackTester {

	public static void main(String[] args) {

		StringStack stackList = new StringStack();
		
		stackList.push("cow");
		stackList.push("monkey");
		stackList.pop();
		stackList.push("dog");
		stackList.push("wow");
		
		System.out.println(stackList.peek());
		System.out.println(stackList.size());
		System.out.println(stackList.toString());
		
		stackList.clear();	
		
		System.out.println(stackList.size());
		
		stackList.push("C++");
		stackList.push("Object");
		
		System.out.println(stackList.toString());
	}

}

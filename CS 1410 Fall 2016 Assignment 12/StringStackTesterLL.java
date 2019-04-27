package assign12;

import assign12.StringStackLL;

/**
 * This program demonstrates the StringStackLL class by utilizing the member
 * functions such as pop, peek, push, size, clear, and toString.
 * 
 * @author Steen Sia
 * @version November 30, 2016
 */
public class StringStackTesterLL {

	public static void main(String[] args) {

		Stack stackList = new StringStackLL();

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

		// Test to see if it prints an empty string representation.
		Stack newStack = new StringStackLL();
		System.out.println(newStack.toString());

		newStack.push("A");
		newStack.push("B");
		newStack.push("C");
		newStack.push("D");
		newStack.push("E");
		newStack.push("F");
		newStack.push("G");
		newStack.push("H");
		newStack.push("I");
		newStack.push("J");

		System.out.println(newStack.toString());
		System.out.println(newStack.size());

		System.out.println(newStack.pop());
		// Uses the interface type Stack to create the stack object.
		Stack myStack = new StringStackLL();

		myStack.push("Bingo!");
		System.out.println(myStack.toString());
		System.out.println(myStack.size());
		System.out.println(myStack.pop());
		// Test to make sure NoSuchElementException is working
		System.out.println(myStack.pop());

	}

}

package assign12;

/**
 * Interface for a LIFO Stack Abstract Data Structure.
 * 
 * @author sia
 * @version November 30, 2016
 */

public interface Stack {
	/**
	 * Adds a string to the top of the stack.
	 * 
	 * @param s
	 */
	void push(String s);

	/**
	 * Removes a string from the top of the stack.
	 * 
	 * @return the string at the top of the stack
	 */
	String pop();

	/**
	 * Queries the string at the top of the stack.
	 * 
	 * @return the string at the top of stack
	 */
	String peek();

	/**
	 * Resets the stack by removing the items and changing the size to zero.
	 * 
	 * @return none
	 */
	void clear();

	/**
	 * Shows a string representation of the items in the stack.
	 * 
	 * @return the strings in the stack
	 */
	String toString();

	/**
	 * Determines the number of items in the stack.
	 * 
	 * @return the item count of the stack
	 */
	int size();
}

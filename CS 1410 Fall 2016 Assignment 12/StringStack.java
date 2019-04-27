package assign12;

/**
 * The StringStack class represents a stack function with the use of basic
 * arrays and manipulation of a variable.
 *
 * @author Steen Sia
 * @version November 30, 2016
 */
public class StringStack implements Stack {
	private int top;
	private String[] arr;

	/**
	 * Default StringStack constructor
	 *
	 * Sets the Stack to an empty array of size 10 and starts the top counter at
	 * -1.
	 * 
	 * @param none
	 * @return none
	 */
	public StringStack() {
		arr = new String[10];
		top = -1;
	}

	/**
	 * This member function adds the string on to the array with the use of top
	 * counter.
	 *
	 * @param the
	 *            string entered and to be added.
	 * @return none.
	 */
	public void push(String item) {

		// Copies contents of old array into a bigger array.
		if (top + 1 == arr.length) {
			String[] newArr = new String[arr.length * 2];
			for (int i = 0; i < arr.length; i++) {
				newArr[i] = arr[i];
			}
			arr = newArr;
		}
		arr[++top] = item;
	}

	/**
	 * This member function removes the string from the top by decrementing the
	 * top counter;
	 *
	 * @param none
	 * @return the last index after being decremented.
	 */
	public String pop() {
		return arr[top--];

	}

	/**
	 * This member function reveals the string at the top of the array.
	 *
	 * @param none
	 * @return the last index.
	 */
	public String peek() {
		return arr[top];

	}

	/**
	 * This member function displays the size of the array.
	 *
	 * @param none
	 * @return the array size.
	 */
	public int size() {
		return top + 1;
	}

	/**
	 * This member function removes all elements by resetting the top counter to
	 * -1. It allows the user to overwrite the elements when pushing.
	 *
	 * @param none
	 * @return none
	 */
	public void clear() {
		top = -1;
	}

	/**
	 * This member function returns the textual representation of the stack from
	 * the top element to the bottom element.
	 *
	 * @param none
	 * @return string representation of stack
	 */
	public String toString() {
		String collect = "[";
		for (int i = top; i >= 0; i--) {
			collect += arr[i];
			if (i > 0) {
				collect += ", ";
			}
		}
		return collect + "]";
	}

	public static void main(String[] args) {

	}
}

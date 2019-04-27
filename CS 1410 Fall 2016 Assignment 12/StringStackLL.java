package assign12;

/**
 * The StringStackLL class represents a stack function with the use of linked
 * list instead of an array to store strings. This class will also use a
 * variable to keep track of the number of strings and a head index to point to
 * each new string.
 *
 * @author Steen Sia
 * @version November 30, 2016
 */
public class StringStackLL implements Stack {

	private class Node {
		public String data;
		public Node next;
	}

	// keeps track of item count
	private int size = 0;
	// first link index
	private Node head = null;

	/**
	 * Default StringStackLL constructor
	 *
	 * Sets everything to default or 0.
	 * 
	 * @param none
	 * @return none
	 */
	public StringStackLL() {
	}

	/**
	 * This member function adds the string on to the linked list with the use
	 * of a temporary variable to store the string and pass it on to the head
	 * index and increments the size.
	 *
	 * @param the
	 *            string entered and to be added.
	 * @return none.
	 */
	public void push(String s) {
		// Creates a temporary node to hold the string to be pushed
		// the next node head points to is temp which stores the string.
		Node temp = head;
		head = new Node();
		head.data = s;
		head.next = temp;
		size++;

	}

	/**
	 * This member function removes the string from the top by pointing head to
	 * the previous link and decrements the size.
	 *
	 * @param none
	 * @return the string that was removed
	 */
	public String pop() {
		// throws an error exception when the head is pointing to nothing/size
		// is 0 to notify the user they cannot do this action.
		if (head == null) {
			throw new java.util.NoSuchElementException();
		}
		// temp contains head's string then head points to the previous link
		String temp = head.data;
		head = head.next;
		size--;
		// return the top of the stack which is in temp.
		return temp;

	}

	/**
	 * This member function reveals the string at the end of the linked list.
	 *
	 * @param none
	 * @return the last string of the linked list.
	 */
	public String peek() {
		// throws an error exception when the head is pointing to nothing/size
		// is 0 to notify the user they cannot do this action.
		if (head == null) {
			throw new java.util.NoSuchElementException();
		}
		return head.data;

	}

	/**
	 * This member function displays the size of the linked list.
	 *
	 * @param none
	 * @return the linked list size.
	 */
	public int size() {
		return size;
	}

	/**
	 * This member function removes all elements by resetting the size of the
	 * linked list to 0. It allows the user to overwrite the elements when
	 * pushing.
	 *
	 * @param none
	 * @return none
	 */
	public void clear() {
		head = null;
		size = 0;
	}

	/**
	 * This member function returns the textual representation of the stack from
	 * the top element of the linked list to the bottom element of the linked
	 * list.
	 *
	 * @param none
	 * @return string representation of the stack.
	 */
	public String toString() {
		String collect = "[";
		Node temp = new Node();
		temp = head;

		for (int i = size; i > 0; i--) {
			collect += temp.data;
			// Link begins at one
			if (i > 1) {
				collect += ", ";
			}
			temp = temp.next;
		}
		return collect + "]";
	}
}

/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * Linked stack definition
 *
 * Stack.h: class & function definitions
 *   (class defined as template)
 */

#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

#include "Node.h"

template <class T>
class Stack {
public:
	Stack();						// Constructor
	~Stack();						// Destructor
	bool empty() const;				// Checks if stack is empty
	void push(const T& val);		// Pushes data on top of stack
	void pop();						// Removes top item from stack
	T getTop() const;				// Accessor for data in top node

	/*** OVERLOADED OPERATORS ***/
	Stack<T>& operator =(const Stack<T>& rhs);
	bool operator ==(const Stack<T>& rhs);

	// Template declaration necessary here because operator
	//    is technically outside class
	template <class T>
	friend ostream& operator <<(ostream& out, Stack<T>& aStack);

private:
	Node<T>* top;		// Node at top of stack
};

/*** FUNCTION DEFINITIONS ***/

// Constructor
template <class T>
Stack<T>::Stack() : top(nullptr)
{}

// Destructor
// Deletes nodes from stack until it's empty
template <class T>
Stack<T>::~Stack() {
	while (!empty())
		pop();
}

// Checks if stack is empty
template <class T>
bool Stack<T>::empty() const {
	return (top == nullptr);
}

// Pushes data on top of stack
template <class T>
void Stack<T>::push(const T& val) {
	Node<T>* newNode;

	// GENERAL STEPS FOR ADDING TO LINKED LIST
	// 1. Allocate new node
	// 2. New node -> successor
	//   (since new node will become top of stack, current top node
	//    is its successor)
	newNode = new Node(val, top);

	// 3. Predecessor -> new node 
	//   (in stack, no predecessor because new node goes at top)
	top = newNode;
}

// Removes top item from stack
template <class T>
void Stack<T>::pop() {

	// 1. Copy address of node to remove
	Node<T>* ptr = top;

	// 2. top = address of 2nd node
	// Equivalent to: top = (*top).getNext();
	top = top->getNext();

	// 3. Delete old top node
	delete ptr;
}

// DON'T CALL THIS IF STACK IS EMPTY
// Return value at top of stack
template <class T>
T Stack<T>::getTop() const {
	return top->getVal();	// Same as (*top).getVal();
}

// Overloaded assignment--performs deep copy
template <class T>
Stack<T>& Stack<T>::operator =(const Stack<T>& rhs) {
	Stack<T> temp;

	// Ensure no self-assignment
	if (!(*this == rhs)) {

		// Deallocate any nodes in calling object at start
		// Could call ~Stack(), but that fn. isn't usually called
		while (!empty())
			pop();

		// Now, copy the data
		// First, copy from rhs to the temp stack
		Node<T>* ptr = rhs.top;
		while (ptr != nullptr) {
			temp.push(ptr->getVal());
			ptr = ptr->getNext();
		}

		// Now, traverse the temp stack and copy to the calling obj
		ptr = temp.top;
		while (ptr != nullptr) {
			push(ptr->getVal());
			ptr = ptr->getNext();
		}
	}

	// Return reference to calling object
	return *this;
}

// Overloaded comparison
template <class T>
bool Stack<T>::operator ==(const Stack<T>& rhs) {

	// First, traverse both stacks
	Node<T>* ptr = top;
	Node<T>* ptr2 = rhs.top;

	while (ptr != nullptr && ptr2 != nullptr) {

		// Compare corresponding nodes
		// If you find a mismatch, stacks aren't equal
		if (ptr->getVal() != ptr2->getVal())
			return false;

		ptr = ptr->getNext();
		ptr2 = ptr2->getNext();
	}

	// If you reach end of loop, reached end of at least
	//   one stack

	if (ptr == nullptr && ptr2 == nullptr)	// Stacks match
		return true;
	else				// if (ptr != nullptr || ptr2 != nullptr)
		return false;
}

// Overloaded output (friend function)
// Example of stack traversal
template <class T>
ostream& operator <<(ostream& out, Stack<T>& aStack) {

	// 1. ptr = first node
	Node<T>* ptr = aStack.top;

	// 2. As long as we haven't hit the last node ...
	//    (or gone past it)
	while (ptr != nullptr) {

		// 2a. Do something with the current node
		//   (in this case, print the value in that node)
		out << ptr->getVal() << endl;

		// 2b. ptr = address of next node
		ptr = ptr->getNext();
	}

	// Return reference to output stream
	return out;
}

/*** END FUNCTION DEFINITIONS ***/


#endif STACK_H
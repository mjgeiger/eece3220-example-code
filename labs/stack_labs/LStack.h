/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * Linked stack definition
 *   
 * Stack.h: class & function definitions
 *   (class defined as template)
 * EXTENDED FOR STACK LABS TO ADD PROTOTYPES FOR 
 *    FUNCTIONS isOrdered AND minToTop
 */

#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

#include "Node.h"

template <class T>
class Stack {
public:
	/*** NEW FUNCTION PROTOTYPES ***/
	bool isOrdered() const;			// Checks if stack in ascending order
	void minToTop();				// Moves min value on stack to top node
	/*** END NEW FUNCTION PROTOTYPES ***/


	Stack();						// Constructor
	~Stack();						// Destructor
	bool empty() const;				// Checks if stack is empty
	void push(const T &val);		// Pushes data on top of stack
	void pop();						// Removes top item from stack
	T getTop() const;				// Accessor for data in top node
	
	/*** OVERLOADED OPERATORS ***/
	Stack<T> &operator =(const Stack<T> &rhs);
	bool operator ==(const Stack<T> &rhs);

	// Template declaration necessary here because operator
	//    is technically outside class
	template <class T>
	friend ostream &operator <<(ostream &out, Stack<T> &aStack);

private:
	Node<T> *top;		// Node at top of stack
};

/*** FUNCTION DEFINITIONS ***/

/*** NEW FUNCTIONS TO BE WRITTEN ***/
// Checks if stack in ascending order
// ASSUMES EVERY TYPE HAS WORKING COMPARISONS
template <class T>
bool Stack<T>::isOrdered() const {
	T tempVal;		// Temporary value used in comparisons

	// Technically, an empty stack is in ascending order
	if (empty())
		return true;

	// No "else" needed--function returns if stack is empty
	
	// Loop compares previous node's value (tempVal) to 
	//   current node's value
	tempVal = top->getVal();
	Node<T>* p = top->getNext();
	while (p != nullptr) {
		
		// If current node value < prev node's value, out of order
		if (p->getVal() < tempVal)
			return false;

		tempVal = p->getVal();
		p = p->getNext();
	}

	// If you reach end of loop without returning, 
	//    stack must be in order
	return true;
}

// Moves min value on stack to top node
//   Pushes everything else down one node
// ALSO ASSUMES VALID COMPARISONS
template <class T>
void Stack<T>::minToTop() {

	// Save some time--if the stack is empty, no point
	if (empty()) return;

	// Otherwise, start by finding node with min value
	// Start by assuming min value is in first node
	Node<T>* min = top;
	Node<T>* minPred = nullptr;		// Removing node from middle requires pointer to prev node
	T minVal = top->getVal();

	// Then, traverse stack and see if there's anything lower
	Node<T>* p = top->getNext();
	Node<T>* prev = top;
	while (p != nullptr) {
		if (p->getVal() < minVal) {
			min = p;
			minPred = prev;
			minVal = p->getVal();
		}

		prev = p;
		p = p->getNext();
	}

	// If the minimum value isn't already in the top node,
	//   unlink the node with the min value, fix the stack
	//   and move min node to top
	if (min != top) {

		// Predecessor points past min node
		minPred->setNext(min->getNext());	

		// Min node points to old "top"
		min->setNext(top);

		// top points to min node
		top = min;
	}
}
/*** END NEW FUNCTIONS ***/

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
void Stack<T>::push(const T &val) {
	Node<T>* newNode;

	// GENERAL STEPS FOR ADDING TO LINKED LIST
	// 1. Allocate new node
	// 2. New node -> successor
	//   (since new node will become top of stack, current top node
	//    is its successor)
	newNode = new Node<T>(val, top);

	// 3. Predecessor -> new node 
	//   (in stack, no predecessor because new node goes at top)
	top = newNode;

	// Could have just written:
	//  top = new Node<T>(val, top);
}

// Removes top item from stack
template <class T>
void Stack<T>::pop() {
	
	// 1. Copy address of node to remove
	Node<T>* temp = top;

	// 2. top = address of 2nd node
	// Equivalent to: top = (*top).getNext();
	top = top->getNext();

	// 3. Delete old top node
	delete temp;
}

// DON'T CALL THIS IF STACK IS EMPTY
// Return value at top of stack
template <class T>
T Stack<T>::getTop() const {
	return top->getVal();
}

// Overloaded assignment--performs deep copy
template <class T>
Stack<T> &Stack<T>::operator =(const Stack<T> &rhs) {

	// Ensure no self-assignment
	if (!(*this == rhs)) {

		// Deallocate any nodes in calling object at start
		while (!empty())
			pop();

		// Now, copy the data

		// First, create a temporary stack and copy data there
		//  (data in temp is in reverse order of rhs)
		Stack<T> temp;
		Node<T>* p = rhs.top;
		while (p != nullptr) {
			temp.push(p->getVal());
			p = p->getNext();
		}

		// Now, copy from temp to calling object, reversing order again
		p = temp.top;
		while (p != nullptr) {
			push(p->getVal());
			p = p->getNext();
		}
	} 	// temp destructor runs at this point


	// Return reference to calling object
	return *this;
}

// Overloaded comparison
template <class T>
bool Stack<T>::operator ==(const Stack<T> &rhs) {
	Node<T>* p = top;		// Top of calling object (LHS)
	Node<T>* q = rhs.top;	// Top of RHS

	// Traverse both stacks until you hit end of one stack
	while (p != nullptr && q != nullptr) {
	
		// Processing step--compare values in corresponding nodes
		//  If they don't match, stacks don't match--return false
		if (p->getVal() != q->getVal())
			return false;

		// Update both pointers
		p = p->getNext();
		q = q->getNext();
	}

	// If you get to end of loop *and* both pointers are null,
	//   stacks match --> return true
	if (p == nullptr && q == nullptr)
		return true;

	// Otherwise, one stack is shorter than the other --> return false
	else
		return false;

}

// Overloaded output (friend function)
// Example of stack traversal
template <class T>
ostream &operator <<(ostream &out, Stack<T> &aStack) {

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
/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * Linked stack definition
 *
 * Stack.cpp: function definitions
 */

#include "Stack.h"		// Implicitly includes <iostream>

// Constructor (written 3/18)
Stack::Stack() : top(nullptr)
{}

// Destructor (written 3/20)
Stack::~Stack() {
	while (!empty()) {
		pop();
	}
}

// Checks if stack is empty (written 3/18)
bool Stack::empty() const {
	return (top == nullptr);
}

// Pushes data on top of stack (written 3/18)
void Stack::push(const double& val) {
	top = new Node(val, top);
}

// Removes top item from stack (written 3/20)
void Stack::pop() {
	Node* temp;

	// Can't pop from an empty stack
	if (top == nullptr)
		cout << "Stack is empty\n";

	// To change top node and still have address of
	//   node to pop off stack, must use temp pointer
	//   to store top node address, then move "top"
	//   to second node
	else {
		temp = top;
		top = top->getNext();
		delete temp;
	}
}

// Accessor for data in top node (written 3/20)
double Stack::getTop() {
	if (top != nullptr)
		return top->getVal();
	else {
		cout << "Stack is empty\n";
		return 0;
	}
}

// Overloaded assignment operator (written 3/20)
Stack& Stack::operator =(const Stack& rhs) {
	Stack temp;		// Temporary stack to allow copying
	Node* p;		// Temporary node pointer

	// Make sure there's no self-assignment, e.g. s1 = s1;
	if (!(*this == rhs)) {

		// Step 0. If there's data in the calling object, empty it
		while (!empty())
			pop();

		// Make sure rhs isn't empty--if it is, the assignment's done!
		if (rhs.top != nullptr) {
			// Step 1. Copy data from rhs to temp, in reverse order
			p = rhs.top;
			while (p != nullptr) {
				temp.push(p->getVal());
				p = p->getNext();
			}

			// Step 2. Empty temp stack and copy data to calling object
			while (!temp.empty()) {
				this->push(temp.getTop());
				temp.pop();
			}
		}
	}
	return *this;		// Return reference to calling object for chained assignment
						//  e.g. a = b = c = d;
}

// Overloaded comparison operator (written 3/20)
bool Stack::operator ==(const Stack& rhs) {
	Node* tmp1, * tmp2;	// Node pointer for each stack

	tmp1 = top;		// Top of calling object
	tmp2 = rhs.top;	// Top of RHS

	// Traverse stacks while:
	//  (1) Haven't hit end of either one (tested in loop condition), and
	//  (2) Data in all nodes so far match (if statement will exit if false)
	while (tmp1 != nullptr && tmp2 != nullptr) {

		// If mismatch found, exit function
		if (tmp1->getVal() != tmp2->getVal())
			return false;

		// Move both Node pointers ahead to next node
		tmp1 = tmp1->getNext();
		tmp2 = tmp2->getNext();
	}

	// Stacks are same length & contain same data
	//   (if they were same length and contained different data,
	//    if statement in loop would have forced function to 
	//    return false before reaching this point)
	if (tmp1 == nullptr && tmp2 == nullptr)
		return true;

	// Else case: one stack is shorter than the other
	else
		return false;
}

// Overloaded output operator (written 3/20)
ostream& operator <<(ostream& out, Stack& aStack) {
	Node* temp;
	
	if (aStack.top == nullptr)
		out << "Stack is empty\n";
	else {

		// General traversal algorithm:
		// 1. pointer = first node address
		// 2. while (pointer != nullptr)
		//     a. Do something with node (print, search, etc)
		//     b. pointer = address of next node
		temp = aStack.top;
		while (temp != nullptr) {
			out << temp->getVal() << '\n';
			temp = temp->getNext();
		}
	}
	
	// Necessary for chained outputs, i.e. cout << s1 << s2;
	return out;
}
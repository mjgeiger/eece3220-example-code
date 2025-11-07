/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * Linked stack definition
 *
 * Stack.cpp: function definitions
 */

#include "Stack.h"		// Implicitly includes <iostream>

// Constructor
Stack::Stack() 
{}

// Destructor
// Deletes nodes from stack until it's empty
Stack::~Stack() {
}

// Checks if stack is empty
bool Stack::empty() const {
}

// Pushes data on top of stack
void Stack::push(const double &val) {
	// 1. Allocate new node & store data in it
	// 2. Make new node point to node that follows it (old "top" of stack)
	// 3. Make "top" pointer point to new node
}

// Removes top item from stack
void Stack::pop() {
}

// Return value stored in top node
double Stack::getTop() {
}

// Overloaded assignment--performs deep copy
Stack &Stack::operator =(const Stack &rhs) {

	// Return reference to calling object
	return *this;
}


// Overloaded comparison
// If we have if (s1 == s2), s1 is calling object, s2 is rhs
bool Stack::operator ==(const Stack &rhs) {
}

// Overloaded output (friend function)
// Traverse Stack from top to bottom and print each node
ostream &operator <<(ostream &out, Stack &aStack) {
}
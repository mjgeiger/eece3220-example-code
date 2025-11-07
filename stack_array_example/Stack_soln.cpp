/*
 * M. Geiger
 * EECE.3220: Data Structures
 *
 * Source file for in-class stack example
 * Stack member function definitions
 */

#include "Stack.h"
#include <iostream>
using std::cout;
using std::endl;

// Constructor
Stack::Stack(unsigned maxSize) : 
	cap(maxSize), tos(-1)
{
	list = new double[cap];
}

// Destructor
Stack::~Stack() {
	delete[] list;
}

// Returns true if stack empty
bool Stack::empty() const {
	// Could write as:
	//    return (tos == -1);
	
	if (tos == -1) 
		return true;
	else 
		return false;
}

// Push val to top of stack
void Stack::push(const double &val) {
	if (tos == (int)cap - 1)
		cout << "Stack is full" << endl;
	else {
		tos++;
		list[tos] = val;

		// Could have written: list[++tos] = val;
	}
}

// Remove top of stack
void Stack::pop() {
	if (empty())
		cout << "Stack is empty" << endl;
	else
		tos--;
}

// Read top of stack
double Stack::top() {
	if (empty()) {
		cout << "Stack is empty" << endl;
		return list[cap - 1];		// Have to return something ...
	}
	else
		return list[tos];
}
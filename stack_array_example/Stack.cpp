/*
 * M. Geiger
 * EECE.3220: Data Structures
 *
 * Source file for in-class stack example
 * Stack member function definitions
 */

#include <iostream>
#include "Stack.h"
using std::cout;
using std::endl;

/*
double* list;	// The actual data stored on the stack
int tos;		// Index for top of stack
unsigned cap;	// Capacity (max size) of stack
*/
Stack::Stack(unsigned maxSize) :
	tos(-1), cap(maxSize)
{
	list = new double[maxSize];		
}

Stack::~Stack() {
	delete[] list;
}

bool Stack::empty() const { 
	return (tos == -1);
}

void Stack::push(const double& val) {
	// Can't push when stack full
	if (tos == cap - 1)
		cout << "ERROR: stack full\n";

	// Otherwise:
	// 1. Increment tos
	// 2. Set list[tos] = val
	else {
		list[++tos] = val;
	}
}

void Stack::pop() {
	// Can't pop when empty
	if (tos == -1)
		cout << "ERROR: stack empty\n";

	else
		tos--;
}

// Returns object at TOS
// ASSUME THIS ISN'T CALLED IF STACK IS EMPTY
double Stack::top() const { 
	return list[tos];
}
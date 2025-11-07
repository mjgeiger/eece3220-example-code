/*
 * M. Geiger
 * EECE.3220: Data Structures
 *
 * Header file for in-class stack example
 * Stack class definition
 */

#ifndef STACK_H
#define STACK_H

class Stack {
public:
	Stack(unsigned maxSize = 1024);		// Constructor
	~Stack();							// Destructor
	bool empty() const;					// Returns true if stack empty
	void push(const double &val);		// Push val to top of stack
	void pop();							// Remove top of stack
	double top() const;					// Read contents of top of stack
										// NOTE: Do not call if stack is empty!
private:
	double *list;	// The actual data stored on the stack
	int tos;		// Index for top of stack
	unsigned cap;	// Capacity (max size) of stack
};

#endif   // STACK_H
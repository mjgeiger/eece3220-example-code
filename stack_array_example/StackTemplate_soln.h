/*
 * M. Geiger
 * EECE.3220: Data Structures
 *
 * Header file for in-class stack example
 * Stack class definition--as a template
 */

#ifndef STACK_H
#define STACK_H

using namespace std;
#include <iostream>

template <class T>
class Stack {
public:
	Stack(unsigned maxSize = 1024);		// Constructor
	~Stack();							// Destructor
	bool empty() const;					// Returns true if stack empty
	void push(const T& val);			// Push val to top of stack
	void pop();							// Remove top of stack
	T top() const;						// Read contents of top of stack
private:
	T* list;		// The actual data stored on the stack
	int tos;		// Index for top of stack
	unsigned cap;	// Capacity (max size) of stack
};

template <class T>
Stack<T>::Stack(unsigned maxSize) :
	tos(-1), cap(maxSize)
{
	list = new T[maxSize];
}

template <class T>
Stack<T>::~Stack() {
	delete[] list;
}

template <class T>
bool Stack<T>::empty() const {
	return (tos == -1);
}

template <class T>
void Stack<T>::push(const T& val) {
	if (tos == cap - 1)
		cout << "Stack full!\n";
	else
		list[++tos] = val;
}

template <class T>
void Stack<T>::pop() {
	if (empty())
		cout << "Stack empty!\n";
	else
		tos--;
}

// Returns object at TOS
// DO NOT CALL THIS FUNCTION IF STACK IS EMPTY!
template <class T>
T Stack<T>::top() const {
	return list[tos];
}

#endif   // STACK_H
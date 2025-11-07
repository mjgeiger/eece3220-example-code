/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * Linked stack definition
 *   
 * Stack.h: class definition
 * EXTENDED FOR STACK LABS TO ADD PROTOTYPES FOR 
 *    FUNCTIONS isOrdered AND minToTop
 */


#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

#include "Node.h"

class Stack {
public:
	/*** NEW FUNCTION PROTOTYPES ***/
	bool isOrdered() const;			// Checks if stack in ascending order
	void minToTop();				// Moves min value on stack to top node
	/*** END NEW FUNCTION PROTOTYPES ***/

	Stack();						// Constructor
	~Stack();						// Destructor
	bool empty() const;				// Checks if stack is empty
	void push(const double &val);	// Pushes data on top of stack
	void pop();						// Removes top item from stack
	double getTop();				// Accessor for data in top node
									// User should check that stack
									//   isn't empty before calling
	
	/*** OVERLOADED OPERATORS ***/
	Stack &operator =(const Stack &rhs);
	bool operator ==(const Stack &rhs);

	friend ostream &operator <<(ostream &out, Stack &aStack);

private:
	Node *top;		// Node at top of stack
};

/*** HERE'S WHERE YOU'D DECLARE OPERATOR << IF NOT FRIEND FUNCTION ***/
//ostream &operator <<(ostream &out, Stack &aStack);

#endif STACK_H
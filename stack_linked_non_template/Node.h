/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * Simple Node class that can be used with
 *   any list-based data structure
 *   (stack, queue, linked list)
 * Node.h: class definition
 */

#ifndef NODE_H
#define NODE_H

class Node
{
public:
	Node(double v, Node *p);	// Constructor
	double getVal();			// Accessor for data
	Node *getNext();			// Accessor for next pointer
	void setVal(double v);		// Mutator for data
	void setNext(Node* p);		// Mutator for next pointer
private:
	double val;			// Actual data stored in node
	Node *next;			// Pointer to next node
};

#endif // NODE_H

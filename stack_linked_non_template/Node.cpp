/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * Simple Node class that can be used with
 *   any list-based data structure
 *   (stack, queue, linked list)
 * Node.c: function definitions
 */

#include "Node.h"

// Constructor
Node::Node(double v, Node *p) : val(v), next(p)
{}

// Accessor for value within node
double Node::getVal() {
	return val;
}

// Accessor for address of next node
Node *Node::getNext() {
	return next;
}

// Mutator for data
void Node::setVal(double v) {
	val = v;
}

// Mutator for next pointer
void Node::setNext(Node* p) {
	next = p;
}

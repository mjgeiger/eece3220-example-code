/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 *
 * Header file for in-class queue example
 * Queue class definition for linked queue
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using std::ostream;

// This is a fairly old implementation based on an old
//   textbook in which, rather than creating a class 
//   template, we used a typedef to specify a generic
//   typename "QueueElement" for the data type stored
//   in the queue. Changing the data type then only
//   requires changing one line of code (the typedef)
//   as opposed to changing every mention of the type
//   or writing a full class template
// I've left that implementation here because (1) I'm 
//   just giving you a class definition, not the function
//   definitions, and (2) the important thing is to 
//   focus on the contents of the class, not the type of
//   data stored in it.
typedef double QueueElement;

// Linked queue
class Queue {
public:
	Queue();								// Constructor
	~Queue();								// Destructor
	bool empty() const;						// Returns true if queue empty
	void enqueue(const QueueElement &val);	// Add val to back of queue
	void dequeue();							// Remove head of queue
	QueueElement getFront();				// Read contents of front of queue
private:

	// Queue node
	// Defining the Node class *inside* the Queue class gives you
	//   the benefit of being able to access Node data members
	//   by name in Queue functions. That's why the Node class
	//   contains no member functions--having the ability to 
	//   directly access Node data members removes the need for
	//   functions that read or modify those data.
	// One important note: Node data members must be marked as
	//   public to be accessible in Queue functions. Node data
	//   members won't be accessible outside Queue functions
	//   because the class is defined in the private region of
	//   the Queue class definition
	class Node {			
	public:
		QueueElement data;
		Node *next;
	};
	Node *front, *back;		// Addresses of front/back of queue
};

/* 
	Example enqueue function--partially written (and commented out)
    to demonstrate how Queue functions are able to access Node
	data members, given the way the Node class is defined
void Queue::enqueue(const QueueElement& val) {
	Node* newNode;
	
	//Actually write code to allocate a new node here ...
	
	back->next = newNode;
}
*/

#endif   // QUEUE_H
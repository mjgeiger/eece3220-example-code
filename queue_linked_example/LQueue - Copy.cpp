/*
 * M. Geiger
 * EECE.3220: Data Structures
 *
 * Source file for in-class queue example
 * Queue function definitions for array-based queue
 *
 * ASSUMPTIONS:
 *   Each index (front/back) = position to access next
 *   Wasting one spot in array (so full/empty depends
 *     on positions)
 */

#include <iostream>
using std::cout;

#include "LQueue.h"

// BEGIN EXAM 3 FUNCTIONS
void Queue::display(ostream &out) {
	Node *p = front;
	while (p != NULL) {
		out << p->data << " ";
		p = p->next;
	}
	cout << "\n";
}

bool Queue::isPriorityQ() {
	Node *p;
	QueueElement val;

	// Return false if empty
	if (empty())
		return false;

	p = front->next;
	val = front->data;

	while (p != NULL) {
		if (val < p->data)
			return false;

		val = p->data;
		p = p->next;
	}

	// If you get through whole queue, must be ordered
	return true;

}
// END EXAM 3 FUNCTIONS

// Constructor
// Default value for maxSize = 1024
Queue::Queue() : front(NULL), back(NULL)
{}

// Destructor--traverse queue and delete all nodes
Queue::~Queue() {
	while (!empty())
		dequeue();

	/* Inefficient version that shows details of traversal
	Node *prev, *cur;	// prev = address of node to delete
						// cur = node after prev

	// Only need to delete from non-empty queue
	if (!empty()) {
		prev = NULL;
		cur = front;

		// Traverse all nodes and delete them
		while (cur != NULL) {

			// 1. Make both pointers refer to same node
			prev = cur;

			// 2. Move cur ahead one node (before you delete that node)
			cur = cur->next;

			// 3. Delete prev node
			delete prev;
		}
	}
	*/
}

// Returns true if queue empty
bool Queue::empty() const {
	return (front == NULL);
}

// Add val to back of queue
void Queue::enqueue(const QueueElement &val) {
	// Allocate new node
	Node *newNode;
	newNode = new Node;
	newNode->data = val;
	newNode->next = NULL;

	// SPECIAL CASE WHEN GOING FROM 0 --> 1 NODE
	if (empty())
		front = newNode;

	// Otherwise, old "back" node points to new node
	else
		back->next = newNode;

	// "back" pointer points to new node
	back = newNode;

}

// Remove head of queue
void Queue::dequeue() {
	if (!empty()) {
		// ptr = address of front node
		Node *ptr = front;

		// "front" ptr = address of second node
		front = ptr->next;
		if (front == NULL)		// Removing last node
			back = NULL;

		// delete old front node (ptr = address of that node)
		delete ptr;
	}

	else
		cout << "Tried to dequeue() from an empty queue\n";
}

// Read contents of front of queue
QueueElement Queue::getFront() {
	if (!empty())
		return front->data;
	else {
		cout << "ERROR: Queue empty\n";
		// Don't really need full node ... 
		// Node temp;
		QueueElement tempData = 0;
		return tempData;
	}
}
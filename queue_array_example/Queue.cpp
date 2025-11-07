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

#include "Queue.h"

// Constructor
// Default value for maxSize = 1024
Queue::Queue(unsigned maxSize)
{
}

// Destructor
Queue::~Queue() {
}

// Returns true if queue empty
bool Queue::empty() const {
}

// Add val to back of queue
void Queue::enqueue(const QueueElement &val) {
}

// Remove head of queue
void Queue::dequeue() {
}

// Read contents of front of queue
QueueElement Queue::getFront() {
}
































// EXAM 3 FUNCTIONS
unsigned Queue::numVals() {
	if (back >= front)
		return back - front;
	else
		return (back + cap) - front;
}

void Queue::display(ostream& out) {
	int i;

	for (i = front; i != back; i = (i + 1) % cap)
		out << list[i] << ' ';
	out << '\n';
}
// END EXAM 3 FUNCTIONS
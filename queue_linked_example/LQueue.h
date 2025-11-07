/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 *
 * Header file for in-class queue example
 * Queue class definition for linked queue
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

#include <iostream>
using std::ostream;
using std::cout;

// Linked queue
template <typename T>
class Queue {
public:
	Queue();						// Constructor
	~Queue();						// Destructor
	bool empty() const;				// Returns true if queue empty
	void enqueue(const T &val);		// Add val to back of queue
	void dequeue();					// Remove head of queue
	T getFront() const;				// Read contents of front of queue
private:
	Node<T> *front, *back;		// Addresses of front/back of queue
};

// Constructor
template <typename T>
Queue<T>::Queue()
{}

// Destructor--traverse queue and delete all nodes
template <typename T>
Queue<T>::~Queue() {
}

// Returns true if queue empty
template <typename T>
bool Queue<T>::empty() const {
}

// Add val to back of queue
template <typename T>
void Queue<T>::enqueue(const T& val) {
}

// Remove head of queue
template <typename T>
void Queue<T>::dequeue() {
}

// Read contents of front of queue
template <typename T>
T Queue<T>::getFront() const {
}

#endif   // QUEUE_H
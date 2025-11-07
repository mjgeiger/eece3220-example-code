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
template <class T>
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
template <class T>
Queue<T>::Queue() : front(nullptr), back(nullptr)
{}

// Destructor--traverse queue and delete all nodes
template <class T>
Queue<T>::~Queue() {
	while (!empty())
		dequeue();
}

// Returns true if queue empty
template <class T>
bool Queue<T>::empty() const {
	return (back == nullptr);	// Could also use (front == nullptr)
}

// Add val to back of queue
template <class T>
void Queue<T>::enqueue(const T& val) {
	// 1. Allocate new node
	// 2. New node --> successor
	// New node is last one in queue --> no successor
	Node<T>* newNode = new Node<T>(val, nullptr);

	// 3. Predecessor --> new node
	// 3a. Special case: empty queue has no nodes
	if (front == nullptr)
		front = newNode;

	// 3b. Typical case: at least one node in queue
	else
		back->setNext(newNode);

	// Make new node back of queue
	back = newNode;
}

// Remove head of queue
template <class T>
void Queue<T>::dequeue() {
	
	if (empty())
		cout << "ERROR: Queue empty\n";

	else {

		// 1. Copy address of node to delete
		Node<T>* p = front;

		// 2. Unlink node (front points past node)
		front = front->getNext();

		// Special case: removing only node in queue
		if (front == nullptr)
			back = nullptr;

		// 3. Delete node
		delete p;
	}
}

// Read contents of front of queue
template <class T>
T Queue<T>::getFront() const {
	return front->getVal();
}

#endif   // QUEUE_H
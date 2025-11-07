/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * Linked list definition
 *
 * LList_template.h: class definition for linked list as template
 */

#ifndef LLIST_H
#define LLIST_H

#include <iostream>
using std::ostream;

template <class T>
class LList {
public:
	LList();				 // Default constructor
	~LList();				 // Destructor
	bool empty();			 // True if list is empty
	void insert(T v);		 // Add new value to list
	void remove(T v);		 // Remove node with v
private:

	/****************************************************************
	  Slightly different setup than we've seen before, as Node class
	    is defined *inside* LList class.
      Benefits:
	    By making "Node" a member of LList, LList functions can 
		  directly refer to Node data members val and next. No
		  need to write/call accessor functions for Node, so
		  fewer files in solution + no function call overhead on
		  simple data accesses. Node data members are "public" to
		  LList functions but "private" to outside world.
	  Downside:
	    This implementation of Node can *only* be used inside LList.
		  If you want Node objects in other classes, have to redefine.
	****************************************************************/
	class Node {
	public:
		T val;				// Value in each node
		Node<T> *next;		// Pointer to next node
	};

	Node<T> *first;	// Pointer to first node
};

template <class T>
LList<T>::LList() : first(nullptr)
{}

// Destructor
template <class T>
LList<T>::~LList() {
	while (first != nullptr)
		remove(first->val);
}

// True if list is empty
template <class T>
bool LList<T>::empty() {
	return (first == nullptr);
}

// Add new value to list
template <class T>
void LList<T>::insert(T v) {
	// General algorithm for adding new node:
	// 1. Allocate new node
	Node<T>* newNode = new Node<T>;
	newNode->val = v;

	// 2. Find correct spot for new node
	//   (assume ascending order)
	Node<T> *curr, *prev;
	prev = nullptr;
	curr = first;

	while (curr != nullptr && v > curr->val) {
		prev = curr;
		curr = curr->next;
	}

	// 3. Link new node into list
	// 3a. Special case: new node is beginning of list
	if (prev == nullptr)
		first = newNode;

	else
		prev->next = newNode;

	// new node points to successor
	newNode->next = curr;
}

// Remove node with v	
template <class T>
void LList<T>::remove(T v) {
	
	// 1. Find node to remove
	Node<T> *curr, *prev;
	prev = nullptr;
	curr = first;

	while (curr != nullptr && v != curr->val) {
		prev = curr;
		curr = curr->next;
	}

	// Remove node from list if we found it
	if (curr != nullptr) {
		// 2. Unlink node from list
		// 2a. Special case: removing first node
		if (prev == nullptr)
			first = curr->next;
		else
			prev->next = curr->next;

		// 3. Delete node
		delete curr;
	}
}
#endif
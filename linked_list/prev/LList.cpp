/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * Linked list definition
 *
 * LList.cpp: function definitions
 */
 
#include "LList.h"
using namespace std;

/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * Linked list definition
 *
 * LList_empty.cpp: file in which
 *   students can complete
 *   function definitions
 */

#include "LList.h"
using namespace std;

// Default constructor
LList::LList() : first(nullptr)
{}

// Destructor
LList::~LList() {
	while (!empty())
		remove(first->val);
}

// True if list is empty
bool LList::empty() {
	return (first == nullptr);
}

// Add new value to list
void LList::insert(int v) {

	// 1. Allocate new node
	Node* newNode = new Node;
	newNode->val = v;
	newNode->next = nullptr;

	// 2. Link new node in
	// If we want to keep list in ascending order
	//    first, find right place for it
	// Need two node pointers for traversal
	Node* curr = first;
	Node* prev = nullptr;

	while (curr != nullptr) {
		if (curr->val > v)	// First greater value = successor
			break;			// Exit loop

		prev = curr;
		curr = curr->next;
	}

	// 2a. Make new node's predecessor point to it
	// prev == nullptr --> new node is first node
	if (prev == nullptr)
		first = newNode;

	// Otherwise new node is somewhere in middle of list
	else
		prev->next = newNode;

	// 2b. Make new node point to successor
	newNode->next = curr;
}

// Remove node with v	
void LList::remove(int v) {

	// Search for node to remove
	Node* ptr = first;
	Node* prev = nullptr;
	while (ptr != nullptr) {
		if (ptr->val == v)		// Found a match
			break;

		prev = ptr;
		ptr = ptr->next;
	}

	// If that node is in the list,
	if (ptr != nullptr) {

		// 1. Copy node address
		// Just kidding--ptr already holds that address

		// 2. Unlink node to remove
		// If removing first node, update first
		if (ptr == first)
			first = first->next;

		// Otherwise, update predecessor
		else
			prev->next = ptr->next;

		// 3. Delete it
		delete ptr;
	}
}

// Display contents of list
void LList::display(ostream& out) {

}
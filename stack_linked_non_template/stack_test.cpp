/* 
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * Sample program for testing linked stack objects
 *
 * This program defines the stack as a series of linked
 *   Node objects--there's no actual stack object. 
 *   Therefore, the work of managing the different nodes
 *   is done outside of any member functions. The Node
 *   class itself simply contains one data item and a 
 *   pointer to the next node.
 * We developed this program to demonstrate how to work
 *   with a collection of nodes as a stack, then copied
 *   code from this program into member functions to 
 *   build a linked stack class.
 */

#include <iostream>
#include <string>
using namespace std;

#include "Node.h"

int main() {
	string cmd;				// Input command
	double data;			// Data to be pushed on stack
	Node *top = nullptr;	// Pointer to top of stack
	Node *temp;				// Used for pop operation
	
	do {
		cout << "Enter command: ";
		cin >> cmd;

		// push: add data to top of stack
		if (cmd == "push") {
			cin >> data;
			cout << "Pushing " << data << " to stack ...\n";
			
			// Arguments to constructor are:
			//   1. Data to store in node
			//   2. Address for next pointer
			// Want your new node to point to the old "top" node,
			//   then replace it as top of stack
			top = new Node(data, top);
		}

		// pop: remove top item from stack
		else if (cmd == "pop") {
			cout << "Popping top of stack ... \n";

			// Can't pop from an empty stack
			if (top == nullptr)
				cout << " ... just kidding--stack is empty\n";

			// To change top node and still have address of
			//   node to pop off stack, must use temp pointer
			//   to store top node address, then move "top"
			//   to second node
			else {
				temp = top;
				top = top->getNext();
				delete temp;
			}
		}

		// top: display item at top of stack (without removing)
		else if (cmd == "top") {
			if (top == nullptr)
				cout << "Stack is empty\n";
			else
				cout << top->getVal() << '\n';
		}

		// print: display entire stack state, starting at top
		//  Example of linked data structure traversal
		else if (cmd == "print") {
			cout << "Printing stack state ... \n";

			if (top == nullptr)  
				cout << "Stack is empty\n";
			else {

				// General traversal algorithm:
				// 1. pointer = first node address
				// 2. while (pointer != nullptr)
				//     a. Do something with node (print, search, etc)
				//     b. pointer = address of next node
				temp = top;
				while (temp != nullptr) {
					cout << temp->getVal() << '\n';
					temp = temp->getNext();
				}
			}
		}

		// Any other command that isn't "exit": invalid command
		else if (cmd != "exit")
			cout << "Invalid command " << cmd << '\n';

	} while (cmd != "exit");	// exit: ends loop & program

	cout << "Exiting program ... \n";

	// Clean up: delete all nodes in stack
	while (top != nullptr) {
		temp = top;
		top = top->getNext();
		delete temp;
	}

	return 0;
}


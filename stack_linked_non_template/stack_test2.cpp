/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * Sample program for testing linked stack objects
 *
 * This program works with a linked Stack class,
 *   although it could work with any of our Stack
 *   implementations if we added overloaded operators 
 *   to the array-based or vector-based stacks.
 */

#include <iostream>
#include <string>
using namespace std;

#include "Stack.h"

int main() {
	Stack s1, s2;		// Stack objects
	string cmd;			// Input command
	double data;		// Data to be pushed on stack

	do {
		cout << "Enter command: ";
		cin >> cmd;

		// push: add data to top of stack
		if (cmd == "push") {
			cin >> data;
			cout << "Pushing " << data << " to stack ...\n";
			s1.push(data);
		}

		// pop: remove top item from stack
		else if (cmd == "pop") {
			cout << "Popping top of stack ... \n";

			// Can't pop from an empty stack
			if (s1.empty())
				cout << " ... just kidding--stack is empty\n";

			else
				s1.pop();
		}

		// top: display item at top of stack (without removing)
		else if (cmd == "top") {
			if (!s1.empty())
				cout << "Top of stack = " << s1.getTop() << '\n';
			else
				cout << "Stack is empty\n";
		}

		// print: display entire stack state, starting at top
		//  Example of linked data structure traversal
		else if (cmd == "print") {
			cout << "Printing stack state ... \n";
			if (s1.empty())
				cout << "Stack is empty\n";
			else {
				cout << s1;
			}
		}

		/***** ADDITIONAL COMMANDS TO TEST WITH LINKED STACK *****/
		// copy: copy stack s1 to s2
		//   Tests overloaded assignment
		else if (cmd == "copy") {
			cout << "Copying s1 to second stack, s2 ... \n";
			s2 = s1;
			s2.operator=(s1);
		}

		// compare: compare current states of s1 and s2
		//   Tests overloaded ==
		else if (cmd == "compare") {
			cout << "Comparing s1 to s2 ... \n";
			cout << ((s1 == s2) ? "s1 == s2\n" : "s1 != s2\n");
		}
		/***** END ADDITIONAL COMMANDS TO TEST WITH LINKED STACK *****/
	
		// Any other command that isn't "exit": invalid command
		else if (cmd != "exit")
			cout << "Invalid command " << cmd << '\n';

	} while (cmd != "exit");	// exit: ends loop & program

	cout << "Exiting program ... \n";
	return 0;

	// No need to "clean up" stack before exit--destructor does that
}
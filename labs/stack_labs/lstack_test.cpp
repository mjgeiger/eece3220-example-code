/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 *
 * lstack_test.cpp: main program to test
 *    isOrdered AND minToTop functions
 *    for lab assignments
 */

#include <iostream>
#include "LStack.h"

int main() {
	Stack<int> S1;

	int part;

	cout << "Which part? ";
	cin >> part;

	switch (part) {
	case 1:				// Testing isOrdered()

		cout << "Initially, S1:\n" << S1;
		cout << "Stack " << (S1.isOrdered() ? "is" : "is not")
			<< " in order\n\n";

		S1.push(22);
		S1.push(20);
		S1.push(15);
		S1.push(11);

		cout << "Now, S1:\n" << S1;
		cout << "Stack " << (S1.isOrdered() ? "is" : "is not")
			<< " in order\n\n";

		S1.pop();
		S1.pop();
		S1.pop();
		S1.push(23);
		S1.push(22);
		S1.push(21);
		S1.push(20);

		cout << "Finally, S1:\n" << S1;
		cout << "Stack " << (S1.isOrdered() ? "is" : "is not")
			<< " in order\n\n";

		break;
	case 2:
		cout << "Initially, S1:\n" << S1;
		S1.minToTop();
		cout << "After minToTop(), S1:\n" << S1 << '\n';

		S1.push(32);
		S1.push(20);
		S1.push(45);
		S1.push(99);

		cout << "Now, S1:\n" << S1;
		S1.minToTop();
		cout << "After minToTop(), S1:\n" << S1 << '\n';

		S1.push(5);
		
		cout << "Then, S1:\n" << S1;
		S1.minToTop();
		cout << "After minToTop(), S1:\n" << S1 << '\n';

		S1.pop();
		S1.pop();

		cout << "Finally, S1:\n" << S1;
		S1.minToTop();
		cout << "After minToTop(), S1:\n" << S1 << '\n';


		break;
	}

	return 0;
}
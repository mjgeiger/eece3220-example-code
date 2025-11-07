/*
* EECE.3220: Data Structures
* Instructor: M. Geiger
* Program to review conditionals/loops and introduce C++ basics
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	char cmd = 'c';	// User input command
	int n;			// User input value
	int i;			// Loop index
	int result;		// Result for factorial & exponential

	do {
		// Prompt for/read inputs (not checking formatting errors)
		cout << "Enter command & integer: ";
		cin >> cmd >> n;
		cout << "cmd: " << cmd << ", n: " << n << endl;

		switch (cmd) {
		case 'F': case 'f':			// Compute n!
			result = 1;
			for (i = n; i > 1; --i) // --i --> i = i - 1
				result *= i;	// result = result * i

			// endl is effectively same as '\n'
			cout << "n! = " << result << endl;

			break;

		case 'P': case 'p':			// Compute 2^n
			result = 1;
			for (i = 0; i < n; ++i)
				result *= 2;	// result = result * 2;

			cout << "2^n = " << result << endl;

			break;

		default:
			if (cmd != 'X' && cmd != 'x')
				cout << "Invalid command " << cmd << endl;
		}
	} while (cmd != 'X' && cmd != 'x');

	return 0;
}
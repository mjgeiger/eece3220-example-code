/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * Basic C++ input/output example
 * Lecture slides assume input:
 *  1 2
 *  3.4 5
 *  2 3 3.4 7
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
	int i, j;
	double x, y;

	cout << "Enter first four inputs: ";
	cin >> i >> j >> x >> y;
	cout << "First output " << endl;
	cout << i << ',' << j << ',' << x
		<< ',' << y << endl;
	cin >> x >> y >> i >> j;
	cout << "Second output" << endl;
	cout << i << ',' << j << ',' << x
		<< ',' << y << endl;
	return 0;
}

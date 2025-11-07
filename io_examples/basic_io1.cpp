/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * Basic C++ input/output example
 * Lecture slides assume input: 1 2 4.5
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
	int i, j;
	double x;
	char c;
	cin >> i >> j;
	cin >> x >> c;
	cout << "output \n";
	cout << i << ',' << j << '\n'
		<< x << "cm" << endl
		<< "Input char: " << c << endl;
	return 0;
}

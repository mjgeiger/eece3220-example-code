/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * Basic C++ input/output example
 */

#include <iostream>
using std::cout;
using std::endl;
using std::fixed;

#include <iomanip>
using std::setprecision;

#include <cmath> 
using std::sqrt; // sqrt prototype

void chgPrecision() {
	cout << setprecision(10);
}

int main()
{
	double root2 = sqrt(2.0); // calc square root of 2
	int places; // precision, vary from 0-9

	cout << "Square root of 2 with precisions 0-9."
		<< endl;

	cout << fixed; // use fixed point format (not sci. not)

	// set precision for each digit, then show square root
	for (places = 0; places <= 9; places++)
		cout << setprecision(places) << root2 << endl;

	return 0;
}



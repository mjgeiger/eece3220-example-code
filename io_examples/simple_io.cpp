/*
*	EECE.3220: Data Structures
*	Instructor: M. Geiger
*
*	Basic input/output example
*/

#include <iostream>
using namespace std;

int main() {

	// Variables for this program
	int x;
	double y;
	char c1;

	// Basic input and output statements
	cout << "Enter 1 int, 1 double, 1 char: ";
	cin >> x >> y >> c1;

	/* Output statements that print 
	    variable and expression values */
	cout << "x = " << x 
		<< ", y = " << y 
		<< ", sum = " << x + y << '\n';
	cout << "c1 = " << c1 << endl;
	
	return 0;
}
/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * Basic function examples to illustrate
 *   different methods of argument passing
 */

#include <iostream>
using namespace std;

// Prototypes--typically in .h
int f1();
double f2(int x, int y);		// Pass by value
void f3(int* p1, int* p2);		// Pass by pointer (or address)
void f4(int& r1, int& r2);		// Pass by reference

int c;			/* Global variable--not recommended!
					My experience is that programs using
					global variables are difficult to debug
					as they grow in complexity--since it's
					hard to track which function changes variable */

int main() {
	int retval;
	int a = 10, b = 5;
	double retval2;

	// Example of basic function with return value
	retval = f1();		// retval = 26 (assuming user enters 32 20)
	cout << "Return value = " << retval << endl;

	retval2 = f2(a, b);		// Example of pass by value
							//  x = a = 10, y = b = 5

	f3(&a, &b);				// Example of pass by address

	f4(a, b);				// Example of pass by reference
							//  In function r1 = a, r2 = b

	return 0;
}

// Function definitions--typically in separate .cpp file
int f1() {
	int v1, v2;
	cout << "Enter two ints: ";
	cin >> v1 >> v2;
	return (v1 + v2) / 2;
}

double f2(int x, int y) {
	x++;
	y--;

	cout << "x = " << x << ", y = " << y << endl;

	return (x + y) / 2.0;
}

void f3(int* p1, int* p2) {		// int * == pointer to int
	*p1 = *p1 + 2;				// *p1 --> "value to which p1 points"
	*p2 = *p2 - 3;				// *p2 --> "value to which p2 points"
}

void f4(int& r1, int& r2) {		// r1 = alias (another name) for first argument
								// r2 = alias for second argument
	r1 = r1 + 5;
	r2 = r2 + 10;
}
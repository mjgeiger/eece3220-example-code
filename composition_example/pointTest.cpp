/*
	M. Geiger
	EECE.3220: Data Structures
	Main program to test Point class
*/

#include <iostream>
using namespace std;

#include "Point.h"

int main() {
	Point p1, p2(9, 15);	// Modified p2 declaration to use parameterized constructor
	double newX1, newY1;

	// Print initial values in each Point
	cout << "Initial state of p1: ";
	p1.printPoint(cout);
	cout << "\nInitial state of p2: ";
	p2.printPoint(cout);

	// Read in new coordinates and assign them to points
	cout << "\n\nEnter new x, y coordinates for p1: ";
	cin >> newX1 >> newY1;
	p1.setX(newX1);
	p1.setY(newY1);
	cout << "p2 coordinates = p1 coordinates + 10 ... \n\n";
	p2.setX( p1.getX() + 10 );
	p2.setY( p1.getY() + 10 );

	// Print updated points
	cout << "New state of p1: ";
	p1.printPoint(cout);
	cout << "\nNew state of p2: ";
	p2.printPoint(cout);
	cout << endl;

	return 0;
}
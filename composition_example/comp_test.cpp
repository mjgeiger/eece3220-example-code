/*
	M. Geiger
	EECE.3220: Data Structures
	Main program for in-class composition example
*/

#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ofstream;

#include "Point.h"
#include "Rectangle.h"

void changePoint(Point& p, double newX, double newY) {
	p.setX(newX);
	p.setY(newY);
}

int main() {
	Rectangle r1, r2(5, 10, 3, 4);
	Point p1, p2(-1, 1);
	Point p3;

	cout << "P1: ";
	p1.printPoint(cout);

	cout << "\nP2: ";
	p2.printPoint(cout);

	changePoint(p2, 100, -100);

	cout << "\nP2 now: ";
	p2.printPoint(cout);

	cout << "\nR1 origin: ";
	// How are we going to print origin of r1?
	p3 = r1.getOrigin();		// Here's one way to print the origin
	p3.printPoint(cout);

	cout << "\nR2 origin: ";
	// How are we going to print origin of r2? Here's another way ...
	r2.getOrigin().printPoint(cout);

	// Assigning new origin
	r1.setOrigin(p2);
	cout << "\nNew R1 origin: ";
	// One more origin to print ...
	r1.getOrigin().printPoint(cout);

	return 0;
}
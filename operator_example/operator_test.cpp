/*
	M. Geiger
	EECE.3220: Data Structures
	Main program for in-class operator overloading example
*/

#include <iostream>
using std::cout;
using std::endl;

#include "Point.h"

int main() {
	Point p1, p2(-1, 1);		// p1 --> default constructor, p2 --> parameterized constructor
	Point p3;					// p3 --> default constructor

	p1 = p2;		// p1.operator=(p2);
	
	p1 = p2 = p3;	// Basically 2 statements:
					//  p2 = p3;
					//  p1 = p2;	Only works if first = 
					//              returns p2

	cout << p1;
	cout << "P1: " << p1;	// cout << "P1: ", cout << p1
	cout << "\nP2: " << p2;

	p3.setX(-1);
	p3.setY(1);

	if (p2 == p3)		// p2.operator ==(p3)
		cout << "p2 p3 equal\n";
	else
		cout << "p2, p3 not equal\n";

	p1 = p2;		// p1.operator=(p2);

	cout << "New p1 = " << p1 << '\n';

	return 0;
}

// Could use for p1 + p2
Point operator+(Point& lhs, Point& rhs) {
	Point temp;
	temp.setX(lhs.getX() + rhs.getX());
	temp.setY(lhs.getY() + rhs.getY());
	return temp;
}
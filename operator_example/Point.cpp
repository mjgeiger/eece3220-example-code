/*
	M. Geiger
	EECE.3220: Data Structures
	Point example code for in-class operator overloading example
	  (Modified version of composition example)
	Function definitions
*/

#include "Point.h"

// Default constructor
Point::Point() : xCoord(0), yCoord(0) {}

// Parameterized constructor
Point::Point(double X, double Y) : xCoord(X), yCoord(Y) {}

// "Set" functions
void Point::setX(double newX) {
	xCoord = newX;
}

void Point::setY(double newY) {
	yCoord = newY;
}

// "Get" functions
double Point::getX() const {
	return xCoord;
}

double Point::getY() const {
	return yCoord;
}


// OVERLOADED OPERATORS
// Example usage: if (p1 == p2) { }
bool Point::operator ==(const Point& rhs) {
	return (xCoord == rhs.xCoord && yCoord == rhs.yCoord);

	/*	ABOVE CODE ESSENTIALLY DOES THE FOLLOWING:
	if (xCoord == rhs.xCoord && yCoord == rhs.yCoord)
		return true;
	else
		return false;
	*/
}

// Example usage:  cout << p1;   or
//   cout << p1 << " " << p2;
// Example output: (2, 3) or (1.2, 3.456)
ostream& operator <<(ostream& out, const Point& p) {
	out << '(' << p.xCoord << ", " << p.yCoord << ')';
	return out;
}

// EXTRA OVERLOADED OPERATORS
// Addition: p1 + p2 = 
//			(p1.xCoord + p2.xCoord, p1.yCoord + p2.yCoord)
Point Point::operator+(const Point& rhs) {
	Point temp;
	temp.xCoord = xCoord + rhs.xCoord;
	temp.yCoord = yCoord + rhs.yCoord;
	return temp;
}


// Less than: p1 < p2 if p1.xCoord < p2.xCoord and 
//						 p1.yCoord < p2.yCoord
bool Point::operator<(const Point& rhs) {
	return (xCoord < rhs.xCoord && yCoord < rhs.yCoord);
}

// Input: assume point entered in form (x, y)
//        and account for *all* input chars
istream& operator>>(istream& in, Point& p) {
	in.ignore(1);		// Skips (
	in >> p.xCoord;
	in.ignore(1);		// Skips ,
	in >> p.yCoord;
	in.ignore(1);		// Skips )
	return in;
}
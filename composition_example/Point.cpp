/*
	M. Geiger
	EECE.3220: Data Structures
	Point example code for in-class composition example
	Function definitions
*/

#include "Point.h"

// Default constructor
Point::Point() : xCoord(0), yCoord(0)
{}

// Parameterized constructor
Point::Point(double newX, double newY) : 
	xCoord(newX), yCoord(newY)
{}

// "Set" functions
void Point::setX(double newX) {
	xCoord = newX;
}

void Point::setY(double newY) {
	yCoord = newY;
}

// "Get" functions
double Point::getX() {
	return xCoord;
}

double Point::getY() {
	return yCoord;
}

// Output Point as (xCoord, yCoord)
void Point::printPoint(ostream &out) {
	out << '(' << xCoord << ", " << yCoord << ')';
}
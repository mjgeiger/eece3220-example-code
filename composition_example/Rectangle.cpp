/*
	M. Geiger
	EECE.3220: Data Structures
	Rectangle example code for in-class composition example
	Function definitions
*/

#include "Rectangle.h"

// Default constructor
//    height = width = 1, origin = (0, 0)
Rectangle::Rectangle() : height(1), width(1), origin(0, 0)
{}

// Parameterized constructor
Rectangle::Rectangle(double h, double w, double x, double y)
	: height(h), width(w), origin(x, y)
{}
	
// "Get" functions
double Rectangle::getHeight() {
	return height;
}

double Rectangle::getWidth() {
	return width;
}

Point Rectangle::getOrigin() {
	return origin;
}

// "Set" functions
void Rectangle::setHeight(double h) {
	height = h;
}

void Rectangle::setWidth(double w) {
	width = w;
}

void Rectangle::setOrigin(double x, double y) {
	// Can't write: origin.xCoord = x;
	origin.setX(x);
	origin.setY(y);
}

void Rectangle::setOrigin(Point p) {
	origin = p;
}
	
// Return area of rectangle
double Rectangle::area() {
	return height * width;
}
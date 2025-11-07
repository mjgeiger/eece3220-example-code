/*
	M. Geiger
	EECE.3220: Data Structures
	Rectangle example code for in-class composition example
	Class definition
*/

#ifndef Rectangle_h
#define Rectangle_h

#include "Point.h"

class Rectangle {
public:
	Rectangle();						// Default constructor
	Rectangle(double h, double w,		// Parameterized const.
		double x, double y);
	double getHeight();					// Return height
	double getWidth();					// Return width
	Point getOrigin();					// Return origin
	void setHeight(double h);			// Change height
	void setWidth(double w);			// Change width
	void setOrigin(double x, double y);	// Change origin (using separate x, y)
	void setOrigin(Point p);			// Change origin
	double area();						// Return area of rectangle
private:
	double width;
	double height;
	Point origin;	// Lower left corner
};


#endif
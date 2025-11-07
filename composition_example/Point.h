/* 
	M. Geiger
	EECE.3220: Data Structures
	Point example code for in-class composition example
	Class definition
*/

#ifndef Point_h		// Header guard
#define Point_h
	
#include <iostream>	// Necessary for printPoint prototype
using std::ostream;	//  ... but it doesn't work without
					//  indicating what part of <iostream>
					//  we're using

class Point {
public:
	Point();							// Default constructor (added Lec. 2.2)
	Point(double newX, double newY);	// Parameterized constructor (added Lec. 2.2)
	void setX(double newX);			// Set X coordinate
	void setY(double newY);			// Set Y coordinate
	double getX();					// Returns X coordinate
	double getY();					// Returns Y coordinate
	void printPoint(ostream &out);	// Output Point as 
									//  (xCoord, yCoord)
private:
	double xCoord;		// X coordinate
	double yCoord;		// Y coordinate
};


#endif
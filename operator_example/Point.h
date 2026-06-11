/* 
	M. Geiger
	EECE.3220: Data Structures
	Point example code for in-class operator overloading example
	  (Modified version of composition example)
	Class definition
*/

#ifndef Point_h		// Header guard
#define Point_h
	
#include <iostream>	// Necessary for printPoint prototype
using std::ostream;	//  ... but it doesn't work without
					//  indicating what part of <iostream>
					//  we're using
using std::istream;

class Point {
public:
	Point();						// Default constructor
	Point(double X, double Y);		// Parameterized constructor
	void setX(double newX);			// Set X coordinate
	void setY(double newY);			// Set Y coordinate
	double getX() const;					// Returns X coordinate
	double getY() const;					// Returns Y coordinate

	// OVERLOADED OPERATORS
	/* 2/17/26: Stopped using pointless operator= function; will
		cover fundamentals of assignment when actually necessary
		(Stack class)
	Point& operator =(const Point &rhs);	// Assignment
											// e.g., p1 = p2; --> p1.operator=(p2);
	*/
	bool operator ==(const Point &rhs);		// Equality

	friend ostream& operator <<(ostream& out, const Point& p);	// Output operator
	
	// ADDITIONAL OPERATORS
	Point operator+(const Point& rhs);
	bool operator<(const Point& rhs);
	friend istream& operator>>(istream& in, Point& p);

private:
	double xCoord;		// X coordinate
	double yCoord;		// Y coordinate
};

#endif
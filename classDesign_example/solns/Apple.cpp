/*
* EECE.3220: Data Structures
* Instructor: M. Geiger
* 9/21/2021
* Class design example
*
* Apple.cpp: Apple function definitions
*/

#include "Apple.h"

// Default constructor
Apple::Apple() : type(""), month(1) {}

// Parameterized constructor
Apple::Apple(string t, unsigned m) : type(t), month(m) {}

// Sets type and month data members
void Apple::setApple(string t, unsigned m) {
	type = t;
	month = m;
}

// Prints information about apple
void Apple::display(ostream& out) {
	out << "Type: " << type << '\n';
	out << "Month available: " << month << '\n';
}

// Returns true if apple is available during given month
bool Apple::isAvailable(unsigned m) {
	if (month == m)
		return true;
	else
		return false;
}

// Return apple type
string Apple::getType() {
	return type;
}
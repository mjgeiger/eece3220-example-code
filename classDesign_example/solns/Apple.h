/*
* EECE.3220: Data Structures
* Instructor: M. Geiger
* 9/21/2021
* Class design example
*
* Apple.h: Apple class definition
*/

#ifndef APPLE_H
#define APPLE_H

#include <string>
#include <iostream>

using namespace std;

class Apple
{
public:
	Apple();
	Apple(string t, unsigned m);
	void setApple(string t, unsigned m);	// Sets type and month data members
	void display(ostream& out);				// Prints information about apple
	bool isAvailable(unsigned m);			// Returns true if apple is available during given month
	string getType();						// Return apple type
private:
	string type;		// Type of apple
	unsigned month;		// Month in which apple is available to pick
};

#endif		// APPLE_H
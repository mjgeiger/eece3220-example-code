/*
* EECE.3220: Data Structures
* Instructor: M. Geiger
* 9/21/2021
* Class design example
*
* Orchard.h: Orchard class definition
*/

#ifndef ORCHARD_H
#define ORCHARD_H

#include <string>
#include <iostream>
#include "Apple.h"

using namespace std;

class Orchard
{
public:
	Orchard();
	void setOrchard(string n, unsigned o, unsigned c);	// Set name, open, & closing times
	bool addTrees(unsigned n, string t, unsigned m);	// Add n trees of type t available in month m
														//   Return true if successful, false if no space
	void display(ostream& out);							// Print information about orchard
	void allAvail(ostream& out, unsigned m);			// List all available apples during month m
	unsigned totalTrees();								// Counts total number of trees
private:
	string name;			// Orchard name
	Apple apples[10];		// List of up to 10 types of apples in orchard
	unsigned nTrees[10];	// Number of each type of apple tree
							// Corresponds to apples[] array, so trees[0] is number
							//    of trees of apple type in apples[0]
	unsigned types;			// # of different apple types actually present
	unsigned oTime, cTime;	// Open and closing times (hours only)
};

#endif		// ORCHARD_H
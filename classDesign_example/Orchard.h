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
	Orchard(string n, unsigned s, unsigned e);
	string getName();
	unsigned getStart();
	unsigned getEnd();
	unsigned getNVars();
	unsigned getTotTrees();	// added 2/6

	// Two options for writing file info into Orchard
	// OPTION 1: 1 function to write name, start/end,
	//           separate function to add each Apple variety
	void setOrchard(string n, unsigned s, unsigned e);
	bool addApple(string an, unsigned m, unsigned nt);

	// OPTION 2: Take in file name and have one function
	//           to read all Orchard info out of file
	void readFile(string fn);

	// Print all orchard info
	void display(ostream& out);

	// Check/print what apples are available in given month
	void printAvailable(ostream& out, unsigned m);
private:
	string name;			// Orchard name
	unsigned start, end;	// Open and close times
	Apple vars[10];			// Array of all apple varieties
	unsigned nvars;			// # of varieties in orchard
	unsigned totalTrees;	// Total # trees in orchard (added 2/6)
};

#endif		// ORCHARD_H
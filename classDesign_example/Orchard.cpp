/*
* EECE.3220: Data Structures
* Instructor: M. Geiger
* 9/21/2021
* Class design example
*
* Orchard.cpp: Orchard function definitions
*/

#include "Orchard.h"
#include <fstream>

using namespace std;

Orchard::Orchard() : 
	name("NotARealOrchard"), start(0), end(0), nvars(0),
	totalTrees(0)
{}

Orchard::Orchard(string n, unsigned s, unsigned e) :
	name(n), start(s), end(e), nvars(0), totalTrees(0)
{}

string Orchard::getName() {
	return name;
}

unsigned Orchard::getStart() {
	return start;
}

unsigned Orchard::getEnd() {
	return end;
}

unsigned Orchard::getNVars() {
	return nvars;
}

unsigned Orchard::getTotTrees() {	// added 2/6
	return totalTrees;
}

// Two options for writing file info into Orchard
// OPTION 1: 1 function to write name, start/end,
//           separate function to add each Apple variety
void Orchard::setOrchard(string n, unsigned s, unsigned e) {
	name = n;
	start = s;
	end = e;
}

// Returns true on success, false on failure (if array full)
bool Orchard::addApple(string an, unsigned m, unsigned nt) {
	if (nvars == 10)
		return false;

	// Otherwise, write arguments into current Apple object
	vars[nvars++].setApple(an, m, nt);
	totalTrees += nt;
	return true;
}

// OPTION 2: Take in file name and have one function
//           to read all Orchard info out of file
void Orchard::readFile(string fn) {
	ifstream inFile;
	unsigned ntypes, i;
	string aName;
	unsigned m, ntrees;

	inFile.open(fn);

	// Input file format: orchard name on 1st line, open/close times on 2nd, # types on 3rd
	// Each apple type on 2 lines: type name on first, month & numberOfTrees on 2nd
	getline(inFile, name);
	inFile >> start >> end >> ntypes;

	for (i = 0; i < ntypes; i++) {
		inFile.ignore(1);			// Skip newline at end of previous line
		getline(inFile, aName);
		inFile >> m >> ntrees;

		/**** WRITE INPUT INFO INTO Orchard OBJECT IN ARRAY ****/
		addApple(aName, m, ntrees);
		totalTrees += ntrees;
	}

	inFile.close();
}

// Print all orchard info
void Orchard::display(ostream& out) {
	unsigned i;

	out << name << endl;
	out << "Open from " << start << ":00 to "
		<< end << ":00\n";
	out << "Picking " << nvars << " different apple types in "
		<< totalTrees << " total trees\n\n";

	// Print each apple variety
	for (i = 0; i < nvars; i++)
		vars[i].display(out);
}

// Check/print what apples are available in given month
void Orchard::printAvailable(ostream& out, unsigned m) {
	unsigned i;
	bool avail = false;		// Tracks whether any available in month m

	for (i = 0; i < nvars; i++) {
		if (vars[i].getMonth() == m) {
			out << vars[i].getName() << endl;
			avail = true;
		}
	}

	if (avail == false)
		out << "None\n";
}
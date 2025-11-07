/*
* EECE.3220: Data Structures
* Instructor: M. Geiger
* 9/21/2021
* Class design example
*
* Orchard.cpp: Orchard function definitions
*/

#include "Orchard.h"

// Default constructor--assume orchard is unnamed and empty
Orchard::Orchard() : name(""), types(0), oTime(12), cTime(12) {}

// Set name, open, & closing times
void Orchard::setOrchard(string n, unsigned o, unsigned c) {
	name = n;
	oTime = o;
	cTime = c;
}

// Add n trees of type t available in month m
//   Return true if successful, false if no space
bool Orchard::addTrees(unsigned n, string t, unsigned m) {
	
	// No room for new tree
	if (types == 10)
		return false;

	// Set appropriate entry in nTrees, apples arrays, then increment type count
	else {
		nTrees[types] = n;
		apples[types++].setApple(t, m);
		return true;
	}
}

// Print information about orchard
void Orchard::display(ostream& out) {
	unsigned i;
	
	out << name << '\n';
	out << "Open from " << oTime << ":00 to " << cTime << ":00\n";
	out << "Picking " << types << " different apple types in "
		<< totalTrees() << " total trees\n\n";

	// Print all apple information
	for (i = 0; i < types; i++) {
		apples[i].display(out);
		out << "Number of trees: " << nTrees[i] << "\n\n";
	}
}

// List all available apples during month m
void Orchard::allAvail(ostream& out, unsigned m) {
	bool any = false;		// Set to true if anything's printed
	unsigned i;

	out << "Available apples during month " << m << ":\n";
	for (i = 0; i < types; i++) {
		if (apples[i].isAvailable(m)) {
			out << apples[i].getType() << '\n';
			any = true;
		}
	}

	// Print message if none available
	if (any == false)
		out << "None\n";

	out << '\n';
}

// Counts total number of trees
unsigned Orchard::totalTrees() {
	unsigned i;			// Loop index
	unsigned count = 0;	// Total count

	for (i = 0; i < types; i++)
		count += nTrees[i];

	return count;
}
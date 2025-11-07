/*
* EECE.3220: Data Structures
* Instructor: M. Geiger
* 9/21/2021
* Class design example
* 
* orchardTest.cpp: main program
*/

#include "Orchard.h"
#include "Apple.h"

#include <fstream>
#include <iostream>

using namespace std;

int main() {
	string fname;		// Input file name
	ifstream inFile;	// Input file stream	
	string cmd;			// Input command

	Orchard oList[10];	// List of orchards
	unsigned nOrch = 0;	// Number of orchards

	string oName;		// Orchard name
	unsigned op, cl;	// Open/close time
	unsigned ntypes;	// Number of types

	string aName;		// Apple name
	unsigned m, ntrees;	// Month available; number of trees

	unsigned i;			// Loop index

	do {
		cout << "Enter command: ";
		cin >> cmd;

		// Read new orchard information from file
		if (cmd == "read") {
			cout << "Enter input file name: ";
			cin >> fname;
			inFile.open(fname);

			// Input file format: orchard name on 1st line, open/close times on 2nd, # types on 3rd
			// Each apple type on 2 lines: type name on first, month & numberOfTrees on 2nd
			getline(inFile, oName);
			inFile >> op >> cl >> ntypes;
			oList[nOrch].setOrchard(oName, op, cl);

			for (i = 0; i < ntypes; i++) {
				inFile.ignore(1);			// Skip newline at end of previous line
				getline(inFile, aName);
				inFile >> m >> ntrees;
				oList[nOrch].addTrees(ntrees, aName, m);
			}

			inFile.close();

			nOrch++;			// Count new orchard
		}

		// Print all information about given orchard
		else if (cmd == "print") {
			if (nOrch == 0)
				cout << "No current orchards listed\n";

			else if (nOrch == 1)
				oList[0].display(cout);

			else {
				cout << "Enter orchard number between 0 and " << nOrch - 1 << '\n';
				cin >> i;
				oList[i].display(cout);
			}
		}

		// Check availability of apple types
		else if (cmd == "available") {

			if (nOrch == 0)
				cout << "No current orchards listed\n";

			else {
				cout << "Enter month: ";
				cin >> m;

				if (nOrch == 1)
					oList[0].allAvail(cout, m);

				else {
					cout << "Enter orchard number between 0 and " << nOrch - 1 << '\n';
					cin >> i;
					oList[i].allAvail(cout, m);
				}
			}
		}

		else if (cmd != "exit")
			cout << "Error: invalid command " << cmd << '\n';

	} while (cmd != "exit");

	return 0;
}
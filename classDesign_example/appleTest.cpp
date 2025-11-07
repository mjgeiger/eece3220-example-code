/*
* EECE.3220: Data Structures
* Instructor: M. Geiger
* 2/14/2022
* Class design example
*
* appleTest.cpp: main program to test Apple class
*/

#include <iostream>
#include <fstream>
using namespace std;

#include "Apple.h"

int main() {
	string fname;		// Input file name
	ifstream inFile;	// Input file stream	
	string cmd;			// Input command

	unsigned ntypes = 0;// Number of apple types

	string aName;		// Apple name
	unsigned m, ntrees;	// Month available; number of trees

	Apple aList[10];	// List of up to 10 different Apple objects

	unsigned i;			// Loop index

	do {
		cout << "Enter command: ";
		cin >> cmd;

		// Read new orchard information from file
		if (cmd == "read") {
			cout << "Enter input file name: ";
			cin >> fname;
			inFile.open(fname);

			// Input file format: # apple types on 1st line, then
			// Each apple type on 2 lines: type name on first, month & numberOfTrees on 2nd
			inFile >> ntypes;

			for (i = 0; i < ntypes; i++) {
				inFile.ignore(1);			// Skip newline at end of previous line
				getline(inFile, aName);
				inFile >> m >> ntrees;

				// UPDATE CURRENT ARRAY ELEMENT
				aList[i].setApple(aName, m, ntrees);
			}

			inFile.close();
		}

		// Print all information about given apple type
		else if (cmd == "print") {
			if (ntypes == 0)
				cout << "No current types listed\n";

			else if (ntypes == 1)
				aList[0].display(cout);  // Print info about only apple type

			else {
				cout << "Enter apple number between 0 and " << ntypes - 1 << '\n';
				cin >> i;
				aList[i].display(cout);	// Print info about requested apple type
			}
		}

		// Check availability of apple types
		else if (cmd == "available") {

			if (ntypes == 0)
				cout << "No current apples listed\n";

			else {
				cout << "Enter month: ";
				cin >> m;

				bool printed = false;		// Indicates whether any apple names printed

				for (i = 0; i < ntypes; i++) {
					if ( m == aList[i].getMonth() ) {
						cout << aList[i].getName() << '\n';
						printed = true;
					}
				}

				if (printed == false)
					cout << "Nothing available\n";
			}
		}

		else if (cmd != "exit")
			cout << "Error: invalid command " << cmd << '\n';

	} while (cmd != "exit");

	return 0;
}
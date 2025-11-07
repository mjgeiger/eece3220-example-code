/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * Basic C++ file input/output example
 */

#include <fstream>
#include <iostream>
using std::ifstream;
using std::ofstream;
using std::endl;

int main() {
	int x, y;
	ifstream infile;
	ofstream outfile;

	// Open input, output files
	infile.open("f1.txt");
	outfile.open("f2.txt");

	// Read integer values, then reprint to output
	infile >> x >> y;
	outfile << "product = " << x * y << ", quotient = " << y / x << endl;

	infile.close();
	outfile.close();

	return 0;
}

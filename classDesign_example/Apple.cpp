/*
* EECE.3220: Data Structures
* Instructor: M. Geiger
* 9/21/2021
* Class design example
*
* Apple.cpp: Apple function definitions
*/

#include "Apple.h"

Apple::Apple() {
	name = "";
	month = 0;
	nTrees = 0;
}

Apple::Apple(string n, unsigned m, unsigned nt) {
	name = n;
	month = m;
	nTrees = nt;
}

string Apple::getName() {
	return name;
}

unsigned Apple::getMonth() {
	return month;
}

unsigned Apple::getNTrees() {
	return nTrees;
}

void Apple::setApple(string n, unsigned m, unsigned nt) {
	name = n;
	if (m >= 1 && m <= 12)
		month = m;
	nTrees = nt;
}

/* Sample output:
Type: Cortland
Month available: 10
Number of trees: 20
*/
void Apple::display(ostream& out) {
	out << "Type: " << name
		<< "\nMonth available: " << month
		<< "\nNumber of trees: " << nTrees << endl;
}
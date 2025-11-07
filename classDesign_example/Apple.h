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
	Apple(string n, unsigned m, unsigned nt);
	string getName();
	unsigned getMonth();
	unsigned getNTrees();
	void setApple(string n, unsigned m, unsigned nt);
	void display(ostream& out);
private:
	string name;		// Name of apple variety
	unsigned month;		// Month in which it's available
	unsigned nTrees;	// Number of trees of this variety
};

#endif		// APPLE_H
/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * Sample program for testing linked stack objects
 *   using templates
 *
 * This program demonstrates how a templated Stack class
 *   can be used, declaring multiple Stack objects storing
 *   different types of data
 */

#include <iostream>
#include <string>
using namespace std;

#include "Stack.h"
//#include "sampleClass.h"

int main() {
	Stack <int> iStack;		// Stack of integers
	Stack <double> dStack;	// Stack of doubles
	int i;
	
	// Add data to both stacks
	for (i = 0; i < 250; i += 25) {
		iStack.push(i);
		dStack.push(i / 2.0);
	}

	cout << "Integer stack:\n" << iStack;
	cout << "\nDouble stack:\n" << dStack;

	return 0;
}
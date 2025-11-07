/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 *
 * Example to demonstrate class basics
 * time_test.cpp: Main program to test Time class
 */

#include "Time.h"
#include <iostream>
using namespace std;

int main() {
	Time t1, t2;
	Time t3(5, 15, 'A');

	t1.set(10, 30, 'A');
	t2.set(9, 17, 'P');

	if (t1.lessThan(t2))		// (t1 < t2)
		cout << "t1 < t2\n";
	else
		cout << "t1 >= t2\n";

	return 0;
}
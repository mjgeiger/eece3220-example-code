//
//  LList_tester.cpp
//
//  Created by Michael Geiger on 3/1/17; updated 6/18/2020
//  Copyright © 2020 Michael Geiger. All rights reserved.
//

#include "LList.h"

#include <iostream>
using std::cout;
using std::cin;

int main() {
	LList L1;

	cout << "L1: \n";
	L1.display(cout);		// Print empty list

	// Testing insert
	cout << "Inserting 3, 2, 7, and 0\n";
	L1.insert(3);
	L1.insert(2);
	L1.insert(7);
	L1.insert(0);
	cout << "L1: \n";
	L1.display(cout);

	// Testing deletion
	cout << "Removing 2, 3, and 5 (5 isn't in list)\n";
	L1.remove(2);
	L1.remove(3);
	L1.remove(5);
	cout << "Updated L1: \n";
	L1.display(cout);

	return 0;
}

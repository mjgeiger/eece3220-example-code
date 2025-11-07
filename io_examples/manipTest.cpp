//
//  manipTest.cpp
//  dataStructuresTest
//
//  Created by Michael Geiger on 2/4/19.
//  Copyright 2019 Michael Geiger. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, const char * argv[]) {
	// Testing showpoint/noshowpoint etc.
	double d1 = 1.23456789;
	double d2 = 998877665544332211;
	double d3 = 54321;
	
	cout << "Default outputs:\n d1 = " << d1 
		<< ", d2 = " << d2 << ", d3 = " << d3 << endl << endl;
	
	cout << showpoint;
	cout << "With showpoint only:\n d1 = " << d1 
		<< ", d2 = " << d2 << ", d3 = " << d3 << endl << endl;
	
	cout << fixed;
	cout << "showpoint/fixed:\n d1 = " << d1 
		<< ", d2 = " << d2 << ", d3 = " << d3 << endl << endl;
	
	cout << noshowpoint;
	cout << "noshow:\n d1 = " << d1 
		<< ", d2 = " << d2 << ", d3 = " << d3 << endl << endl;
	
	cout << defaultfloat;
	cout << "Back to default:\n d1 = " << d1 
		<< ", d2 = " << d2 << ", d3 = " << d3 << endl << endl;
	
	return 0;
}

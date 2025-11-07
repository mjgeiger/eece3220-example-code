#include "Complex.h"

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	Complex c1;
	Complex c2(5, -3);	// c2.real = 5, c2.imag = -3

	double r = c1.getReal();	// c1 = "calling object"
								// Will not be modified because
								//   getReal() is const

	Complex c3;
	c3 = c1.add(c2);			// c3 = c1 + c2 -->
								// c3 = c1.operator+(c2)
	
	ofstream f1("out1.txt");

	c1.display(cout);			// cout << c1
	c2.display(f1);

	f1.close();

	return 0;
}
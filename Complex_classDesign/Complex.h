#pragma once

#include <iostream>
using namespace std;

class Complex {
public:
	// Add member functions
	Complex();						// Default constructor
	Complex(double r, double i);	// Param. constructor
	
	// Set/get functions
	void setReal(double r);
	void setImag(double i);
	double getReal();
	double getImag();

	// Math functions
	Complex add(const Complex& rhs);
	// Could add more

	// Display
	void display(ostream& out);
private:
	// Add data members
	double real, imag;		// Real/imaginary part of #
};
#pragma once

#include <iostream>
using namespace std;

class Complex {
public:
	Complex();						// Default constructor
	Complex(double r, double i);	// Parameterized constructor
	Complex(double r);				// Sets real = r, imag = 0
	
	// Set/get functions
	void setReal(double r);
	void setImag(double i);
	double getReal() const;
	double getImag() const;

	// Math functions
	Complex add(const Complex& rhs);
	// Could list subtraction, multiplication, etc. ...
	
	Complex conjugate();

	// Display
	void display(ostream& out);

private:
	double real, imag;		// Real & imaginary part of number
};
#pragma once

#include <iostream>
using namespace std;

class Complex {
public:
	// Add member functions
	// Constructors
	Complex();
	Complex(double r, double i);

	// Set/get functions
	void setCplx(double r, double i);
	void setReal(double r);
	void setImag(double i);
	double getReal() const;
	double getImag() const;	

	// Magnitude
	double getMagnitude();

	// Math functions: +, -, *, /
	Complex add(const Complex &rhs);
	Complex sub(const Complex &rhs);
	Complex mul(const Complex &rhs);
	Complex div(const Complex &rhs);

	// Conjugate
	Complex getConjugate();

	// Display
	void print(ostream& out);	// c1.print(cout);

private:
	// Add data members
	/* Real & imaginary parts */
	double real, imag;
};
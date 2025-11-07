#pragma once

#include <iostream>
using namespace std;

class Complex {
public:
	// Constructors
	Complex();			
	Complex(double real);
	Complex(double real, double imag); 

	// Set/get functions
	void setReal(double r);
	void setImag(double i);
	double getReal() const;
	double getImag() const;

	// Conversion functions
	void toPolar(double& radius, double& angle);
	Complex getConjugate();

	// Math functions
	Complex add(Complex& rhs);		// Calling obj. + rhs
	Complex sub(Complex& rhs);		// Calling obj. - rhs
	Complex mul(Complex& rhs);		// Calling obj. * rhs
	Complex div(Complex& rhs);		// Calling obj. / rhs

	void output(ostream& out);
private:
	double real, imag;		// Real and imaginary parts of #
};
#include "Complex.h"

// Default constructor
Complex::Complex() : real(0), imag(0)
{}

Complex::Complex(double r) : real(r), imag(0) 
{}

Complex::Complex(double r, double i) : real(r), imag(i)
{}

// Set/get functions
void Complex::setReal(double r) {
	real = r;
}

void Complex::setImag(double i) {
	imag = i;
}

double Complex::getReal() const {
	return real;
}

double Complex::getImag() const {
	return imag;
}

// Math functions
// Calling obj. + rhs
Complex Complex::add(Complex& rhs) {
	Complex result;

	result.real = real + rhs.real;
	result.imag = imag + rhs.imag;

	return result;
}		
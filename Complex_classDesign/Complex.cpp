#include "Complex.h"
#include <cmath>

// Default constructor
Complex::Complex() : real(0), imag(0)
{}

// Parameterized constructor
Complex::Complex(double r, double i) : 
	real(r), imag(i)
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

// Math operations
Complex Complex::add(const Complex& rhs) const {
	Complex temp;

	temp.real = real + rhs.real;
	temp.imag = imag + rhs.imag;

	return temp;
}

Complex Complex::sub(const Complex& rhs) const {}
Complex Complex::mul(const Complex& rhs) const {}
Complex Complex::div(const Complex& rhs) const {}

void Complex::display(ostream& os) const {
	os << real;
	if (imag >= 0) {
		os << " + " << imag << "i";
	}
	else {
		os << " - " << -imag << "i";
	}
}

// Going from rectangular --> polar
//     r = sqrt(real*real + imag*imag)
//     theta = arctan(imag / real)
//			(may have to adjust for quadrant)
// Going from polar --> rectangular
//     real = r cos(theta)
//     imag = r sin(theta)
double Complex::getPolarRad() const {
	return sqrt(real * real + imag * imag);
}

double Complex::getPolarAng() const {
	return atan(imag / real);
}

void Complex::toPolar(double* r, double* a) const {
	*r = sqrt(real * real + imag * imag);
	*a = atan(imag / real);
}

void Complex::fromPolar(double r, double a) {
	real = r * cos(a);
	imag = r * sin(a);
}

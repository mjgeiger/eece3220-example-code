#include "Complex.h"
#include <cmath>

// Define member functions here
Complex::Complex() : real(0), imag(0)
{}						
	
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

double Complex::getReal() {
    return real;
}

double Complex::getImag() {
    return imag;
}

// Math functions: a = b.add(c)
Complex Complex::add(const Complex& rhs) {
    Complex result;

    result.real = real + rhs.real;
    result.imag = imag + rhs.imag;

    return result;
}

// Display: print object in form: a + bi
void Complex::display(ostream& out) {
    out << real << " + " << imag << "i";
}
#include "Complex.h"
#include <cmath>

// Define member functions here
// Constructor
Complex::Complex() : real(0), imag(0)
{}

// Data member: _Complex_real
// Argument: _Complex_Complex_real
Complex::Complex(double r, double i)  
    : real(r), imag(i)
{}

// Set/get functions
void Complex::setCplx(double r, double i) {
    real = r;
    imag = i;
}

double Complex::getReal() const {
    return real;
}

double Complex::getImag() const {
    return imag;
}

// Math functions
Complex Complex::add(const Complex &rhs) {
    Complex num(real + rhs.real, imag + rhs.imag);

    /* If, for some reason, you don't want to do math 
        in your num constructor, these statements also work:
    num.real = real + rhs.real;
    num.imag = imag + rhs.imag;
    */

    return num;
}



// Display
void Complex::print(ostream& out) {	// c1.print(cout);
    out << real << " + " << imag << "i" << endl;
}
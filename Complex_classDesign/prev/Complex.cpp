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

Complex Complex::add(const Complex& rhs) {
	Complex result;

	// If c3 = c1.add(c2) is called outside function
	// Inside function:
	//   result --> c3
	//   rhs    --> c2
	//   real   --> c1.real
	//   imag	--> c1.imag
	result.real = real + rhs.real;		// real = this->real
	result.imag = imag + rhs.imag;

	return result;
}

Complex Complex::conjugate() {
	Complex result(real, -imag);
	// Above is equivalent to:
	//		result.real = real;
	//		result.imag = -imag;

	return result;
}

// Example: c1.display(cout);
void Complex::display(ostream& out) {
	if (imag > 0)
		out << real << " + " << imag << 'i';
	else if (imag < 0)
		out << real << " - " << -imag << 'i';
	else
		out << real;
}

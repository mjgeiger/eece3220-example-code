#pragma once

#include <iostream>
using namespace std;

class Complex {
public:
	Complex();
	Complex(double r, double i);
	void setReal(double r);
	void setImag(double i);
	double getReal() const;
	double getImag() const;
	Complex add(const Complex& rhs) const;
	Complex sub(const Complex& rhs) const;
	Complex mul(const Complex& rhs) const;
	Complex div(const Complex& rhs) const;

	void display(ostream& out) const;

	double getPolarRad() const;
	double getPolarAng() const;
	void toPolar(double* r, double* a) const;
	void fromPolar(double r, double a);
private:
	double real, imag;
};
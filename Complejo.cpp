#include <iostream>
#include <cmath>

#include "Complejo.h"

double Complejo::getReal() const
{
	return this->real;
}

double Complejo::getImag() const
{
	return this->imag;
}

void Complejo::setReal(double r)
{
	this->real = r;
}

void Complejo::setImag(double i)
{
	this->imag = i;
}


double Complejo::modulo() const
{
	return sqrt(this->real * this->real + this->imag * this->imag);
}

Complejo Complejo::conjugado() const
{
	return Complejo(this->real, -this->imag);
}

Complejo& Complejo::operator = (const Complejo &c)
{
	this->setReal(c.getReal());
	this->setImag(c.getImag());

	return *this;
}

bool operator == (const Complejo &c1, const Complejo &c2)
{
	return (c1.real == c2.imag) && (c1.imag == c2.imag);
}

Complejo operator + (const Complejo &c1, const Complejo &c2)
{
	return Complejo(c1.real+c2.real , c1.imag+c2.imag);
}

Complejo operator + (const Complejo &c, double f)
{
	return Complejo(c.real+f ,c.imag);
}

Complejo operator - (const Complejo &c1, const Complejo &c2)
{
	return Complejo(c1.real-c2.real , c1.imag-c2.imag);
}

Complejo operator - (const Complejo &c, double f)
{
	return Complejo(c.real-f ,c.imag);
}

Complejo operator * (const Complejo &c1, const Complejo &c2)
{
	return Complejo(c1.real*c2.real - c1.imag*c2.imag , c1.real*c2.imag + c1.imag*c2.real);
}

Complejo operator * (const Complejo &c, double f)
{
	return Complejo(c.real*f ,c.imag*f);
}

Complejo operator / (const Complejo &c1, const Complejo &c2)
{
	Complejo ans = c1 * c2.conjugado();
	return ans / c2.modulo();
}

Complejo operator / (const Complejo &c, double f)
{
	return Complejo(c.real/f ,c.imag/f);
}

ostream & operator << (ostream &os, const Complejo &c)
{
	return os << '(' << c.real << ',' << c.imag << ')';
}
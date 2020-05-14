#ifndef COMPLEJO_INCLUDED
#define COMPLEJO_INCLUDED

#include <iostream>
using namespace std;

class Complejo
{

private:
	double real;
	double imag;

public:
	Complejo():real(0.0),imag(0.0){};
	Complejo(double r, double i):real(r),imag(i){};
	Complejo(const Complejo &c):real(c.real),imag(c.imag){};
	~Complejo(){};

	double getReal() const;
	double getImag() const;
	void setReal(double);
	void setImag(double);

	double modulo() const;
	double arg() const;
	Complejo conjugado() const;

	Complejo transformarZ() const;
	Complejo transformarLn() const;

	Complejo& operator = (const Complejo &);

	friend bool operator == (const Complejo &, const Complejo &);
	friend Complejo operator + (const Complejo &, const Complejo &);
	friend Complejo operator + (const Complejo &, double);
	friend Complejo operator - (const Complejo &, const Complejo &);
	friend Complejo operator - (const Complejo &, double);
	friend Complejo operator * (const Complejo &, const Complejo &);
	friend Complejo operator * (const Complejo &, double);
	friend Complejo operator / (const Complejo &, const Complejo &);
	friend Complejo operator / (const Complejo &, double);

	friend ostream & operator << (ostream &, const Complejo &);
};


#endif // COMPLEJO_INCLUDED
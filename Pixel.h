#ifndef PIXEL_H_INCLUDED
#define PIXEL_H_INCLUDED

#include "Complejo.h"

class Pixel
{

private:
	int intensidad;
	Complejo pos;

public:
	Pixel():intensidad(0),pos(Complejo(0,0)){};
	Pixel(int i, Complejo c):intensidad(i),pos(c){};
	~Pixel();

	void setIntensidad(int);
	void setPos(Complejo c);
	int getIntensidad() const;
	Complejo getPos() const;

	Pixel &operator = (const Pixel &);
};

#endif
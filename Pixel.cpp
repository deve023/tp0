#include "Pixel.h"

Pixel::~Pixel()
{}

void Pixel::setIntensidad(int i)
{
	this->intensidad = i;
}

void Pixel::setPos(Complejo c)
{
	this->pos = c;
}

int Pixel::getIntensidad() const
{
	return this->intensidad;
}

Complejo Pixel::getPos() const
{
	return this->pos;
}

const Pixel &Pixel::operator = (const Pixel &px)
{
	this->intensidad = px.intensidad;
	this->pos = px.pos;

	return *this;
}
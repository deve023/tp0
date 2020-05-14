#include "Imagen.h"

Imagen::Imagen(int sx, int sy, int im)
{
	this->sizeX = sx;
	this->sizeY = sy;
	this->intensidadMax = im;
	if(sx > 0 && sy > 0)
	{
		this->pixeles = new int*[sy];
		for(int i = 0; i < sx; i++)
			this->pixeles[i] = new int[sx];
	}

	else
		this->pixeles = NULL;
}

Imagen::~Imagen()
{
	delete[] pixeles;
}

bool Imagen::setImagen(int **pixeles, int sx, int sy)
{
	if(pixeles == NULL || sx != this->sizeX || sy != this->sizeY)
		return false;

	for(int i = 0; i < sy; i++)
		for(int j = 0; j < sx; j++)
			this->pixeles[i][j] = pixeles[i][j];

	return true;
}

void Imagen::setSizeX(int sx)
{
	this->sizeX = sx;
}

void Imagen::setSizeY(int sy)
{
	this->sizeY = sy;
}

void Imagen::setIntensidadMax(int im)
{
	this->intensidadMax = im;
}

int **Imagen::getPixeles()
{
	return this->pixeles;
}

int Imagen::getSizeX()
{
	return this->sizeX;
}

int Imagen::getSizeY()
{
	return this->sizeY;
}

int Imagen::getIntensidadMax()
{
	return this->intensidadMax;
}

void transformarZ(const Imagen &imag)
{}

void transformarExpZ(const Imagen &imag)
{}

#include "Imagen.h"

Imagen::Imagen(int **pxs, int sx, int sy, int im)
{
	this->pixeles = NULL;
	this->intensidadMax = im;
	this->setPixeles(pxs, sx, sy);
}

Imagen::Imagen(const Imagen &i)
{
	this->pixeles = NULL;
	this->intensidadMax = i.intensidadMax;
	this->setPixeles(i.pixeles, i.sizeX, i.sizeY);
}

Imagen::~Imagen()
{
	if(this->pixeles)
	{
		for(int i = 0; i < this->sizeY; i++)
			delete pixeles[i];
		delete[] pixeles;
	}
}

bool Imagen::setPixeles(int **pixeles, int sx, int sy)
{
	if(this->pixeles)
	{
		for(int i = 0; i < this->sizeY; i++)
			delete pixeles[i];
		delete[] pixeles;
		this->pixeles = NULL;
	}

	this->sizeX = sx;
	this->sizeY = sy;

	this->pixeles = new int*[sy];
	for(int i = 0; i < sy; i++)
	{
		this->pixeles[i] = new int[sx];
		for(int j = 0; j < sx; j++)
		{
			// se verifica que no se copie una intensidad que exceda el rango permitido
			if(pixeles[i][j] > this->intensidadMax || pixeles[i][j] < 0)
			{
				for(int i = 0; i < this->sizeY; i++)
					delete pixeles[i];
				delete[] pixeles;
				this->pixeles = NULL;
				
				return false;
			}

			this->pixeles[i][j] = pixeles[i][j];
		}
	}
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

void Imagen::getPixeles(int ** &destino) const
{
	for(int i = 0; i < this->sizeY; i++)
		for(int j = 0; j < this->sizeX; j++)
			destino[i][j] = this->pixeles[i][j];
}

int Imagen::getSizeX() const
{
	return this->sizeX;
}

int Imagen::getSizeY() const
{
	return this->sizeY;
}

int Imagen::getIntensidadMax() const
{
	return this->intensidadMax;
}

Imagen &Imagen::operator = (const Imagen &i)
{
	this->intensidadMax = i.intensidadMax;
	this->setPixeles(i.pixeles, i.sizeX, i.sizeY);
	
	return *this;
}

void transformarZ(const Imagen &imag)
{}

void transformarExpZ(const Imagen &imag)
{}

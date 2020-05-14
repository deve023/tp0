#include "Imagen.h"

Imagen::Imagen(int sx, int sy, int im)
{
	this->sizeX = sx;
	this->sizeY = sy;
	this->intensidadMax = im;

	if(sx > 0 && sy > 0)
	{
		this->pixeles = new int*[sy];
		for(int i = 0; i < sy; i++)
			this->pixeles[i] = new int[sx];
	}

	else
		this->pixeles = NULL;
}

Imagen::Imagen(const Imagen &i)
{
	this->sizeX = i.sizeX;
	this->sizeY = i.sizeY;
	this->intensidadMax = i.intensidadMax;

	int **aux = i.getPixeles();
	if(aux)
	{
		this->pixeles = new int*[this->sizeY];
		for(int i = 0; i < this->sizeY; i++)
		{
			this->pixeles[i] = new int[this->sizeX];
			for(int j = 0; j < this->sizeX; j++)
				this->pixeles[i][j] = aux[i][j];
		}
	}

	else
		this->pixeles = NULL;
}

Imagen::~Imagen()
{
	delete[] pixeles;
}

bool Imagen::setPixeles(int **pixeles, int sx, int sy)
{
	if(pixeles == NULL || sx != this->sizeX || sy != this->sizeY)
		return false;

	for(int i = 0; i < sy; i++)
		for(int j = 0; j < sx; j++)
		{
			// se verifica que no se copie una intensidad que exceda el rango permitido
			if(pixeles[i][j] > this->intensidadMax || pixeles[i][j] < 0)
			{
				delete[] this->pixeles;
				this->pixeles = NULL;
				return false;
			}

			this->pixeles[i][j] = pixeles[i][j];
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

int **Imagen::getPixeles() const
{
	return this->pixeles;
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

Imagen &Imagen::operator = (const Imagen &imag)
{
	if(this->sizeX == imag.getSizeX() && this->sizeY == imag.getSizeY() && this->intensidadMax == imag.getIntensidadMax())
		if(!imag.getPixeles())
			this->pixeles = imag.getPixeles();
		else
			this->setPixeles(imag.getPixeles(), this->sizeX, this->sizeY);
	else
		this->sizeX = imag.getSizeX();
		this->sizeY = imag.getSizeY();
		this->intensidadMax = imag.getIntensidadMax();
		delete[] this->pixeles;

		int **aux = imag.getPixeles();
		if(aux)
		{
			this->pixeles = new int*[this->sizeY];
			for(int i = 0; i < this->sizeY; i++)
			{
				this->pixeles[i] = new int[this->sizeX];
				for(int j = 0; j < this->sizeX; j++)
					this->pixeles[i][j] = aux[i][j];
			}
		}
		else
			this->pixeles = imag.getPixeles();
	return *this;

}

void transformarZ(const Imagen &imag)
{}

void transformarExpZ(const Imagen &imag)
{}

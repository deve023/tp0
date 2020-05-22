#ifndef IMAGEN_H_INCLUDED
#define IMAGEN_H_INCLUDED

#ifndef NULL
#define NULL 0
#endif

#include "Complejo.h"
#include "Pixel.h"
#include <math.h>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

class Imagen
{

private:
	int sizeX, sizeY;
	int intensidadMax;
	Pixel **pixeles;

public:
	Imagen():sizeX(0),sizeY(0),intensidadMax(0),pixeles(NULL){};
	Imagen(int **intensidadPixeles, int sx, int sy, int im);
	Imagen(const Imagen &);
	~Imagen();

	// setea los valores de pixeles, sizeX y sizeY
	// se le pasa una matriz con la intensidad de cada pixel
	// pre: pixeles debe no ser NULL y sx e sy almacenar sus dimensiones
	// Devuelve false si no pudo almacenar los valores. En ese caso deja this->pixeles apuntando a NULL
	bool setPixeles(int **intensidadPixeles, int sx, int sy);
	void setSizeX(int);
	void setSizeY(int);
	void setIntensidadMax(int);

	// guarda en destino una copia de la matriz de pixeles
	// pre: destino ya debe tener memoria pedida
	Pixel **getPixeles() const;
	int ** getIntensidadPixeles() const;
	int getSizeX() const;
	int getSizeY() const;
	int getIntensidadMax() const;

	Imagen &operator = (const Imagen &);

	Imagen transformarZ() const;
	Imagen transformarExpZ() const;
	bool leerArchivoPgm(istream *);
	void escribirArchivoPgm(ostream *);
};

#endif
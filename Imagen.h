#ifndef IMAGEN_H_INCLUDED_
#define IMAGEN_H_INCLUDED_

#ifndef NULL
#define NULL 0
#endif

#include "Complejo.h"
#include "Pixel.h"

#include <iostream>
#include <sstream>

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


	void setIntensidadMax(int);

	// Setea los valores de pixeles, sizeX y sizeY
	// se le pasa una matriz con la intensidad de cada pixel, y sus dimensiones.
	// pre: pixeles debe no ser NULL y sx e sy almacenar sus dimensiones
	//      las intensidades deben estar en el rango [0, intensidadMax].
	// post: imagen tendra almacenados sus pixeles, con intensidad y posicion en el plano complejo acordes. Y sizeX y sizeY.
	// Devuelve false si no pudo almacenar los valores. En ese caso deja this->pixeles apuntando a NULL.
	bool setPixeles(int **intensidadPixeles, int sx, int sy);

	int getSizeX() const;
	int getSizeY() const;
	int getIntensidadMax() const;

	// Se devuelve una copia de la matriz dinamica de pixeles almacenada en imagen
	// pre: imagen deberia existir y tener una matriz de pixeles asociada
	// post: se devuelve un puntero a la matriz copia de pixeles
	//       si this->pixeles es NULL devuelve NULL.
	Pixel **getPixeles() const;

	// Se devuelve un puntero a una matriz dinamica que almacena las intensidades de los pixeles asociados a la imagen
	// pre: imagen deberia existir y tener una matriz de pixeles asociada
	// post: se devuelve un puntero a la matriz dinamica de intensidades de pixeles
	//       si this->pixeles es NULL devuelve NULL.
	int ** getIntensidadPixeles() const;

	Imagen &operator = (const Imagen &);

	// Se devuelve una imagen que es la transformada del objeto imagen, segun la transformacion identidad.
	// pre: el objeto imagen deberia existir y tener una matriz de pixeles asociada
	// post: se devuelve la imagen transformada
	//       si imagen no tuviese una matriz de pixeles asociada, se devuelve una imagen nula.
	Imagen transformarZ() const;

	// Se devuelve una imagen que es la transformada del objeto imagen, segun la transformacion exponencial.
	// pre: el objeto imagen deberia existir y tener una matriz de pixeles asociada
	// post: se devuelve la imagen transformada
	//       si imagen no tuviese una matriz de pixeles asociada, se devuelve una imagen nula.
	Imagen transformarExpZ() const;

	// Se lee una imagen en formato PGM de (*istream) y se almacena en el objeto imagen.
	// pre: istream debe estar apuntando al archivo ya abierto en modo lectura, este debe ser de texto y respetar el formato de imagen PGM.
	// post: el objeto imagen termina almacenando los datos de la imagen leida.
	// en caso de fallar la lectura, se devuelve false y no se modifican los atributos del objeto imagen.
	bool leerArchivoPgm(istream *);

	// Se escribe en formato PGM en (*ostream) los datos del objeto imagen.
	// pre: ostream debe estar apuntando a un archivo de texto ya abierto en modo escritura.
	// post: el archivo queda reescrito con los datos de la imagen
	void escribirArchivoPgm(ostream *) const;
};

#endif // IMAGEN_H_INCLUDED_
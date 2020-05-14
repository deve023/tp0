#ifndef IMAGEN_H_INCLUDED
#define IMAGEN_H_INCLUDED

#ifndef NULL
#define NULL 0
#endif

class Imagen
{

private:
	int sizeX, sizeY;
	int intensidadMax;
	int **pixeles;

public:
	Imagen():sizeX(0),sizeY(0),intensidadMax(0),pixeles(NULL){};
	Imagen(int **pxs, int sx, int sy, int im);
	Imagen(const Imagen &);
	~Imagen();

	// setea los valores de pixeles, sizeX y sizeY
	// pre: pixeles debe no ser NULL y sx e sy almacenar sus dimensiones
	// Devuelve false si no pudo almacenar los valores. En ese caso deja this->pixeles apuntando a NULL
	bool setPixeles(int **pixeles, int sx, int sy);
	void setSizeX(int);
	void setSizeY(int);
	void setIntensidadMax(int);

	// guarda en destino una copia de la matriz de pixeles
	// pre: destino ya debe tener memoria pedida
	void getPixeles(int ** &destino) const;
	int getSizeX() const;
	int getSizeY() const;
	int getIntensidadMax() const;

	Imagen &operator = (const Imagen &);

	void transformarZ(const Imagen &); // FALTA IMPLEMENTAR
	void transformarExpZ(const Imagen &); // FALTA IMPLEMENTAR
};

#endif
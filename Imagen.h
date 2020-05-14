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
	Imagen(int sx, int sy, int im);
	Imagen(const Imagen &);
	~Imagen();

	bool setPixeles(int **pixeles, int sx, int sy);
	void setSizeX(int);
	void setSizeY(int);
	void setIntensidadMax(int);
	int **getPixeles() const;
	int getSizeX() const;
	int getSizeY() const;
	int getIntensidadMax() const;

	Imagen &operator = (const Imagen &);

	void transformarZ(const Imagen &); // FALTA IMPLEMENTAR
	void transformarExpZ(const Imagen &); // FALTA IMPLEMENTAR
};

#endif
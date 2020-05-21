#include "Imagen.h"

Imagen::Imagen(int **intensidadPixeles, int sx, int sy, int im)
{
	this->pixeles = NULL;
	this->intensidadMax = im;
	this->setPixeles(intensidadPixeles, sx, sy);
}

Imagen::Imagen(const Imagen &i)
{
	this->intensidadMax = i.intensidadMax;
	this->sizeX = i.sizeX;
	this->sizeY = i.sizeY;

	Pixel **aux = i.getPixeles();

	if(!aux)
		this->pixeles = aux;
	else
	{
		this->pixeles = new Pixel*[this->sizeY];
		for(int i = 0; i < this->sizeY; i++)
		{
			this->pixeles[i] = new Pixel[this->sizeX];
			for(int j = 0; j < this->sizeX; j++)
				this->pixeles[i][j] = aux[i][j];
		}
	}

	for(int i = 0; i < this->sizeY; i++)
		delete[] aux[i];
	delete[] aux;
}

Imagen::~Imagen()
{
	if(this->pixeles)
	{
		for(int i = 0; i < this->sizeY; i++)
			delete[] this->pixeles[i];
		delete[] this->pixeles;
	}
}

bool Imagen::setPixeles(int **intensidadPixeles, int sx, int sy)
{
	if(this->pixeles)
	{
		for(int i = 0; i < this->sizeY; i++)
			delete[] this->pixeles[i];
		delete[] this->pixeles;
		this->pixeles = NULL;
	}

	this->sizeX = sx;
	this->sizeY = sy;

	// Se calculan las distancias entre pixeles en el plano complejo
	double distX = 2.0 / (sx - 1);
	double distY = 2.0 / (sy - 1);

	this->pixeles = new Pixel*[this->sizeY];
	for(int i = 0; i < this->sizeY; i++)
	{
		this->pixeles[i] = new Pixel[this->sizeX];
		for(int j = 0; j < this->sizeX; j++)
		{
			int intensidad = intensidadPixeles[i][j];

			// Si la intensidad se va de rango, aborto y devuelvo false
			if(intensidad < 0 || intensidad > this->intensidadMax)
			{
				for(int k = 0; k <= i; i++)
					delete[] pixeles[i];
				delete[] pixeles;

				return false;
			}

			Complejo posicion(-1 + j*distX, 1 - i*distY);

			this->pixeles[i][j] = Pixel(intensidad, posicion);
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

Pixel **Imagen::getPixeles() const
{
	if(!this->pixeles)
		return NULL;

	Pixel **copia = new Pixel*[this->sizeY];
	for(int i = 0; i < this->sizeY; i++)
	{
		copia[i] = new Pixel[this->sizeX];
		for(int j = 0; j < this->sizeX; j++)
			copia[i][j] = this->pixeles[i][j];
	}

	return copia;
}

int **Imagen::getIntensidadPixeles() const
{
	if(!this->pixeles)
		return NULL;

	int **intensidadPixeles = new int*[this->sizeY];
	for(int i = 0; i < this->sizeY; i++)
	{
		intensidadPixeles[i] = new int[this->sizeX];
		for(int j = 0; j < this->sizeX; j++)
			intensidadPixeles[i][j] = this->pixeles[i][j].getIntensidad();
	}
	return intensidadPixeles;
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

	if(this->pixeles)
	{
		for(int i = 0; i < this->sizeY; i++)
			delete this->pixeles[i];
		delete[] pixeles;
	}

	this->intensidadMax = i.intensidadMax;
	this->sizeX = i.sizeX;
	this->sizeY = i.sizeY;

	Pixel **aux = i.getPixeles();

	this->pixeles = new Pixel*[this->sizeY];
	for(int i = 0; i < this->sizeY; i++)
	{
		this->pixeles[i] = new Pixel[this->sizeX];
		for(int j = 0; j < this->sizeX; j++)
			this->pixeles[i][j] = aux[i][j];
	}

	return *this;
}

Imagen Imagen::transformarZ() const
{
	return *this;
}

Imagen Imagen::transformarExpZ() const
{
	Imagen dest;

	// Si la imagen no tiene pixeles, se devuelve una imagen con valores nulos
	if(!this->pixeles)
		return dest;

	dest.setIntensidadMax(this->intensidadMax);
	dest.setSizeX(this->sizeX);
	dest.setSizeY(this->sizeY);

	double distX = 2.0 / (dest.sizeX - 1);
	double distY = 2.0 / (dest.sizeY - 1);

	dest.pixeles = new Pixel*[dest.sizeY];
	for(int i = 0; i < dest.sizeY; i++)
	{
		dest.pixeles[i] = new Pixel[dest.sizeX];
		for(int j = 0; j < dest.sizeX; j++)
		{
			Complejo posDest(-1 + j*distX, 1 - i*distY);
			Complejo posOrig = posDest.transformarExp();

			int jOrig = round((posOrig.getReal() + 1.0) / distX);
			int iOrig = round((1.0 - posOrig.getImag()) / distY);

			int intensidad;
			if(iOrig < 0 || iOrig >= this->sizeY || jOrig < 0 || jOrig >= this->sizeX)
				intensidad = 0;
			else
				intensidad = this->pixeles[iOrig][jOrig].getIntensidad();

			dest.pixeles[i][j] = Pixel(intensidad, posDest);
		}
	}
	return dest;
}

bool Imagen::leerArchivoPgm(istream *iss)
{	
	bool error = true; // Podriamos usarlo para tener registrado si hay o no un error
	string line;
    getline(*iss,line);

    if (line.compare("P2")){
        cerr << "No es archivo PGM, comienza con" << line <<  endl; 
		return false; //error=false;
    }

    do {
    getline(*iss,line);
	} while (line[0] == '#');

	istringstream issAux(line);

    int x, y;
    if(!(issAux >> x)){
    	cerr << "No puede leer el tamaño de la imagen" << endl;
    	return false; //error=false;
    }
    
    if(!(issAux >> y)){
    	cerr << "No puede leer el tamaño de la imagen" << endl;
    	return false;//error=false;
    }

	if(!(*iss >> intensidadMax)){
		cerr << "No puede leer la intensidad máxima" << endl;
    	return false;//error=false;
	}

	int i,j;

	int **aux = new int*[y];
	for(i=0; i < y; i++)
	{
		aux[i] = new int[x];
		for (j=0;j<x;j++){	
				*iss>>aux[i][j];			 
		}
	}


	// y finalmente si no hubieron errores metemos la data
	this->intensidadMax = intensidadMax;

	if(!this->setPixeles(aux, x, y)){ // no hace falta chequear si la imagen esta llena o vacia porque set pixeles se encarga de eso
		error=false;
	} 

	//IMPRIMO LO QUE ACABO DE HACER PARA VERLO SOLO PARA TESTEAR
	cout << this->sizeX << " " << this->sizeY << endl << this->intensidadMax << endl;

	for(i = 0; i < this->sizeY; i++)
	{
		for(j = 0; j < this->sizeX - 1; j++)
			(cout) << this->pixeles[i][j].getIntensidad() << " ";
		(cout) << this->pixeles[i][j].getIntensidad() << endl;
	}

	// Libero memoria del vector auxiliar. esto debe hacerse solo si se pidio memoria en primer lugar
	// ojo por si hubo error antes y no se creo y estamos borrando de mas o si se pidio y hubo error en el medio, etc
	for(int i = 0; i < y; i++)
		delete[] aux[i];
	delete[] aux;


	return true;//return error;
}

void Imagen::escribirArchivoPgm(ostream *oss)
{
	(*oss)<<"P2"<<endl
	<< this->sizeX << " " << this->sizeY << endl
	<< this->intensidadMax << endl;

	int i, j;
	for(i = 0; i < this->sizeY; i++)
	{
		for(j = 0; j < this->sizeX - 1; j++)
			(*oss) << this->pixeles[i][j].getIntensidad() << " ";
		(*oss) << this->pixeles[i][j].getIntensidad() << endl;
	}
}
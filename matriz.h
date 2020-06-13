#ifndef MATRIZ_H_INCLUDED_
#define MATRIZ_H_INCLUDED_


#include <iostream>
using namespace std;

template <typename T>
class Matriz
{
private:
	int x,y;
	T ** matriz;
	

	class Arreglo 
	{
	private:

		friend class Matriz;

		T* arreglo;


    public:
        Arreglo(T* a);
        T & operator[](int);
    };


public:
	
	Matriz ();
	Matriz (const Matriz &);
	Matriz (int , int );
	~Matriz();

	bool esVacia ();	
	Arreglo operator[](int);
	void setMatriz (T**, int , int);
	const Matriz &operator = (const Matriz &);
	void imprimir();
	
};

template<typename T>
Matriz<T>::Arreglo::Arreglo(T* a) : arreglo(a)
{
}

template<typename T>
T& Matriz<T>::Arreglo::operator[](int indice) 
{
            return arreglo[indice];
        }

template<typename T>
Matriz<T>::Matriz () : x(0), y(0), matriz(NULL)
{
}

template<typename T>
Matriz<T>::Matriz (const Matriz &m)
{
	this->x =m.x;
	this->y =m.y;

	this->matriz = new T * [this->x];

	for(int i = 0; i < this->x; i++){	
			this->matriz[i] = new T [this->y];
			for (int j = 0;j<this->y;j++)
				this->matriz[i][j]=m.matriz[i][j]; 
	} 

}

template<typename T>
Matriz<T>:: Matriz (int x, int y)
{
	this->x =x;
	this->y =y;

	this->matriz = new T * [this->x];

	for(int i = 0; i < this->x; i++)
			this->matriz[i] = new T [this->y];

}

template<typename T>
Matriz<T>::~Matriz()
{
	if(this->matriz)
	{
		for(int i = 0; i < this->x; i++)
			delete[] this->matriz[i];
		delete[] this->matriz;
	}
}


template<typename T>
bool Matriz<T>::esVacia (){
  	if (this->matriz==NULL)
  		return true;
  	return false;
  }

template<typename T>
typename Matriz<T>::Arreglo Matriz<T>::operator[](int indice) 
{
    return Arreglo(matriz[indice]);
}


template <typename T>
void Matriz<T>::setMatriz(T** m, int x, int y)
{
	this->x=x;
	this->y=y;

	if (!m)
		this->matriz=NULL;

	else{

		this->matriz = new T * [this->x];

		for(int i = 0; i < this->x; i++){	
			this->matriz[i] = new T [this->y];
			for (int j = 0; j<this->y; j++)
				this->matriz [i][j] = m[i][j];
		}

	}
}	

template <typename T>
const Matriz<T> & Matriz<T>::operator = (const Matriz &m)
{

	if (this->matriz){
		for(int i = 0; i < this->x; i++)
			delete[] this->matriz[i];
		delete[] this->matriz;
		this->matriz=NULL;
	}	

	this->x = m.x;
	this->y = m.y;

	this->matriz = new T * [this->x];

	for(int i = 0; i < this->x; i++)
	{	
			this->matriz[i] = new T [this->y];
			for(int j = 0; j<this->y; j++)
				this->matriz [i][j] = m.matriz [i][j];
	}
		
	return *this;
}


template <typename T>
void Matriz<T>::imprimir()
{
	cout << this->x << endl <<this->y << endl;
if(this->matriz==NULL)
	cout << "Matriz nula" << endl;
else{

	for (int i=0;i<this->x;i++)
	{
		for (int j=0;j<this->y;j++)
			cout<<this->matriz[i][j];

	}
	cout<<endl;
}


}

#endif


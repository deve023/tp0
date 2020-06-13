#include "Matriz.h"

#include <iostream>

using namespace std;

//CREÉ EL MAIN PARA PROBAR COMO FUNCIONA CON INT NOMÁS
int main(){

	cout << "TEST 1"<< endl;
	Matriz <int> aux;
	aux.setMatriz(NULL,0,0);
	aux.imprimir();


	cout << "TEST 2"<< endl;
	Matriz <int> aux2 (4,2);
	aux2.imprimir();

	cout << "TEST 3"<< endl;

	int **array=NULL;
	array = new int * [5];
	for (int i=0;i<5;i++){
		array[i]=new int [3];
		for (int j=0;j<3;j++)
			array[i][j]=2;
	}
	Matriz<int> aux3;
	aux3.setMatriz(array,3,5);
	aux3.imprimir();

	for (int i=0;i<5;i++)
		delete array[i];
	delete array;

	cout << "TEST 4"<< endl;

	if(aux.esVacia()==true)
		printf("correcto\n");
	if (aux2.esVacia())
		printf("incorreto\n");
	if(!aux3.esVacia())
		printf("correcto	\n");

	cout << "TEST 5"<< endl;

	Matriz <int> aux4= aux3;
	aux4.imprimir();
	aux2=aux4;
	aux2.imprimir();

	cout << "TEST6" << endl;
	for (int i=0;i<5;i++)
		for(int j=0;j<3;j++)
			cout << aux4 [i][j];


}

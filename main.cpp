#include <iostream>
#include <vector>
#include <string>

#include "Complejo.h"

using namespace std;

#define USO_CORRECTO_MSG "El uso correcto es: ./tp0 -i imag.pgm -o imagtranf.pgm -t [exp(z) / z]"

int main(int argc, char *argv[])
{
	// se chequea si el numero de argumentos esta dentro del rango correspondiente
	if(argc < 3 || argc > 7)
	{
		cout << USO_CORRECTO_MSG << endl;
		return 1;
	}

	// strings que almacenan las instrucciones del usuario
	string input = "cin";
	string output = "cout";
	string funcion = "";

	for(int i = 1; i < argc; i++)
	{
		string aux = argv[i]; // se pasa el argumento a string para poder aplicarle las funciones de la clase string

		if(!aux.compare("-i"))
		{
			if(i == argc - 1)
			{
				cout << USO_CORRECTO_MSG << endl;
				return 1;
			}

			input = argv[++i];
		}

		else if(!aux.compare("-o"))
		{
			if(i == argc - 1)
			{
				cout << USO_CORRECTO_MSG << endl;
				return 1;
			}

			output = argv[++i];
		}

		else if(!aux.compare("-f"))
		{
			if(i == argc - 1)
			{
				cout << USO_CORRECTO_MSG << endl;
				return 1;
			}

			funcion = argv[++i];
		}

		else
		{
			cout << USO_CORRECTO_MSG << endl;
			return 1;
		}
	}

	// se verifican las funciones requeridas por el usuario
	if( funcion.compare("z") && funcion.compare("exp(z)"))
	{
		cout << "Las transformaciones habilitadas son z y exp(z)" << endl;
		return 1;
	}

	if(!input.compare("-"))
		input = "cin";

	if(!output.compare("-"))
		output = "cout";

	cout << input << " " << output << " " << funcion << endl; // Linea para probar que se esten guardando bien los inputs. ESTO NO VA

	return 0;
}
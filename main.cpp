#include <iostream>
#include <vector>
#include <cstring>

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
	string input("cin");
	string output("cout");
	string funcion("");

	for(int i = 1; i < argc; i++)
	{
		if(!strcmp(argv[i], "-i"))
		{
			if(i == argc - 1)
			{
				cout << USO_CORRECTO_MSG << endl;
				return 1;
			}

			input = string(argv[++i]);
		}

		else if(!strcmp(argv[i], "-o"))
		{
			if(i == argc - 1)
			{
				cout << USO_CORRECTO_MSG << endl;
				return 1;
			}

			output = string(argv[++i]);
		}

		else if(!strcmp(argv[i], "-f"))
		{
			if(i == argc - 1)
			{
				cout << USO_CORRECTO_MSG << endl;
				return 1;
			}

			funcion = string(argv[++i]);
		}

		else
		{
			cout << USO_CORRECTO_MSG << endl;
			return 1;
		}
	}

	// TODO: pasar funcion a minusculas

	// se verifican las funciones requeridas por el usuario
	if( funcion.compare( string("z") ) && funcion.compare( string("exp(z)") ) )
	{
		cout << "Las transformaciones habilitadas son z y exp(z)" << endl;
		return 1;
	}

	if(!input.compare( string("-") ))
		input = string("cin");

	if(!output.compare( string("-") ))
		output = string("cout");

	cout << input << " " << output << " " << funcion << endl; // Linea para probar que se esten guardando bien los inputs. ESTO NO VA

	return 0;
}
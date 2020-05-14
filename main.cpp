#include <iostream>
#include <vector>
#include <string>

#include "Complejo.h"
#include "Imagen.h"

using namespace std;

#define USO_CORRECTO_MSG "El uso correcto es: ./tp0 -i imag.pgm -o imagtranf.pgm -t [exp(z) / z]"

#define FLAG_INPUT "-i"
#define FLAG_OUTPUT "-o"
#define FLAG_FUNCION "-f"

// Guarda en input, output y funcion, las entradas correspondientes de la linea de comando
// devuelve false si no se respeto el formato
bool leerEntrada(int argc, char *argv[], string &input, string &output, string &funcion);

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

	if(!leerEntrada(argc, argv, input, output, funcion))
	{
		cout << USO_CORRECTO_MSG << endl;
		return 1;
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

bool leerEntrada(int argc, char *argv[], string &input, string &output, string &funcion)
{
	for(int i = 1; i < argc; i++)
	{
		string aux = argv[i]; // se pasa el argumento a string para poder aplicarle las funciones de la clase string

		if(!aux.compare(FLAG_INPUT))
		{
			if(i == argc - 1)
				return false;

			input = argv[++i];
		}

		else if(!aux.compare(FLAG_OUTPUT))
		{
			if(i == argc - 1)
				return false;

			output = argv[++i];
		}

		else if(!aux.compare(FLAG_FUNCION))
		{
			if(i == argc - 1)
				return false;

			funcion = argv[++i];
		}

		else
			return false;
	}
	return true;
}
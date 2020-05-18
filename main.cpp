#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Imagen.h"
#include "cmdline.h"

using namespace std;

#define USO_CORRECTO_MSG "El uso correcto es: tp0 -f funcion [-i file] [-o file]"

static void opt_input(string const &);
static void opt_output(string const &);
static void opt_funcion(string const &);
static void opt_help(string const &);

static option_t options[] = {
	{1, "i", "input", "-", opt_input, OPT_DEFAULT},
	{1, "o", "output", "-", opt_output, OPT_DEFAULT},
	{1, "f", "funcion", NULL, opt_funcion, OPT_MANDATORY},
	{0, "h", "help", NULL, opt_help, OPT_DEFAULT},
	{0, },
};

static string funcion;
static istream *iss = 0;	// Input Stream (clase para manejo de los flujos de entrada)
static ostream *oss = 0;	// Output Stream (clase para manejo de los flujos de salida)
static fstream ifs; 		// Input File Stream (derivada de la clase ifstream que deriva de istream para el manejo de archivos)
static fstream ofs;		// Output File Stream (derivada de la clase ofstream que deriva de ostream para el manejo de archivos)


int main(int argc, char *argv[])
{
	cmdline cmdl(options);	// Objeto con parametro tipo option_t (struct) declarado globalmente. Ver línea 51 main.cc
	cmdl.parse(argc, argv); // Metodo de parseo de la clase cmdline
	
	return 0;
}

static void
opt_input(string const &arg)
{
	// Si el nombre del archivos es "-", usaremos la entrada
	// estándar. De lo contrario, abrimos un archivo en modo
	// de lectura.
	//
	if (arg == "-")
		iss = &cin;		// Establezco la entrada estandar cin como flujo de entrada
	else
	{
		ifs.open(arg.c_str(), ios::in); // c_str(): Returns a pointer to an array that contains a null-terminated
										// sequence of characters (i.e., a C-string) representing
										// the current value of the string object.
		iss = &ifs;
	}

	// Verificamos que el stream este OK.
	//
	if (!iss->good()) {
		cerr << "No se puede abrir " << arg << "." << endl;
		exit(1);
	}
}

static void opt_output(string const &arg)
{
	// Si el nombre del archivos es "-", usaremos la salida
	// estándar. De lo contrario, abrimos un archivo en modo
	// de escritura.
	//
	if (arg == "-")
		oss = &cout;	// Establezco la salida estandar cout como flujo de salida
	else
	{
		ofs.open(arg.c_str(), ios::out);
		oss = &ofs;
	}

	// Verificamos que el stream este OK.
	//
	if (!oss->good())
	{
		cerr << "No se puede abrir " << arg << "." << endl;
		exit(1);		// EXIT: Terminación del programa en su totalidad
	}
}

static void opt_funcion(string const &arg)
{}

static void opt_help(string const &arg)
{
	cout << USO_CORRECTO_MSG << endl;
	exit(0);
}
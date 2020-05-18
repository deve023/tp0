#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstdlib>

#include "comando.h"

using namespace std;

static void opt_input(string const &);
static void opt_output(string const &);
static void opt_function(string const &);
static void opt_help(string const &);

static option_t options[] = {
	{1, "i", "input", "-", opt_input, OPT_DEFAULT},
	{1, "o", "output", "-", opt_output, OPT_DEFAULT},
	{1, "f", "function", "-", opt_function, OPT_DEFAULT},
	{0, "h", "help", NULL, opt_help, OPT_DEFAULT},
	{0, },
};

static string function;
static istream *iss = 0;
static ostream *oss = 0;
static fstream ifs;
static fstream ofs;

static void opt_input(string const &arg)
{
	
	if(arg == "-")
		iss = &cin;
	else
	{
		ifs.open(arg.c_str(), ios::in);
		iss = &ifs;
	}

	if (!iss->good())
	{
		cerr << "No se puede abrir " << arg << "." << endl;
		exit(1);
	}

	//NO SE HACE ACÁ PERO SIRVE  PARA LEER LINEA POR LINEA
	string line;
	while (ifs.good()){
        getline (ifs,line);
        cout << line<<" \n";
	}
}

static void opt_output(string const &arg)
{
	if(arg == "-")
		oss = &cout;
	else
	{
		ofs.open(arg.c_str(), ios::out);
		oss = &ofs;
	}

	if(!oss->good())
	{
		cerr << "No puede abrir " << arg << "." << endl;
		exit(1);
	}

	//COMO ESCRIBIR EN EL ARCHIVO
	ofs<<"P2"<<endl<<"segunda linea"<<endl;
}

static void opt_function(string const &arg)
{

	istringstream iss(arg);
	
	if(iss.bad() || !(iss >> function))
	{
		cerr << "no puede leer la transformación." << endl;
		exit(1);
	}
	
	// Funcion por defecto
	if(!function.compare("-")) 
		function = "z";

	// se verifica que se haya pasado una funcion viable
	if(function.compare("exp(z)") && function.compare("z"))
	{
		cerr << arg << " no es una  transformación aceptada." << endl;
		exit(1);
	}
}

static void opt_help(string const &arg)
{
	cout << "tp0 [-f function] [-i file] [-o file]"
	     << endl;
	exit(0);
}

int main(int argc, char * const argv[])
{

	comando comando(options);
	comando.parse(argc, argv);

	//cout << function << endl;
	//opt_function ("exp(z)");
	//cout<<function<<endl;
	//opt_output("file.pgm");
	//opt_input("file.pgm");
	//opt_help("");
}
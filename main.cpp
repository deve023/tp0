#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstdlib>



#include <comando.h>

using namespace std;

string function;
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

static istream *iss = 0;
static ostream *oss = 0;
static fstream ifs;
static fstream ofs;

static void opt_input(string const &arg)
{
	
	if (arg == "-") {
		iss = &cin;
	} else {
		ifs.open(arg.c_str(), ios::in);
		iss = &ifs;
	}

	if (!iss->good()) {
		cerr << "cannot open "
		     << arg
		     << "."
		     << endl;
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
	if (arg == "-") {
		oss = &cout;
	} else {
		ofs.open(arg.c_str(), ios::out);
		oss = &ofs;
	}

	if (!oss->good()) {
		cerr << "no puede abrir "
		     << arg
		     << "."
		     << endl;
		exit(1);
	}
	//COMO ESCRIBIR EN EL ARCHIVO
	ofs<<"P2"<<endl<<"segunda linea"<<endl;
}

static void opt_function(string const &arg)
{
	if (arg == "-") 
		;
		//hago transformacion identidad

	istringstream iss(arg);
	
	
	if (!(iss >> function)) {
		cerr << "no es una  transformación: "
		     << arg
		     << "."
		     << endl;
		exit(1);
	}

	if (iss.bad()) {
		cerr << "no puede leer la transformación."
		     << endl;
		exit(1);
	}

	if (!(function.compare("exp(z)")))
		;//hago transformación exponencial
	else if (!(function.compare("z")))
		;
		//hago transformación identidad
	else {
		cerr << "no es una  transformación: "
		     << arg
		     << "."
		     << endl;
		exit(1);
	}

	//TENGO EN FUNCTION GUARDADA LA TRANSFORMACIÓN QUE TENGO QUE HACER
}

static void opt_help(string const &arg)
{
	cout << "tp0 [-f function] [-i file] [-o file]"
	     << endl;
	exit(0);
}

int main(){
	//opt_function ("exp(z)");
	//cout<<function<<endl;
	//opt_output("file.pgm");
	//opt_input("file.pgm");
	//opt_help("");
}
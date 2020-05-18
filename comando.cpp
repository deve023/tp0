#include <string>
#include <cstdlib>
#include <iostream>

#include "comando.h"

comando::comando()
{}

comando::comando(option_t *table) : option_table(table)
{}

void comando::parse(int argc, char * const argv[])
{

#define END_OF_OPTIONS(p)       \
	((p)->short_name == 0   \
	 && (p)->long_name == 0 \
	 && (p)->parse == 0)

	for (option_t *op = option_table; !END_OF_OPTIONS(op); ++op)
		op->flags &= ~OPT_SEEN;

	for (int i = 1; i < argc; ++i)
	{
		// Todos los parámetros de este programa deben
		// pasarse en forma de opciones. Encontrar un
		// parámetro no-opción es un error.
		//
		if (argv[i][0] != '-')
		{
			cerr << "Argumento invalido, no es opcion: " << argv[i] << endl;
			exit(1);
		}

		if (argv[i][1] == '-' && argv[i][2] == 0)
				break;

		if (argv[i][1] == '-')
				i += do_long_opt(&argv[i][2], argv[i + 1]);
			else
				i += do_short_opt(&argv[i][1], argv[i + 1]);
	}

	for (option_t *op = option_table; !END_OF_OPTIONS(op); ++op)
	{

#define OPTION_NAME(op) \
	(op->short_name ? op->short_name : op->long_name)

		if(op->flags & OPT_SEEN)
			continue;
		
		if(op->def_value == 0)
			continue;
		op->parse(string(op->def_value));
	}
}

int comando::do_long_opt(const char *opt, const char *arg)
{
	for(option_t *op = option_table; op->long_name != 0; ++op)
	{
		if(string(opt) == string(op->long_name))
		{	
			op->flags |= OPT_SEEN;

			if(op->has_arg)
			{	
				if(arg == 0)
				{
					cerr << "La siguiente opcion requiere un argumento: " << "--" << opt << "\n";
					exit(1);
				}
				op->parse(string(arg));
				return 1;
			}
			else
			{
				op->parse(string(""));
				return 0;
			}
		}
	}

	cerr << "Opcion desconocida: " << "--" << opt << "." << endl;
	exit(1);

	return -1; // Valor de retorno para calmar al compilador
}

int comando::do_short_opt(const char *opt, const char *arg)
{
	option_t *op;

	for(op = option_table; op->short_name != 0; ++op)
	{
		if(string(opt) == string(op->short_name))
		{	
			op->flags |= OPT_SEEN;

			if(op->has_arg)
			{	
				if(arg == 0)
				{
					cerr << "La siguiente opcion requiere un argumento: " << "-" << opt << "\n";
					exit(1);
				}
				op->parse(string(arg));
				return 1;
			}
			else
			{
				op->parse(string(""));
				return 0;
			}
		}
	}

	cerr << "Opcion desconocida: " << "-" << opt << "." << endl;
	exit(1);

	return -1; // Valor de retorno para calmar al compilador
}
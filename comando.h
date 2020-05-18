#ifndef _COMANDO_H_INCLUDED_
#define _COMANDOH_INCLUDED_

#include <string>
#include <iostream>

#define OPT_DEFAULT   0
#define OPT_SEEN      1

struct option_t {
	int has_arg;
	const char *short_name;
	const char *long_name;
	const char *def_value;
	void (*parse)(std::string const &);
	int flags;
};

class comando {

	option_t *option_table;

	comando();
	int do_long_opt(const char *, const char *);
	int do_short_opt(const char *, const char *);
public:
	comando(option_t *);
	void parse(int, char * const []);
};

#endif
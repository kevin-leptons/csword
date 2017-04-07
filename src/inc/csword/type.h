/*
SYNOPSIS

	General types.

DESCRIPTION

RETURN

ERRORS

FILES

BUGS

AUTHOR

	Kevin Leptons <kevin.leptons@gmail.com>
*/

#ifndef __CSWORD_TYPE_H__
#define __CSWORD_TYPE_H__

#include <linux/limits.h>

#include <csword/version.h>

enum tbool
{
	T_FALSE = 0,
	T_TRUE = 1,
	T_UNDEF = 2
};

#if _WIN32 || _WIN64
	#define DELIMITER '\\'
	#define DELIMITER_STR "\\"
#else
	#define DELIMITER '/'
	#define DELIMITER_STR "/"
#endif

enum ptype
{
	LIB,
	CMD,
	GUI
};

struct csinfo
{
	char name[NAME_MAX];
	char author[NAME_MAX];
	char email[NAME_MAX];
	char license[NAME_MAX];
	struct version version;
	enum ptype type;
};

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

#endif

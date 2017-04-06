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

#endif

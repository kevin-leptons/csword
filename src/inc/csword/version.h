/*
SYNOPSIS

DESCRIPTION

RETURN

ERRORS

FILES

BUGS

AUTHOR

	Kevin Leptons <kevin.leptons@gmail.com>
*/

#ifndef __CSWORD_VERSION_H__
#define __CSWORD_VERSION_H__

#include <stdint.h>

struct version
{
	uint32_t major;
	uint32_t minor;
	uint32_t revison;
	uint32_t build;
};

const extern struct version _VERSION;

char *strver(const struct version *ver, char *str);

#endif

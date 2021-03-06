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
#include <stdlib.h>

#define VERSION_STR_MAX 255

struct version
{
	uint32_t major;
	uint32_t minor;
	uint32_t revison;
	uint32_t build;
};

const extern struct version _VERSION;

int strver(const struct version *ver, char *str, size_t size);

#endif

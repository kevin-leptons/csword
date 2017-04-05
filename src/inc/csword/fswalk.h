/*
SYNOPSIS

	Walk on file system.

DESCRIPTION

RETURN

ERRORS

FILES

BUGS

AUTHOR

	Kevin Leptons <kevin.leptons@gmail.com>
*/

#ifndef __CSWORD_FSWALK_H__
#define __CSWORD_FSWALK_H__

#include <stdio.h>

int fswalk(const char *path,
	int (*handler)(const char *path, const FILE *file));

#endif

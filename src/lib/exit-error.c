/*
DESCRIPTION

	Implement exit_error()

AUTHOR

	Kevin Leptons <kevin.leptons@gmail.com>
*/

#include <csword/error.h>

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void exit_error(const char *caller)
{
	fprintf(stderr, "Error: %s\n%s\n", caller, strerror(errno));
	exit(EXIT_FAILURE);
}

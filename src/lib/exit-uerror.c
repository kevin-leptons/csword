/*
DESCRIPTION

	Implement exit_uerror()

AUTHOR

	Kevin Leptons <kevin.leptons@gmail.com>
*/

#include <csword/error.h>

#include <stdlib.h>
#include <stdio.h>

void exit_uerror(const char *msg)
{
	fprintf(stderr, "Error: %s\n", msg);
	exit(EXIT_FAILURE);
}

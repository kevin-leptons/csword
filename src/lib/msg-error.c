/*
DESCRIPTION

	Implement msg_error()

AUTHOR

	Kevin Leptons <kevin.leptons@gmail.com>
*/

#include <csword/error.h>

#include <stdio.h>

void msg_error(const char *msg)
{
	fprintf(stderr, "Error: %s\n", msg);
}

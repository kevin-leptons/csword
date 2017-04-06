/*
DESCRIPTION

	Implement fgwalk()

AUTHOR

	Kevin Leptons <kevin.leptons@gmail.com>
*/

#include <csword/fswalk.h>

#include <csword/error.h>

int fswalk(const char *path,
	int (*handler)(const char *path, const FILE *file))
{
	return FN_OK;
}

/*
DESCRIPTION

	Implement mk_cspec()

AUTHOR

	Kevin Leptons <kevin.leptons@gmail.com>
*/

#include <csword/fs.h>

#include <string.h>

void mk_cspec(struct cspec *spec, const char *src, const char* dest)
{
	strcpy(spec->src, src);
	strcpy(spec->dest, dest);
}

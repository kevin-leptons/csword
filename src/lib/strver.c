/*
DESCRIPTION

	Implement strver()

AUTHOR

	Kevin Leptons <kevin.leptons@gmail.com>
*/

#include <csword/version.h>

#include <stdio.h>

#include <csword/error.h>

const struct version _VERSION = {
	.major = 0, .minor = 1, .revison = 0, .build = 0
};

int strver(const struct version *ver, char *str, size_t size)
{
	snprintf(str, size, "%i.%i.%i.%i",
			ver->major, ver->minor, ver->revison, ver->build);

	return FN_OK;
}

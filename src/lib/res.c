/*
DESCRIPTION

	Implement res()

AUTHOR

	Kevin Leptons <kevin.leptons@gmail.com>
*/

#include <csword/res.h>

#include <csword/error.h>
#include <string.h>

int res(const char *rpath, char *buf)
{
	strcpy(buf, RES_PATH);
	strcat(buf, rpath);

	return FN_OK;
}

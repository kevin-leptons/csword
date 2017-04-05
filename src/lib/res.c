/*
DESCRIPTION

	Implement res()

AUTHOR

	Kevin Leptons <kevin.leptons@gmail.com>
*/

#include <csword/res.h>

#include <csword/error.h>

int res(const char *rpath, char *buf)
{
	strcpy(buf, RES_PATH);

	return FN_OK;
}

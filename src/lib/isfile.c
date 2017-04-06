/*
DESCRIPTION

	Implement isfile()

AUTHOR

	Kevin Leptons <kevin.leptons@gmail.com>
*/

#include <csword/fs.h>

#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

enum tbool isfile(const char *path)
{
	return T_FALSE;
}

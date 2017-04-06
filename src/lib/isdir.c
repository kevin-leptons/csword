/*
DESCRIPTION

	Implement isdir()

AUTHOR

	Kevin Leptons <kevin.leptons@gmail.com>
*/

#include <csword/fs.h>

#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

enum tbool isdir(const char *path)
{
	struct stat s;

	errno = 0;
	if (stat(path, &s) == 0)
		return S_ISDIR(s.st_mode) ? T_TRUE : T_FALSE;

	if (errno == ENOENT || errno == ENOTDIR)
		return T_FALSE;

	return T_UNDEF;
}

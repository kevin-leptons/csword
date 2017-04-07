/*
DESCRIPTION

	Implement read_con()

AUTHOR

	Kevin Leptons <kevin.leptons@gmail.com>
*/

#include <csword/fs.h>

#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <csword/error.h>

size_t read_con(FILE *file, char *buf, size_t size,
				const char *begin, const char *end)
{
	size_t rsize;
	char *fn = buf + size;

	if (begin > fn || end > fn || begin > end)
		return -1;

	errno = 0;
	rsize = end - begin;
	if (rsize == 0)
		return fread(buf, 1, size, file);

	memcpy(buf, begin, rsize);
	return fread(buf + rsize + 1, 1, size, file);
}

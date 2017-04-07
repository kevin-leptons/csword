/*
SYNOPSIS

DESCRIPTION

RETURN

ERRORS

FILES

BUGS

AUTHOR

	Kevin Leptons <kevin.leptons@gmail.com>
*/

#ifndef __CSWORD_FS_H__
#define __CSWORD_FS_H__

#include <sys/types.h>

#include <stdlib.h>
#include <stdio.h>

#include <csword/type.h>

#define FS_BLKSIZE 4096

struct cspec
{
	char src[NAME_MAX];
	char dest[NAME_MAX];
};

enum tbool isdir(const char *path);

enum tbool isfile(const char *path);

int make_dir(const char *path, mode_t mode);

int pjoin(char *dest, const char *first, const char *last);

int fcopy(const char *src, const char *dest);

int fclone(const char *src, const char *dest, const struct cspec *spec,
	size_t size);

void mk_cspec(struct cspec *spec, const char *src, const char* dest);

size_t read_con(FILE *file, char *buf, size_t size,
				const char *begin, const char *end);

#endif

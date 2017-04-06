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

#include <csword/type.h>

enum tbool isdir(const char *path);

enum tbool isfile(const char *path);

int make_dir(const char *path, mode_t mode);

int pjoin(char *dest, const char *first, const char *last);

int fcopy(const char *src, const char *dest);

#endif

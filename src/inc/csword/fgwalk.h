/*
SYNOPSIS

	Walk on file graph.

DESCRIPTION

RETURN

ERRORS

FILES

BUGS

AUTHOR

	Kevin Leptons <kevin.leptons@gmail.com>
*/

#ifndef __CSWORD_FGWALK_H__
#define __CSWORD_FGWALK_H__

#include <stdlib.h>

struct fnode
{
	char *name;
	struct fnode *child;
	struct fnode *next;
	size_t nchild;
};

int fgwalk(const struct fnode *root,
	int (*handler)(const struct fnode *node));

#endif

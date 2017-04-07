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

#ifndef __CSWORD_CMD_H__
#define __CSWORD_CMD_H__

#include <csword/type.h>

int cmd_help(void);

int cmd_version(void);

int cmd_create(const struct csinfo *info, const char *dir);

#endif

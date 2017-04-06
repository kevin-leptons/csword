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

enum ptype
{
	LIB,
	CMD,
	GUI
};

int cmd_help(void);

int cmd_version(void);

int cmd_create(const char *dir, enum ptype type);

#endif

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

#ifndef __CSWORD_ERROR_H__
#define __CSWORD_ERROR_H__

#define FN_OK 0
#define FN_ER -1

void exit_error(const char *caller);

void exit_uerror(const char *msg);

void msg_error(const char *msg);

#endif

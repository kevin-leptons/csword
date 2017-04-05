/*
SYNOPSIS

	Control resource files.

DESCRIPTION

RETURN

ERRORS

FILES

BUGS

AUTHOR

	Kevin Leptons <kevin.leptons@gmail.com>
*/

#ifndef __CSWORD_RES_H__
#define __CSWORD_RES_H__

#ifdef CSWORD_DEBUG
#define RES_PATH "../res"
#elif __linux__
#define RES_PATH "/usr/share"
#elif __WIN32__ || _WIN64
#define RES_PATH "res"
#error "Doen't support OS type"
#endif

int res(const char *rpath, char *buf);

#endif

/*
DESCRIPTION

	Implement pjoin()

AUTHOR

	Kevin Leptons <kevin.leptons@gmail.com>
*/

#include <csword/fs.h>

#include <string.h>

#include <csword/error.h>
#include <csword/type.h>
#include <stdio.h>

int pjoin(char *dest, const char *first, const char *last)
{
	strcpy(dest, first);
	strcat(dest, DELIMITER_STR);
	strcat(dest, last);

	return FN_OK;
}

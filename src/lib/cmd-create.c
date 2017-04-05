/*
DESCRIPTION

	Implement cmd_create()

AUTHOR

	Kevin Leptons <kevin.leptons@gmail.com>
*/

#include <csword/cmd.h>

#include <stdio.h>

#include <archive_entry.h>

#include <csword/error.h>
#include <csword/limit.h>
#include <csword/res.h>

int cmd_create(const char *dir)
{
	char buf[PATH_MAX];
	if (res("pkg-tmp.tar.gz", buf) != FN_OK)
		return FN_ER;

	printf("absolute path: %s\n", buf);

	return FN_OK;
}

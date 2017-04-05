/*
DESCRIPTION

	Implement cmd_version()

AUTHOR

	Kevin Leptons <kevin.leptons@gmail.com>
*/

#include <csword/cmd.h>

#include <stdio.h>

#include <csword/version.h>

int cmd_version(void)
{
	printf("csword v%s\n", strver(&_VERSION, NULL));
}

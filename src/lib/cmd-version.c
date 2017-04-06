/*
DESCRIPTION

	Implement cmd_version()

AUTHOR

	Kevin Leptons <kevin.leptons@gmail.com>
*/

#include <csword/cmd.h>

#include <stdio.h>

#include <csword/error.h>
#include <csword/version.h>

int cmd_version(void)
{
	char buf[VERSION_STR_MAX];

	strver(&_VERSION, buf, sizeof(buf));
	printf("csword v%s, %s %s\n", buf, __DATE__, __TIME__);

	return FN_OK;
}

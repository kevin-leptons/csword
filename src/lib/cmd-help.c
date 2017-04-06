/*
DESCRIPTION

	Implement cmd_help()

AUTHOR

	Kevin Leptons <kevin.leptons@gmail.com>
*/

#include <csword/cmd.h>

#include <stdio.h>

#include <csword/error.h>

int cmd_help(void)
{
	printf(
		"USAGE\n"
		"\tcsword <command> <arguments>\n"
		"COMMANDS\n"
		"\tcreate <type> <dir>: Create C a package in <dir> directory\n"
		"\tverify <dir>: Verify C package in <dir> directory\n"
	);

	return FN_OK;
}

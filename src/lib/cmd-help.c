/*
DESCRIPTION

	Implement cmd_help()

AUTHOR

	Kevin Leptons <kevin.leptons@gmail.com>
*/

#include <csword/cmd.h>

#include <stdio.h>

int cmd_help(void)
{
	printf(
		"USAGE\n"
		"\tcsword <command> <arguments>\n"
		"COMMANDS\n"
		"\tcreate <dir>\tCreate C a package in <dir> directory\n"
		"\tverify <dir>\tVerify C package in <dir> directory\n"
	);
}

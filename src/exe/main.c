/*
SYSNOPSIS

	csword create <dir>

DESCRIPTION

RETURN

BUGS

FILES

AUTHOR

	Kevin Leptons <kevin.leptons@gmail.com>
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <csword/error.h>
#include <csword/cmd.h>

int main(int argc, char *argv[])
{
	if (argc == 2) {
		if (strcmp(argv[1], "help") == 0)
			return cmd_help();

		cmd_help();
		return EXIT_FAILURE;
	}

	if (argc == 3) {
		if (strcmp(argv[1], "create") == 0)
			return cmd_create(argv[2]);
		else
			cmd_help();

		return EXIT_FAILURE;
	}

	cmd_help();
    return EXIT_FAILURE;
}

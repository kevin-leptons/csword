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
	enum ptype pkg_type;

	if (argc == 2) {
		if (strcmp(argv[1], "help") == 0)
			return cmd_help();
		else if (strcmp(argv[1], "version") == 0)
			return cmd_version();

		cmd_help();
		return EXIT_FAILURE;
	}

	if (argc == 4) {
		if (strcmp(argv[1], "create") == 0) {
			if (strcmp(argv[2], "lib") == 0)
				pkg_type = LIB;
			else if (strcmp(argv[2], "cmd") == 0)
				pkg_type = CMD;
			else if (strcmp(argv[2], "gui") == 0)
				pkg_type = GUI;
			else
				exit_uerror("Specify package type: lib, cmd, gui");

			return cmd_create(argv[3], pkg_type);
		}

		cmd_help();
		return EXIT_FAILURE;
	}

	cmd_help();
    return EXIT_FAILURE;
}

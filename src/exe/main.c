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
#include <csword/type.h>

int main(int argc, char *argv[])
{
	struct csinfo info;

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
				info.type = LIB;
			else if (strcmp(argv[2], "cmd") == 0)
				info.type = CMD;
			else if (strcmp(argv[2], "gui") == 0)
				info.type = GUI;
			else
				exit_uerror("Specify package type: lib, cmd, gui");

			strcpy(info.name, "CSWORD");
			strcpy(info.author, "Kevin Leptons");
			strcpy(info.email, "kevin.leptons@gmail.com");
			strcpy(info.license, "GPLv3");
			info.version.major = 0;
			info.version.minor = 1;
			info.version.revison = 0;
			info.version.build = 0;
			return cmd_create(&info, argv[3]);
		}

		cmd_help();
		return EXIT_FAILURE;
	}

	cmd_help();
    return EXIT_FAILURE;
}

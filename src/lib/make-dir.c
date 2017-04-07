/*
DESCRIPTION

	Implement make_dir()

AUTHOR

	Kevin Leptons <kevin.leptons@gmail.com>
*/

#include <csword/fs.h>

#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <linux/limits.h>

#include <csword/error.h>

int make_dir(const char *path, mode_t mode)
{
	char tpath[PATH_MAX];
	char *p;
	size_t len;

	errno = 0;
	strcpy(tpath, path);
	len = strlen(tpath);

	if (len > 0) {
		if (tpath[0] == DELIMITER)
			p = tpath + 1;
		else
			p = tpath;

		if (tpath[len - 1] == DELIMITER)
			tpath[len - 1] = '\0';
	}

	for (; *p != '\0'; p++) {
		if (*p != DELIMITER)
			continue;

		*p = '\0';
		errno = 0;
		mkdir(tpath, mode);
		*p = DELIMITER;
		if (errno == 0 || errno == EEXIST)
			continue;
		else
			return FN_ER;

		break;
	}

	return mkdir(tpath, mode);
}

/*
DESCRIPTION

	Implement fcopy()

AUTHOR

	Kevin Leptons <kevin.leptons@gmail.com>
*/

#include <csword/fs.h>

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/limits.h>

#include <csword/error.h>

#define BUF_SIZE 1024
#define NEW_FILE_MODE S_IRWXU | S_IRWXG | S_IRWXO

int fcopy(const char *src, const char *dest)
{
	char buf[BUF_SIZE];
	int fds, fdd;
	size_t rsize;

	fds = open(src, O_RDONLY);
	if (fds == FN_ER)
		return FN_ER;

	fdd = open(dest, O_CREAT | O_CREAT | O_WRONLY, NEW_FILE_MODE);
	if (fdd == FN_ER) {
		close(fds);
		return FN_ER;
	}

	for (;;) {
		// read data block from src file
		rsize = read(fds, buf, BUF_SIZE);
		if (rsize < 0) {
			close(fds);
			close(fdd);
			return FN_ER;
		} else if (rsize == 0) {
			break;
		}

		// write data block to dest file
		if (write(fdd, buf, rsize) == FN_ER) {
			close(fds);
			close(fdd);
			return FN_ER;
		}
	}

	close(fds);
	close(fdd);

	return FN_OK;
}

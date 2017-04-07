/*
DESCRIPTION

	Implement fclone()

AUTHOR

	Kevin Leptons <kevin.leptons@gmail.com>
*/

#include <csword/fs.h>

#include <errno.h>
#include <stdio.h>
#include <string.h>

#include <csword/error.h>

const struct cspec *first_match(char **f, char **m, const char *c,
								const struct cspec *spec, size_t ssize);
const struct cspec *other_match(char **f, char **m, const char n,
								const struct cspec *spec, size_t ssize);
size_t match_str(const char *a, const char *b);

int fclone(const char *src, const char *dest, const struct cspec *spec,
	size_t size)
{
	FILE *fr = NULL;
	FILE *fw = NULL;
	char rbuf[FS_BLKSIZE];
	char *b;
	char *e;
	char *s;
	char *f;
	char *m;
	char *lw;
	size_t rsize;
	size_t wsize;
	const struct cspec *mspec = NULL;

	errno = 0;
	fr = fopen(src, "r");
	if (fr == NULL)
		return FN_ER;
	fw = fopen(dest, "w");
	if (fw == NULL || errno != 0)
		goto ERROR;

	for (lw = rbuf, b = NULL, s = NULL, e = NULL, f = NULL, m = NULL;; s++) {
		// push to dest file
		if (e != NULL && s == e) {
			if (f == NULL) {
				wsize = e - lw + 1;
				if (fwrite(lw, 1, wsize, fw) < wsize)
					goto ERROR;
				lw = s;
				e = NULL;
			}
			else {
				wsize = b - lw;
				if (fwrite(lw, 1, wsize, fw) < wsize)
					goto ERROR;
				wsize = e - b + 1;
				memcpy(rbuf, b, wsize);
				b = rbuf + (b - lw);
				e = rbuf + (e - lw);
				s = e;
				lw = rbuf;
			}
		}

		// pull from src file
		if (s == e) {
			if (e == NULL) {
				rsize = fread(rbuf, 1, sizeof(rbuf), fr);
				if (errno != 0)
					goto ERROR;
				else if (rsize == 0)
					break;
				lw = rbuf;
				s = rbuf;
				e = rbuf + rsize;
			} else {
				rsize = fread(e + 1, 1, sizeof(rbuf) - (e - rbuf + 1), fr);
				if (errno != 0)
					goto ERROR;
				else if (rsize == 0)
					break;
				e = e + rsize;
			}
		}

		// start matching
		if (f == NULL) {
			mspec = first_match(&f, &m, s, spec, size);
			if (mspec != NULL)
				b = s;
		}

		// started matching but didn't finished
		if (f != NULL && *m != '\0') {
			if (*s == *m)
				m++;
			else {
				f = NULL;
				m = NULL;
				b = NULL;
			}

			// if (*s != *m) {
			// 	mspec = other_match(&f, &m, *s, spec, size);
			// 	if (mspec == NULL) {
			// 		b = NULL;
			// 		f = NULL;
			// 		m = NULL;
			// 		s--;
			// 	}
			// }
			// else {
			// 	m++;
			// }
		}

		// finished matching, replace and reset
		if (f != NULL && *m == '\0') {
			wsize = b - lw;
			if (fwrite(lw, 1, wsize, fw) < wsize)
				goto ERROR;
			lw = s + 1;
			wsize = strlen(mspec->dest);
			if (fwrite(mspec->dest, 1, wsize, fw) < wsize)
				goto ERROR;
			b = NULL;
			f = NULL;
			m = NULL;
			mspec = NULL;
		}
	}

	// write rest of data
	if (e != NULL) {
		wsize = e - lw;
		fwrite(lw, 1, wsize, fw);
		if (errno != 0)
			goto ERROR;
	}

	fclose(fr);
	fclose(fw);
	return FN_OK;

ERROR:
	if (fr != NULL)
		fclose(fr);
	if (fw != NULL)
		fclose(fw);
	return FN_ER;
}

const struct cspec *first_match(char **f, char **m, const char *c,
				const struct cspec *spec, size_t ssize)
{
	size_t msize;
	size_t tsize;
	size_t i;
	const struct cspec *p;
	const struct cspec *mspec = NULL;

	*f = NULL;
	*m = NULL;
	for (i = 0, msize = 0; i < ssize; i++) {
		p = spec + i;
		if (p->src[0] == *c) {
			tsize = strlen(p->src);
			if (tsize > msize) {
				*f = (char *) p->src;
				*m = (char *) p->src;
				msize = tsize;
				mspec = p;
			}
		}
	}

	return mspec;
}

const struct cspec *other_match(char **f, char **m, const char n,
								const struct cspec *spec, size_t ssize)
{
	size_t msize;
	size_t tsize;
	size_t csize;
	size_t i;
	char *omatch = *f;
	const struct cspec *p;
	const struct cspec *mspec;
	char tmp[NAME_MAX];

	csize = *m - *f;
	memcpy(tmp, *f, csize);
	tmp[csize] = n;
	tmp[csize + 1] = '\0';

	for (i = 0, msize = 0, mspec = NULL; i < ssize; i++) {
		p = spec + i;
		if (p->src == omatch)
			continue;
		tsize = match_str(p->src, tmp);
		if (tsize > msize) {
			*f = (char *) p->src;
			*m = *f + tsize;
			msize = tsize;
			mspec = p;
		}
	}

	return mspec;
}

size_t match_str(const char *a, const char *b)
{
	size_t i;

	for (i = 0; i < strlen(b); i++) {
		if (*(a + i) != *(b + i))
			break;
	}

	return i;
}

/*
DESCRIPTION

	Implement cmd_create()

AUTHOR

	Kevin Leptons <kevin.leptons@gmail.com>
*/

#include <csword/cmd.h>

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <linux/limits.h>

#include <archive_entry.h>

#include <csword/error.h>
#include <csword/limit.h>
#include <csword/res.h>
#include <csword/fs.h>

static int create_ske(const struct csinfo *info, const char *dir);
static int create_lib(const struct csinfo *info, const char *dir);
static int create_cmd(const struct csinfo *info, const char *dir);
static int create_gui(const struct csinfo *info, const char *dir);

int cmd_create(const struct csinfo *info, const char *dir)
{
	if (info->type == LIB)
		return create_lib(info, dir);
	else if (info->type == CMD)
		return create_cmd(info, dir);
	else if (info->type == GUI)
		return create_gui(info, dir);
	else
		return FN_ER;
}

static int create_ske(const struct csinfo *info, const char *dir)
{
	char src[PATH_MAX], dest[PATH_MAX];
	enum tbool is_dir;
	struct cspec spec[4];

	is_dir = isdir(dir);
	if (is_dir == T_TRUE) {
		msg_error("Directory is early exist");
		return FN_ER;
	} else if (is_dir == T_UNDEF) {
		msg_error("Permission is denie");
		return FN_ER;
	}
	if (make_dir(dir, S_IRWXU | S_IRWXG | S_IRWXO) != FN_OK)
		exit_error("make_dir");

	if (res("ske-tmp/readme.md", src) != FN_OK)
		exit_error("res");
	if (pjoin(dest, dir, "readme.md") != FN_OK)
		exit_error("pjoin");
	mk_cspec(&spec[0], "$PKG_NAME", info->name);
	mk_cspec(&spec[1], "$AUTHOR", info->author);
	mk_cspec(&spec[2], "$LICENSE", info->license);
	mk_cspec(&spec[3], "$EMAIL", info->email);
	if (fclone(src, dest, spec, 2) != FN_OK)
		exit_error("fclone");

	printf("Package was created: %s\n", dir);
	return FN_OK;
}

static int create_lib(const struct csinfo *info, const char *dir)
{
	if (create_ske(info, dir) != FN_OK)
		return FN_ER;

	return FN_OK;
}

static int create_cmd(const struct csinfo *info, const char *dir)
{
	if (create_ske(info, dir) != FN_OK)
		return FN_ER;

	return FN_OK;
}

static int create_gui(const struct csinfo *info, const char *dir)
{
	if (create_ske(info, dir) != FN_OK)
		return FN_ER;

	return FN_OK;
}

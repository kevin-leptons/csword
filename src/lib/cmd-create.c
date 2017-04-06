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

static int create_ske(const char *name, const char *dir);
static int create_lib(const char *name, const char *dir);
static int create_cmd(const char *name, const char *dir);
static int create_gui(const char *name, const char *dir);

int cmd_create(const char *dir, enum ptype type)
{
	char name[NAME_MAX];

	if (type == LIB)
		return create_lib(name, dir);
	else if (type == CMD)
		return create_cmd(name, dir);
	else if (type == GUI)
		return create_gui(name, dir);
	else
		return FN_ER;
}

static int create_ske(const char*name, const char *dir)
{
	char src[PATH_MAX], dest[PATH_MAX];
	enum tbool is_dir;

	printf("Create package in: %s\n", dir);

	is_dir = isdir(dir);
	if (is_dir == T_TRUE) {
		msg_error("Directory is early exist");
		return FN_ER;
	} else if (is_dir == T_UNDEF) {
		msg_error("Permission is denie");
		return FN_ER;
	}
	if (make_dir(dir, S_IRUSR | S_IWUSR | S_IXUSR) != 0)
		return FN_ER;

	if (res("ske-tmp/readme.md", src) != FN_OK)
		return FN_ER;
	if (pjoin(dest, dir, "readme.md") != FN_OK)
		return FN_ER;
	if (fcopy(src, dest) != FN_OK)
		return FN_ER;

	return FN_OK;
}

static int create_lib(const char *name, const char *dir)
{
	if (create_ske(name, dir) != FN_OK)
		return FN_ER;

	return FN_OK;
}

static int create_cmd(const char *name, const char *dir)
{
	if (create_ske(name, dir) != FN_OK)
		return FN_ER;

	return FN_OK;
}

static int create_gui(const char *name, const char *dir)
{
	if (create_ske(name, dir) != FN_OK)
		return FN_ER;

	return FN_OK;
}

#!/bin/bash

# SPEC      : control repository
# AUTHOR    : kevin.leptons@gmail.com

# bash options
set -e

# variables
VERSION="0.1.0"
ROOT=$(realpath .)
SRC="$ROOT/src"
DEST="$ROOT/dest"
DIST="$ROOT/dist"
PACK="$ROOT/pack"
RES="$ROOT/res"

# help menu
HELP="USAGE:\n
    $(basename $0) [commands]

COMMANDS

    build        build repo
    dist         build distribution
    install      install repo
    clean        clean build
    remove       remove repo
    -h           show help menu\n"

repo_build()
{
	local PKG_TMP_DIR="pkg-tmp"

    # prepare
    mkdir -vp $DEST
    cd $DEST

	# create template compress files
	# tar -zcvf $DEST/$PKG_TMP_DIR.tar.gz -C $RES $PKG_TMP_DIR

    # build
    cmake $ROOT -DCSWORD_DEBUG=1
    make
}

repo_dist()
{
	cd $DEST
	make install
}

repo_install()
{
    echo "Not implemented"
    exit 1
}

repo_clean()
{
    rm -rfv $DEST $PACK $DIST
}

repo_remove()
{
    echo "Not implemented"
    exit 1
}

show_help()
{
    printf "$HELP"
}

# parse arguments
case "$1" in
    build) repo_build; exit 0;;
    dist) repo_dist; exit 0;;
    install) repo_install; exit 0;;
    clean) repo_clean; exit 0;;
    remove) repo_remove; exit 0;;
    -h) show_help; exit 0;;
    *) show_help; exit 1;;
esac

/*
SYNOPSIS

	Control resource files.

DESCRIPTION

RETURN

ERRORS

FILES

BUGS

AUTHOR

	Kevin Leptons <kevin.leptons@gmail.com>
*/

#ifndef __CSWORD_RES_H__
#define __CSWORD_RES_H__

#if CMAKE_BUILD_TYPE == DEBUG
	#if __linux__
		#define RES_PATH CMAKE_BINARY_DIR "/res/"
	#elif __WIN32__ || _WIN64
		#define RES_PATH "..\\res\\"
	#else
		#error "Doen't support OS type"
	#endif
#else
	#if __linux__
		#define RES_PATH "/usr/share/"
	#elif __WIN32__ || _WIN64
		#define RES_PATH ".\res\\"
	#else
		#error "Doen't support OS type"
	#endif
#endif

int res(const char *rpath, char *buf);

#endif

#pragma once

#include <errno.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#ifdef HAVE_ALLOCA_H
#include <alloca.h>
#endif
#include <string.h>
#ifndef _WIN32
#include <unistd.h>
#endif
#ifdef NCURSES
#include <curses.h>
#endif
#include <locale.h>
#include <math.h>
#include <stddef.h>
#include <sys/stat.h>

#include "cava/common.h"
#include "util.h"

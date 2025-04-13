#pragma once

#include "../cavacore.h"
#include "../config.h"
#include "../input/common.h"

#ifdef SDL
#include "sdl_cava.h"
#endif

#ifdef SDL_GLSL
#include "sdl_glsl.h"
#endif

#include "noritake.h"
#include "raw.h"
#include "terminal_noncurses.h"

#ifndef _WIN32
#ifdef NCURSES
#include "terminal_bcircle.h"
#include "terminal_ncurses.h"
#include <curses.h>
#endif

#endif

struct audio_raw {
    int *bars;
    int *previous_frame;
    float *bars_left;
    float *bars_right;
    float *bars_raw;
    float *previous_bars_raw;
    double *cava_out;
    int *dimension_bar;
    int *dimension_value;
    double userEQ_keys_to_bars_ratio;
    int channels;
    int number_of_bars;
    int output_channels;
    int height;
    int lines;
    int width;
    int remainder;
};

int audio_raw_init(struct audio_data *audio, struct audio_raw *audio_raw, struct config_params *prm,
                   struct cava_plan *plan);
#ifndef SDL_GLSL
int audio_raw_fetch(struct audio_raw *audio_raw, struct config_params *prm, struct cava_plan *plan);
#else
int audio_raw_fetch(struct audio_raw *audio_raw, struct config_params *prm, int *re_paint,
                    struct cava_plan *plan);
#endif

int audio_raw_clean(struct audio_raw *audio_raw);
int audio_raw_destroy(struct audio_raw *audio_raw);

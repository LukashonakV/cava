/*
Copyright (c) 2022 Karl Stavestrand <karl@stavestrand.no>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#ifdef __cplusplus
extern "C" {
#endif
#pragma once
#include "cava/cavacore.h"

#include <stdint.h>
#include <stdlib.h>

#include <fftw3.h>

// cava_plan, parameters used internally by cavacore, do not modify these directly
// only the cut off frequencies is of any potential interest to read out,
// the rest should most likley be hidden somehow
struct cava_plan {
    int FFTbassbufferSize;
    int FFTbufferSize;
    int number_of_bars;
    int audio_channels;
    int input_buffer_size;
    int rate;
    int bass_cut_off_bar;
    int sens_init;
    int autosens;
    int frame_skip;
    int status;
    char error_message[1024];

    double sens;
    double framerate;
    double noise_reduction;

    fftw_plan p_bass_l, p_bass_r;
    fftw_plan p_l, p_r;

    fftw_complex *out_bass_l, *out_bass_r;
    fftw_complex *out_l, *out_r;

    double *bass_multiplier;
    double *multiplier;

    double *in_bass_r_raw, *in_bass_l_raw;
    double *in_r_raw, *in_l_raw;
    double *in_bass_r, *in_bass_l;
    double *in_r, *in_l;
    double *prev_cava_out, *cava_mem;
    double *input_buffer, *cava_peak;

    double *eq;

    float *cut_off_frequency;
    int *FFTbuffer_lower_cut_off;
    int *FFTbuffer_upper_cut_off;
    double *cava_fall;
};

#ifdef __cplusplus
}
#endif

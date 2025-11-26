#ifdef __cplusplus
extern "C" {
#endif

// cava_init, initialize visualization, takes the following parameters:

// number_of_bars, number of wanted bars per channel

// rate, sample rate of input signal

// channels, number of interleaved channels in input

// autosens, toggle automatic sensitivity adjustment 1 = on, 0 = off
// on, gives a dynamically adjusted output signal from 0 to 1
// the output is continously adjusted to use the entire range
// off, will pass the raw values from cava directly to the output
// the max values will then be dependent on the input

// noise_reduction, adjust noise reduciton filters. 0 - 1, recomended 0.77
// the raw visualization is very noisy, this factor adjusts the integral
// and gravity filters inside cavacore to keep the signal smooth
// 1 will be very slow and smooth, 0 will be fast but noisy.

// low_cut_off, high_cut_off cut off frequencies for visualization in Hz
// recomended: 50, 10000

// returns a cava_plan to be used by cava_execute. If cava_plan.status is 0 all is OK.
// If cava_plan.status is -1, cava_init was called with an illegal paramater, see error string in
// cava_plan.error_message
extern struct cava_plan *cava_init(int number_of_bars, unsigned int rate, int channels,
                                   int autosens, double noise_reduction, int low_cut_off,
                                   int high_cut_off);

// cava_execute, executes visualization

// cava_in, input buffer can be any size. internal buffers in cavacore is
// 4096 * number of channels at 44100 samples rate, if new_samples is greater
// then samples will be discarded. However it is recomended to use less
// new samples per execution as this determines your framerate.
// 512 samples at 44100 sample rate mono, gives about 86 frames per second.

// new_samples, the number of samples in cava_in to be processed per execution
// in case of async reading of data this number is allowed to vary from execution to execution

// cava_out, output buffer. Size must be number of bars * number of channels. Bars will
// be sorted from lowest to highest frequency. If stereo input channels are configured
// then all left channel bars will be first then the right.

// plan, the cava_plan struct returned from cava_init

// cava_execute assumes cava_in samples to be interleaved if more than one channel
// only up to two channels are supported.
extern void cava_execute(double *cava_in, int new_samples, double *cava_out,
                         struct cava_plan *plan);

// cava_destroy, destroys the plan, frees up memory
extern void cava_destroy(struct cava_plan *plan);

#ifdef __cplusplus
}
#endif

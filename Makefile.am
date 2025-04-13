AUTOMAKE_OPTIONS = foreign

ACLOCAL_AMFLAGS = -I m4

bin_PROGRAMS = cava
cavadir = $(top_srcdir)
cava_SOURCES = src/cava.c src/cavacore.c src/common.c src/config.c src/input/common.c src/input/fifo.c src/input/shmem.c \
               src/output/terminal_noncurses.c src/output/raw.c src/output/noritake.c src/output/common.c\
               include/cava/cavacore.h include/cava/config.h include/cava/input/common.h include/cava/input/fifo.h include/cava/input/shmem.h \
               include/cava/output/terminal_noncurses.h include/cava/output/raw.h include/cava/output/noritake.h \
               include/cava/debug.h include/cava/util.h third_party/incbin.h
cava_CPPFLAGS = -DPACKAGE=\"$(PACKAGE)\" -DVERSION=\"$(VERSION)\" \
           -D_POSIX_SOURCE -D_POSIX_C_SOURCE=200809L -D_XOPEN_SOURCE_EXTENDED \
           -DFONTDIR=\"@FONT_DIR@\" -DFONTFILE=\"@FONT_FILE@\" \
           -I$(top_builddir) -I$(top_builddir)/include
cava_CFLAGS = -std=c99 -Wall -Wextra -Wno-unused-result -Wno-unknown-warning-option -Wno-maybe-uninitialized -Wno-vla-parameter

EXTRA_DIST = \
    output/shaders/pass_through.vert \
    output/shaders/bar_spectrum.frag \
    output/shaders/northern_lights.frag \
    output/shaders/winamp_line_style_spectrum.frag \
    output/shaders/spectrogram.frag \
    example_files/config \
    cava.psf \
    LICENSE \
    run_all_tests.sh \
    SHADERS.md \
    .clang-format

if OSX
    cava_CFLAGS += -DNORT
    cava_LDADD =
else
    cava_LDADD = -lrt
    cava_font_dir = @FONT_DIR@
    cava_font__DATA = @FONT_FILE@
endif

if FREEBSD
if CAVAFONT
    CLEANFILES = cava.bdf cava.fnt

cava.fnt: ${srcdir}/cava.psf
	${PSF2BDF} --fontname="-gnu-cava-medium-r-normal--16-160-75-75-c-80-iso10646-1" ${srcdir}/cava.psf cava.bdf
	${VTFONTCVT} -o cava.fnt cava.bdf
endif
endif

if ALSA
    cava_SOURCES += src/input/alsa.c include/cava/input/alsa.h
endif

if PORTAUDIO
    cava_SOURCES += src/input/portaudio.c include/cava/input/portaudio.h
endif

if PIPEWIRE
    cava_SOURCES += src/input/pipewire.c include/cava/input/pipewire.h
endif

if PULSE
    cava_SOURCES += src/input/pulse.c include/cava/input/pulse.h
endif

if SNDIO
    cava_SOURCES += src/input/sndio.c include/cava/input/sndio.h
endif

if OSS
    cava_SOURCES += src/input/oss.c include/cava/input/oss.h
endif

if JACK
    cava_SOURCES += src/input/jack.c include/cava/input/jack.h
endif

if NCURSES
    cava_SOURCES += src/output/terminal_ncurses.c src/output/terminal_bcircle.c \
                    include/cava/output/terminal_ncurses.h include/cava/output/terminal_bcircle.h

endif

if SDL
    cava_SOURCES += src/output/sdl_cava.c include/cava/output/sdl_cava.h
endif

if SDL_GLSL
    cava_SOURCES += src/output/sdl_glsl.c include/cava/output/sdl_glsl.h
endif

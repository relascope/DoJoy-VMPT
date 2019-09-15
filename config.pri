
CONFIG += release

PREFIX_PATH = /usr/local

DEFINES +=  HAVE_BZ2 HAVE_FFTW3 HAVE_FFTW3F HAVE_SNDFILE HAVE_LIBSAMPLERATE HAVE_RUBBERBAND HAVE_SORD HAVE_SERD HAVE_CAPNP HAVE_LIBLO HAVE_PORTAUDIO HAVE_JACK HAVE_LIBPULSE HAVE_LRDF HAVE_OGGZ HAVE_FISHSOUND HAVE_MAD HAVE_ID3TAG HAVE_OPUS HAVE_X11

QMAKE_CC = gcc
QMAKE_CXX = g++
QMAKE_LINK = g++

QMAKE_CFLAGS += -g -O2
QMAKE_CXXFLAGS += -fpic -Wall -Wextra -Woverloaded-virtual -Wformat-nonliteral -Wformat-security -Winit-self -Wswitch-enum -Wconversion -pipe -g0 -O3 -ffast-math -DNDEBUG -DBUILD_RELEASE -DNO_TIMING -DNO_HIT_COUNTS      -I/usr/include/sord-0 -I/usr/include/serd-0 -I/usr/include/serd-0 -pthread -I/usr/local/include  -pthread  -D_REENTRANT -I/usr/include/raptor2     -I/usr/include/opus 
QMAKE_LFLAGS +=  -O3 -ffast-math

CONFIG += c++14

linux*:LIBS += -L$$PWD -lbase -lasound -ldl 

macx*:DEFINES += HAVE_COREAUDIO
macx*:LIBS += -framework CoreAudio -framework CoreMidi -framework AudioUnit -framework AudioToolbox -framework CoreFoundation -framework CoreServices

LIBS +=  -lbz2 -lfftw3 -lfftw3f -lsndfile -lsamplerate -lrubberband -lsord-0 -lserd-0 -lserd-0 -L/usr/local/lib -lcapnp -pthread -lpthread -lkj -pthread -lpthread -llo -lpthread -lportaudio -lasound -lm -lpthread -ljack -lpulse -llrdf -loggz -logg -lfishsound -lvorbis -lvorbisenc -lspeex -lFLAC -lmad -lid3tag -lz -lopusfile -lX11

linux*:LIBS -= -ljack

DEFINES += HAVE_PIPER HAVE_PLUGIN_CHECKER_HELPER DYNAMIC_JACK

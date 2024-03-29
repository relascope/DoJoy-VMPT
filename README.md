DoJoy-VMPT
==========
#### A virtual music power trainer - the way of joy to study music

* Brought to you with the way of Joy: http:://www.dojoy.at
* Based on Sonic Visualiser: http://sonicvisualiser.org/

Features
--------
* Stay in Tune with your music by synchronizing it via MIDI Clock
* Tempo changes are detected
* connect your DAW
* practice with Soundbrenner Pulse
![Soundbrenner Pulse - Smart Vibrating Metronome](https://www.soundbrenner.com/wp-content/themes/soundbrenner-theme2/images/home/flipped.png)


Feel free to ask for help. 

Usage
-----
0. start Jack audio Demon (e.g. via QJackCtl) and make sure 
1. open audio file
2. run any plugin that
3. Ctrl+m run aubio onsets or beatroot beat tracker or any other rythm plugin
4. You see a new JACK client, which omits the the beats in MIDI

Planned Features
----------------
* Adjust the tempo to a specified BPM value
* Tune the music to your instrument - not the other way round



DoJoy-VMPT is based on Sonic Visualiser
=======================================

#### A program for viewing and analysing the contents of music audio files

![Sonic Visualiser small screenshot](http://sonicvisualiser.org/images/sv-3.0-win-thumb.png)

* Home page and downloads: http://sonicvisualiser.org/
* Code project: https://code.soundsoftware.ac.uk/projects/sonic-visualiser

With Sonic Visualiser you can:

 * Load audio files in various formats (WAV/AIFF, plus Ogg and mp3
if compiled in) and view their waveforms
 
 * Look at audio visualisations such as spectrogram views, with
interactive adjustment of display parameters

 * Annotate audio data by adding labelled time points and defining
segments, point values and curves

 * Run feature-extraction plugins to calculate annotations
automatically, using algorithms such as beat trackers, pitch
detectors and so on (see http://vamp-plugins.org/)

 * Import annotation data from various text formats and MIDI files

 * Play back the original audio with synthesised annotations, taking
care to synchronise playback with the display position

 * Slow down and speed up playback and loop segments of interest,
including seamless looping of complex non-contiguous areas

 * Export annotations and audio selections to external files.

Sonic Visualiser can also be controlled remotely using the Open Sound
Control (OSC) protocol (if support is compiled in).


Credits
-------

Sonic Visualiser was developed at the Centre for Digital Music,
Queen Mary, University of London.

  http://c4dm.eecs.qmul.ac.uk/

Sonic Visualiser was written by Chris Cannam with contributions from
Christian Landone, Mathieu Barthet, Dan Stowell, Jesus Corral Garcia,
Matthias Mauch, and Craig Sapp.

Code copyright 2005-2007 Chris Cannam and copyright 2006-2019 Queen
Mary, University of London, except where indicated in the individual
source files.

Russian translation provided by Alexandre Prokoudine, copyright
2006-2019 Alexandre Prokoudine.

Czech translation provided by Pavel Fric, copyright 2010-2019 Pavel
Fric.

This work was partially funded by the European Commission through the
SIMAC project IST-FP6-507142 and the EASAIER project IST-FP6-033902.

This work was partially funded by the Arts and Humanities Research
Council through its Research Centre for the History and Analysis of
Recorded Music (CHARM).

This work was partially funded by the Engineering and Physical
Sciences Research Council through the OMRAS2 project EP/E017614/1, the
Musicology for the Masses project EP/I001832/1, and the Sound Software
project EP/H043101/1.

Sonic Visualiser is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or (at
your option) any later version.  See the file COPYING included with
this distribution for more information.

Sonic Visualiser may also make use of the following libraries:

 * Qt5 -- Copyright The Qt Company, distributed under the LGPL
 * JACK -- Copyright Paul Davis, Jack O'Quin et al, under the LGPL
 * PortAudio -- Copyright Ross Bencina, Phil Burk et al, BSD license
 * Ogg decoder -- Copyright CSIRO Australia, BSD license
 * MAD mp3 decoder -- Copyright Underbit Technologies Inc, GPL
 * libsamplerate -- Copyright Erik de Castro Lopo, BSD license
 * libsndfile -- Copyright Erik de Castro Lopo, LGPL
 * FFTW3 -- Copyright Matteo Frigo and MIT, GPL
 * Rubber Band -- Copyright Particular Programs Ltd, GPL
 * Vamp plugin SDK -- Copyright Chris Cannam and QMUL, BSD license
 * LADSPA plugin SDK -- Copyright Richard Furse et al, LGPL
 * RtMIDI -- Copyright Gary P. Scavone, BSD license
 * Dataquay -- Copyright Particular Programs Ltd, BSD license
 * Sord and Serd -- Copyright David Robillard, BSD license
 * Redland -- Copyright Dave Beckett and the University of Bristol, LGPL/Apache license
 * liblo OSC library -- Copyright Steve Harris, GPL
 * Cap'n Proto -- Copyright Sandstorm Development Group, Inc, BSD license

(Some distributions of Sonic Visualiser may have one or more of these
libraries statically linked.)  Many thanks to their authors.


Compiling Sonic Visualiser
--------------------------

If you are planning to compile Sonic Visualiser from source code,
please read the file INSTALL.txt.

 * Linux and macOS CI build: [![Build Status](https://travis-ci.org/sonic-visualiser/sonic-visualiser.svg?branch=master)](https://travis-ci.org/sonic-visualiser/sonic-visualiser)
 * Windows CI build: [![Build status](https://ci.appveyor.com/api/projects/status/26pygienkigw39p7?svg=true)](https://ci.appveyor.com/project/cannam/sonic-visualiser)


More information
----------------

For more information about Sonic Visualiser, please go to

  http://www.sonicvisualiser.org/


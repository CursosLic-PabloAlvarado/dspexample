# dspexample

Copyright (C) 2011-2021  Pablo Alvarado<br/>
                         Tecnológico de Costa Rica<br/>


This is a simple project used as platform to develop basic audio processing
algorithms in C++.  It is used in an introductory lecture of DSP, as a
warming-up experience before dealing with more complex implementation issues.

You will need a GNU/Linux distribution with QtCreator, Jack, g++ and related
tools.

## Compile

To compile the aplication, you will need Qt and its tools:

     > qmake
     > make

## Execute

Just run

     > ./dspexample [audio.wav]

to play an 'audio.wav' file, or give nothing to capture your audio signal live
from the microphone.

It is recommended to use the program 'qjackctl' to control all audio
configurations and to diagnose any audio problems.

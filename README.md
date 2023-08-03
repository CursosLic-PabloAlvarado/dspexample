# dspexample

Copyright (C) 2011-2023  Pablo Alvarado<br/>
                         Tecnológico de Costa Rica<br/>


This is a simple project used as platform to develop basic audio processing
algorithms in C++.  It is used in an introductory lecture of DSP, as a
warming-up experience before dealing with more complex implementation issues.

You will need a GNU/Linux distribution with QtCreator, Jackd2, g++ and related
tools.

## Jack and PulseAudio

Many Linux systems use PulseAudio as the default sound server, Ubuntu
included, using it to handle all sound playback (media players,
desktop alerts, web browsers and more).  Please check

https://jackaudio.org/faq/pulseaudio_and_jack.html

to learn how to activate jack temporarily and deactivate pulseaudio (for instance, with pasuspender -- jackd

## Requisites

   jackd studio-controls

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

The package jack-tools installs some tools to test your jack
installation, like jack-scope

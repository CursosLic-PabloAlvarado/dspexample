/*
 * DSP EXAMPLE
 * Example platform for testing simple DSP algorithms
 *
 * Copyright (C) 2011  Pablo Alvarado
 *                     Tecnológico de Costa Rica
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * \mainpage dspExample
 *
 * \section intro Introduction
 *
 * This is a simple project used as platform to develop basic audio processing
 * algorithms in C++.  It is used in an introductory lecture of DSP, as a
 * warming-up experience before dealing with more complex implementation issues.
 * 
 * You will need a GNU/Linux distribution with QtCreator, Jack, g++ and related
 * tools.
 * 
 * \subsection Compile
 * 
 * To compile the aplication, you will need Qt and its tools:
 * 
 * \code
 * > qmake
 * > make
 * \endcode
 * 
 * \subsection Execute
 * 
 * Just run
 * 
 * \code
 * > ./dspexample [audio.wav]
 * \endcode
 * 
 * to play an 'audio.wav' file, or give nothing to capture your audio signal
 * live from the microphone.
 * 
 * It is recommended to use the program 'qjackctl' to control all audio
 * configurations and to diagnose any audio problems.
 * 
 * \section license License
 * 
 * Copyright (C) 2011  Pablo Alvarado
 *                     Tecnológico de Costa Rica
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

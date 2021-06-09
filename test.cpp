/*
 * DSP Example is part of the DSP Lecture at TEC-Costa Rica
 * Copyright (C) 2010  Pablo Alvarado
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
 * \file   test.h
 *         Provides an empty framework to do experiments
 * \author Pablo Alvarado
 * \date   2011.09.13
 */

#include "test.h"
#include <cmath>
#include <cstring>

test::test() {
}

/*
 * Destructor
 */
test::~test() {
}

/*
 * Init the filter operation
 */
void test::init() {

}

/**
 * Filter the in buffer and leave the result in out
 */
void test::filter(int blockSize,
                        float* in,
                        float* out) {

  // default implementation just copies the input into the output
  memcpy(out,in,sizeof(float)*blockSize);
}

/*
 * Reset
 */
void test::reset() {
}


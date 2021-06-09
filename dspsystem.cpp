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
 * \file   freqFilter.h
 *         Implements filtering in the frequency domain
 * \author Pablo Alvarado
 * \date   2010.12.12
 *
 * $Id: equalizer.cpp $
 */

#include "dspsystem.h"
#include <cstring>

#undef _DSP_DEBUG
#define _DSP_DEBUG

#ifdef _DSP_DEBUG
#define _debug(x) std::cerr << x
#include <iostream>
#else
#define _debug(x)
#endif


dspSystem::dspSystem()
  : eq_(0),ff_(0),cf_(0),rv_(0),ts_(0),
    eqhnSize_(0),eqHwSize_(0),sampleRate_(0),bufferSize_(0),
    equalizerOn_(false),filter60On_(false),reverbOn_(false),testerOn_(false) {
}

dspSystem::~dspSystem() {
  delete eq_;
  eq_=0;

  delete ff_;
  ff_=0;

  delete cf_;
  cf_=0;

  delete rv_;
  rv_=0;

  delete ts_;
  ts_=0;
}

/*
 * (De)activate equalizer
 */
void dspSystem::setEqualizer(bool on) {
  if (!on) {
    ff_->reset();
  }
  equalizerOn_=on;
}

/*
 * (De)activate 60Hz filter
 */
void dspSystem::setFilter60(bool on) {
  filter60On_=on;
}

/*
 * (De)activate reverberator
 */
void dspSystem::setReverb(bool on) {
  reverbOn_=on;
}

/**
 * (De)activate tester
 */
void dspSystem::setTester(bool on) {
  testerOn_=on;
}


reverb* dspSystem::getReverberator() {
  return rv_;
}


/**
 * Initialization function for the current filter plan
 */
bool dspSystem::init(const int sampleRate,const int bufferSize) {
  _debug("dspSystem::init()" << std::endl);

  sampleRate_ = sampleRate;
  bufferSize_ = bufferSize;

  eqHwSize_=bufferSize*2;
  eqhnSize_=bufferSize*3/4;

  delete eq_;
  eq_=new equalizer(16,eqhnSize_,eqHwSize_);

  delete ff_;
  ff_=new freqFilter(bufferSize);

  delete cf_;
  cf_=new combFilter();

  // comb filter should remove 6Hz centered on 60Hz x k
  cf_->init(sampleRate,60.0f,6.0f);

  delete rv_;
  rv_=new reverb();

  // use some dummy values first.
  rv_->init(sampleRate,1000,0.5f);

  updateEqualizer();

  // Initialization of test object
  delete ts_;
  ts_=new test;

  ts_->init();

  return true;
}

equalizer* dspSystem::getEqualizer() {
  return eq_;
}

test* dspSystem::getTester() {
  return ts_;
}

void dspSystem::updateEqualizer() {
  _debug("dspSystem::updateEqualizer()" << std::endl);

#if 0 // Debug code: use a unit impulse reponse
  _debug(" DEBUG MODE: Using unit impulse" << std::endl);
  float delta[eqhnSize_];
  memset(delta,0,eqhnSize_*sizeof(float));
  delta[0]=1.0f;
  ff_->setFilter(delta,eqhnSize_,eqHwSize_);
#else // normal operation code
  _debug(" Setting new equalizer" << std::endl);

  // tell the equalizer to recompute the frequency reponse
  eq_->createFilter();
  // no assign that frequency response to the frequency domain filter
  ff_->setFilter(eq_->getFrequencyResponse(),eqHwSize_,eqhnSize_);
#endif

}

/**
 * Processing function
 */
bool dspSystem::process(float* in,float* out) {

  if (!equalizerOn_ && !filter60On_ && !reverbOn_ && !testerOn_) {
    // nothing to be done: just pass through
    memcpy(out,in,bufferSize_*sizeof(float));
  } else {

    float* tmpIn = in;
    float* tmpOut = out;

    if (reverbOn_) {
      rv_->filter(bufferSize_,tmpIn,tmpOut);
      float* tmp = tmpIn;
      tmpIn = tmpOut;
      tmpOut = tmp;
    }

    if (equalizerOn_) {
      ff_->filter(tmpIn,tmpOut);
      float* tmp = tmpIn;
      tmpIn = tmpOut;
      tmpOut = tmp;
    }

    if (filter60On_) {
      cf_->filter(bufferSize_,tmpIn,tmpOut);
      float* tmp = tmpIn;
      tmpIn = tmpOut;
      tmpOut = tmp;
    }

    if (testerOn_) {
      ts_->filter(bufferSize_,tmpIn,tmpOut);
      float* tmp = tmpIn;
      tmpIn = tmpOut;
      tmpOut = tmp;
    }

    if (tmpOut == out) {
      memcpy(out,in,bufferSize_*sizeof(float));
    }

  }

  return true;
}

/**
 * Shutdown the processor
 */
bool dspSystem::shutdown() {
  delete eq_;
  eq_=0;
  return true;
}

/**
 * Set buffer size (call-back)
 */
int dspSystem::setBufferSize(const int bufferSize) {
  bufferSize_=bufferSize;
  return 1;
}

/**
 * Set sample rate (call-back)
 */
int dspSystem::setSampleRate(const int sampleRate) {
  sampleRate_=sampleRate;
  return 1;
}

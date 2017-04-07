/*
 * File: audio_unit.h
 * AUTHOR: William Willie Wells
 * DATE: April 2017 ...
 */

#ifndef _AUDIO_UNIT_H_
#define _AUDIO_UNIT_H_

// package message/structs include
//#include <gps_testing/Rssi.h> 

// c++ includes
//#include <boost/thread/thread.hpp>

// namespace
using namespace std;

// defines
//#define PI

// class
template <class Comparable>
class AudioUnit{
  public:
    // con(de)structors
    AudioUnit(const Comparable &sound = Comparable(), AudioUnit *n = NULL, AudioUnit *p = NULL)
	  : soundUnit(sound), next(n), previous(p){}
    ~AudioUnit();
  private:
    // in(ex)ternal parameters
    Comparable soundUnit;
    AudioUnit<Comparable> *next;
	AudioUnit<Comparable> *previous;
	
	// friend classes
	friend class AudioStream<Comparable>
};
#endif // audio_unit

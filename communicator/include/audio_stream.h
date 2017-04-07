/*
 * File: audio_stream.h
 * AUTHOR: William Willie Wells
 * DATE: April 2017 ...
 */

#ifndef _AUDIO_STREAM_H_
#define _AUDIO_STREAM_H_

// package message/structs include
//#include <audio_unit.h> 

// c++ includes
//#include <boost/thread/thread.hpp>

// namespace
using namespace std;

// defines
//#define PI

// class
template <class Comparable>
class AudioStream{
  public:
    // con(de)structors
	AudioStream();
    AudioStream(const AudioStream &rhs);
    ~AudioStream();
	
	bool isSilent() const;
	bool atSilence() const;
	void makeSilent();
	void remove(const Comparable &sound);
	void insert(const Comparable &sound);
	AudioUnit<Comparable> find(const Comparable &sound) const;
	void forward();
	void backward();
	
	// operators
	const AudioStream & operator=(const AudioStream &rhs);
  private:
    // in(ex)ternal parameters
    AudioUnit<Comparable> *silence;
	AudioUnit<Comparable> *audio;
	int size;
	
	// friend classes
	//friend class AudioUnit<Comparable>
};
#endif // audio_stream

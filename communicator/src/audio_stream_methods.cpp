/*
 * FILE: audio_stream_methods.cpp
 * AUTHOR: William Willie Wells
 * DATE: April 2017 ...
 */

// class include
#include "../include/audio_stream.h"

template <class Comparable>
bool AudioStream<Comparable>::isSilent() const{ return silence->next == NULL; }

template <class Comparable>
bool AudioStream<Comparable>::atSilence() const{ return audio == NULL; }

template <class Comparable>
AudioUnit<Comparable> AudioStream<Comparable>::find(const Comparable &sound) const{
  audio = silence->next;
  while(audio->next != silence && audio->soundUnit != sound){ forward(); }
  
  return audio;
}

template <class Comparable>
void AudioStream<Comparable>::remove(const Comparable &sound){
  AudioUnit<Comparable> es = find(sound);
  if(es.audio != NULL){
    AudioUnit<Comparable> *expiredSound = es.audio;
    // remove expired audio from audio stream  
    expiredSound->previous->next = expiredSound->next;
	expiredSound->next->previous = expiredSound->previous;
	
	// clean removal of expired audio data
	expiredSound->previous = expiredSound->next = NULL;
	delete expiredSound;
	if(size > 0){ size--; }
  }
}

template <class Comparable>
void AudioStream<Comparable>::makeSilent(){ while(!isSilent()){ remove(silence->next); } }

// destructor
template<class Comparable>
AudioStream<Comparable>::~AudioStream(){ makeSilent(); delete silence; delete audio; }

template <class Comparable>
void AudioStream<Comparable>::forward(){ if(!atSilence()){ audio = audio->next; } }

template <class Comparable>
void AudioStream<Comparable>::backward(){ if(!atSilence()){ audio = audio->previous; } }

template <class Comparable>
void AudioStream<Comparable>::insert(const Comparable &sound){
  audio->next = new AudioUnit<Comparable>(sound,audio->next,audio);
  audio->next->next->previous = audio->next; // was audio now audio->next
  forward();
  size++;  
}
	
// operators
template <class Comparable>
const AudioStream & AudioStream<Comparable>::operator=(const AudioStream &rhs){
  if(this != rhs){
    makeSilent();
	
	AudioUnit<Comparable> iterator = rhs.silence->next;
	while(iterator->next != rhs.silence){ 
	  insert(iterator->soundUnit); 
	  iterator->forward(); 
	}
  }
  return *this;
}

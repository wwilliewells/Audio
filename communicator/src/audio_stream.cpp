/*
 * FILE: audio_stream.cpp
 * AUTHOR: William Willie Wells
 * DATE: April 2017 ...
 */

// class include
#include "../include/audio_stream.h"

// constructor
template<class Comparable>
AudioStream<Comparable>::AudioStream():size(0){ 
  audio = silence = new AudioUnit<Comparable>; 
}

// copy constructor
template<class Comparable>
AudioStream<Comparable>::AudioStream():size(0){ 
  audio = silence = new AudioUnit<Comparable>;
  *this = rhs;  
}

// c++ Main
int main(int argc, char **argv){
  // log start
  //cout;

  // create and start node instance
  AudioStream<int> aStream;

  // keep spinning until landing acheived
  //while(1){};

  // log stop and shutdown
  //cout;

  return 0;
}
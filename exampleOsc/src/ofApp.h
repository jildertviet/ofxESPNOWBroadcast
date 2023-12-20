#pragma once

#include "ofMain.h"
#include "ofxESPNOWBroadcast.h"
#include "ofxOsc.h"

class ofApp : public ofBaseApp {
public:
  void setup();
  void update();
  void exit();

  ofxESPNOWBroadcastSender espnowSender;
  ofxOscReceiver oscReceiver;
};

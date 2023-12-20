#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  espnowSender.init("wlp166s0");
  oscReceiver.setup(7997);
  ofSetFrameRate(120);
  cout << "1. Send data from SC with: n.sendMsg(\"/espnow\", "
          "Int8Array.newFrom([1,2,3]));"
       << endl;
  cout << "2. Make sure the interface is in Monitor mode" << endl;
  cout << "3. Use port " << oscReceiver.getPort() << endl;
}

//--------------------------------------------------------------
void ofApp::update() {
  while (oscReceiver.hasWaitingMessages()) {
    ofxOscMessage m;
    oscReceiver.getNextMessage(m);
    if (m.getAddress() == "/espnow") {
      ofBuffer b = m.getArgAsBlob(0);
      for (int i = 0; i < b.size(); i++) {
        cout << (int)(unsigned char)b.getData()[i] << " ";
      }
      cout << endl;
      espnowSender.send(b.getData(), b.size());

      cout << "Send" << endl;
    }
  }
}

void ofApp::exit() { espnowSender.exit(); }

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  espnowSender.init("wlp166s0");
  oscReceiver.setup(7997);
  // ofSetFrameRate(60);
  cout << "Send data from SC with: n.sendMsg(\"/espnow\", "
          "Int8Array.newFrom([1,2,3]));"
       << endl;
}

//--------------------------------------------------------------
void ofApp::update() {
  while (oscReceiver.hasWaitingMessages()) {
    ofxOscMessage m;
    oscReceiver.getNextMessage(m);
    if (m.getAddress() == "/espnow") {
      ofBuffer b = m.getArgAsBlob(0);
      for (int i = 0; i < b.size(); i++) {
        cout << (int)b.getData()[i] << " ";
      }
      cout << endl;
      espnowSender.send(b.getData(), b.size());

      cout << "Send" << endl;
    }
  }
  // espnowSender.testSend();
}

void ofApp::exit() { espnowSender.exit(); }

//--------------------------------------------------------------
void ofApp::draw() {}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}

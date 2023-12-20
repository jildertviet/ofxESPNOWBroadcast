#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  sender.init("wlp166s0", DATARATE_1Mbps, CHANNEL_freq_1);
  ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update() {
  if (ofGetFrameNum() % 30 == 0) {
    cout << "Send" << endl;
    sender.testSend();
  }
}

void ofApp::exit() { sender.exit(); }

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

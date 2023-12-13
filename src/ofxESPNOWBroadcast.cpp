#include "ofxESPNOWBroadcast.h"
using namespace std;

ofxESPNOWBroadcastSender::ofxESPNOWBroadcastSender() {}

void ofxESPNOWBroadcastSender::init(std::string interfaceName) {
  nice(-20);

  char *cstr = new char[interfaceName.length() + 1];
  strcpy(cstr, interfaceName.c_str());
  handler = new ESPNOW_manager(cstr, DATARATE_1Mbps, CHANNEL_freq_1, my_mac,
                               dest_mac, false);
  delete[] cstr;
  handler->start();
}
void ofxESPNOWBroadcastSender::exit() {
  cout << "Exit" << endl;
  handler->end();
}

void ofxESPNOWBroadcastSender::testSend() {
  uint8_t msg[7] = {'a', 0x00, 0x00, 0x00, 0x00, 0x01, 0x01};
  memcpy(handler->mypacket.wlan.actionframe.content.payload, msg, 7);
  handler->mypacket.wlan.actionframe.content.length = 7 + 5; //
  handler->send();
}
void ofxESPNOWBroadcastSender::send(char *data, int len) {
  memcpy(handler->mypacket.wlan.actionframe.content.payload, data, len);
  handler->mypacket.wlan.actionframe.content.length = len + 5;
  handler->send();
}

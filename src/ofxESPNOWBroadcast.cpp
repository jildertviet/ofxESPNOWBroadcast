#include "ofxESPNOWBroadcast.h"

using namespace std;

// static uint8_t ESP_mac[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

ofxESPNOWBroadcastSender::ofxESPNOWBroadcastSender() {}

// void ofxESPNOWBroadcastSender::init(std::string interfaceName) {
//   nice(-20);
//   std::string ifName = "wlp166s0";
//   cout << ifName.length() << endl;
//   char *cstr = new char[ifName.length() + 1];
//   strcpy(cstr, ifName.c_str());
//   cout << "a" << endl;
//   handler = new ESPNOW_manager(cstr, DATARATE_1Mbps, CHANNEL_freq_1, my_mac,
//                                dest_mac, false);
//   cout << "x" << endl;
//   delete[] cstr;
//   handler->start();
// }
//
void ofxESPNOWBroadcastSender::exit() { handler->end(); }

void ofxESPNOWBroadcastSender::testSend() {
  uint8_t msg[7] = {'a', 0x00, 0x00, 0x00, 0x00, 0x01, 0x01};
  // cout << handler << endl;
  memcpy(handler->mypacket.wlan.actionframe.content.payload, msg, 7);
  handler->mypacket.wlan.actionframe.content.length = 7 + 5; //
  // handler->set_dst_mac(dest_mac);
  handler->send();
  handler->end();
  cout << "Done" << endl;
  std::exit(0);
}

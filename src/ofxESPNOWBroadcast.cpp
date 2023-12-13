#include "ofxESPNOWBroadcast.h"
#include <iostream> // std::cout, std::end

using namespace std;

static uint8_t my_mac[6] = {0xF8, 0x1A, 0x67, 0xb7, 0xEB, 0x0B};
static uint8_t dest_mac[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
// static uint8_t ESP_mac[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

ofxESPNOWBroadcastSender::ofxESPNOWBroadcastSender() {}

void ofxESPNOWBroadcastSender::init(std::string interfaceName) {
  nice(-20);
  char *ifName = "wlp166s0";
  handler = new ESPNOW_manager(ifName, DATARATE_1Mbps, CHANNEL_freq_1, my_mac,
                               dest_mac, false);
  handler->start();
}

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

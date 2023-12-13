#include <stdint.h>
#include <stdio.h>

#include <assert.h>
#include <iostream>
#include <sys/time.h>
#include <unistd.h>

#include <thread>

#include "ESPNOW_manager.h"
#include "ESPNOW_types.h"

static uint8_t my_mac[6] = {0xF8, 0x1A, 0x67, 0xb7, 0xEB, 0x0B};
static uint8_t dest_mac[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

class ofxESPNOWBroadcastSender {
public:
  ofxESPNOWBroadcastSender();
  void init(std::string interfaceName) {
    nice(-20);
    std::string ifName = "wlp166s0";
    std::cout << ifName.length() << std::endl;
    char *cstr = new char[ifName.length() + 1];
    strcpy(cstr, ifName.c_str());
    std::cout << "a" << std::endl;
    handler = new ESPNOW_manager("wlp166s0", DATARATE_1Mbps, CHANNEL_freq_1,
                                 my_mac, dest_mac, false);
    std::cout << "x" << std::endl;
    delete[] cstr;
    handler->start();
  }
  void exit();

  void testSend();

  std::string interfaceName = "";
  ESPNOW_manager *handler;
};

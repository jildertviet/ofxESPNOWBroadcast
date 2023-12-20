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
  void init(std::string interfaceName, char dataRate = DATARATE_1Mbps,
            int channel = CHANNEL_freq_1);
  void exit();

  void testSend();
  void send(char *data, int len);

  ESPNOW_manager *handler;
};

#include <stdint.h>
#include <stdio.h>

#include <assert.h>
#include <sys/time.h>
#include <unistd.h>

#include <thread>

#include "ESPNOW_manager.h"
#include "ESPNOW_types.h"

class ofxESPNOWBroadcastSender {
public:
  ofxESPNOWBroadcastSender();
  void init();
  void exit();

  void send();

  ESPNOW_manager *handler;
};

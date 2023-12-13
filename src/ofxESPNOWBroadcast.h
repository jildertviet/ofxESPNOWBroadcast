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
  void init(std::string interfaceName);
  void exit();

  void testSend();

  std::string interfaceName = "";
  ESPNOW_manager *handler;
};

#include <stdint.h>
#include <stdio.h>

#include <assert.h>
#include <unistd.h>
#include <sys/time.h>

#include <thread>

#include "ESPNOW_manager.h"
#include "ESPNOW_types.h"

class ofxESPNOWSender{
public:
    ofxESPNOWSender();
    void init();
    void exit();
    
    void send();
    
    ESPNOW_manager *handler;
};

#include "ofxESPNOW.h"
#include <iostream>     // std::cout, std::end

using namespace std;

static uint8_t my_mac[6] = {0xF8, 0x1A, 0x67, 0xb7, 0xEB, 0x0B};
static uint8_t dest_mac[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
static uint8_t ESP_mac[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

uint8_t payload[127];

ofxESPNOWSender::ofxESPNOWSender(){

}

void ofxESPNOWSender::init(){
  nice(-20);
  
    string ifNameString = "wlxe894f61bf4fd";
    cout << ifNameString.length() << endl;
    char* ifName = new char[ifNameString.length() + 1];
    strcpy(ifName, ifNameString.c_str());

    handler = new ESPNOW_manager(ifName, DATARATE_24Mbps, CHANNEL_freq_9, my_mac, dest_mac, false);
    // handler->set_filter(ESP_mac, dest_mac);
//    handler->set_recv_callback(&callback);
    // handler->start();
}

void ofxESPNOWSender::exit(){
    handler->end();
}

void ofxESPNOWSender::send(){
    char msg[6] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    handler->mypacket.wlan.actionframe.content.length = 6 + 5; // 6 = msg size
    memcpy(handler->mypacket.wlan.actionframe.content.payload, msg, 6);
    //handler->set_dst_mac(dest_mac);
    handler->send();
}

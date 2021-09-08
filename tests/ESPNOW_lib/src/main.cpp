/*
Etienne Arlaud
*/

#include <stdint.h>
#include <stdio.h>

#include <assert.h>
#include <unistd.h>
#include <sys/time.h>

#include <thread>

#include "ESPNOW_manager.h"
#include "ESPNOW_types.h"

using namespace std;

static uint8_t my_mac[6] = {0xE8,0x94,0xF6,0x1B,0xF4,0xFD};
static uint8_t dest_mac[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
static uint8_t ESP_mac[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

ESPNOW_manager *handler;

uint8_t payload[127];

void callback(uint8_t src_mac[6], uint8_t *data, int len) {
	handler->mypacket.wlan.actionframe.content.length = 127 + 5;
	memcpy(handler->mypacket.wlan.actionframe.content.payload, data, 6);
	//handler->set_dst_mac(dest_mac);
	handler->send();
}

int main(int argc, char **argv) {
	assert(argc > 1);

	nice(-20);

	handler = new ESPNOW_manager(argv[1], DATARATE_24Mbps, CHANNEL_freq_9, my_mac, dest_mac, false);

	handler->set_filter(ESP_mac, dest_mac);

	handler->set_recv_callback(&callback);

	handler->start();

	char msg[6] = {0x00, 0x00,0x00, 0x00, 0x00, 0x00};
	handler->mypacket.wlan.actionframe.content.length = 6 + 5;
	memcpy(handler->mypacket.wlan.actionframe.content.payload, msg, 6);
	handler->set_dst_mac(dest_mac);
	handler->send();

	handler->end();
}

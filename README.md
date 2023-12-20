ofxESPNOWBroadcast
================
Experimental add-on.  
Linux only. 

## Description
This add-on enables you to send ESPNOW from a Linux computer to ESP32 and/or ESP8266.  
This way you don't need a USB⇿ESPNOW-bridge device.  

## Usage
1. Put your WiFi card (the example below uses _wlp166s0_) into monitor mode.
2. Set the channel on which the ESP's listen for ESPNOW.
   ```
		systemctl stop NetworkManager; # Otherwise the card goes back into Managed mode. 
		ifconfig wlp166s0 down;
		iwconfig wlp166s0 mode Monitor;
		ifconfig wlp166s0 up;
		iwconfig wlp166s0 channel 1; 
		iwconfig wlp166s0; # To see if the card is actually in Monitor mode and on Channel 1
   ```
3. Run the app as root, otherwise the ESPNOW_lib won't work.

Also check the Linux-ESPNOW repo for README's (also in the seperate directories). 

## Credits
This is basicly a copy of [Linux-ESPNOW](https://github.com/thomasfla/Linux-ESPNOW/) by Thomas Flayols.  
Therefore the same license applies.  

## Test
I've tested this on my Framework (13) laptop running Linux Mint 21.2.
This model has a AX210 WiFi chip.

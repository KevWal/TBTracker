// GPS.h

#ifndef GPS_H
#define GPS_H

#include <Arduino.h>

#define UNKNOWN 0
#define PEDESTRIAN 3
#define AIRBORNE 6 


void checkGPS();

void smartDelay(unsigned long ms);

void processGPSData();

void printGPSData();

void sendUBX(unsigned char *Message, int Length);

void setDesiredMode(uint8_t aDesiredMode);

//If SerialGPS is defined then we are using a Hardware serial port and dont need Software Serial
#ifndef SERIALGPS
  #include <SoftwareSerial.h>
  extern SoftwareSerial SERIALGPS;
#endif

#endif
# KW Tracker Updates

This tracker code is based heavily on the work by Roel Kroes in TBTracker, but now heavily modified by me, Kevin Walton.

- Added Horus 4FSK Mode support

- Addition of all UKHAS / HABHUB / Akerman LoRa Modes

- Addition of TinyGS.com compatibility

- Refactored into a C++ structure using guarded header files and cpp files (apart from TBTracker.ino is still named .ino to maintain Arduino IDE compatibility).  This allows it to be compiled in both Arduino IDE and other C++ compilers like PlatformIO, as well as significantly speeding up development time as the whole program does not need recompiling after every change.

- Added support for Airborne and Pedestrian modes - needed for UBlox GPS's

- Different Debug serial port handling

- Create a smaller RTTY sentence for quick transmission

- Added ability to use ATMEGA1284P

- Added ability to use temperature from LoRa Module

- Added an LED showing GPS lock status

- Power down GPS before Tx to save battery (GPS backup power still live)

- Now using RadioLib native interrupt timing routines
  - due to - https://github.com/jgromes/RadioLib/issues/596
  - see instructions here - https://github.com/jgromes/RadioLib/wiki/Interrupt-Based-Timing)

- Now using RadioLib native FSK4 routines

## ToDo

- Test the Power / Current Limit code

## TinyGS.com Compatibility

We are asking the TinyGS Network to have a default listening setup (when no satellites are in view) of:

- 433.662Mhz, Modes 2 = SF: 8 CR: 5 BW: 62.5 kHz

- "Modem startup" of {"mode":"LoRa","sat":"Default","freq":433.662,"bw":62.5,"pl":8,"pwr":0,"sf":8,"cr":8,"sw":18,"crc":true,"fldro":0,"cl":0,"gain":0}

- Modem Startup string is documented here: https://github.com/G4lile0/tinyGS/wiki/Radio-Tuning-Guide

- "Advanced Parameters" of {"dmode":9} gets extra logging


# Original TBTracker Readme
Plug and Play RTTY and LoRa High Altitude Balloon Tracker for Arduino and SX127x (or Hope RFM9x).

TBTracker is a sketch for a tracker for high altitude weather balloons. It will send telemetry data in RTTY and LoRa format.
It is designed to send telemetry data in the correct format for https://tracker.habhub.org/ and/or https://amateur.sondehub.org

It can send data in RTTY or LoRa format on different frequencies and with different callsigns.

Currently it supports:
- Time
- Longitude
- Latitude
- Altitude

Some extra fields can be transmitted as well but not all are visible on Sondehub and Habhub (see the settings file in the code):
- Number of satellites visible
- Internal temperature
- Internal voltage
- External voltage

The code as is, is for the SX1278 module. If you have a SX1276, then change line 5 in radio.ino. See the comments in that file.

You will need two extra Arduino libraries to be able to compile this sketch.:

 https://github.com/jgromes/RadioLib (RadioLib)
 
 https://github.com/mikalhart/TinyGPSPlus (TinyGPS++)

To run this, you need a TTGO T-Deer board or:
 *  1 x Arduino Mini - 3.3v (or compatible Arduino board)
 *  1 x SX1278 LoRa chip (or compatible LoRa chip. Basically it will work with all sx127x series chips)
 *  1 x ATGM336H, BN220 GPS (9600 Baud) or any UBlox or compatible GPS device like a NEO6 or NEO8. I recommend the ATGM336H GPS module. 

Connect the T-Deer as an Arduino Mini to the Arduino IDE.
Many parameters are user adjustable in settings.h
 
The Arduino Pro mini has a rather small memory capacity. If you run into memory issues, consider disabling RTTY or LORA in the settings.h file. Also disabling DEVMODE in settings.h will free up a lot of memory at the cost of no serial output. 
 
Have fun,
 
Roel.

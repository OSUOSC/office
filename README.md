# OSC Office Script

## Description

This code checks a serial connection to an Arduino in the Open Source Club
office, checking a photoresistor to see if the lights are on in the office and
updating a file ".office" accordingly. We serve this file to the web, so things
can check it accordingly.

1. office.py
 - This is the script that does the checking, it polls the Aruino continously
   and updates a file accordingly.
2. Boards/
 - This folder contains the physical circuit design of our CDS sheild attached
   to the arduino.
3. osccds/
 - This folder contains the Arduino sketch file.

## Installation

1. Flash the sketch "osccds" to your Arduino
2. Copy office.py to desired deployment location and create a cron job to
   ensure it runs / is running. This could also be a daemon, instead. 

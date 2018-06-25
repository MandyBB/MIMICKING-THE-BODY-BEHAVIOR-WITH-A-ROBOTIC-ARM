#ifndef LIBRARIES_H
#define LIBRARIES_H

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <Servo.h>

//Define type of servo
#define NSERVO 6
extern Servo SERVOS[NSERVO];
const int PINS[NSERVO] = {5,4,0,2,14,12}; //D1 until D6
const int INIT[NSERVO] = {0,0,20,100,40,70};
const int MAX[NSERVO] = {180,180,140,0,120,180};
extern int REAL[NSERVO];  
extern int TARGET[NSERVO];  
extern int SPEEDS[NSERVO];


// Define the server
WiFiUDP Udp;
unsigned int UDPPort = 2380; // local port to listen on
char packetBuffer[2*NSERVO]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //buffer to hold incoming packet
//Ip configuration.
const IPAddress local(11, 11, 11, 11);
const IPAddress dns(11, 11, 11, 11);
const IPAddress netmask(255, 255, 255, 0);
const IPAddress remote(11,11,11,110);


//Define variable
extern unsigned long clock_begin;
extern unsigned long clock_end;


#endif

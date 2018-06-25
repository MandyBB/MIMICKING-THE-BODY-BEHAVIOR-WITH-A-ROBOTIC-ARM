#include "Libraries.h"

void setup() {
      //Servo motor
      SetupServoArm(); 
      clock_begin = millis();
      //Wifi configuration
      UDPSetup();
}

void loop() {
  //loopServoDance();
  clock_end = millis();   
 
  if (clock_end > clock_begin + 1,77) {
    clock_begin = clock_end;

    UDP_Reception();
    MoveMyArm();
  }
     
}


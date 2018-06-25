#include "Libraries.h"

void setup() {
      //Servo motor
      SetupServoArm(); 
      
      //Wifi configuration
      UDPSetup();
      clock_begin = millis();
}

void loop() {
  loopServoDance();
  clock_end = millis();   

  if (count==6){
    if (clock_end > clock_begin + 1,77) {
      clock_begin = clock_end;
       
      UDP_Reception();
      MoveMyArm();
      }
       
  }
}


#include "Libraries.h"

// Initialization of the values
unsigned long clock_begin = 0;
unsigned long clock_end = 0;


//Naming a type servo
Servo SERVOS[NSERVO];

int REAL[NSERVO];
int TARGET[NSERVO];
int SPEEDS[NSERVO];

boolean DIR[NSERVO] = {true,true,true,false,true,true};

unsigned long PrevTime = 0;
const long interval = 1000; //intervalo de 50 milisegundos
const char T[][6] = { 0,0,0,0,0,0,
                      50,50,50,50,50,50,
                      80,80,80,80,80,80,
                      50,50,50,50,50,50,
                      0,0,0,0,0,0,
                      0,0,0,100,0,39
                      };
const unsigned int TMAX =  (sizeof(T)/sizeof(char))/6;
unsigned int count = 0;

void servoSetup(int num) {
  SERVOS[num].attach(PINS[num]); // Attach to a Digital Pin
  TARGET[num] = INIT[num];
  REAL[num] = INIT[num];
  SPEEDS[num] = 0;
  SERVOS[num].write(INIT[num]);
}

void SetupServoArm() {
  for (int num = 0; num < NSERVO; num++) {
    servoSetup(num);
  }
}

void UDPSetup(){
  WiFi.softAPdisconnect(true);
  WiFi.disconnect(true);
  WiFi.config(local, dns, netmask);
  WiFi.mode(WIFI_STA); 
  WiFi.begin("Robotic_Arm"); //Name of the wifi
    
  Serial.begin(115200);

  Udp.begin(UDPPort); //listening to the port UDPPort
  Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.softAPIP().toString().c_str(), UDPPort); //Print at serial
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
}

void UDP_Reception() {
  int packetSize1 = Udp.parsePacket(); //verify if a packet have been received
  // receive incoming UDP packets
  if ( packetSize1 ) { //if the packet was received then:
    if ( Udp.read(packetBuffer, (2 * NSERVO)) > 0 ) {
        Serial.print(packetBuffer);
        Serial.println(" ");
      for (int num = 0; num < NSERVO; num++) {
        SPEEDS[num] = int(packetBuffer[num]);
        TARGET[num] = int(packetBuffer[num + NSERVO]);
      }
    }
  }
}

// update the position of the arm motor according to speed and target received parameters
void MoveMyServo(int num) {
  // increase motor position according to speed parameter
  if (SPEEDS[num] = 13) {
    TARGET[num]=REAL[num];
  }
  else if (SPEEDS[num] > 0 && SPEEDS[num] < 11) {
    if (REAL[num] > TARGET[num]) REAL[num] = ( REAL[num] + TARGET[num] )/2;
    REAL[num] = REAL[num] + SPEEDS[num];
  }
  else {
    // when speed is null decrease the motor position
    REAL[num] = REAL[num] - 1;
    // however, the motor position cannot be below the initial value
    if (REAL[num] < INIT[num]) REAL[num] = INIT[num];
  }
  
  // send the position value to the motor
  SERVOS[num].write( DIR[num]? REAL[num] : MAX[num]-REAL[num] );
}


// update the position of each arm motor
void MoveMyArm(){
    for (int num = 0; num < NSERVO; num++) {
      MoveMyServo(num);    
  }
}

void loopServoDance() {
  while(count<TMAX){
    unsigned long NowTime = millis();
    if (NowTime - PrevTime >= interval) {
      PrevTime = NowTime;
      SERVOS[5].write(map(T[count][5],0,100,0,180));
      SERVOS[4].write(map(T[count][4],0,100,40,120));
      SERVOS[3].write(map(T[count][3],0,100,10,100));
      SERVOS[2].write(map(T[count][2],0,100,10,140));
      SERVOS[1].write(map(T[count][1],0,100,0,180));
      SERVOS[0].write(map(T[count][0],0,100,0,180));
              Serial.print(count);
        Serial.printf(" ");
      count++;
      return;
    }
  }
  return;
}





# MIMICKING-THE-BODY-BEHAVIOR-WITH-A-ROBOTIC-ARM
This study designs and develops all the useful components of a bionic arm robot. The core technologies are MyoWare™ Muscle sensors, Nextion display, ESP8266 microcontrollers and a robotic arm with six degrees of freedom. There is also a Wifi communication between subsystems and a man-machine interface will be designed to be able to drive a robotic arm. To do the acquisition of the human arm signals, it will be used electromyography technology and the Nextion display to interact with the robotic arm in real-time. The validity of a virtual simulation will be also studied.

## Contents
- [Materials](#Materials)
- [Robotic Arm](#Robotic-Arm)
- [Sensors](#Sensors)

## Materials
For this project it will be needed:
- 2 Node MCU ESP8266 1.0v;
- 2 HDMI type D / USB cables;
- Computer installed the Arduino IDE;
- [1 Robotic Arm with 6 servo motors](http://www.arobose.com/shop/kits-robot/45-bras-robotique.html);
- [3 MyoWare](https://www.sparkfun.com/products/13723);
- [1 Nextion NX4024T032](https://nextion.itead.cc/resources/datasheets/nx4024t032_011/);
- 2 breadboards;
- A lot of solid core wire.

## Robotic Arm
### Materials
For the Robotic Arm it is necessary:
- 1 Node MCU ESP8266 1.0v;
- 1 HDMI type D / USB cable;
- Computer installed the Arduino IDE;
- [1 Robotic Arm with 6 servo motors](http://www.arobose.com/shop/kits-robot/45-bras-robotique.html);
- 1 breadboards;
- 7 solid core wire.

### Pinout
The controlable pins, are D1 till D6 where:
- D1 = Grip;
- D2 = Pulse Rotation;
- D3 = FlexionHand;
- D4 = Elbow;
- D5 = Showder Lateral;
- D6 = Showder Rotation.
And the Ground of the ESP must be connected to the Ground of the Robotic Arm.
Also is important to settle the external energy alimentation for the Robotic Arm and the ESP must be plugged at the computer by the HDMI type D/USB cable.

## Sensors

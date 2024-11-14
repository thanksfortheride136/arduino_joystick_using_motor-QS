/*This enables the joystick control using the arduino joystick WITH A MOTOR.
Wiring: 
GND -> GND
5V -> 5V
VRx -> Analog Pin
VRy -> Analog Pin
SW -> Digital Pin
Max values for x/y coordinates are 1021 and the min value are 502.
----------------------

Motor Wiring:
Typical (BUT MAY VARY):
Red -> 5V+
Brown -> GND
Yellow -> Digital Pin
*/

#include <Servo.h>

Servo servo1;

const int vrx_pin = A0;   //defines each directions pins
const int vry_pin = A1;
int motorPin = 7;

int xValue = 0;   //stores x and y vals
int yValue = 0;



void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  servo1.attach(motorPin);
}

void loop() {
  controlServo();
  readJoyValue();
  xValue = analogRead(vrx_pin); //reads the value from the analog pin
  yValue = analogRead(vry_pin);
  // put your main code here, to run repeatedly:
  
  
  
}

void readJoyValue(){
  Serial.print("x = ");
  Serial.print(xValue);
  Serial.print(", y = ");
  Serial.println(yValue);
  delay(100);  // Add a small delay to make the output more readable
}

void controlServo(){
  if(xValue < 400){
    servo1.write(0);
  }else if(xValue > 600){
    servo1.write(180);
  }else{
    servo1.write(95);
  }
}

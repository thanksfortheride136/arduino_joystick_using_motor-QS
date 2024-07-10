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

#include <Arduino.h>
#include <Servo.h>

int xValue = analogRead(A5);
int yValue = analogRead(A4);
int x_pin = A4;
int y_pin = A5;
int motorPin = 13;

Servo motor1;

void setup() {
  Serial.begin(9600);
  motor1.attach(motorPin);
}

void loop() {
  // read analog X and Y analog values
  xValue = analogRead(x_pin);
  yValue = analogRead(y_pin);
  //motor1.write(90);
  // print data to Serial Monitor on Arduino IDE, can do many other things!
  //Serial.print("x = ");
  //Serial.print(xValue);
  //Serial.print(", y = ");
  //Serial.println(yValue);
  if(xValue > 1020){
    motor1.write(160);
  }else if(xValue < 1){
    motor1.write(20);
  }else{
    motor1.write(95);
  }
  //turnMotor();
}


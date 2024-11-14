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

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo1.attach(motorPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  moveMotor();
  readJoyValue();
  
  
}

void readJoyValue(){
  xValue = analogRead(vrx_pin); //reads the value from the analog pin
  yValue = analogRead(vry_pin);
  Serial.print("x = ");
  Serial.print(xValue);
  Serial.print(", y = ");
  Serial.println(yValue);
  delay(100);  // Add a small delay to make the output more readable
}

void moveMotor(){
  if(xValue < 400){
    servo1.write(0);
  }else if(xValue > 600){
    servo1.write(180);
  }else{
    servo1.write(95);
  }
}

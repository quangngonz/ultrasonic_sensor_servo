/*
  Ultrasonic sensor Pins:
      VCC: +5VDC
      Trig : Trigger (INPUT) - Pin11
      Echo: Echo (OUTPUT) - Pin 12
      GND: GND
 */
 
#include <Servo.h>
Servo myservo;

int trigPin = 11;    // Trigger
int echoPin = 12;    // Echo
long duration, cm, inches;
 
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  myservo.attach(9);
  myservo.write(0);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

int getDistance(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  return cm;
  
}
 
void loop() {
  if(getDistance()<15){
    myservo.write(180);
  } else{
    myservo.write(0);
  }
  delay(250);
}

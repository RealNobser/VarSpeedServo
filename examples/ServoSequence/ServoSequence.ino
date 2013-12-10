/*
  ServoSequence
  Reads an analog input, and plays different servo sequences depending on the analog value
 
  This example code is in the public domain.
 */
 
#include <VarSpeedServo.h> 

VarSpeedServo myservo1;

const int servoPin1 = 9;  // the digital pin used for the servo

servoSequencePoint slow[] = {{100,20},{20,20},{60,50}};
servoSequencePoint twitchy[] = {{0,255},{180,40},{90,127},{120,60}};

const int analogPin = A0;

// the setup routine runs once when you press reset:
void setup() {
  myservo1.attach(servoPin1);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(analogPin);
  if (sensorValue > 200) {
    myservo1.sequencePlay(slow, 3); // play sequence slowHalf that has 3 positions, loop and start at first position
  } else {
    myservo1.sequencePlay(twitchy, 4, true, 2); // play sequence 1, loop, start at third position
  }
  delay(2);        // delay in between reads for analogin stability
}


#include "SoftwareSerial.h"
#include <Servo.h>

// setup serial
SoftwareSerial mySoftwareSerial(10, 11); // RX, TX

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 13;     // the number of the pushbutton pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
// set scope mode to off
bool scopeModeOn = false;

// servo setup
// main arm
Servo servo1;


void setup(void) {

  Serial.begin(9600);
  // assigning the servo to pins 2 and 3
  servo1.attach(2);
  delay(1000);
  // set servo to off position
  servo1.write(100);
  delay(1000);
}

//main loop of program
void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  // check button state
  Serial.println(buttonState);
  
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // enable scope mode
    scopeModeOn = !scopeModeOn;

    // move scope into place
    if (scopeModeOn == true) {
      servo1.write(100);
      
    }

    // move scope into standby
    if (scopeModeOn == false) {
      servo1.write(45);
      
    }
    delay(500);
  }
}
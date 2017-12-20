

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards


void servoSetup() {
  myservo.attach(5);  // attaches the servo on pin 9 to the servo object
 
}

void doorOpen() {
    myservo.write(180);           
    delay(1000);                      
    myservo.write(0);
}


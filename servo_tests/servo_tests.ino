//#include <Servo.h>
#include <ServoEasing.hpp>

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;

int pos = 0;  // variable to store the servo position

void setup() {
  myservo1.attach(23);
  myservo2.attach(25);
  myservo3.attach(27);
  myservo4.attach(29);
  myservo5.attach(31);
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) {  // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos);
    myservo2.write(pos);
    myservo3.write(pos);
    myservo4.write(pos);
    myservo5.write(pos);
    delay(15);  // waits 15 ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) {  // goes from 180 degrees to 0 degrees
    myservo1.write(pos);
    myservo2.write(pos);
    myservo3.write(pos);
    myservo4.write(pos);
    myservo5.write(pos);
    delay(15);                           // waits 15 ms for the servo to reach the position
  }
}

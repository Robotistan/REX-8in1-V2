#include <ESP32Servo.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;

int servoPin1 = 2;
int servoPin2 = 26;
int servoPin3 = 18;
int servoPin4 = 19;

void setup() {
  myservo1.attach(servoPin1);
  myservo2.attach(servoPin2);
  myservo3.attach(servoPin3);
  myservo4.attach(servoPin4);
}

void loop() {
  myservo1.write(90);
  myservo2.write(90);
  myservo3.write(90);
  myservo4.write(90);
}

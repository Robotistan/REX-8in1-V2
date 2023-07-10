#include <ESP32Servo.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
int pos = 0;
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
  myservo1.write(0);
  myservo2.write(0);
  myservo3.write(0);
  myservo4.write(0);
  delay(2000);
  for (pos = 0; pos <= 90; pos += 1) {
    myservo1.write(pos);
    myservo2.write(pos);
    myservo3.write(pos);
    myservo4.write(pos);
    delay(15);
  }
  delay(2000);
  for (pos = 90; pos <= 180; pos += 1) {
    myservo1.write(pos);
    myservo2.write(pos);
    myservo3.write(pos);
    myservo4.write(pos);
    delay(15);
  }
  delay(2000);
  for (pos = 180; pos >= 90; pos -= 1) {
    myservo1.write(pos);
    myservo2.write(pos);
    myservo3.write(pos);
    myservo4.write(pos);
    delay(15);
  }
  delay(2000);
  for (pos = 90; pos >= 0; pos -= 1) {
    myservo1.write(pos);
    myservo2.write(pos);
    myservo3.write(pos);
    myservo4.write(pos);
    delay(15);
  }
  delay(2000);
}

//"""REX 8in1 Arm Bot"""
//Check the web site for Robots https://rex-rdt.readthedocs.io/en/latest/

#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>
#include <Arduino.h>
#include <analogWrite.h>
#include <ESP32Servo.h>

enum MOTOR_TYPE {
  DC_MOTOR,
  SERVO_MOTOR
};
enum MOTOR_TYPE motorType = DC_MOTOR;

//define Motor Pins
#define MotorA1 15 // Forward
#define MotorA2 23 // Backward

#define MotorB1 32 // Forward
#define MotorB2 33 // Backward

#define MotorC1 5 // Forward
#define MotorC2 4 // Backward

#define MotorD1 27 // Forward
#define MotorD2 14 // Backward

int position1 = 90 ;
int position2 = 90 ;
int position3 = 90 ;
int position4 = 90 ;

//define buzzer pins which named "horn"
#define horn 25

//define pins of servo motors
Servo Servo1; // Forward-Bakcward
Servo Servo2; // Right-Legt
Servo Servo3; // Up-Down
Servo Servo4; // Open-Close

void setup() {
  
  //first positions of servo motors
  Servo1.write(position1 = 90);
  Servo2.write(position2 = 90);
  Servo3.write(position3 = 90);
  Servo4.write(position4 = 90);

  //active pins which is defined
  pinMode(horn, OUTPUT);

  Servo1.attach(2);
  Servo2.attach(26);
  Servo3.attach(18);
  Servo4.attach(19);

  pinMode(MotorA1, OUTPUT);
  pinMode(MotorA2, OUTPUT);

  pinMode(MotorB1, OUTPUT);
  pinMode(MotorB2, OUTPUT);

  pinMode(MotorC1, OUTPUT);
  pinMode(MotorC2, OUTPUT);

  pinMode(MotorD1, OUTPUT);
  pinMode(MotorD2, OUTPUT);

  Serial.begin(115200);      // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin("REX_ROBOT"); //set bluetooth name of your device
}

void loop() {
  //Print of servo motor position on Serial Port
  /*Serial.println(position1);
  Serial.println(position2);
  Serial.println(position3);
  Serial.println(position4);*/

  //This function is used to keep information coming from the mobile device up to date.
  Dabble.processInput();
  stop();

  if (GamePad.isSelectPressed()) {
    motorType = SERVO_MOTOR;
    tone(horn, 330);
    delay(500);
    noTone(horn);
  }
  if (GamePad.isStartPressed()) {
    motorType = DC_MOTOR;
    tone(horn, 330);
    delay(100);
    noTone(horn);
  }

  switch (motorType) {
    case DC_MOTOR:
      //Serial.println("DC Turn On");
      dc_motor();
      break;
    case SERVO_MOTOR:
      //erial.println("Servo Turn On");
      servo_motor();
      break;
  }

  //Serial.println('\t');
  int a = GamePad.getAngle();
  /*Serial.print("Angle: ");
  Serial.print(a);
  Serial.print('\t');*/

  int b = GamePad.getRadius();
  /*Serial.print("Radius: ");
  Serial.print(b);
  Serial.print('\t');*/

  float c = GamePad.getXaxisData();
  /*Serial.print("x_axis: ");
  Serial.print(c);
  Serial.print('\t');*/

  float d = GamePad.getYaxisData();
  /*Serial.print("y_axis: ");
  Serial.println(d);
  Serial.println();*/

}

void servo_motor() {
  if (GamePad.isUpPressed())
  {
    if (position2 > 0) {
      position2 = position2 - 1;
      Serial.println("Up pressed");
      Serial.println(position2);
    }
    delay(5);
    Servo2.write(position2);
  }

  if (GamePad.isDownPressed())
  {
    if (position2 < 140) {
      position2 = position2 + 1;
    }
    delay(5);
    Servo2.write(position2);
  }

  if (GamePad.isRightPressed())
  {
    //Serial.print("Servo Right");
    if (position1 < 180) {
      position1 = position1 + 1;
    }
    delay(5);
    Servo1.write(position1);
  }
  if (GamePad.isLeftPressed())
  {
    //Serial.print("Servo Left");
    if (position1 > 85) {
      position1 = position1 - 1;
    }
    delay(5);
    Servo1.write(position1);
  }

  if (GamePad.isSquarePressed())
  {
    //Serial.print("Servo Square");
    if (position4 < 160) {
      position4 = position4 + 1;
    }
    delay(5);
    Servo4.write(position4);
  }

  if (GamePad.isCirclePressed())
  {
    //Serial.print("Servo Circle");
    if (position4 > 0) {
      position4 = position4 - 1;
    }
    delay(5);
    Servo4.write(position4);
  }

  if (GamePad.isCrossPressed())
  {
    //Serial.print("Servo Cross");
    if (position3 > 0) {
      position3 = position3 - 1;
    }
    delay(5);
    Servo3.write(position3);
  }

  if (GamePad.isTrianglePressed())
  {
    //Serial.print("Servo Triangle");
    if (position3 < 180) {
      position3 = position3 + 1;
    }
    delay(5);
    Servo3.write(position3);
  }
}

void dc_motor() {
  if (GamePad.isUpPressed())
  {
    //Serial.print("DC Forward");
    forward();

  }

  if (GamePad.isDownPressed())
  {
    //Serial.print("DC Back");
    backward();
  }

  if (GamePad.isLeftPressed())
  {
    //Serial.print("DC Left");
    left();
  }

  if (GamePad.isRightPressed())
  {
    //Serial.print("DC Right");
    right();
  }
  if (GamePad.isSquarePressed())
  {
    //Serial.print("DC Square");
  }

  if (GamePad.isCirclePressed())
  {
    //Serial.print("DC Circle");
    for (int i = 0; i < 3; i++)
    {
      forward();
      tone(horn, 330);
      delay(300);
      left();
      tone(horn, 430);
      delay(300);
      right ();
      tone(horn, 530);
      delay(300);
      tone(horn, 630);
      left();
      delay(300);
      noTone(horn);
    }
  }

  if (GamePad.isCrossPressed())
  {
    //Serial.print("DC Cross");
    tone(horn, 330);
    delay(100);
    noTone(horn);
  }

  if (GamePad.isTrianglePressed())
  {
    //Serial.print("DC Triangle");
    Servo1.write(position1 = 85);
    Servo2.write(position2 = 0);
    Servo3.write(position3 = 30);
    Servo4.write(position4 = 90);
  }
}

void forward() {

  digitalWrite(MotorA1, HIGH);
  digitalWrite(MotorA2, LOW);

  digitalWrite(MotorB1, HIGH);
  digitalWrite(MotorB2, LOW);

  digitalWrite(MotorC1, HIGH);
  digitalWrite(MotorC2, LOW);

  digitalWrite(MotorD1, HIGH);
  digitalWrite(MotorD2, LOW);
}

void right() {
  digitalWrite(MotorA1, HIGH);
  digitalWrite(MotorA2, LOW);

  digitalWrite(MotorB1, HIGH);
  digitalWrite(MotorB2, LOW);

  digitalWrite(MotorC1, LOW);
  digitalWrite(MotorC2, HIGH);

  digitalWrite(MotorD1, LOW);
  digitalWrite(MotorD2, HIGH);
}

void left() {

  digitalWrite(MotorA1, LOW);
  digitalWrite(MotorA2, HIGH);

  digitalWrite(MotorB1, LOW);
  digitalWrite(MotorB2, HIGH);

  digitalWrite(MotorC1, HIGH);
  digitalWrite(MotorC2, LOW);

  digitalWrite(MotorD1, HIGH);
  digitalWrite(MotorD2, LOW);

}

void stop() {

  digitalWrite(MotorA1, LOW);
  digitalWrite(MotorA2, LOW);

  digitalWrite(MotorB1, LOW);
  digitalWrite(MotorB2, LOW);

  digitalWrite(MotorC1, LOW);
  digitalWrite(MotorC2, LOW);

  digitalWrite(MotorD1, LOW);
  digitalWrite(MotorD2, LOW);

}

void backward() {

  digitalWrite(MotorA1, LOW);
  digitalWrite(MotorA2, HIGH);

  digitalWrite(MotorB1, LOW);
  digitalWrite(MotorB2, HIGH);

  digitalWrite(MotorC1, LOW);
  digitalWrite(MotorC2, HIGH);

  digitalWrite(MotorD1, LOW);
  digitalWrite(MotorD2, HIGH);
}

void gamepad() {
  digitalWrite(MotorA1, HIGH);
  digitalWrite(MotorA2, LOW);

  digitalWrite(MotorB1, HIGH);
  digitalWrite(MotorB2, LOW);

  digitalWrite(MotorC1, HIGH);
  digitalWrite(MotorC2, LOW);

  digitalWrite(MotorD1, HIGH);
  digitalWrite(MotorD2, LOW);
}

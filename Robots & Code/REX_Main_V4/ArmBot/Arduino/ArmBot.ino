//"""REX 8in1 Arm Bot"""
// ESP32 Board Version Must Be 2.0.11

#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>
#include <Arduino.h>
#include <ESP32Servo.h>

enum MOTOR_TYPE {
  DC_MOTOR,
  SERVO_MOTOR
};

enum MOTOR_TYPE motorType = DC_MOTOR;

//define Motor Pins
#define MotorA1 15  // Forward
#define MotorA2 23  // Backward

#define MotorB1 32  // Forward
#define MotorB2 33  // Backward

#define MotorC1 5  // Forward
#define MotorC2 4  // Backward

#define MotorD1 27  // Forward
#define MotorD2 14  // Backward

int position1 = 90;
int position2 = 90;
int position3 = 90;
int position4 = 90;

//define buzzer pin named "horn"
int horn = 25;

//define pins of servo motors
Servo Servo1;  // Forward-Bakcward
Servo Servo2;  // Right-Legt
Servo Servo3;  // Up-Down
Servo Servo4;  // Open-Close

void setup() {
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);

  Servo1.setPeriodHertz(50);
  Servo2.setPeriodHertz(50);
  Servo3.setPeriodHertz(50);
  Servo4.setPeriodHertz(50);
  //defined active pins
  pinMode(horn, OUTPUT);

  Servo1.attach(2, 600, 2500);
  Servo2.attach(26, 600, 2500);
  Servo3.attach(18, 600, 2500);
  Servo4.attach(19, 600, 2500);

  //first positions of servo motors
  Servo1.write(position1);
  Servo2.write(position2);
  Servo3.write(position3);
  Servo4.write(position4);


  pinMode(MotorA1, OUTPUT);
  pinMode(MotorA2, OUTPUT);

  pinMode(MotorB1, OUTPUT);
  pinMode(MotorB2, OUTPUT);

  pinMode(MotorC1, OUTPUT);
  pinMode(MotorC2, OUTPUT);

  pinMode(MotorD1, OUTPUT);
  pinMode(MotorD2, OUTPUT);

  Serial.begin(115200);       // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin("REX_ROBOT");  //set bluetooth name of your device
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
    digitalWrite(horn, HIGH);
    delay(100);
    digitalWrite(horn, LOW);
    delay(1);

    int position1 = 90;
    int position2 = 90;
    int position3 = 90;
    int position4 = 90;
    
  }
  if (GamePad.isStartPressed()) {
    motorType = DC_MOTOR;
    digitalWrite(horn, HIGH);
    delay(100);
    digitalWrite(horn, LOW);
    delay(1);
    digitalWrite(horn, HIGH);
    delay(100);
    digitalWrite(horn, LOW);
    delay(1);
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

  if (GamePad.isUpPressed()) {
    if (position2 > 0) {
      position2 = position2 - 1;
    }
  }
  if (GamePad.isDownPressed()) {
    if (position2 < 140) {
      position2 = position2 + 1;
    }
  }
  if (GamePad.isRightPressed()) {
    if (position1 < 140) {
      position1 = position1 + 1;
    }
  }
  if (GamePad.isLeftPressed()) {
    if (position1 > 40) {
      position1 = position1 - 1;
    }
  }
  if (GamePad.isSquarePressed()) {
    if (position4 < 160) {
      position4 = position4 + 1;
    }
  }

  if (GamePad.isCirclePressed()) {
    if (position4 > 90) {
      position4 = position4 - 1;
    }
  }

  if (GamePad.isCrossPressed()) {
    if (position3 > 30) {
      position3 = position3 - 1;
    }
  }

  if (GamePad.isTrianglePressed()) {
    if (position3 < 150) {
      position3 = position3 + 1;
    }
  }

  delay(10);

  Servo1.write(position1);
  Servo2.write(position2);
  Servo3.write(position3);
  Servo4.write(position4);
}

void dc_motor() {
  if (GamePad.isUpPressed()) {
    forward();
  }

  if (GamePad.isDownPressed()) {
    backward();
  }

  if (GamePad.isLeftPressed()) {
    left();
  }

  if (GamePad.isRightPressed()) {
    right();
  }
  if (GamePad.isSquarePressed()) {
  }

  if (GamePad.isCirclePressed()) {
    for (int i = 0; i < 3; i++) {
      forward();
      digitalWrite(horn, HIGH);
      delay(300);
      digitalWrite(horn, LOW);
      delay(300);
      left();
      digitalWrite(horn, HIGH);
      delay(400);
      digitalWrite(horn, LOW);
      delay(300);
      right();
      digitalWrite(horn, HIGH);
      delay(500);
      digitalWrite(horn, LOW);
      delay(300);
      digitalWrite(horn, HIGH);
      delay(600);
      digitalWrite(horn, LOW);
      left();
      delay(300);
    }
  }

  if (GamePad.isCrossPressed()) {
    //Serial.print("DC Cross");
    digitalWrite(horn, HIGH);
    delay(200);
    digitalWrite(horn, LOW);
    delay(1);
  }

  if (GamePad.isTrianglePressed()) {
    //Serial.print("DC Triangle");
    Servo1.write(90);
    Servo2.write(90);
    Servo3.write(90);
    Servo4.write(90);
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

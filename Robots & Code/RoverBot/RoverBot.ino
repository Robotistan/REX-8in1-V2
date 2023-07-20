//"""REX 8in1 Rover Bot"""
//Check the web site for Robots https://rex-rdt.readthedocs.io/en/latest/
// you can also control arm bot in this code.
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

int position1 = 90;
int position2 = 90;
int position3 = 90;
int position4 = 90;

//Define Motor Pins
#define MotorA1 15 // Forward
#define MotorA2 23 // Backward

#define MotorB1 32 // Forward
#define MotorB2 33 // Backward

#define MotorC1 5 // Forward
#define MotorC2 4 // Backward

#define MotorD1 27 // Forward
#define MotorD2 14 // Backward

#define horn 2

Servo Servo1; // ileri geri
Servo Servo2; // sağ sol
Servo Servo3; // yukarı aşağı
Servo Servo4; // kıskaç açık kapalı

void setup() {
  //active pins which is defined
  pinMode(horn, OUTPUT);

  Servo1.attach(25);
  Servo2.attach(26);
  Servo3.attach(18);
  Servo4.attach(19);

  //first positions of servo motors
  Servo1.write(position1 = 85);
  Servo2.write(position2 = 140);
  Servo3.write(position3 = 22);
  Servo4.write(position4 = 90);

  pinMode(MotorA1, OUTPUT);
  pinMode(MotorA2, OUTPUT);

  pinMode(MotorB1, OUTPUT);
  pinMode(MotorB2, OUTPUT);

  pinMode(MotorC1, OUTPUT);
  pinMode(MotorC2, OUTPUT);

  pinMode(MotorD1, OUTPUT);
  pinMode(MotorD2, OUTPUT);
  
  Serial.begin(115200);  // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin("REX_ROBOT"); //set bluetooth name of your device
}

void loop() {

  Serial.println(position1);
  Serial.println(position2);
  Serial.println(position3);
  Serial.println(position4);

  Dabble.processInput();
  dur();
  if (GamePad.isSelectPressed()) {
    motorType = SERVO_MOTOR;
    tone(horn, 330);
    delay(500);
    noTone(2);
  }
  if (GamePad.isStartPressed()) {
    motorType = DC_MOTOR;
    tone(horn, 330);
    delay(100);
    noTone(2);
  }

  switch (motorType) {
    case DC_MOTOR:
      Serial.println("DC Çalışıyor");
      dc_motor();
      break;
    case SERVO_MOTOR:
      Serial.println("Servo Çalışıyor");
      servo_motor();
      break;
  }

  Serial.println('\t');
  int a = GamePad.getAngle();
  Serial.print("Angle: ");
  Serial.print(a);
  Serial.print('\t');

  int b = GamePad.getRadius();
  Serial.print("Radius: ");
  Serial.print(b);
  Serial.print('\t');

  float c = GamePad.getXaxisData();
  Serial.print("x_axis: ");
  Serial.print(c);
  Serial.print('\t');

  float d = GamePad.getYaxisData();
  Serial.print("y_axis: ");
  Serial.println(d);
  Serial.println();

}

void servo_motor() {
  if (GamePad.isUpPressed())
  {
    if (position2 > 0) {
      position2 = position2 - 1;
    }
    Servo2.write(position2);
  }

  if (GamePad.isDownPressed())
  {
    if (position2 < 140) {
      position2 = position2 + 1;
    }
    Servo2.write(position2);
  }

  if (GamePad.isRightPressed())
  {
    Serial.print("Servo Sağa");
    if (position1 < 180) {
      position1 = position1 + 1;
    }
    Servo1.write(position1);
  }
  if (GamePad.isLeftPressed())
  {
    Serial.print("Servo Sola");
    if (position1 > 85) {
      position1 = position1 - 1;
    }
    Servo1.write(position1);
  }

  if (GamePad.isSquarePressed())
  {
    Serial.print("Servo Kare");
    if (position4 < 160) {
      position4 = position4 + 1;
    }
    Servo4.write(position4);
  }

  if (GamePad.isCirclePressed())
  {
    Serial.print("Servo Daire");
    if (position4 > 0) {
      position4 = position4 - 1;
    }
    Servo4.write(position4);
  }

  if (GamePad.isCrossPressed())
  {
    Serial.print("Servo Çarpı");
    if (position3 > 0) {
      position3 = position3 - 1;
    }
    Servo3.write(position3);
  }

  if (GamePad.isTrianglePressed())
  {
    Serial.print("Servo Üçgen");
    if (position3 < 180) {
      position3 = position3 + 1;
    }
    Servo3.write(position3);
  }
}

void dc_motor() {
  if (GamePad.isUpPressed())
  {
    Serial.print("İleri");
    ileri();

  }

  if (GamePad.isDownPressed())
  {
    Serial.print("DC Geri");
    geri();
  }

  if (GamePad.isLeftPressed())
  {
    Serial.print("DC Sola");
    yerindesol();
  }

  if (GamePad.isRightPressed())
  {
    Serial.print("DC Sağa");
    yerindesag();
  }
  if (GamePad.isSquarePressed())
  {
    Serial.print("DC Kare");
  }

  if (GamePad.isCirclePressed())
  {
    Serial.print("DC Daire");
  }

  if (GamePad.isCrossPressed())
  {
    Serial.print("DC Çarpı");
    tone(horn, 330);
    delay(100);
    noTone(2);
  }

  if (GamePad.isTrianglePressed())
  {
    Serial.print("DC Üçgen");
    Servo1.write(position1 = 85);
    Servo2.write(position2 = 0);
    Servo3.write(position3 = 30);
    Servo4.write(position4 = 90);
  }
}

void ileri() { // ileri yönde hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(MotorA1, HIGH);
  digitalWrite(MotorA2, LOW);

  digitalWrite(MotorB1, HIGH);
  digitalWrite(MotorB2, LOW);

  digitalWrite(MotorC1, HIGH);
  digitalWrite(MotorC2, LOW);

  digitalWrite(MotorD1, HIGH);
  digitalWrite(MotorD2, LOW);
}

void yerindesag() { // sağa dönme hareketi için fonksiyon tanımlıyoruz.
  digitalWrite(MotorA1, HIGH);
  digitalWrite(MotorA2, LOW);

  digitalWrite(MotorB1, HIGH);
  digitalWrite(MotorB2, LOW);

  digitalWrite(MotorC1, LOW);
  digitalWrite(MotorC2, HIGH);

  digitalWrite(MotorD1, LOW);
  digitalWrite(MotorD2, HIGH);
}

void yerindesol() { // sola dönme hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(MotorA1, LOW);
  digitalWrite(MotorA2, HIGH);

  digitalWrite(MotorB1, LOW);
  digitalWrite(MotorB2, HIGH);

  digitalWrite(MotorC1, HIGH);
  digitalWrite(MotorC2, LOW);

  digitalWrite(MotorD1, HIGH);
  digitalWrite(MotorD2, LOW);

}

void dur() { // durma hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(MotorA1, LOW);
  digitalWrite(MotorA2, LOW);

  digitalWrite(MotorB1, LOW);
  digitalWrite(MotorB2, LOW);

  digitalWrite(MotorC1, LOW);
  digitalWrite(MotorC2, LOW);

  digitalWrite(MotorD1, LOW);
  digitalWrite(MotorD2, LOW);

}

void geri() { // geri hareketi için fonksiyon tanımlıyoruz.

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

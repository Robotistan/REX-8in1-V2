// ESP32 Board Version Must Be 2.0.11

//Wi-Bot
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>
#include <Arduino.h>

//define motor pins and speeds
#define MotorPWM 13	//Pwm

#define MotorA1 15  // Forward
#define MotorA2 23  // Backward

#define MotorB1 32  // Forward
#define MotorB2 33  // Backward

#define MotorC1 27  // Forward
#define MotorC2 14  // Backward

#define MotorD1 5  // Forward
#define MotorD2 4  // Backward

//define buzzer pin named "horn"
#define horn 25

void setup() {
  pinMode(horn, OUTPUT);

  pinMode(MotorPWM, OUTPUT);

  pinMode(MotorA1, OUTPUT);
  pinMode(MotorA2, OUTPUT);

  pinMode(MotorB1, OUTPUT);
  pinMode(MotorB2, OUTPUT);

  pinMode(MotorC1, OUTPUT);
  pinMode(MotorC2, OUTPUT);

  pinMode(MotorD1, OUTPUT);
  pinMode(MotorD2, OUTPUT);

  Serial.begin(115200);
  Dabble.begin("REX_ROBOT");
}

void loop() {
  Dabble.processInput();
  stop();
  if (GamePad.isUpPressed())
  {
    forward();
  }

  if (GamePad.isDownPressed())
  {
    backward();
  }

  if (GamePad.isLeftPressed())
  {
    left();
  }

  if (GamePad.isRightPressed())
  {
    right();
  }

  if (GamePad.isSquarePressed())
  {
    Serial.print("Square");

  }

  if (GamePad.isCirclePressed())
  {
    rex_horn();
  }

  if (GamePad.isCrossPressed())
  {
    rex_horn();
  }

  if (GamePad.isTrianglePressed())
  {
    Serial.print("Triangle");
  }

  if (GamePad.isStartPressed())
  {
    Serial.print("Start");
  }

  if (GamePad.isSelectPressed())
  {
    Serial.print("Select");
  }
  Serial.print('\t');

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

void forward() { 
  digitalWrite(MotorPWM, HIGH);

  digitalWrite(MotorA1, HIGH);
  digitalWrite(MotorA2, LOW);

  digitalWrite(MotorB1, HIGH);
  digitalWrite(MotorB2, LOW);

  digitalWrite(MotorC1, HIGH);
  digitalWrite(MotorC2, LOW);

  digitalWrite(MotorD1, HIGH);
  digitalWrite(MotorD2, LOW);
}

void left() { 
  digitalWrite(MotorPWM, HIGH);

  digitalWrite(MotorA1, LOW);
  digitalWrite(MotorA2, HIGH);

  digitalWrite(MotorB1, LOW);
  digitalWrite(MotorB2, HIGH);

  digitalWrite(MotorC1, HIGH);
  digitalWrite(MotorC2, LOW);

  digitalWrite(MotorD1, HIGH);
  digitalWrite(MotorD2, LOW);
}

void right() { 
  digitalWrite(MotorPWM, HIGH);

  digitalWrite(MotorA1, HIGH);
  digitalWrite(MotorA2, LOW);

  digitalWrite(MotorB1, HIGH);
  digitalWrite(MotorB2, LOW);

  digitalWrite(MotorC1, LOW);
  digitalWrite(MotorC2, HIGH);

  digitalWrite(MotorD1, LOW);
  digitalWrite(MotorD2, HIGH);
}

void stop() {
  digitalWrite(MotorPWM, LOW);

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
  digitalWrite(MotorPWM, HIGH);
  
  digitalWrite(MotorA1, LOW);
  digitalWrite(MotorA2, HIGH);

  digitalWrite(MotorB1, LOW);
  digitalWrite(MotorB2, HIGH);

  digitalWrite(MotorC1, LOW);
  digitalWrite(MotorC2, HIGH);

  digitalWrite(MotorD1, LOW);
  digitalWrite(MotorD2, HIGH);
}

void rex_horn() {
  for(int i=0; i<50; i++){
    digitalWrite(horn, HIGH);
    delay(1);
    digitalWrite(horn, LOW);
    delay(1);
  }
}

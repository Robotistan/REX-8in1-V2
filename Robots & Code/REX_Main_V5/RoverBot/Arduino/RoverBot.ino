//"""REX 8in1 Rover Bot"""
//Check the web site for Robots https://rex-rdt.readthedocs.io/en/latest/
#include <DabbleESP32.h>
#include <Arduino.h>

//Define Motor Pins
#define MotorPWM 13	//Pwm

#define MotorA1 15 // Forward
#define MotorA2 23 // Backward

#define MotorB1 32 // Forward
#define MotorB2 33 // Backward

#define MotorC1 5 // Forward
#define MotorC2 4 // Backward

#define MotorD1 27 // Forward
#define MotorD2 14 // Backward

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
  
  Serial.begin(115200);  // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin("REX_ROBOT"); //set bluetooth name of your device
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
    Serial.print("Circle");
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

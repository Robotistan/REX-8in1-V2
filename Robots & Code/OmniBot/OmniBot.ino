//"""REX 8in1 Omni Bot"""
//Check the web site for Robots https://rex-rdt.readthedocs.io/en/latest/

#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE

#include <DabbleESP32.h>
#include <Arduino.h>
#include <analogWrite.h>
#include <ESP32Servo.h>


//define pins of motors
//DC Motor_1
#define MotorA1 23
#define MotorA2 15

//DC Motor_2
#define MotorB1 33
#define MotorB2 32

//DC Motor_3
#define MotorC1 16
#define MotorC2 17

//DC Motor_4
#define MotorD1 14
#define MotorD2 27
#define horn 2

#define low_s 100
#define mid_s 150
#define high_s 250

int i = 0 ;
void setup() {
  //active pins which is defined

  pinMode(horn, OUTPUT);

  pinMode(MotorA1, OUTPUT);
  pinMode(MotorA2, OUTPUT);

  pinMode(MotorB1, OUTPUT);
  pinMode(MotorB2, OUTPUT);

  pinMode(MotorC1, OUTPUT);
  pinMode(MotorC2, OUTPUT);

  pinMode(MotorD1, OUTPUT);
  pinMode(MotorD2, OUTPUT);

  Serial.begin(115200); // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin("REX_OMNI"); //set bluetooth name of your device
}


void loop() {
  delay(20);
  Dabble.processInput();
  Serial.println('\t');

  int a = GamePad.getAngle();
  Serial.print("Angle: ");
  Serial.print(a);
  Serial.print('\t');

  int b = GamePad.getRadius();
  Serial.print("Radius: ");
  Serial.print(b);
  Serial.print('\t');

  if (GamePad.isCrossPressed())
  {
    Serial.print("DC Çarpı");
    tone(horn, 330);
    delay(100);
    noTone(2);
  }
  if (GamePad.isSquarePressed())
  {
  }
  /////////////////////////////YUKARI////////////////////////////////////

  if (a > 60 && a < 120 && b >= 1 && b <= 3)
  {
    analogWrite(MotorA1, low_s);
    analogWrite(MotorA2, 0);

    analogWrite(MotorB1, low_s);
    analogWrite(MotorB2, 0);

    analogWrite(MotorC1, low_s);
    analogWrite(MotorC2, 0);

    analogWrite(MotorD1, low_s);
    analogWrite(MotorD2, 0);
  }

  else if (a > 60 && a < 120 && b > 3 && b <= 5)
  {
    analogWrite(MotorA1, mid_s);
    analogWrite(MotorA2, 0);

    analogWrite(MotorB1, mid_s);
    analogWrite(MotorB2, 0);

    analogWrite(MotorC1, mid_s);
    analogWrite(MotorC2, 0);

    analogWrite(MotorD1, mid_s);
    analogWrite(MotorD2, 0);
  }

  else if (a > 60 && a < 120 && b > 5 && b <= 7)
  {
    analogWrite(MotorA1, high_s);
    analogWrite(MotorA2, 0);

    analogWrite(MotorB1, high_s);
    analogWrite(MotorB2, 0);

    analogWrite(MotorC1, high_s);
    analogWrite(MotorC2, 0);

    analogWrite(MotorD1, high_s);
    analogWrite(MotorD2, 0);
  }
  /////////////////////////////AŞAĞI////////////////////////////////////

  else if (a > 240 && a < 300 && b >= 1 && b <= 3)
  {
    analogWrite(MotorA1, 0);
    analogWrite(MotorA2, low_s);

    analogWrite(MotorB1, 0);
    analogWrite(MotorB2, low_s);

    analogWrite(MotorC1, 0);
    analogWrite(MotorC2, low_s);

    analogWrite(MotorD1, 0);
    analogWrite(MotorD2, low_s);
  }

  else if (a > 240 && a < 300 && b > 3 && b <= 5)
  {
    analogWrite(MotorA1, 0);
    analogWrite(MotorA2, mid_s);

    analogWrite(MotorB1, 0);
    analogWrite(MotorB2, mid_s);

    analogWrite(MotorC1, 0);
    analogWrite(MotorC2, mid_s);

    analogWrite(MotorD1, 0);
    analogWrite(MotorD2, mid_s);
  }

  else if (a > 240 && a < 300 && b > 5 && b <= 7)
  {
    analogWrite(MotorA1, 0);
    analogWrite(MotorA2, high_s);

    analogWrite(MotorB1, 0);
    analogWrite(MotorB2, high_s);

    analogWrite(MotorC1, 0);
    analogWrite(MotorC2, high_s);

    analogWrite(MotorD1, 0);
    analogWrite(MotorD2, high_s);
  }

  /////////////////////////////SAĞ////////////////////////////////////
  //////////////////////////////0-30////////////////
  else if (a >= 0 && a < 30 && b >= 1 && b <= 3)
  {
    analogWrite(MotorA1, low_s);
    analogWrite(MotorA2, 0);

    analogWrite(MotorB1, 0);
    analogWrite(MotorB2, low_s);

    analogWrite(MotorC1, 0);
    analogWrite(MotorC2, low_s);

    analogWrite(MotorD1, low_s);
    analogWrite(MotorD2, 0);
  }

  else if (a >= 0 && a < 30 && b > 3 && b <= 5)
  {
    analogWrite(MotorA1, mid_s);
    analogWrite(MotorA2, 0);

    analogWrite(MotorB1, 0);
    analogWrite(MotorB2, mid_s);

    analogWrite(MotorC1, 0);
    analogWrite(MotorC2, mid_s);

    analogWrite(MotorD1, mid_s);
    analogWrite(MotorD2, 0);
  }

  else if (a >= 0 && a < 30 && b > 5 && b <= 7)
  {
    analogWrite(MotorA1, high_s);
    analogWrite(MotorA2, 0);

    analogWrite(MotorB1, 0);
    analogWrite(MotorB2, high_s);

    analogWrite(MotorC1, 0);
    analogWrite(MotorC2, high_s);

    analogWrite(MotorD1, high_s);
    analogWrite(MotorD2, 0);
  }
  //////////////////////////330-360///////////////////////////
  else if (a > 330 && a < 360 && b >= 1 && b <= 3)
  {
    analogWrite(MotorA1, low_s);
    analogWrite(MotorA2, 0);

    analogWrite(MotorB1, 0);
    analogWrite(MotorB2, low_s);

    analogWrite(MotorC1, 0);
    analogWrite(MotorC2, low_s);

    analogWrite(MotorD1, low_s);
    analogWrite(MotorD2, 0);
  }

  else if (a > 330 && a < 360 && b > 3 && b <= 5)
  {
    analogWrite(MotorA1, mid_s);
    analogWrite(MotorA2, 0);

    analogWrite(MotorB1, 0);
    analogWrite(MotorB2, mid_s);

    analogWrite(MotorC1, 0);
    analogWrite(MotorC2, mid_s);

    analogWrite(MotorD1, mid_s);
    analogWrite(MotorD2, 0);
  }

  else if (a > 330 && a < 360 && b > 5 && b <= 7)
  {
    analogWrite(MotorA1, high_s);
    analogWrite(MotorA2, 0);

    analogWrite(MotorB1, 0);
    analogWrite(MotorB2, high_s);

    analogWrite(MotorC1, 0);
    analogWrite(MotorC2, high_s);

    analogWrite(MotorD1, high_s);
    analogWrite(MotorD2, 0);
  }

  /////////////////////////////SOL////////////////////////////////////

  else if (a > 150 && a < 210 && b >= 1 && b <= 3)
  {
    analogWrite(MotorA1, 0);
    analogWrite(MotorA2, low_s);

    analogWrite(MotorB1, low_s);
    analogWrite(MotorB2, 0);

    analogWrite(MotorC1, low_s);
    analogWrite(MotorC2, 0);

    analogWrite(MotorD1, 0);
    analogWrite(MotorD2, low_s);
  }

  else if (a > 150 && a < 210 && b > 3 && b <= 5)
  {
    analogWrite(MotorA1, 0);
    analogWrite(MotorA2, mid_s);

    analogWrite(MotorB1, mid_s);
    analogWrite(MotorB2, 0);

    analogWrite(MotorC1, mid_s);
    analogWrite(MotorC2, 0);

    analogWrite(MotorD1, 0);
    analogWrite(MotorD2, mid_s);
  }

  else if (a > 150 && a < 210 && b > 5 && b <= 7)
  {
    analogWrite(MotorA1, 0);
    analogWrite(MotorA2, high_s);

    analogWrite(MotorB1, high_s);
    analogWrite(MotorB2, 0);

    analogWrite(MotorC1, high_s);
    analogWrite(MotorC2, 0);

    analogWrite(MotorD1, 0);
    analogWrite(MotorD2, high_s);
  }

  //////////////////////////////////ARA YÖNLER///////////////////////////////////////////
  /////////////////////////////SAĞ-YUKARI////////////////////////////////////

  else if (a >= 30 && a <= 60 && b >= 1 && b <= 3)
  {
    analogWrite(MotorA1, low_s);
    analogWrite(MotorA2, 0);

    analogWrite(MotorB1, 0);
    analogWrite(MotorB2, 0);

    analogWrite(MotorC1, 0);
    analogWrite(MotorC2, 0);

    analogWrite(MotorD1, low_s);
    analogWrite(MotorD2, 0);
  }

  else if (a >= 30 && a <= 60 && b > 3 && b <= 5)
  {
    analogWrite(MotorA1, mid_s);
    analogWrite(MotorA2, 0);

    analogWrite(MotorB1, 0);
    analogWrite(MotorB2, 0);

    analogWrite(MotorC1, 0);
    analogWrite(MotorC2, 0);

    analogWrite(MotorD1, mid_s);
    analogWrite(MotorD2, 0);
  }

  else if (a >= 30 && a <= 60 && b > 5 && b <= 7)
  {
    analogWrite(MotorA1, high_s);
    analogWrite(MotorA2, 0);

    analogWrite(MotorB1, 0);
    analogWrite(MotorB2, 0);

    analogWrite(MotorC1, 0);
    analogWrite(MotorC2, 0);

    analogWrite(MotorD1, high_s);
    analogWrite(MotorD2, 0);
  }

  /////////////////////////////SOL-YUKARI////////////////////////////////////

  else if (a >= 120 && a <= 150 && b >= 1 && b <= 3)
  {
    analogWrite(MotorA1, 0);
    analogWrite(MotorA2, 0);

    analogWrite(MotorB1, low_s);
    analogWrite(MotorB2, 0);

    analogWrite(MotorC1, low_s);
    analogWrite(MotorC2, 0);

    analogWrite(MotorD1, 0);
    analogWrite(MotorD2, 0);
  }

  else if (a >= 120 && a <= 150 && b > 3 && b <= 5)
  {
    analogWrite(MotorA1, 0);
    analogWrite(MotorA2, 0);

    analogWrite(MotorB1, mid_s);
    analogWrite(MotorB2, 0);

    analogWrite(MotorC1, mid_s);
    analogWrite(MotorC2, 0);

    analogWrite(MotorD1, 0);
    analogWrite(MotorD2, 0);
  }

  else if (a >= 120 && a <= 150 && b > 5 && b <= 7)
  {
    analogWrite(MotorA1, 0);
    analogWrite(MotorA2, 0);

    analogWrite(MotorB1, high_s);
    analogWrite(MotorB2, 0);

    analogWrite(MotorC1, high_s);
    analogWrite(MotorC2, 0);

    analogWrite(MotorD1, 0);
    analogWrite(MotorD2, 0);
  }
  /////////////////////////////SOL-AŞAĞI////////////////////////////////////

  else if (a >= 210 && a <= 240 && b >= 1 && b <= 3)
  {
    analogWrite(MotorA1, 0);
    analogWrite(MotorA2, low_s);

    analogWrite(MotorB1, 0);
    analogWrite(MotorB2, 0);

    analogWrite(MotorC1, 0);
    analogWrite(MotorC2, 0);

    analogWrite(MotorD1, 0);
    analogWrite(MotorD2, low_s);
  }

  else if (a >= 210 && a <= 240 && b > 3 && b <= 5)
  {
    analogWrite(MotorA1, 0);
    analogWrite(MotorA2, mid_s);

    analogWrite(MotorB1, 0);
    analogWrite(MotorB2, 0);

    analogWrite(MotorC1, 0);
    analogWrite(MotorC2, 0);

    analogWrite(MotorD1, 0);
    analogWrite(MotorD2, mid_s);
  }

  else if (a >= 210 && a <= 240 && b > 5 && b <= 7)
  {
    analogWrite(MotorA1, 0);
    analogWrite(MotorA2, high_s);

    analogWrite(MotorB1, 0);
    analogWrite(MotorB2, 0);

    analogWrite(MotorC1, 0);
    analogWrite(MotorC2, 0);

    analogWrite(MotorD1, 0);
    analogWrite(MotorD2, high_s);
  }


  /////////////////////////////SAĞ-AŞAĞI////////////////////////////////////

  else if (a >= 300 && a <= 330 && b >= 1 && b <= 3)
  {
    analogWrite(MotorA1, 0);
    analogWrite(MotorA2, 0);

    analogWrite(MotorB1, 0);
    analogWrite(MotorB2, low_s);

    analogWrite(MotorC1, 0);
    analogWrite(MotorC2, low_s);

    analogWrite(MotorD1, 0);
    analogWrite(MotorD2, 0);
  }

  else if (a >= 300 && a <= 330 && b > 3 && b <= 5)
  {
    analogWrite(MotorA1, 0);
    analogWrite(MotorA2, 0);

    analogWrite(MotorB1, 0);
    analogWrite(MotorB2, mid_s);

    analogWrite(MotorC1, 0);
    analogWrite(MotorC2, mid_s);

    analogWrite(MotorD1, 0);
    analogWrite(MotorD2, 0);
  }

  else if (a >= 300 && a <= 330 && b > 5 && b <= 7)
  {
    analogWrite(MotorA1, 0);
    analogWrite(MotorA2, 0);

    analogWrite(MotorB1, 0);
    analogWrite(MotorB2, high_s);

    analogWrite(MotorC1, 0);
    analogWrite(MotorC2, high_s);

    analogWrite(MotorD1, 0);
    analogWrite(MotorD2, 0);
  }
  /////////////////////////////DUR////////////////////////////////////
  else
  {
    analogWrite(MotorA1, LOW);
    analogWrite(MotorA2, LOW);

    analogWrite(MotorB1, LOW);
    analogWrite(MotorB2, LOW);

    analogWrite(MotorC1, LOW);
    analogWrite(MotorC2, LOW);

    analogWrite(MotorD1, LOW);
    analogWrite(MotorD2, LOW);
  }
}

//"""REX 8in1 Tracker Bot"""
//Check the web site for Robots https://rex-rdt.readthedocs.io/en/latest/
#define left_sensor 34   // IR pins
#define right_sensor 35  // IR pins

//define motor pins and speeds
#define MotorA1 23
#define MotorA2 15

#define MotorB1 33
#define MotorB2 32

#define MotorC1 4
#define MotorC2 5

#define MotorD1 14
#define MotorD2 27

#define mid 160
#define slow 150
#define reverse 120

#define STOP 0
#define FWD 1
#define BWD 2
#define RIGHT 3
#define LEFT 4
#define THRESHOLD 3600


uint8_t directionStt = STOP;
uint8_t oldDirection = STOP;

unsigned long reverseTime = 0;

void setup() {
  Serial.begin(115200);

  pinMode(left_sensor, INPUT);
  pinMode(right_sensor, INPUT);

  pinMode(MotorA1, OUTPUT);
  pinMode(MotorA2, OUTPUT);

  pinMode(MotorB1, OUTPUT);
  pinMode(MotorB2, OUTPUT);

  pinMode(MotorC1, OUTPUT);
  pinMode(MotorC2, OUTPUT);

  pinMode(MotorD1, OUTPUT);
  pinMode(MotorD2, OUTPUT);
}


void loop() {

  //convert analog values to integer values.
  int leftSensor = analogRead(left_sensor);
  int rightSensor = analogRead(right_sensor);
  
  Serial.print("left:");
  Serial.print(leftSensor);
  Serial.print("  right:");
  Serial.println(rightSensor);
  Serial.println("");


  if (leftSensor >= THRESHOLD && rightSensor >= THRESHOLD) {
    directionStt = FWD;
  } else if (leftSensor < THRESHOLD && rightSensor > THRESHOLD) {
    directionStt = RIGHT;
  } else if (leftSensor > THRESHOLD && rightSensor < THRESHOLD) {
    directionStt = LEFT;
  } else if (leftSensor < THRESHOLD && rightSensor < THRESHOLD && directionStt != STOP) {
    directionStt = BWD;
  }

  if (directionStt != oldDirection) {
    oldDirection = directionStt;
    if (directionStt == FWD)
      forward();
    else if (directionStt == RIGHT)
      right();
    else if (directionStt == LEFT)
      left();
    else if (directionStt == BWD) {
      backward();
      reverseTime = millis();
    } else if (directionStt == STOP)
      stop();
  }

  if (directionStt == BWD && millis() - reverseTime > 300)
    directionStt = STOP;
}

void forward() {

  analogWrite(MotorA1, mid);
  analogWrite(MotorA2, LOW);

  analogWrite(MotorB1, mid);
  analogWrite(MotorB2, LOW);

  analogWrite(MotorC1, mid);
  analogWrite(MotorC2, LOW);

  analogWrite(MotorD1, mid);
  analogWrite(MotorD2, LOW);
}

void right() {
  analogWrite(MotorA1, mid);
  analogWrite(MotorA2, LOW);

  analogWrite(MotorB1, mid);
  analogWrite(MotorB2, LOW);
  //delay(300);
  analogWrite(MotorC1, LOW);
  analogWrite(MotorC2, mid);

  analogWrite(MotorD1, LOW);
  analogWrite(MotorD2, mid);
}

void left() {

  analogWrite(MotorA1, LOW);
  analogWrite(MotorA2, mid);

  analogWrite(MotorB1, LOW);
  analogWrite(MotorB2, mid);
  analogWrite(MotorC1, mid);
  analogWrite(MotorC2, LOW);

  analogWrite(MotorD1, mid);
  analogWrite(MotorD2, LOW);
}

void stop() {

  analogWrite(MotorA1, LOW);
  analogWrite(MotorA2, LOW);

  analogWrite(MotorB1, LOW);
  analogWrite(MotorB2, LOW);

  analogWrite(MotorC1, LOW);
  analogWrite(MotorC2, LOW);

  analogWrite(MotorD1, LOW);
  analogWrite(MotorD2, LOW);
}

void backward() {
  analogWrite(MotorA1, LOW);
  analogWrite(MotorA2, mid);

  analogWrite(MotorB1, LOW);
  analogWrite(MotorB2, mid);
  //delay(300);
  analogWrite(MotorC1, LOW);
  analogWrite(MotorC2, mid);

  analogWrite(MotorD1, LOW);
  analogWrite(MotorD2, mid);
}

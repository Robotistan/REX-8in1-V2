#define SensorLEFT 34   // IR pin
#define SensorRIGHT 35  // IR pin
int trigPin = 17;       // Trigger
int echoPin = 16;       // Echo
long duration, cm;

#define MotorA1 15
#define MotorA2 23

#define MotorB1 32
#define MotorB2 33

#define MotorC1 5
#define MotorC2 4

#define MotorD1 27
#define MotorD2 14


#define fast 255
#define mid 150
#define slow 100
#define THRESHOLD 3600

void forward() {
  analogWrite(MotorA1, mid);
  analogWrite(MotorA2, 0);

  analogWrite(MotorB1, mid);
  analogWrite(MotorB2, 0);

  analogWrite(MotorC1, mid);
  analogWrite(MotorC2, 0);

  analogWrite(MotorD1, mid);
  analogWrite(MotorD2, 0);
}
void slowforward() {
  analogWrite(MotorA1, slow);
  analogWrite(MotorA2, 0);

  analogWrite(MotorB1, slow);
  analogWrite(MotorB2, 0);

  analogWrite(MotorC1, slow);
  analogWrite(MotorC2, 0);

  analogWrite(MotorD1, slow);
  analogWrite(MotorD2, 0);
}
void right() {
  analogWrite(MotorA1, mid);
  analogWrite(MotorA2, 0);

  analogWrite(MotorB1, mid);
  analogWrite(MotorB2, 0);

  analogWrite(MotorC1, 0);
  analogWrite(MotorC2, mid);

  analogWrite(MotorD1, 0);
  analogWrite(MotorD2, mid);
}

void left() {
  analogWrite(MotorA1, 0);
  analogWrite(MotorA2, mid);

  analogWrite(MotorB1, 0);
  analogWrite(MotorB2, mid);

  analogWrite(MotorC1, mid);
  analogWrite(MotorC2, 0);

  analogWrite(MotorD1, mid);
  analogWrite(MotorD2, 0);
}

void stop() {
  analogWrite(MotorA1, 0);
  analogWrite(MotorA2, 0);

  analogWrite(MotorB1, 0);
  analogWrite(MotorB2, 0);

  analogWrite(MotorC1, 0);
  analogWrite(MotorC2, 0);

  analogWrite(MotorD1, 0);
  analogWrite(MotorD2, 0);
}

void backward() {
  analogWrite(MotorA1, LOW);
  analogWrite(MotorA2, mid);

  analogWrite(MotorB1, LOW);
  analogWrite(MotorB2, mid);

  analogWrite(MotorC1, LOW);
  analogWrite(MotorC2, mid);

  analogWrite(MotorD1, LOW);
  analogWrite(MotorD2, mid);
}

void setup() {
  Serial.begin(115200);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(SensorLEFT, INPUT);
  pinMode(SensorRIGHT, INPUT);

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
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  cm = (duration / 2) / 29.1;
  /* Serial.print(cm);
  Serial.print("cm");
  Serial.print("  ");*/
  delay(100);


  int leftSensor = analogRead(SensorLEFT);
  int rightSensor = analogRead(SensorRIGHT);

  /*
  Serial.print("leftSensor: ");
  Serial.print(leftSensor);
  Serial.print("  rightSensor: ");
  Serial.println(rightSensor);
  */

  if ((leftSensor < THRESHOLD && rightSensor < THRESHOLD)) {
    stop();
    delay(500);
    backward();
    delay(800);
    left();
    delay(400);

  } else if ((cm < 15) && (leftSensor >= THRESHOLD && rightSensor >= THRESHOLD)) {
    forward();
  } else {
    slowforward();
  }
}

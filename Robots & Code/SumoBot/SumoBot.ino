#define SensorSol 34 // IR pin
#define SensorSag 35 // IR pin
int trigPin = 17;    // Trigger
int echoPin = 16;    // Echo
long duration, cm;

#define MotorA1 15
#define MotorA2 23

#define MotorB1 32
#define MotorB2 33

#define MotorC1 5
#define MotorC2 4

#define MotorD1 27
#define MotorD2 14

#define mid 115
#define slow 0
#define THRESHOLD   3600

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

  analogWrite(MotorC1, LOW);
  analogWrite(MotorC2, mid);

  analogWrite(MotorD1, LOW);
  analogWrite(MotorD2, mid);
}

void setup() {
  Serial.begin(115200);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(SensorSol, INPUT);
  pinMode(SensorSag, INPUT);

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
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(100);
  if  (cm < 15) {
    forward();
  }

  int leftSensor = analogRead(SensorSol);
  int rightSensor = analogRead(SensorSag);
  /*
  Serial.print("leftSensor ");
  Serial.print(leftSensor);
  Serial.print("rightSensor ");
  Serial.println(rightSensor);
 */ 

  if ((leftSensor >= THRESHOLD && rightSensor >= THRESHOLD))  {
    backward();
    delay(1000);
    left();
    delay(400);
  }
  else if((cm < 15) && (leftSensor <= THRESHOLD && rightSensor <= THRESHOLD)){
    forward();
  }
  else {  
    forward();
  }
}

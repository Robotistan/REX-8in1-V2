#define SensorSol 34 // IR pinleri
#define SensorSag 35 // IR pinleri
int trigPin = 4;    // Trigger
int echoPin = 5;    // Echo
long duration, cm;

// Motor pinlerini tanımlıyoruz.

#define MotorA1 15
#define MotorA2 23

#define MotorB1 33
#define MotorB2 32

#define MotorC1 17
#define MotorC2 16

#define MotorD1 27
#define MotorD2 14

#define mid 115
#define slow 0
#define THRESHOLD   600

void setup() {

  Serial.begin(115200);
  // Giriş ve çıkışları tanımladığımız pinlerde belirtiyoruz.
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
    ileri();
  }

  int leftSensor = analogRead(SensorSol);
  int rightSensor = analogRead(SensorSag);

  if (leftSensor >= THRESHOLD && rightSensor >= THRESHOLD) {
    ileri();
  }
  else {
    geri();
    delay(1000);
    sol();
    delay(400);
  }

void ileri() {

  analogWrite(MotorA1, mid);
  analogWrite(MotorA2, LOW);

  analogWrite(MotorB1, mid);
  analogWrite(MotorB2, LOW);

  analogWrite(MotorC1, mid);
  analogWrite(MotorC2, LOW);

  analogWrite(MotorD1, mid);
  analogWrite(MotorD2, LOW);
}

void sag() {
  analogWrite(MotorA1, mid);
  analogWrite(MotorA2, LOW);

  analogWrite(MotorB1, mid);
  analogWrite(MotorB2, LOW);

  analogWrite(MotorC1, LOW);
  analogWrite(MotorC2, mid);

  analogWrite(MotorD1, LOW);
  analogWrite(MotorD2, mid);
}

void sol() {

  analogWrite(MotorA1, LOW);
  analogWrite(MotorA2, mid);

  analogWrite(MotorB1, LOW);
  analogWrite(MotorB2, mid);

  analogWrite(MotorC1, mid);
  analogWrite(MotorC2, LOW);

  analogWrite(MotorD1, mid);
  analogWrite(MotorD2, LOW);
}

void dur() {

  analogWrite(MotorA1, LOW);
  analogWrite(MotorA2, LOW);

  analogWrite(MotorB1, LOW);
  analogWrite(MotorB2, LOW);

  analogWrite(MotorC1, LOW);
  analogWrite(MotorC2, LOW);

  analogWrite(MotorD1, LOW);
  analogWrite(MotorD2, LOW);
}

void geri() {
  analogWrite(MotorA1, LOW);
  analogWrite(MotorA2, mid);

  analogWrite(MotorB1, LOW);
  analogWrite(MotorB2, mid);

  analogWrite(MotorC1, LOW);
  analogWrite(MotorC2, mid);

  analogWrite(MotorD1, LOW);
  analogWrite(MotorD2, mid);
}

void HC_ileri() {
  
  }

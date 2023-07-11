int trigPin = 4;    // Trigger
int echoPin = 5;    // Echo
long duration, cm;

#define slow 120
#define MID 140
#define FAST 110

#define MotorA1 15
#define MotorA2 23

#define MotorB1 32
#define MotorB2 33

#define MotorC1 5
#define MotorC2 4

#define MotorD1 14
#define MotorD2 27

#define horn 2

int turns = 0 ;
void setup() {
  //Serial Port begin
  Serial.begin (9600);

  //Define inputs and outputs

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(horn, OUTPUT);

  pinMode(MotorA1, OUTPUT);
  pinMode(MotorA2, OUTPUT);

  pinMode(MotorB1, OUTPUT);
  pinMode(MotorB2, OUTPUT);

  pinMode(MotorC1, OUTPUT);
  pinMode(MotorC2, OUTPUT);

  pinMode(MotorD1, OUTPUT);
  pinMode(MotorD2, OUTPUT);
  delay(1500);
}


void loop() {
  Serial.println(turns);
  distance();
  if (cm < 8) {
    geri();
    horn2();
    yerindesol();
    dur();
    delay(100);
    turns++ ;
  }
  else
  {
    ileri();
  }
  if ( turns > 2)
  {
    dur();
  }
}

void ileri() { // ileri yönde hareketi için fonksiyon tanımlıyoruz.

  analogWrite(MotorA1, MID);
  analogWrite(MotorA2, LOW);

  analogWrite(MotorB1, MID);
  analogWrite(MotorB2, LOW);

  analogWrite(MotorC1, MID);
  analogWrite(MotorC2, LOW);

  analogWrite(MotorD1, MID);
  analogWrite(MotorD2, LOW);
}

void yerindesag() { // sağa dönme hareketi için fonksiyon tanımlıyoruz.
  analogWrite(MotorA1, LOW);
  analogWrite(MotorA2, FAST);

  analogWrite(MotorB1, FAST);
  analogWrite(MotorB2, LOW);

  analogWrite(MotorC1, LOW);
  analogWrite(MotorC2, FAST);

  analogWrite(MotorD1, LOW);
  analogWrite(MotorD2, FAST);
  delay(1000);
}

void yerindesol() { // sola dönme hareketi için fonksiyon tanımlıyoruz.
  analogWrite(MotorA1, LOW);
  analogWrite(MotorA2, MID);

  analogWrite(MotorB1, LOW);
  analogWrite(MotorB2, MID);

  analogWrite(MotorC1, MID);
  analogWrite(MotorC2, LOW);

  analogWrite(MotorD1, MID);
  analogWrite(MotorD2, LOW);
  delay(850);
}

void dur() { // durma hareketi için fonksiyon tanımlıyoruz.

  analogWrite(MotorA1, LOW);
  analogWrite(MotorA2, LOW);

  analogWrite(MotorB1, LOW);
  analogWrite(MotorB2, LOW);

  analogWrite(MotorC1, LOW);
  analogWrite(MotorC2, LOW);

  analogWrite(MotorD1, LOW);
  analogWrite(MotorD2, LOW);

}

void geri() { // geri hareketi için fonksiyon tanımlıyoruz.

  analogWrite(MotorA1, LOW);
  analogWrite(MotorA2, slow);

  analogWrite(MotorB1, LOW);
  analogWrite(MotorB2, slow);

  analogWrite(MotorC1, LOW);
  analogWrite(MotorC2, slow);

  analogWrite(MotorD1, LOW);
  analogWrite(MotorD2, slow);
  delay(200);
}

void horn2() {
  tone(horn, 330);
  delay(50);
  noTone(2);
}

void distance() {
  delay(40);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  cm = (duration / 2) / 29.1;
  /* Serial.print(cm);
    Serial.print("cm");
    Serial.println();*/
}

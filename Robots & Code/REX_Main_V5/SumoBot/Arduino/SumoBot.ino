//"""REX 8in1 Sumo Bot"""
//Check the web site for Robots https://rex-rdt.readthedocs.io/en/latest/

#define SensorLEFT 34   // IR pin
#define SensorRIGHT 35  // IR pin

//define pins of motors
#define MotorPWM 13	//Pwm

#define MotorA1 15
#define MotorA2 23

#define MotorB1 32
#define MotorB2 33

#define MotorC1 5
#define MotorC2 4

#define MotorD1 27
#define MotorD2 14

//define speed of motors
#define FAST 255
#define MID 130
#define SLOW 100

#define THRESHOLD 3600

int trigPin = 17;   // Trigger
int echoPin = 16;   // Echo
long duration, cm;

//setting PWM properties
const int freq = 50;
const int PWMchannel_1 = 4;
const int PWMchannel_2 = 5;
const int PWMchannel_3 = 6;
const int PWMchannel_4 = 7;
const int PWMchannel_5 = 8;
const int PWMchannel_6 = 9;
const int PWMchannel_7 = 10;
const int PWMchannel_8 = 11;

const int resolution = 8;

void setup() {
  Serial.begin(115200);   //make sure your Serial Monitor is also set at this baud rate.

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(SensorLEFT, INPUT);
  pinMode(SensorRIGHT, INPUT);

  pinMode(MotorPWM, OUTPUT);

  pinMode(MotorA1, OUTPUT);
  pinMode(MotorA2, OUTPUT);

  pinMode(MotorB1, OUTPUT);
  pinMode(MotorB2, OUTPUT);

  pinMode(MotorC1, OUTPUT);
  pinMode(MotorC2, OUTPUT);

  pinMode(MotorD1, OUTPUT);
  pinMode(MotorD2, OUTPUT);

  ledcSetup(PWMchannel_1, freq, resolution);
  ledcAttachPin(MotorA1, PWMchannel_1);

  ledcSetup(PWMchannel_2, freq, resolution);
  ledcAttachPin(MotorA2, PWMchannel_2);

  ledcSetup(PWMchannel_3, freq, resolution);
  ledcAttachPin(MotorB1, PWMchannel_3);

  ledcSetup(PWMchannel_4, freq, resolution);
  ledcAttachPin(MotorB2, PWMchannel_4);

  ledcSetup(PWMchannel_5, freq, resolution);
  ledcAttachPin(MotorC1, PWMchannel_5);

  ledcSetup(PWMchannel_6, freq, resolution);
  ledcAttachPin(MotorC2, PWMchannel_6);

  ledcSetup(PWMchannel_7, freq, resolution);
  ledcAttachPin(MotorD1, PWMchannel_7);

  ledcSetup(PWMchannel_8, freq, resolution);
  ledcAttachPin(MotorD2, PWMchannel_8);
}

void forward() {
  digitalWrite(MotorPWM, HIGH);

  ledcWrite(PWMchannel_1, MID); //MotorA1
  ledcWrite(PWMchannel_2, LOW); //MotorA2

  ledcWrite(PWMchannel_3, MID); //MotorB1
  ledcWrite(PWMchannel_4, LOW); //MotorB2

  ledcWrite(PWMchannel_5, MID); //MotorC1
  ledcWrite(PWMchannel_6, LOW); //MotorC2

  ledcWrite(PWMchannel_7, MID); //MotorD1
  ledcWrite(PWMchannel_8, LOW); //MotorD2
}

void right() {
  digitalWrite(MotorPWM, HIGH);

  ledcWrite(PWMchannel_1, MID);  //MotorA1
  ledcWrite(PWMchannel_2, LOW);  //MotorA2

  ledcWrite(PWMchannel_3, MID);  //MotorB1
  ledcWrite(PWMchannel_4, LOW);  //MotorB2

  ledcWrite(PWMchannel_5, LOW);  //MotorC1
  ledcWrite(PWMchannel_6, MID);  //MotorC2

  ledcWrite(PWMchannel_7, LOW);  //MotorD1
  ledcWrite(PWMchannel_8, MID);  //MotorD2
}

void left() {
  digitalWrite(MotorPWM, HIGH);

  ledcWrite(PWMchannel_1, LOW);  //MotorA1
  ledcWrite(PWMchannel_2, MID);  //MotorA2

  ledcWrite(PWMchannel_3, LOW);  //MotorB1
  ledcWrite(PWMchannel_4, MID);  //MotorB2

  ledcWrite(PWMchannel_5, MID);  //MotorC1
  ledcWrite(PWMchannel_6, LOW);  //MotorC2

  ledcWrite(PWMchannel_7, MID);  //MotorD1
  ledcWrite(PWMchannel_8, LOW);  //MotorD2
}

void stop() {
  digitalWrite(MotorPWM, LOW);

  ledcWrite(PWMchannel_1, LOW); //MotorA1
  ledcWrite(PWMchannel_2, LOW); //MotorA2

  ledcWrite(PWMchannel_3, LOW); //MotorB1
  ledcWrite(PWMchannel_4, LOW); //MotorB2

  ledcWrite(PWMchannel_5, LOW); //MotorC1
  ledcWrite(PWMchannel_6, LOW); //MotorC2

  ledcWrite(PWMchannel_7, LOW); //MotorD1
  ledcWrite(PWMchannel_8, LOW); //MotorD2
}

void backward() {
  digitalWrite(MotorPWM, HIGH);
  
  ledcWrite(PWMchannel_1, LOW); //MotorA1
  ledcWrite(PWMchannel_2, MID); //MotorA2

  ledcWrite(PWMchannel_3, LOW); //MotorB1
  ledcWrite(PWMchannel_4, MID); //MotorB2

  ledcWrite(PWMchannel_5, LOW); //MotorC1
  ledcWrite(PWMchannel_6, MID); //MotorC2

  ledcWrite(PWMchannel_7, LOW); //MotorD1
  ledcWrite(PWMchannel_8, MID); //MotorD2
}

void loop() {
  delay(40);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  cm = (duration / 2) / 29.1;
  /*
  Serial.print(cm);
  Serial.print("cm");
  Serial.println("  ");
  */
  if(cm <= 15){
    int leftSensor = analogRead(SensorLEFT);
    int rightSensor = analogRead(SensorRIGHT);
    /*
    Serial.print("leftSensor: ");
    Serial.print(leftSensor);
    Serial.print("  rightSensor: ");
    Serial.println(rightSensor);
    */
    delay(2);
    if ((leftSensor >= THRESHOLD) || (rightSensor >= THRESHOLD)) {
      backward();
      delay(150);
    }
    else if ((leftSensor < THRESHOLD) && (rightSensor < THRESHOLD)) {
      forward();
    }
    else{
      stop();
    }
  }
  else{
    int leftSensor = analogRead(SensorLEFT);
    int rightSensor = analogRead(SensorRIGHT);
    /*
    Serial.print("leftSensor: ");
    Serial.print(leftSensor);
    Serial.print("  rightSensor: ");
    Serial.println(rightSensor);
    */
    delay(2);
    if ((leftSensor >= THRESHOLD) || (rightSensor >= THRESHOLD)) {
      backward();
      delay(150);
    }
    else if ((leftSensor < THRESHOLD) && (rightSensor < THRESHOLD)) {
      left();
      delay(50);
      stop();
    }
    else{
      stop();
    }
  }
}

//"""REX 8in1 Tracker Bot Example Code"""
//Check the web site for Robots https://rex-rdt.readthedocs.io/en/latest/
#define left_sensor 34 // IR pins
#define right_sensor 35 // IR pins

//define motor pins and speeds
#define MotorA1 15
#define MotorA2 23

#define MotorB1 32
#define MotorB2 33

#define MotorC1 17
#define MotorC2 16

#define MotorD1 27
#define MotorD2 14


void setup() {
  Serial.begin(115200);
  //active pins which is defined

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
  Serial.println(leftSensor);
  Serial.print("right:");
  Serial.println(rightSensor);
  Serial.println("");
  delay(1000);
}


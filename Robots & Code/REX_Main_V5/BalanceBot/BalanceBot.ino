#include "I2Cdev.h"
#include "PID_v1.h" 
#include "MPU6050_6Axis_MotionApps20.h"
#include <Wire.h>

#define INTERRUPT_PIN 13

#define MotorPWM 13	//Pwm

#define Motor_A1 15
#define Motor_A2 23
#define Motor_C1 5
#define Motor_C2 4

MPU6050 mpu;

bool dmpReady = false;  // set true if DMP init was successful

uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer

// orientation/motion vars
Quaternion q;           // [w, x, y, z]         quaternion container
VectorFloat gravity;    // [x, y, z]            gravity vector
float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector

//............set following 4 values for your robot....
double setpoint = 189.7;  //set the value when the bot is perpendicular to ground using serial monitor.(input value)
double Kp = 4; //Set this value first
double Kd = 0.2; //Set this value secound
double Ki = 40; //Finally set this value

double input, output;
PID pid(&input, &output, &setpoint, Kp, Ki, Kd, DIRECT);

bool interrupteddd = false;

volatile bool mpuInterrupt = false;     // indicates whether MPU interrupt pin has gone high
void dmpDataReady()
{
  mpuInterrupt = true;
  interrupteddd = true;
}

void setup() {
  Serial.begin(115200);
  Wire.begin();

  Serial.println(F("Initializing I2C devices..."));
  mpu.initialize();

  // verify connection
  Serial.println(F("Testing device connections..."));
  Serial.println(mpu.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));

  // load and configure the DMP
  devStatus = mpu.dmpInitialize();

  // supply your own gyro offsets here, scaled for min sensitivity (calibration)
  mpu.setXGyroOffset(74);
  mpu.setYGyroOffset(12);
  mpu.setZGyroOffset(5);
  mpu.setZAccelOffset(1094);

  // make sure it worked (returns 0 if so)
  if (devStatus == 0){
    // turn on the DMP, now that it's ready
    Serial.println(F("Enabling DMP..."));
    mpu.setDMPEnabled(true);

    // enable Arduino interrupt detection
    pinMode(INTERRUPT_PIN, INPUT);
    Serial.println(F("Enabling interrupt detection (Arduino external interrupt 0)..."));
    attachInterrupt(INTERRUPT_PIN, dmpDataReady, RISING);
    mpuIntStatus = mpu.getIntStatus();

    // set our DMP Ready flag so the main loop() function knows it's okay to use it
    Serial.println(F("DMP ready! Waiting for first interrupt..."));
    dmpReady = true;

    // get expected DMP packet size for later comparison
    packetSize = mpu.dmpGetFIFOPacketSize();
    
    //setup PID
    pid.SetMode(AUTOMATIC);
    pid.SetSampleTime(10);
    pid.SetOutputLimits(-200, 200);
  }
  else{
    // ERROR!
    // 1 = initial memory load failed
    // 2 = DMP configuration updates failed
    // (if it's going to break, usually the code will be 1)
    Serial.print(F("DMP Initialization failed (code "));
    Serial.print(devStatus);
    Serial.println(F(")"));
  }

  //Initialise the Motor outpu pins
  pinMode(MotorPWM, OUTPUT);
  pinMode (Motor_A1, OUTPUT);
  pinMode (Motor_A2, OUTPUT);
  pinMode (Motor_C1, OUTPUT);
  pinMode (Motor_C2, OUTPUT);

  //By default turn off both the motors
  digitalWrite(MotorPWM, LOW);
  analogWrite(Motor_A1, LOW);
  analogWrite(Motor_A2, LOW);
  analogWrite(Motor_C1, LOW);
  analogWrite(Motor_C2, LOW);
}

void loop() {
  // if programming failed, don't try to do anything
  if (!dmpReady) return;
  
  // wait for MPU interrupt or extra packet(s) available
  while (!mpuInterrupt && fifoCount < packetSize)
  {
    //no mpu data - performing PID calculations and output to motors
    pid.Compute();

    //Print the value of Input and Output on serial monitor to check how it is working.
    //Serial.print(input); Serial.print(" =>"); Serial.println(output);
    if (input > 120 && input < 230) { //If the Bot is falling
      if (output > 0) //Falling towards front
        Forward(); //Rotate the wheels forward
      else if (output < 0) //Falling towards back
        Reverse(); //Rotate the wheels backward
    }
    else
      Stop(); //Hold the wheels still
  }

  // reset interrupt flag and get INT_STATUS byte
  mpuInterrupt = false;
  mpuIntStatus = mpu.getIntStatus();
  // get current FIFO count
  fifoCount = mpu.getFIFOCount();

  // check for overflow (this should never happen unless our code is too inefficient)
  if ((mpuIntStatus & 0x10) || fifoCount == 1024)
  {
    // reset so we can continue cleanly
    mpu.resetFIFO();
    Serial.println(F("FIFO overflow!"));
    // otherwise, check for DMP data ready interrupt (this should happen frequently)
  }
  else if (mpuIntStatus & 0x02)
  {
    // wait for correct available data length, should be a VERY short wait
    while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();

    // read a packet from FIFO
    mpu.getFIFOBytes(fifoBuffer, packetSize);

    // track FIFO count here in case there is > 1 packet available
    // (this lets us immediately read more without waiting for an interrupt)
    fifoCount -= packetSize;

    mpu.dmpGetQuaternion(&q, fifoBuffer); //get value for q
    mpu.dmpGetGravity(&gravity, &q); //get value for gravity
    mpu.dmpGetYawPitchRoll(ypr, &q, &gravity); //get value for ypr
    //Serial.println(ypr[1]);
    input = ypr[1] * 180 / M_PI + 180;    
    //Serial.println("ypr[1]=");
    //Serial.println(ypr[1]);
  }
}

void Forward() //Rotate the wheel forward
{
  digitalWrite(MotorPWM, HIGH);
  analogWrite(Motor_A1, output + 55);
  analogWrite(Motor_A2, 0);
  analogWrite(Motor_C1, output + 55);
  analogWrite(Motor_C2, 0);
  //Serial.print("F"); //Debugging information
}

void Reverse() //Rotate the wheel reverse
{
  digitalWrite(MotorPWM, HIGH);
  analogWrite(Motor_A1, 0);
  analogWrite(Motor_A2, (output * -1) + 55);
  analogWrite(Motor_C1, 0);
  analogWrite(Motor_C2, (output * -1) + 55);
  //Serial.print("R"); //Debugging information
}

void Stop() //Stop both the wheels
{
  digitalWrite(MotorPWM, LOW);
  analogWrite(Motor_A1, 0);
  analogWrite(Motor_A2, 0);
  analogWrite(Motor_C1, 0);
  analogWrite(Motor_C2, 0);
  //Serial.print("S"); //Debugging information
}

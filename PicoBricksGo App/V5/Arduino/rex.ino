// Libraries
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <ESP32Servo.h>

// Define BLE UUIDs (Universally Unique Identifiers)
#define SERVICE_UUID        "6E400001-B5A3-F393-E0A9-E50E24DCCA9E" // Custom Service UUID
#define CHARACTERISTIC_UUID "6E400002-B5A3-F393-E0A9-E50E24DCCA9E" // Custom Characteristic UUID

BLECharacteristic *pCharacteristic;
String characteristicValue = "";

//Motor Pins Definations
#define MotorPWM 13	// PWM

#define MotorA1 15  // Forward
#define MotorA2 23  // Backward

#define MotorB1 32  // Forward
#define MotorB2 33  // Backward

#define MotorC1 27  // Forward
#define MotorC2 14  // Backward

#define MotorD1 5  // Forward
#define MotorD2 4  // Backward

#define STOP 0
#define FWD 1
#define BWD 2
#define RIGHT 3
#define LEFT 4
#define FWD_RIGHT 5
#define FWD_LEFT  6
#define BWD_RIGHT 7
#define BWD_LEFT  8

#define joystick 1
#define buttons 2

// Default Servo Positions
int position1 = 90;
int position2 = 90;
int position3 = 90;
int position4 = 90;

//Define pins of servo motors
Servo Servo1;  // Forward-Bakcward
Servo Servo2;  // Right-Left
Servo Servo3;  // Up-Down
Servo Servo4;  // Open-Close

//Define Buzzer Pin Named "horn"
int horn = 25;

// Variables
int buffer[5];
int control = 0;
int i = 0;
int ySpeed  = 0;
int xSpeed  = 0;
int deadZone = 20;      // Dead zone threshold around the center (adjust if needed)
int centerX = 127;      // Center value for X-axis
int centerY = 127;      // Center value for Y-axis
int xValue = 0;         // Joystick X-axis
int yValue = 0;         // Joystick Y-axis

void move(int direction, int speed){
    speed = constrain(speed, 150, 255);  // Ensure speed is within valid range
    analogWrite(MotorPWM, speed);

  if (direction == FWD){
    digitalWrite(MotorA1, HIGH); digitalWrite(MotorA2, LOW);
    digitalWrite(MotorB1, HIGH); digitalWrite(MotorB2, LOW);
    digitalWrite(MotorC1, HIGH); digitalWrite(MotorC2, LOW);
    digitalWrite(MotorD1, HIGH); digitalWrite(MotorD2, LOW);
  }
  else if (direction == BWD){
    digitalWrite(MotorA1, LOW); digitalWrite(MotorA2, HIGH);
    digitalWrite(MotorB1, LOW); digitalWrite(MotorB2, HIGH);
    digitalWrite(MotorC1, LOW); digitalWrite(MotorC2, HIGH);
    digitalWrite(MotorD1, LOW); digitalWrite(MotorD2, HIGH);
  }
  else if (direction == LEFT){
    digitalWrite(MotorA1, LOW);  digitalWrite(MotorA2, HIGH);
    digitalWrite(MotorB1, LOW);  digitalWrite(MotorB2, HIGH);
    digitalWrite(MotorC1, HIGH); digitalWrite(MotorC2, LOW);
    digitalWrite(MotorD1, HIGH); digitalWrite(MotorD2, LOW);
  }
  else if (direction == RIGHT){
    digitalWrite(MotorA1, HIGH); digitalWrite(MotorA2, LOW);
    digitalWrite(MotorB1, HIGH); digitalWrite(MotorB2, LOW);
    digitalWrite(MotorC1, LOW);  digitalWrite(MotorC2, HIGH);
    digitalWrite(MotorD1, LOW);  digitalWrite(MotorD2, HIGH);
  }
  else if (direction == FWD_RIGHT){
    digitalWrite(MotorA1, HIGH); digitalWrite(MotorA2, LOW);
    digitalWrite(MotorB1, HIGH); digitalWrite(MotorB2, LOW);
    digitalWrite(MotorC1, HIGH); digitalWrite(MotorC2, LOW);  
    digitalWrite(MotorD1, LOW);  digitalWrite(MotorD2, HIGH);
  }
  else if (direction == FWD_LEFT){
    digitalWrite(MotorA1, HIGH); digitalWrite(MotorA2, LOW);
    digitalWrite(MotorB1, LOW);  digitalWrite(MotorB2, HIGH);
    digitalWrite(MotorC1, HIGH); digitalWrite(MotorC2, LOW);
    digitalWrite(MotorD1, HIGH); digitalWrite(MotorD2, LOW);  
  }
  else if (direction == BWD_RIGHT){
    digitalWrite(MotorA1, LOW);  digitalWrite(MotorA2, HIGH);
    digitalWrite(MotorB1, LOW);  digitalWrite(MotorB2, HIGH);
    digitalWrite(MotorC1, LOW);  digitalWrite(MotorC2, HIGH);  
    digitalWrite(MotorD1, HIGH); digitalWrite(MotorD2, LOW);
  }
  else if (direction == BWD_LEFT){
    digitalWrite(MotorA1, LOW);  digitalWrite(MotorA2, HIGH);
    digitalWrite(MotorB1, HIGH); digitalWrite(MotorB2, LOW);
    digitalWrite(MotorC1, LOW);  digitalWrite(MotorC2, HIGH);
    digitalWrite(MotorD1, LOW);  digitalWrite(MotorD2, HIGH); 
  }
  else{ //STOP
    digitalWrite(MotorA1, LOW); digitalWrite(MotorA2, LOW);
    digitalWrite(MotorB1, LOW); digitalWrite(MotorB2, LOW);
    digitalWrite(MotorC1, LOW); digitalWrite(MotorC2, LOW);
    digitalWrite(MotorD1, LOW); digitalWrite(MotorD2, LOW);
  }
}

void omni_move(int direction, int speed){
    speed = constrain(speed, 150, 255);  // Ensure speed is within valid range
    analogWrite(MotorPWM, speed);

  if (direction == FWD){
    digitalWrite(MotorA1, LOW); digitalWrite(MotorA2, HIGH);
    digitalWrite(MotorB1, LOW); digitalWrite(MotorB2, HIGH);
    digitalWrite(MotorC1, LOW); digitalWrite(MotorC2, HIGH);
    digitalWrite(MotorD1, LOW); digitalWrite(MotorD2, HIGH);
  }
  else if (direction == BWD){
    digitalWrite(MotorA1, HIGH); digitalWrite(MotorA2, LOW);
    digitalWrite(MotorB1, HIGH); digitalWrite(MotorB2, LOW);
    digitalWrite(MotorC1, HIGH); digitalWrite(MotorC2, LOW);
    digitalWrite(MotorD1, HIGH); digitalWrite(MotorD2, LOW);
  }
  else if (direction == LEFT){
    digitalWrite(MotorA1, HIGH); digitalWrite(MotorA2, LOW);
    digitalWrite(MotorB1, LOW); digitalWrite(MotorB2, HIGH);
    digitalWrite(MotorC1, LOW); digitalWrite(MotorC2, HIGH);
    digitalWrite(MotorD1, HIGH); digitalWrite(MotorD2, LOW);
  }
  else if (direction == RIGHT){
    digitalWrite(MotorA1, LOW); digitalWrite(MotorA2, HIGH);
    digitalWrite(MotorB1, HIGH); digitalWrite(MotorB2, LOW);
    digitalWrite(MotorC1, HIGH); digitalWrite(MotorC2, LOW);
    digitalWrite(MotorD1, LOW); digitalWrite(MotorD2, HIGH);
  }
  else if (direction == FWD_RIGHT){
    digitalWrite(MotorA1, LOW); digitalWrite(MotorA2, HIGH);
    digitalWrite(MotorB1, LOW);  digitalWrite(MotorB2, LOW);
    digitalWrite(MotorC1, LOW);  digitalWrite(MotorC2, LOW);  
    digitalWrite(MotorD1, LOW); digitalWrite(MotorD2, HIGH);
  }
  else if (direction == FWD_LEFT){
    digitalWrite(MotorA1, LOW);  digitalWrite(MotorA2, LOW);
    digitalWrite(MotorB1, LOW); digitalWrite(MotorB2, HIGH);
    digitalWrite(MotorC1, LOW); digitalWrite(MotorC2, HIGH);
    digitalWrite(MotorD1, LOW);  digitalWrite(MotorD2, LOW);  
  }
  else if (direction == BWD_RIGHT){
    digitalWrite(MotorA1, LOW);  digitalWrite(MotorA2, LOW);
    digitalWrite(MotorB1, HIGH); digitalWrite(MotorB2, LOW);
    digitalWrite(MotorC1, HIGH); digitalWrite(MotorC2, LOW);  
    digitalWrite(MotorD1, LOW);  digitalWrite(MotorD2, LOW);
  }
  else if (direction == BWD_LEFT){
    digitalWrite(MotorA1, HIGH); digitalWrite(MotorA2, LOW);
    digitalWrite(MotorB1, LOW);  digitalWrite(MotorB2, LOW);
    digitalWrite(MotorC1, LOW);  digitalWrite(MotorC2, LOW);
    digitalWrite(MotorD1, HIGH); digitalWrite(MotorD2, LOW); 
  }
  else{ //STOP
    digitalWrite(MotorA1, LOW); digitalWrite(MotorA2, LOW);
    digitalWrite(MotorB1, LOW); digitalWrite(MotorB2, LOW);
    digitalWrite(MotorC1, LOW); digitalWrite(MotorC2, LOW);
    digitalWrite(MotorD1, LOW); digitalWrite(MotorD2, LOW);
  }
}

void rex_horn() {
  for(i=0; i<30; i++){
    digitalWrite(horn, HIGH);
    delay(1);
    digitalWrite(horn, LOW);
    delay(1);
  }
}

// Callbacks for when a client connects or disconnects
class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      Serial.println("Client connected");
    }

    void onDisconnect(BLEServer* pServer) {
      Serial.println("Client disconnected");
      // Restart advertising after client disconnects
      pServer->startAdvertising();
    }
};

// Callbacks for reading/writing the characteristic
class MyCallbacks: public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *pCharacteristic) {
      String value = pCharacteristic->getValue().c_str();

      if (value.length() > 0) {
        for (i = 0; i < value.length(); i++){
          buffer[i] = value[i];
          //Serial.println(buffer[i]);
          //delay(100);
        }

        if(buffer[0] == 75){  //Rex Header Byte
          if(buffer[1] == 1){ //Wibot & Roverbot
            if (buffer[2] == 1){
              control = joystick;
            }
            else{
              control = buttons;
            }

            if(buffer[2] == 2){  //Horn
              rex_horn();
            }

            if(control == buttons){ //Directional Buttons
              if(buffer[2] == 99) {  //Stop
                move(STOP, 0);
              }
              if(buffer[2] == 3) {  //Forward movement
                move(FWD, 255);
              }
              if(buffer[2] == 4) {  //Forward-right diagonal
                move(FWD_RIGHT, 150);
              }
              if(buffer[2] == 5) {  //Right turn
                move(RIGHT, 255);
              }
              if(buffer[2] == 6) {  //Backward-right diagonal
                move(BWD_RIGHT, 150);
              }
              if(buffer[2] == 7) {  //Backward movement
                move(BWD, 255);
              }
              if(buffer[2] == 8) {  //Backward-left diagonal
                move(BWD_LEFT, 150);
              }
              if(buffer[2] == 9) {  //Left turn
                move(LEFT, 255);
              }
              if(buffer[2] == 10) {  //Forward-left diagonal
                move(FWD_LEFT, 150);
              }
            }
            else{ //Joystick
              xValue = buffer[3]; //Joystick X-axis
              yValue = buffer[4]; //Joystick Y-axis

              ySpeed = map(abs(yValue - centerY), 0, 127, 0, 255);  //Map Y-axis for forward/backward speed
              xSpeed = map(abs(xValue - centerX), 0, 127, 0, 255);  //Map X-axis for turning speed

              if (xValue == 0 && yValue == 0) {   //Check if joystick is close to the center for stopping
                move(STOP,0);
              }
              else if (yValue < centerY - deadZone && abs(xValue - centerX) <= deadZone) {   //Forward movement
                move(FWD, ySpeed);
              }
              else if (yValue > centerY + deadZone && abs(xValue - centerX) <= deadZone) {   //Backward movement
                move(BWD, ySpeed);
              }
              else if (xValue < centerX - deadZone && abs(yValue - centerY) <= deadZone) {   //Left turn
                move(LEFT, xSpeed);
              }
              else if (xValue > centerX + deadZone && abs(yValue - centerY) <= deadZone) {   //Right turn
                move(RIGHT, xSpeed);
              }
              else if (yValue < centerY - deadZone && xValue > centerX + deadZone) {  //Forward-right diagonal
                move(FWD_RIGHT, ySpeed);
              }
              else if (yValue < centerY - deadZone && xValue < centerX - deadZone) {  //Forward-left diagonal
                move(FWD_LEFT, ySpeed);
              }
              else if (yValue > centerY + deadZone && xValue > centerX + deadZone) {  //Backward-right diagonal
                move(BWD_RIGHT, ySpeed);
              }
              else if (yValue > centerY + deadZone && xValue < centerX - deadZone) {  //Backward-left diagonal
                move(BWD_LEFT, ySpeed);
              }
              else{
                move(STOP,0);
              }
            }
          }
          else if(buffer[1] == 2){ //Omnibot
            if (buffer[2] == 1){
              control = joystick;
            }
            else{
              control = buttons;
            }

            if(buffer[2] == 2){  //Horn
              rex_horn();
            }

            if(control == buttons){ //Directional Buttons
              if(buffer[2] == 99) {  //Stop
                omni_move(STOP, 0);
              }
              if(buffer[2] == 3) {  //Forward movement
                omni_move(FWD, 255);
              }
              if(buffer[2] == 4) {  //Forward-right diagonal
                omni_move(FWD_RIGHT, 255);
              }
              if(buffer[2] == 5) {  //Right turn
                omni_move(RIGHT, 255);
              }
              if(buffer[2] == 6) {  //Backward-right diagonal
                omni_move(BWD_RIGHT, 255);
              }
              if(buffer[2] == 7) {  //Backward movement
                omni_move(BWD, 255);
              }
              if(buffer[2] == 8) {  //Backward-left diagonal
                omni_move(BWD_LEFT, 255);
              }
              if(buffer[2] == 9) {  //Left turn
                omni_move(LEFT, 255);
              }
              if(buffer[2] == 10) {  //Forward-left diagonal
                omni_move(FWD_LEFT, 255);
              }
            }
            else{ //Joystick
              xValue = buffer[3]; //Joystick X-axis
              yValue = buffer[4]; //Joystick Y-axis

              ySpeed = map(abs(yValue - centerY), 0, 127, 0, 255);  //Map Y-axis for forward/backward speed
              xSpeed = map(abs(xValue - centerX), 0, 127, 0, 255);  //Map X-axis for turning speed

              if (xValue == 0 && yValue == 0) {   //Check if joystick is close to the center for stopping
                omni_move(STOP,0);
              }
              else if (yValue < centerY - deadZone && abs(xValue - centerX) <= deadZone) {   //Forward movement
                omni_move(FWD, ySpeed);
              }
              else if (yValue > centerY + deadZone && abs(xValue - centerX) <= deadZone) {   //Backward movement
                omni_move(BWD, ySpeed);
              }
              else if (xValue < centerX - deadZone && abs(yValue - centerY) <= deadZone) {   //Left turn
                omni_move(LEFT, xSpeed);
              }
              else if (xValue > centerX + deadZone && abs(yValue - centerY) <= deadZone) {   //Right turn
                omni_move(RIGHT, xSpeed);
              }
              else if (yValue < centerY - deadZone && xValue > centerX + deadZone) {  //Forward-right diagonal
                omni_move(FWD_RIGHT, ySpeed);
              }
              else if (yValue < centerY - deadZone && xValue < centerX - deadZone) {  //Forward-left diagonal
                omni_move(FWD_LEFT, ySpeed);
              }
              else if (yValue > centerY + deadZone && xValue > centerX + deadZone) {  //Backward-right diagonal
                omni_move(BWD_RIGHT, ySpeed);
              }
              else if (yValue > centerY + deadZone && xValue < centerX - deadZone) {  //Backward-left diagonal
                omni_move(BWD_LEFT, ySpeed);
              }
              else{
                omni_move(STOP,0);
              }
            }
          }
          else if(buffer[1] == 3){ //Armbot
            if(buffer[2] == 1){  //Servo Motors Reset
              position1 = 90;
              position2 = 90;
              position3 = 90;
              position4 = 90;

              Servo1.write(position1);
              Servo2.write(position2);
              Servo3.write(position3);
              Servo4.write(position4);
            }
            else if(buffer[2] == 2){  //Horn
              rex_horn();
            }
            else if(buffer[2] == 3){ //DC Motors Control
              xValue = buffer[3]; // Joystick X-axis
              yValue = buffer[4]; // Joystick Y-axis

              ySpeed = map(abs(yValue - centerY), 0, 127, 0, 255);  // Map Y-axis for forward/backward speed
              xSpeed = map(abs(xValue - centerX), 0, 127, 0, 255);  // Map X-axis for turning speed

              if (xValue == 0 && yValue == 0) {   // Check if joystick is close to the center for stopping
                move(STOP,0);
              }
              else if (yValue < centerY - deadZone && abs(xValue - centerX) <= deadZone) {   // Forward movement
                move(FWD, ySpeed);
              }
              else if (yValue > centerY + deadZone && abs(xValue - centerX) <= deadZone) {   // Backward movement
                move(BWD, ySpeed);
              }
              else if (xValue < centerX - deadZone && abs(yValue - centerY) <= deadZone) {   // Left turn
                move(LEFT, xSpeed);
              }
              else if (xValue > centerX + deadZone && abs(yValue - centerY) <= deadZone) {   // Right turn
                move(RIGHT, xSpeed);
              }
              else if (yValue < centerY - deadZone && xValue > centerX + deadZone) {  // Forward-right diagonal
                move(FWD_RIGHT, ySpeed);
              }
              else if (yValue < centerY - deadZone && xValue < centerX - deadZone) {  // Forward-left diagonal
                move(FWD_LEFT, ySpeed);
              }
              else if (yValue > centerY + deadZone && xValue > centerX + deadZone) {  // Backward-right diagonal
                move(BWD_RIGHT, ySpeed);
              }
              else if (yValue > centerY + deadZone && xValue < centerX - deadZone) {  // Backward-left diagonal
                move(BWD_LEFT, ySpeed);
              }
              else{
                move(STOP,0);
              }
            }
            else if(buffer[2] == 4){  //Servo Motors Control
              if(buffer[3] == 1){ //Servo 1 Left
                if (position1 > 40) {
                  position1 = position1 - 5;
                  Servo1.write(position1);
                }
              }
              if(buffer[3] == 2){   //Servo 1 Right
                if (position1 < 140) {
                  position1 = position1 + 5;
                  Servo1.write(position1);
                }
              }
              if(buffer[3] == 3){   //Servo 2 Up
                if (position2 < 140) {
                  position2 = position2 + 5;
                  Servo2.write(position2);
                }
              }
              if(buffer[3] == 4){   //Servo 2 Down
                if (position2 > 0) {
                  position2 = position2 - 5;
                  Servo2.write(position2);
                }
              }
              if(buffer[3] == 5){   //Servo 3 Down
                if (position3 > 30) {
                  position3 = position3 - 5;
                  Servo3.write(position3);
                }
              }
              if(buffer[3] == 6){   //Servo 3 Up
                if (position3 < 150) {
                  position3 = position3 + 5;
                  Servo3.write(position3);
                }
              }
              if(buffer[3] == 7){   //Servo 4 Open
                if (position4 > 90) {
                  position4 = position4 - 5;
                  Servo4.write(position4);
                }
              }
              if(buffer[3] == 8){   //Servo 4 Close
                if (position4 < 160) {
                  position4 = position4 + 5;
                  Servo4.write(position4);
                }
              }
            }
          }
          else{
            Serial.println("Wrong data");
          }
      }
      //Clear Buffer
      for(i=0; i<5; i++)
        buffer[i] = 0;
      }
    }
};

void setup() {
  Serial.begin(115200);

  // Initialize BLE
  BLEDevice::init("REX 8in1"); //Set the name for the device
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  // Create a BLE Service
  BLEService *pService = pServer->createService(SERVICE_UUID);

  // Create a BLE Characteristic
  pCharacteristic = pService->createCharacteristic(
                      CHARACTERISTIC_UUID,
                      BLECharacteristic::PROPERTY_READ |
                      BLECharacteristic::PROPERTY_WRITE
                    );

  pCharacteristic->setCallbacks(new MyCallbacks());
  pCharacteristic->setValue(characteristicValue); //Initial value

  // Start the service
  pService->start();

  // Start advertising
  pServer->getAdvertising()->start();

  characteristicValue = "";
  pCharacteristic->setValue(characteristicValue);

  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);

  Servo1.setPeriodHertz(50);
  Servo2.setPeriodHertz(50);
  Servo3.setPeriodHertz(50);
  Servo4.setPeriodHertz(50);

  Servo1.attach(2, 600, 2500);
  Servo2.attach(26, 600, 2500);
  Servo3.attach(18, 600, 2500);
  Servo4.attach(19, 600, 2500);

  //First positions of servo motors
  Servo1.write(position1);
  Servo2.write(position2);
  Servo3.write(position3);
  Servo4.write(position4);

  //Defined active pins
  pinMode(MotorPWM, OUTPUT);

  pinMode(MotorA1, OUTPUT);
  pinMode(MotorA2, OUTPUT);

  pinMode(MotorB1, OUTPUT);
  pinMode(MotorB2, OUTPUT);

  pinMode(MotorC1, OUTPUT);
  pinMode(MotorC2, OUTPUT);

  pinMode(MotorD1, OUTPUT);
  pinMode(MotorD2, OUTPUT);

  pinMode(horn, OUTPUT);
}

void loop() {

}

from machine import Pin, PWM
import bluetooth
from rex import BLESimplePeripheral, Servo
import time

# Create a Bluetooth Low Energy (BLE) object
ble = bluetooth.BLE()

# Create an instance of the BLESimplePeripheral class with the BLE object
sp = BLESimplePeripheral(ble)

#motorA
motor_A1 = PWM(Pin(15))
motor_A1.duty_u16(0)
motor_A2 = PWM(Pin(23))
motor_A2.duty_u16(0)

#motorB
motor_B1 = PWM(Pin(32))
motor_B1.duty_u16(0)
motor_B2 = PWM(Pin(33))
motor_B2.duty_u16(0)

#motorC
motor_C1 = PWM(Pin(5))
motor_C1.duty_u16(0)
motor_C2 = PWM(Pin(4))
motor_C2.duty_u16(0)

#motorD
motor_D1 = PWM(Pin(27))
motor_D1.duty_u16(0)
motor_D2 = PWM(Pin(14))
motor_D2.duty_u16(0)

#servo
Servo1 = Servo(2)
Servo2 = Servo(26)
Servo3 = Servo(18)
Servo4 = Servo(19)

#buzzer
buzzer = Pin(25, Pin.OUT)

position1 = 90;
position2 = 90;
position3 = 90;
position4 = 90;

playBuzzer = 0
buzzerStartTime = 0
Motor_Type = 0

#motor types (default is 0)
DC_Motor = 0
Servo_Motor = 1

#default motor speed
MotorSpeed = 65535

def forward(speed):
   motor_A1.duty_u16(speed)
   motor_A2.duty_u16(0)

   motor_B1.duty_u16(speed)
   motor_B2.duty_u16(0)

   motor_C1.duty_u16(speed)
   motor_C2.duty_u16(0)

   motor_D1.duty_u16(speed)
   motor_D2.duty_u16(0)

def backward(speed):
   motor_A1.duty_u16(0)
   motor_A2.duty_u16(speed)

   motor_B1.duty_u16(0)
   motor_B2.duty_u16(speed)

   motor_C1.duty_u16(0)
   motor_C2.duty_u16(speed)

   motor_D1.duty_u16(0)
   motor_D2.duty_u16(speed)

def right(speed):
   motor_A1.duty_u16(speed)
   motor_A2.duty_u16(0)

   motor_B1.duty_u16(speed)
   motor_B2.duty_u16(0)

   motor_C1.duty_u16(0)
   motor_C2.duty_u16(speed)

   motor_D1.duty_u16(0)
   motor_D2.duty_u16(speed)

def left(speed):
   motor_A1.duty_u16(0)
   motor_A2.duty_u16(speed)

   motor_B1.duty_u16(0)
   motor_B2.duty_u16(speed)

   motor_C1.duty_u16(speed)
   motor_C2.duty_u16(0)

   motor_D1.duty_u16(speed)
   motor_D2.duty_u16(0)

def stop():
   motor_A1.duty_u16(0)
   motor_A2.duty_u16(0)

   motor_B1.duty_u16(0)
   motor_B2.duty_u16(0)

   motor_C1.duty_u16(0)
   motor_C2.duty_u16(0)

   motor_D1.duty_u16(0)
   motor_D2.duty_u16(0)

# Define a callback function to handle received data
def on_rx(data):
    global buzzerStartTime, playBuzzer, Motor_Type, Servo_Motor, DC_Motor, position1, position2, position3, position4
    print("Data received: ", data)  # Print the received data
    
    last_mode = Motor_Type
    if data == b'\xff\x01\x01\x01\x02\x02\x00\x00': #select
        Motor_Type = Servo_Motor
    elif data == b'\xff\x01\x01\x01\x02\x01\x00\x00': #start
        Motor_Type = DC_Motor
    else:
        Motor_Type = last_mode

    if Motor_Type == Servo_Motor:
        if data == b'\xff\x01\x01\x01\x02\x00\x01\x00': #up
            if position2 > 0:
                position2 -= 5
        if data == b'\xff\x01\x01\x01\x02\x00\x02\x00': #down
            if (position2 < 140):
                position2 += 5
        if data == b'\xff\x01\x01\x01\x02\x00\x04\x00': #left
            if (position1 > 40):
                position1 -= 5
        if data == b'\xff\x01\x01\x01\x02\x00\x08\x00': #right
            if (position1 < 140):
                position1 += 5
        if data == b'\xff\x01\x01\x01\x02\x04\x00\x00': #trigle
            if (position3 < 150):
                position3 += 5
        if data == b'\xff\x01\x01\x01\x02 \x00\x00': #square
            if (position4 < 160):
                position4 += 5
        if data == b'\xff\x01\x01\x01\x02\x08\x00\x00': #circle
            if (position4 > 90):
                position4 -= 5
        if data == b'\xff\x01\x01\x01\x02\x10\x00\x00': #cross
            if (position3 > 30):
                position3 -= 5

        Servo1.move(position1)
        Servo2.move(position2)
        Servo3.move(position3)
        Servo4.move(position4)
    else:
        if data == b'\xff\x01\x01\x01\x02\x00\x01\x00': #up
            forward(MotorSpeed)
        elif data == b'\xff\x01\x01\x01\x02\x00\x02\x00': #down
            backward(MotorSpeed)
        elif data == b'\xff\x01\x01\x01\x02\x00\x04\x00': #left
            left(MotorSpeed)
        elif data == b'\xff\x01\x01\x01\x02\x00\x08\x00': #right
            right(MotorSpeed)
        elif data == b'\xff\x01\x01\x01\x02\x04\x00\x00': #trigle
            print("trigle")
        elif data == b'\xff\x01\x01\x01\x02 \x00\x00': #square
            print("square")
        elif data == b'\xff\x01\x01\x01\x02\x08\x00\x00': #circle
            print("circle")
        elif data == b'\xff\x01\x01\x01\x02\x10\x00\x00': #cross
            buzzerStartTime = time.ticks_ms()
            playBuzzer = 1
            buzzer.value(1)
        else:
            stop()
while True:
    currentTime = time.ticks_ms()
    if (playBuzzer == 1) and (time.ticks_diff(currentTime, buzzerStartTime) > 1000):
         buzzer.value(0)
         playBuzzer = 0
         
    if sp.is_connected():  # Check if a BLE connection is established
        sp.on_write(on_rx)  # Set the callback function for data reception




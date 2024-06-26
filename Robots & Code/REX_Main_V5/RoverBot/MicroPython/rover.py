from machine import Pin, PWM
import bluetooth
from rex import BLESimplePeripheral
import time

# Create a Bluetooth Low Energy (BLE) object
ble = bluetooth.BLE()

# Create an instance of the BLESimplePeripheral class with the BLE object
sp = BLESimplePeripheral(ble)

#motorPWM
motor_pwm = Pin(13, Pin.OUT)

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

#buzzer
buzzer = Pin(25, Pin.OUT)

playBuzzer = 0
buzzerStartTime = 0

#default motor speed
MotorSpeed = 65535

def forward(speed):
   motor_pwm.high()

   motor_A1.duty_u16(speed)
   motor_A2.duty_u16(0)

   motor_B1.duty_u16(speed)
   motor_B2.duty_u16(0)

   motor_C1.duty_u16(speed)
   motor_C2.duty_u16(0)

   motor_D1.duty_u16(speed)
   motor_D2.duty_u16(0)
   return

def backward(speed):
   motor_pwm.high()
   
   motor_A1.duty_u16(0)
   motor_A2.duty_u16(speed)

   motor_B1.duty_u16(0)
   motor_B2.duty_u16(speed)

   motor_C1.duty_u16(0)
   motor_C2.duty_u16(speed)

   motor_D1.duty_u16(0)
   motor_D2.duty_u16(speed)

def right(speed):
   motor_pwm.high()
   
   motor_A1.duty_u16(speed)
   motor_A2.duty_u16(0)

   motor_B1.duty_u16(speed)
   motor_B2.duty_u16(0)

   motor_C1.duty_u16(0)
   motor_C2.duty_u16(speed)

   motor_D1.duty_u16(0)
   motor_D2.duty_u16(speed)

def left(speed):
   motor_pwm.high()
   
   motor_A1.duty_u16(0)
   motor_A2.duty_u16(speed)

   motor_B1.duty_u16(0)
   motor_B2.duty_u16(speed)

   motor_C1.duty_u16(speed)
   motor_C2.duty_u16(0)

   motor_D1.duty_u16(speed)
   motor_D2.duty_u16(0)

def stop():
   motor_pwm.low()
   
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
    global buzzerStartTime, playBuzzer
    print("Data received: ", data)  # Print the received data
    
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
    elif data == b'\xff\x01\x01\x01\x02\x02\x00\x00': #select
        print("select")
    elif data == b'\xff\x01\x01\x01\x02\x01\x00\x00': #start
        print("start")
    else:
        stop()

while True:
    currentTime = time.ticks_ms()
    if (playBuzzer == 1) and (time.ticks_diff(currentTime, buzzerStartTime) > 1000):
         buzzer.value(0)
         playBuzzer = 0
         
    if sp.is_connected():  # Check if a BLE connection is established
        sp.on_write(on_rx)  # Set the callback function for data reception

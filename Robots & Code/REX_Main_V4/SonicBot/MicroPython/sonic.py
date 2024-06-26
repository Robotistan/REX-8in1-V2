from machine import Pin, ADC, PWM
import time
from rex import HCSR04

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
motor_D1 = PWM(Pin(14))
motor_D1.duty_u16(0)
motor_D2 = PWM(Pin(27))
motor_D2.duty_u16(0)

buzzer = Pin(25, Pin.OUT)
sensor = HCSR04(trigger_pin=17, echo_pin=16, echo_timeout_us=10000)

#default motor speed
MotorSpeed = 50000

def forward(speed):
   motor_A1.duty_u16(speed)
   motor_A2.duty_u16(0)

   motor_B1.duty_u16(speed)
   motor_B2.duty_u16(0)

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

def backward(speed):
   motor_A1.duty_u16(0)
   motor_A2.duty_u16(speed)

   motor_B1.duty_u16(0)
   motor_B2.duty_u16(speed)

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

while True:
    distance = sensor.distance_cm()
    print(distance)
    if distance > 12:
        forward(MotorSpeed)
    else:
        backward(MotorSpeed)
        buzzer.value(1)
        time.sleep(0.3)
        buzzer.value(0)
        left(MotorSpeed)
        time.sleep(0.2)
        stop()
        

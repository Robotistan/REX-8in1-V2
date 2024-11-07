import machine
from machine import Pin, ADC, PWM, Timer
from time import sleep
import utime
from rex import HCSR04

#IR pins
leftSensor = ADC(Pin(34))
rightSensor = ADC(Pin(35))

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

#speed values
MotorSpeed = 50000

#HCSR04
sensor = HCSR04(trigger_pin=17, echo_pin=16, echo_timeout_us=10000)

threshold = 65000

def forward(speed):
   motor_pwm.value(1)

   motor_A1.duty_u16(speed)
   motor_A2.duty_u16(0)

   motor_B1.duty_u16(speed)
   motor_B2.duty_u16(0)

   motor_C1.duty_u16(speed)
   motor_C2.duty_u16(0)

   motor_D1.duty_u16(speed)
   motor_D2.duty_u16(0)

def right(speed):
   motor_pwm.value(1)
   
   motor_A1.duty_u16(speed)
   motor_A2.duty_u16(0)

   motor_B1.duty_u16(speed)
   motor_B2.duty_u16(0)

   motor_C1.duty_u16(0)
   motor_C2.duty_u16(speed)

   motor_D1.duty_u16(0)
   motor_D2.duty_u16(speed)

def left(speed):
   motor_pwm.value(1)
   
   motor_A1.duty_u16(0)
   motor_A2.duty_u16(speed)

   motor_B1.duty_u16(0)
   motor_B2.duty_u16(speed)

   motor_C1.duty_u16(speed)
   motor_C2.duty_u16(0)

   motor_D1.duty_u16(speed)
   motor_D2.duty_u16(0)

def backward(speed):
   motor_pwm.value(1)
   
   motor_A1.duty_u16(0)
   motor_A2.duty_u16(speed)

   motor_B1.duty_u16(0)
   motor_B2.duty_u16(speed)

   motor_C1.duty_u16(0)
   motor_C2.duty_u16(speed)

   motor_D1.duty_u16(0)
   motor_D2.duty_u16(speed)

def stop():
   motor_pwm.value(0)
   
   motor_A1.duty_u16(0)
   motor_A2.duty_u16(0)

   motor_B1.duty_u16(0)
   motor_B2.duty_u16(0)

   motor_C1.duty_u16(0)
   motor_C2.duty_u16(0)

   motor_D1.duty_u16(0)
   motor_D2.duty_u16(0)

while True:
    distance = sensor.distance_cm()
    #print(distance)
    if distance <= 15:
        leftSensorValue = leftSensor.read_u16()
        rightSensorValue = rightSensor.read_u16()
        #print(leftSensorValue)
        #print(rightSensorValue)
        sleep(0.02)
        if leftSensorValue >= threshold or rightSensorValue >= threshold:
            backward(MotorSpeed)
            sleep(0.5)
        elif leftSensorValue < threshold and rightSensorValue < threshold:
            forward(MotorSpeed)
        else:
            stop()
    else:
        leftSensorValue = leftSensor.read_u16()
        rightSensorValue = rightSensor.read_u16()
        #print(leftSensorValue)
        #print(rightSensorValue)
        sleep(0.02)
        if leftSensorValue >= threshold or rightSensorValue >= threshold:
            backward(MotorSpeed)
            sleep(0.5)
        elif leftSensorValue < threshold and rightSensorValue < threshold:
            left(MotorSpeed)
            sleep(0.1)
            stop()
        else:
            stop()

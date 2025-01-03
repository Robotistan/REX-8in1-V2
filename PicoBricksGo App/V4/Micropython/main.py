import machine
from machine import Pin, PWM
from rex import ESP32_BLE, Servo
import time

#Motor Pins Definations
motor_A1 = PWM(Pin(15))
motor_A1.duty_u16(0)
motor_A2 = PWM(Pin(23))
motor_A2.duty_u16(0)

motor_B1 = PWM(Pin(32))
motor_B1.duty_u16(0)
motor_B2 = PWM(Pin(33))
motor_B2.duty_u16(0)

motor_C1 = PWM(Pin(5))
motor_C1.duty_u16(0)
motor_C2 = PWM(Pin(4))
motor_C2.duty_u16(0)

motor_D1 = PWM(Pin(27))
motor_D1.duty_u16(0)
motor_D2 = PWM(Pin(14))
motor_D2.duty_u16(0)

# Servo Motor Pin Definitions
Servo1 = Servo(2)   # Servo 1: Forward-Backward
Servo2 = Servo(26)  # Servo 2: Right-Left
Servo3 = Servo(18)  # Servo 3: Up-Down
Servo4 = Servo(19)  # Servo 4: Open-Close

#Buzzer Pins Defination
buzzer_pin = Pin(25, Pin.OUT)
buzzer_pwm = machine.PWM(buzzer_pin, freq=1000, duty=0)

#Default Servo Positions (in degrees)
position1 = 90;
position2 = 90;
position3 = 90;
position4 = 90;

# Set the servo motors to their default positions
Servo1.move(position1)
Servo2.move(position2)
Servo3.move(position3)
Servo4.move(position4)

# Movement Directions
STOP = 0
FWD = 1
BWD = 2
RIGHT = 3
LEFT = 4
FWD_RIGHT = 5
FWD_LEFT = 6
BWD_RIGHT = 7
BWD_LEFT = 8

# Notes
NOTE_C  = 262
NOTE_CS = 278
NOTE_D  = 294
NOTE_DS = 312
NOTE_E  = 330
NOTE_F  = 350
NOTE_FS = 370
NOTE_G  = 392
NOTE_GS = 416
NOTE_A  = 440
NOTE_AS = 467
NOTE_B  = 494
NOTE_C2 = 524

# Joystick Modes
joystick = 1
buttons = 2

# Joystick Dead Zone and Center Values
deadZone = 20  # No response in this range
centerX = 127  # Center value for X-axis
centerY = 127  # Center value for Y-axis

def custom_map(value, in_min, in_max, out_min, out_max):  #Map a value from one range to another
    return (value - in_min) * (out_max - out_min) // (in_max - in_min) + out_min

def constrain(val, min_val, max_val):  #Constrain a value between min_val and max_val
    return max(min_val, min(max_val, val))

def move (direction, speed):  #Control motor movement based on direction and speed
    avg = constrain(speed, 150, 255)  # Constrain speed within 150-255
    duty = custom_map(avg,150,255,50000,65535)  # Convert speed to duty cycle
    
    # Define motor behavior for different directions
    if direction == FWD:
        motor_A1.duty_u16(duty)
        motor_A2.duty_u16(0)
        motor_B1.duty_u16(duty)
        motor_B2.duty_u16(0)
        motor_C1.duty_u16(duty)
        motor_C2.duty_u16(0)
        motor_D1.duty_u16(duty)
        motor_D2.duty_u16(0)
    elif direction == BWD:
        motor_A1.duty_u16(0)
        motor_A2.duty_u16(duty)
        motor_B1.duty_u16(0)
        motor_B2.duty_u16(duty)
        motor_C1.duty_u16(0)
        motor_C2.duty_u16(duty)
        motor_D1.duty_u16(0)
        motor_D2.duty_u16(duty)
    elif direction == LEFT:
        motor_A1.duty_u16(0)
        motor_A2.duty_u16(duty)
        motor_B1.duty_u16(0)
        motor_B2.duty_u16(duty)
        motor_C1.duty_u16(duty)
        motor_C2.duty_u16(0)
        motor_D1.duty_u16(duty)
        motor_D2.duty_u16(0)
    elif direction == RIGHT:
        motor_A1.duty_u16(duty)
        motor_A2.duty_u16(0)
        motor_B1.duty_u16(duty)
        motor_B2.duty_u16(0)
        motor_C1.duty_u16(0)
        motor_C2.duty_u16(duty)
        motor_D1.duty_u16(0)
        motor_D2.duty_u16(duty)
    elif direction == FWD_RIGHT:
        motor_A1.duty_u16(duty)
        motor_A2.duty_u16(0)
        motor_B1.duty_u16(duty)
        motor_B2.duty_u16(0)
        motor_C1.duty_u16(duty)
        motor_C2.duty_u16(0)
        motor_D1.duty_u16(0)
        motor_D2.duty_u16(duty)
    elif direction == FWD_LEFT:
        motor_A1.duty_u16(duty)
        motor_A2.duty_u16(0)
        motor_B1.duty_u16(0)
        motor_B2.duty_u16(duty)
        motor_C1.duty_u16(duty)
        motor_C2.duty_u16(0)
        motor_D1.duty_u16(duty)
        motor_D2.duty_u16(0)
    elif direction == BWD_RIGHT:
        motor_A1.duty_u16(0)
        motor_A2.duty_u16(duty)
        motor_B1.duty_u16(0)
        motor_B2.duty_u16(duty)
        motor_C1.duty_u16(0)
        motor_C2.duty_u16(duty)
        motor_D1.duty_u16(duty)
        motor_D2.duty_u16(0)
    elif direction == BWD_LEFT:
        motor_A1.duty_u16(0)
        motor_A2.duty_u16(duty)
        motor_B1.duty_u16(duty)
        motor_B2.duty_u16(0)
        motor_C1.duty_u16(0)
        motor_C2.duty_u16(duty)
        motor_D1.duty_u16(0)
        motor_D2.duty_u16(duty)
    else:  #STOP
        motor_A1.duty_u16(0)
        motor_A2.duty_u16(0)
        motor_B1.duty_u16(0)
        motor_B2.duty_u16(0)
        motor_C1.duty_u16(0)
        motor_C2.duty_u16(0)
        motor_D1.duty_u16(0)
        motor_D2.duty_u16(0)
        
def omni_move (direction, speed):  #Control motor movement based on direction and speed
    avg = constrain(speed, 150, 255)  # Constrain speed within 150-255
    duty = custom_map(avg,150,255,50000,65535)  # Convert speed to duty cycle
    
    # Define motor behavior for different directions
    if direction == FWD:
        motor_A1.duty_u16(0)
        motor_A2.duty_u16(duty)
        motor_B1.duty_u16(0)
        motor_B2.duty_u16(duty)
        motor_C1.duty_u16(0)
        motor_C2.duty_u16(duty)
        motor_D1.duty_u16(0)
        motor_D2.duty_u16(duty)
    elif direction == BWD:
        motor_A1.duty_u16(duty)
        motor_A2.duty_u16(0)
        motor_B1.duty_u16(duty)
        motor_B2.duty_u16(0)
        motor_C1.duty_u16(duty)
        motor_C2.duty_u16(0)
        motor_D1.duty_u16(duty)
        motor_D2.duty_u16(0)
    elif direction == LEFT:
        motor_A1.duty_u16(duty)
        motor_A2.duty_u16(0)
        motor_B1.duty_u16(0)
        motor_B2.duty_u16(duty)
        motor_C1.duty_u16(0)
        motor_C2.duty_u16(duty)
        motor_D1.duty_u16(duty)
        motor_D2.duty_u16(0)
    elif direction == RIGHT:
        motor_A1.duty_u16(0)
        motor_A2.duty_u16(duty)
        motor_B1.duty_u16(duty)
        motor_B2.duty_u16(0)
        motor_C1.duty_u16(duty)
        motor_C2.duty_u16(0)
        motor_D1.duty_u16(0)
        motor_D2.duty_u16(duty)
    elif direction == FWD_RIGHT:
        motor_A1.duty_u16(0)
        motor_A2.duty_u16(duty)
        motor_B1.duty_u16(0)
        motor_B2.duty_u16(0)
        motor_C1.duty_u16(0)
        motor_C2.duty_u16(0)
        motor_D1.duty_u16(0)
        motor_D2.duty_u16(duty)
    elif direction == FWD_LEFT:
        motor_A1.duty_u16(0)
        motor_A2.duty_u16(0)
        motor_B1.duty_u16(0)
        motor_B2.duty_u16(duty)
        motor_C1.duty_u16(0)
        motor_C2.duty_u16(duty)
        motor_D1.duty_u16(0)
        motor_D2.duty_u16(0)
    elif direction == BWD_RIGHT:
        motor_A1.duty_u16(0)
        motor_A2.duty_u16(0)
        motor_B1.duty_u16(duty)
        motor_B2.duty_u16(0)
        motor_C1.duty_u16(duty)
        motor_C2.duty_u16(0)
        motor_D1.duty_u16(0)
        motor_D2.duty_u16(0)
    elif direction == BWD_LEFT:
        motor_A1.duty_u16(duty)
        motor_A2.duty_u16(0)
        motor_B1.duty_u16(0)
        motor_B2.duty_u16(0)
        motor_C1.duty_u16(0)
        motor_C2.duty_u16(0)
        motor_D1.duty_u16(duty)
        motor_D2.duty_u16(0)
    else:  #STOP
        motor_A1.duty_u16(0)
        motor_A2.duty_u16(0)
        motor_B1.duty_u16(0)
        motor_B2.duty_u16(0)
        motor_C1.duty_u16(0)
        motor_C2.duty_u16(0)
        motor_D1.duty_u16(0)
        motor_D2.duty_u16(0)
   
def rex_horn():  #Activate the buzzer for a short beep
    buzzer_pwm.duty(256) 
    buzzer_pwm.freq(262)  
    time.sleep(0.2)
    buzzer_pwm.duty(0)  # Stop the buzzer
    
def piano_tone(note): #Play a specific piano note for a given duration
    buzzer_pwm.duty(256)  # Set a 50% duty cycle
    buzzer_pwm.freq(note)  # Set the frequency for the note
    time.sleep(0.2)
    buzzer_pwm.duty(0)  # Stop the buzzer

# Initialize BLE device with callback for processing incoming data
ble_device = ESP32_BLE()

while True:
    buffer = ble_device.get_data()  # Get data from BLE
    if buffer:
        if buffer[0] == 75:  # Check for Rex Header Byte (75)
            if buffer[1] == 1:  # Wibot & Roverbot
                if buffer[2] == 1:
                  control = joystick
                else:
                  control = buttons

                if buffer[2] == 2:  #Horn
                  rex_horn()
                if control == buttons:  #Directional Buttons
                  if buffer[2] == 99:   #Stop
                    move(STOP, 0)
                  if buffer[2] == 3:  #Forward movement
                    move(FWD, 255)
                  if buffer[2] == 4:  #Forward-right diagonal
                    move(FWD_RIGHT, 150)
                  if buffer[2] == 5:  #Right turn
                    move(RIGHT, 255)
                  if buffer[2] == 6:  #Backward-right diagonal
                    move(BWD_RIGHT, 150)
                  if buffer[2] == 7:  #Backward movement
                    move(BWD, 255)
                  if buffer[2] == 8:  #Backward-left diagonal
                    move(BWD_LEFT, 150)
                  if buffer[2] == 9:  #Left turn
                    move(LEFT, 255)
                  if buffer[2] == 10: #Forward-left diagonal
                    move(FWD_LEFT, 150)
                else:  #Joystick
                  xValue = buffer[3]  #Joystick X-axis
                  yValue = buffer[4]  #Joystick Y-axis

                  ySpeed = custom_map(abs(yValue - centerY), 0, 127, 0, 255)  #Map Y-axis for forward/backward speed
                  xSpeed = custom_map(abs(xValue - centerX), 0, 127, 0, 255)  #Map X-axis for turning speed

                  if (xValue == 0 and yValue == 0):  #Check if joystick is close to the center for stopping
                    move(STOP,0)
                  elif (yValue < centerY - deadZone and abs(xValue - centerX) <= deadZone):  #Forward movement
                    move(FWD, ySpeed)
                  elif (yValue > centerY + deadZone and abs(xValue - centerX) <= deadZone):  #Backward movement
                    move(BWD, ySpeed)
                  elif (xValue < centerX - deadZone and abs(yValue - centerY) <= deadZone):  #Left turn
                    move(LEFT, xSpeed)
                  elif (xValue > centerX + deadZone and abs(yValue - centerY) <= deadZone):  #Right turn
                    move(RIGHT, xSpeed)
                  elif (yValue < centerY - deadZone and xValue > centerX + deadZone):  #Forward-right diagonal
                    move(FWD_RIGHT, ySpeed)
                  elif (yValue < centerY - deadZone and xValue < centerX - deadZone):  #Forward-left diagonal
                    move(FWD_LEFT, ySpeed)
                  elif (yValue > centerY + deadZone and xValue > centerX + deadZone):  #Backward-right diagonal
                    move(BWD_RIGHT, ySpeed)
                  elif (yValue > centerY + deadZone and xValue < centerX - deadZone):  #Backward-left diagonal
                    move(BWD_LEFT, ySpeed)
                  else:
                    move(STOP,0)
            elif buffer[1] == 2: #Omnibot
                if buffer[2] == 1:
                  control = joystick
                else:
                  control = buttons

                if buffer[2] == 2:  #Horn
                  rex_horn()
                if control == buttons:  #Directional Buttons
                  if buffer[2] == 99:  #Stop
                    omni_move(STOP, 0)
                  if buffer[2] == 3:  #Forward movement
                    omni_move(FWD, 255)
                  if buffer[2] == 4:  #Forward-right diagonal
                    omni_move(FWD_RIGHT, 255)
                  if buffer[2] == 5:  #Right turn
                    omni_move(RIGHT, 255)
                  if buffer[2] == 6:  #Backward-right diagonal
                    omni_move(BWD_RIGHT, 255)
                  if buffer[2] == 7:  #Backward movement
                    omni_move(BWD, 255)
                  if buffer[2] == 8:  #Backward-left diagonal
                    omni_move(BWD_LEFT, 255)
                  if(buffer[2] == 9):  #Left turn
                    omni_move(LEFT, 255)
                  if(buffer[2] == 10):  #Forward-left diagonal
                    omni_move(FWD_LEFT, 255)
                else:  #Joystick
                  xValue = buffer[3]  #Joystick X-axis
                  yValue = buffer[4]  #Joystick Y-axis

                  ySpeed = custom_map(abs(yValue - centerY), 0, 127, 0, 255)  #Map Y-axis for forward/backward speed
                  xSpeed = custom_map(abs(xValue - centerX), 0, 127, 0, 255)  #/Map X-axis for turning speed

                  if (xValue == 0 and yValue == 0): #Check if joystick is close to the center for stopping
                    omni_move(STOP,0)
                  elif (yValue < centerY - deadZone and abs(xValue - centerX) <= deadZone):  #Forward movement
                    omni_move(FWD, ySpeed)
                  elif (yValue > centerY + deadZone and abs(xValue - centerX) <= deadZone):  #Backward movement
                    omni_move(BWD, ySpeed)
                  elif (xValue < centerX - deadZone and abs(yValue - centerY) <= deadZone):  #Left turn
                    omni_move(LEFT, xSpeed)
                  elif (xValue > centerX + deadZone and abs(yValue - centerY) <= deadZone):  #Right turn
                    omni_move(RIGHT, xSpeed)
                  elif (yValue < centerY - deadZone and xValue > centerX + deadZone):  #Forward-right diagonal
                    omni_move(FWD_RIGHT, ySpeed)
                  elif (yValue < centerY - deadZone and xValue < centerX - deadZone):  #Forward-left diagonal
                    omni_move(FWD_LEFT, ySpeed)
                  elif (yValue > centerY + deadZone and xValue > centerX + deadZone):  #Backward-right diagonal
                    omni_move(BWD_RIGHT, ySpeed)
                  elif (yValue > centerY + deadZone and xValue < centerX - deadZone):  #Backward-left diagonal
                    omni_move(BWD_LEFT, ySpeed)
                  else:
                    omni_move(STOP,0)
            elif buffer[1] == 3: #Armbot
                if buffer[2] == 1: #Servo Motor Reset
                    position1 = 90;
                    position2 = 90;
                    position3 = 90;
                    position4 = 90;

                    Servo1.move(position1)
                    Servo2.move(position2)
                    Servo3.move(position3)
                    Servo4.move(position4)
                elif buffer[2] == 2: #Horn
                    rex_horn()
                elif buffer[2] == 3:  #DC Motors Control
                    xValue = buffer[3]  #Joystick X-axis
                    yValue = buffer[4]  #Joystick Y-axis
                    
                    ySpeed = custom_map(abs(yValue - centerY), 0, 127, 0, 255)  #Map Y-axis for forward/backward speed
                    xSpeed = custom_map(abs(xValue - centerX), 0, 127, 0, 255)  #Map X-axis for turning speed
                    
                    if (xValue == 0 and yValue == 0):  #Check if joystick is close to the center for stopping
                        move(STOP,0)
                    elif (yValue < centerY - deadZone and abs(xValue - centerX) <= deadZone):  #Forward movement
                        move(FWD, ySpeed)
                    elif (yValue > centerY + deadZone and abs(xValue - centerX) <= deadZone):  #Backward movement
                        move(BWD, ySpeed)
                    elif (xValue < centerX - deadZone and abs(yValue - centerY) <= deadZone):  #Left turn
                        move(LEFT, xSpeed)
                    elif (xValue > centerX + deadZone and abs(yValue - centerY) <= deadZone):  #Right turn
                        move(RIGHT, xSpeed)
                    elif (yValue < centerY - deadZone and xValue > centerX + deadZone):  #Forward-right diagonal
                        move(FWD_RIGHT, ySpeed)
                    elif (yValue < centerY - deadZone and xValue < centerX - deadZone):  #Forward-left diagonal
                        move(FWD_LEFT, ySpeed)
                    elif (yValue > centerY + deadZone and xValue > centerX + deadZone):  #Backward-right diagonal
                        move(BWD_RIGHT, ySpeed)
                    elif (yValue > centerY + deadZone and xValue < centerX - deadZone):  #Backward-left diagonal
                        move(BWD_LEFT, ySpeed)
                    else:
                        move(STOP,0)
                elif buffer[2] == 4:  #Servo Motors Control
                    if buffer[3] == 1:  #Servo 1 Left
                        if position1 > 40:
                            position1 = position1 - 5
                            Servo1.move(position1)
                    if buffer[3] == 2:  #Servo 1 Right
                        if position1 < 140:
                            position1 = position1 + 5
                            Servo1.move(position1)
                    if buffer[3] == 3:  #Servo 2 Up
                        if position2 < 140:
                            position2 = position2 + 5
                            Servo2.move(position2)
                    if buffer[3] == 4:  #Servo 2 Down
                        if position2 > 0:
                            position2 = position2 - 5
                            Servo2.move(position2)
                    if buffer[3] == 5:  #Servo 3 Down
                        if position3 > 30:
                            position3 = position3 - 5
                            Servo3.move(position3)
                    if buffer[3] == 6:  #Servo 3 Up
                        if position3 < 150:
                            position3 = position3 + 5
                            Servo3.move(position3)
                    if buffer[3] == 7:  #Servo 4 Open
                        if position4 > 90:
                            position4 = position4 - 5
                            Servo4.move(position4)
                    if buffer[3] == 8:  #Servo 4 close
                        if position4 < 160:
                            position4 = position4 + 5
                            Servo4.move(position4)
                else:
                    print("Wrong Command")
            elif(buffer[1] == 5): #Piano
                if(buffer[2] == 1): #C1
                    piano_tone(NOTE_C)
                elif(buffer[2] == 2): #D
                    piano_tone(NOTE_D)
                elif(buffer[2] == 3): #E
                    piano_tone(NOTE_E)
                elif(buffer[2] == 4): #F
                    piano_tone(NOTE_F)
                elif(buffer[2] == 5): #G
                    piano_tone(NOTE_G)
                elif(buffer[2] == 6): #A
                    piano_tone(NOTE_A)
                elif(buffer[2] == 7): #B
                    piano_tone(NOTE_B)
                elif(buffer[2] == 8): #C2
                    piano_tone(NOTE_C2)
                elif(buffer[2] == 9): #CS
                    piano_tone(NOTE_CS)
                elif(buffer[2] == 10): #DS
                    piano_tone(NOTE_DS)
                elif(buffer[2] == 11): #FS
                    piano_tone(NOTE_FS)
                elif(buffer[2] == 12): #GS
                    piano_tone(NOTE_GS)
                elif(buffer[2] == 13): #AS
                    piano_tone(NOTE_AS)
            else:
                print("Wrong Robot")

        ble_device.clear_data()

# REX Main

<p align="center">
  <img src="https://user-images.githubusercontent.com/112697142/230360152-12d52dec-c5a4-4487-ae4a-e29177675dd2.gif" alt="animated" />
</p>

<p align="center">
360° Preview
</p>

# ESP32 WROOM 32E Pinout 


#### Warning! Please do not connect an external battery if you are using 18650 batteries while using the card.


<p align="center">
  <img src="https://github.com/Robotistan/REX-8in1-V2/assets/112697142/282f0bed-ec1c-416f-87cb-69754931806c" alt="animated" />
</p>

## Pin Connection Tables
### DC Motor Pins V4
| Motor-A   | GPIO     | Explanation                         | - | Motor-B   | GPIO     | Explanation                         |
| :-------- | :------- | :-------------------------    |:--| :-------- | :------- | :-------------------------    |
| `M_A1`    | `15`     | Forward.                      | - | `M_B1`    | `32`     | Forward.                      |
| `M_A2`    | `23`     | Backward.                     | - | `M_B2`    | `33`     | Backward.                     |

| Motor-C   | GPIO     | Explanation                         | - | Motor-D   | GPIO     | Explanation                         |
| :-------- | :------- | :-------------------------    |:- | :-------- | :------- | :-------------------------    |
| `M_C1`    | `5`      | Forward.                      | - | `M_D1`    | `27`     | Forward.                      |
| `M_C2`    | `4`      | Backward.                     | - | `M_D2`    | `14`     | Backward.                     |

### DC Motor Pins V5
| Motor-A   | GPIO     | Explanation                         | - | Motor-B   | GPIO     | Explanation                         |
| :-------- | :------- | :-------------------------    |:--| :-------- | :------- | :-------------------------    |
| `M_A1`    | `15`     | Forward.                      | - | `M_B1`    | `32`     | Forward.                      |
| `M_A2`    | `23`     | Backward.                     | - | `M_B2`    | `33`     | Backward.                     |

| Motor-C   | GPIO     | Explanation                         | - | Motor-D   | GPIO     | Explanation                         |
| :-------- | :------- | :-------------------------    |:- | :-------- | :------- | :-------------------------    |
| `M_C1`    | `14`      | Forward.                      | - | `M_D1`    | `5`     | Forward.                      |
| `M_C2`    | `27`      | Backward.                     | - | `M_D2`    | `4`     | Backward.                     |

### Servo Motor Pins
| Servo Pins   | GPIO     | Explanation                      | -  | Servo Pins   | GPIO     | Explanation                      |
| :--------    | :------- | :------------------------- |:-| :--------    | :------- | :------------------------- |
| `Servo-1`    | `2`      | Powered by 6V | - | `Servo-3`    | `18`     | Powered by 6V |
| `Servo-2`    | `26`     | Powered by 6V | - | `Servo-4`    | `19`     | Powered by 6V |


### IR Sensor Pins
| IR Sensor | GPIO     |       Explanation                   |
| :-------- | :------- | :-------------------------    |
| `A0`      | `34`      | Connected to left sensor when loked from top. |
| `A1`      | `35`      | Connected to right sensor when loked from top. |
### Ultrasonic Sensor Pins
| Ultrasonic Sensor   | GPIO      |                                     Explanation                                      |
| :--------            | :-------  | :-------------------------                                                     |
| `TRIG`               | `17`      | Pin is used to trigger ultrasonic sound pulses                                 |
| `ECHO`               | `16`      | By measuring the time the Echo pin stays high, the distance can be calculated. |
### I2C Pins
| I2C        | GPIO      |       Explanation                   |
| :--------  | :-------  | :-------------------------    |
| `SCL`      | `22`      | **Connected** Yellow Connection Cable. |
| `SDA`      | `21`      | **Connected** White Connection Cable. |
### Buzzer Pin
| Buzzer     | GPIO      |       Explanation                   |
| :--------  | :-------  | :-------------------------    |
| `Buzzer`   | `25`      |  **Connected** pin 25. |
### MPU6050 Pins
| MPU6050    | GPIO      |       Explanation                  |
| :--------  | :-------  | :-------------------------   |
| `SCL`      | `22`      | I2C Communication |
| `SDA`      | `21`      | I2C Communication |
| `INT`      | `13`      | interrupt pin     |

</p>
<p align="center">
  <img src="https://user-images.githubusercontent.com/78815495/232464533-1807c9cc-87b0-4529-b5ec-bb78b5b8704c.jpg" alt="animated" />
</p>
<h4 align="center">ESP32 WROOM 32E Pinout</h4>
</p>
<p align="center">
  <img height="600" src="https://github.com/Robotistan/REX-8in1-V2/assets/111511331/9c75fb32-9052-4950-a0d4-070f6cd1bd6e" alt="animated" />
</p>
<h4 align="center">You can use external battery.</h4>
</p>
<p align="center">
  <img height="600" src="https://github.com/Robotistan/REX-8in1-V2/assets/111511331/8aa56d2c-6eb6-4dd6-9d9e-08b0318b9e36" alt="animated" />
</p>
<h4 align="center">There is a space between 2 layers for external battery.</h4>

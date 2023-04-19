## ESP32 WROOM 32E Pinout

<p align="center">
360° Preview
</p>

<p align="center">
  <img src="https://user-images.githubusercontent.com/112697142/230360152-12d52dec-c5a4-4487-ae4a-e29177675dd2.gif" alt="animated" />
</p>

<p align="center">
Warning! Please do not connect an external battery if you are using 18650 batteries while using the card.
</p>


<p align="center">
  <img src="https://user-images.githubusercontent.com/78815495/232464806-6abdce40-22c8-40ba-807a-c8adba2092a3.png" alt="animated" />
</p>

### Which pins connected to Sockets

| Motor-A   | GPIO     | Notes                         |
| :-------- | :------- | :-------------------------    |
| `M_A1`    | `15`     | **Gerekli**. API anahtarınız. |
| `M_A2`    | `23`     | **Gerekli**. API anahtarınız. |

| Motor-B   | GPIO     | Notes                         |
| :-------- | :------- | :-------------------------    |
| `M_B1`    | `32`     | **Gerekli**. API anahtarınız. |
| `M_B2`    | `33`     | **Gerekli**. API anahtarınız. |

| Motor-C   | GPIO     | Notes                         |
| :-------- | :------- | :-------------------------    |
| `M_c1`    | `4`      | **Gerekli**. API anahtarınız. |
| `M_c2`    | `5`      | **Gerekli**. API anahtarınız. |

| Motor-D   | GPIO     | Notes                         |
| :-------- | :------- | :-------------------------    |
| `M_D1`    | `14`     | **Gerekli**. API anahtarınız. |
| `M_D2`    | `27`     | **Gerekli**. API anahtarınız. |


| Servo Pins   | GPIO     | Notes                         |
| :--------    | :------- | :-------------------------    |
| `Servo-1`    | `2`      | **Gerekli**. API anahtarınız. |
| `Servo-2`    | `26`     | **Gerekli**. API anahtarınız. |
| `Servo-3`    | `18`     | **Gerekli**. API anahtarınız. |
| `Servo-4`    | `19`     | **Gerekli**. API anahtarınız. |

| IR Sensor | GPIO     |       Notes                   |
| :-------- | :------- | :-------------------------    |
| `TX`      | `1`      | **Gerekli**. API anahtarınız. |
| `RX`      | `3`      | **Gerekli**. API anahtarınız. |

| Ulstrasonic Sensor   | GPIO      |       Notes                   |
| :--------            | :-------  | :-------------------------    |
| `TRIG`               | `17`      | **Gerekli**. API anahtarınız. |
| `ECHO`               | `16`      | **Gerekli**. API anahtarınız. |

| I2C        | GPIO      |       Notes                   |
| :--------  | :-------  | :-------------------------    |
| `SCL`      | `22`      | **Connected**. Yellow Cable. |
| `SDA`      | `21`      | **Connected**. ''White Cable.''  |

| Buzzer     | GPIO      |       Notes                   |
| :--------  | :-------  | :-------------------------    |
| `Buzzer`   | `25`      | **Gerekli**. API anahtarınız. |

| MPU6050    | GPIO      |       Notes                  |
| :--------  | :-------  | :-------------------------   |
| `SCL`      | `22`      | **Connected**. Yellow Cable. |
| `SDA`      | `21`      | **Connected**. White Cable.  |
| `INT`      | `13`      | **Connected**. Yellow Cable. |


</p>
<p align="center">
  <img src="https://user-images.githubusercontent.com/78815495/232464533-1807c9cc-87b0-4529-b5ec-bb78b5b8704c.jpg" alt="animated" />
</p>

